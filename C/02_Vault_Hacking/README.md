# 🛡️ Systems Lab: Stack Buffer Overflow

### 🧠 Context
This project is a fundamental study of memory management mechanics. Before we can build secure systems, we must understand the physical reality of how data is stored and accessed in memory (RAM).

The goal here is not to "hack," but to visualize **contiguity**—the fact that variables on the Stack live side-by-side. By deliberately overflowing a buffer, we can observe how data physically spills into adjacent memory addresses, corrupting the logic of the program.

### 🛠 Technical Overview
The experiment compares two methods of handling user input in **C (C99)** to demonstrate the importance of bounds checking.

1.  **The Vulnerable Kernel (`vault_vulnerable.c`)**
    Uses `scanf`, which reads input until a newline without checking capacity. On the ARM64 Stack, if we input more data than the variable can hold (8 bytes), the excess data doesn't disappear—it overwrites the neighbor variable (`is_admin`).

2.  **The Secure Patch (`vault_safe.c`)**
    Uses `fgets`, which requires a strict length limit. This acts as a container wall, truncating any excess input and preserving the integrity of the memory layout.

> **The Physics of the Crash**
> When input exceeds the buffer (8 bytes), it spills "down" the stack into the flag variable:
>
> ```text
> [   Password Buffer (8 bytes)   ]  💥  [ Admin Flag (4 bytes) ]
> | A | A | A | A | A | A | A | A |  ->  [ OVERWRITTEN HERE ]
> ```

---

### 💥 Experiment A: The Breach
We compile the vulnerable code to observe the stack smashing in real-time.

```bash
# 1. Compile the vulnerable version
clang vault_vulnerable.c -o vault_vulnerable

# 2. Execute
./vault_vulnerable
```

**Triggering the Overflow:**
When prompted, input **20 characters** (e.g., `AAAAAAAAAAAAAAAAAAAA`). This physically exceeds the allocated 8-byte frame.

**Expected Output:**
The application logic breaks because the `is_admin` flag—which sits next to the buffer in memory—is corrupted by the 'A's, changing its value from `0` (False) to a non-zero value (True).

```text
--- 🔐 SECURE VAULT SYSTEM ---
Enter Password: AAAAAAAAAAAAAAAAAAAA

>>> ✅ ACCESS GRANTED! Welcome, Admin. <<<
Debug Info: is_admin value is now 1094795585 (Not Zero)
```

---

### 🛡️ Experiment B: The Remediation
We verify that modern handling functions prevent this spill.

```bash
# 1. Compile the secure version
clang vault_safe.c -o vault_safe

# 2. Verify Fix
./vault_safe
```

**Verifying the Patch:**
Inputting the same 20-character string will now result in the input being cut off (truncated) at the safe limit.

```text
--- 🛡️ SECURE VAULT v2.0 ---
Enter Password: AAAAAAAAAAAAAAAAAAAA

>>> ❌ ACCESS DENIED! Get out. <<<
Debug: is_admin is still safe at 0
```

---

### 📝 Historical Note
This experiment simulates a classic vulnerability pattern prevalent in the 80s and 90s (e.g., the Morris Worm).

While modern Operating Systems use safeguards like **ASLR** (Address Space Layout Randomization) and **Stack Canaries** to make this harder, understanding the raw behavior of the stack is a prerequisite for understanding systems architecture. You cannot truly secure what you do not understand.
