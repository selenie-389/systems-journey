# 🔍 Memory Address Investigator

### 🧠 Context
Understanding how the operating system manages memory is fundamental to Systems Engineering. This project serves as a minimal study of memory layout on the **Android ARM64 architecture**.

The goal is to **pierce the abstraction layer** of high-level coding by directly inspecting virtual memory addresses. By validating where variables reside, we confirm our mental models regarding **Stack versus Heap** allocation in a mobile Linux environment.

### 🛠 Technical Overview
Written in **C (C99)**, this utility inspects the raw pointers of integer variables.

On an ARM64 Android kernel, specific address ranges indicate different memory segments. This tool demonstrates that local variables are allocated in the high memory range (typically starting with `0x7f...`), confirming their placement on the **Stack**. 

This behavior contrasts with Heap allocations or static data segments, providing a concrete visualization of the **Process Memory Map**.

### 🚀 Build & Run
The project is designed to be lightweight with no external dependencies.

```bash
# 1. Compile (using Clang)
clang memory.c -o investigator

# 2. Execute the binary
./investigator
```

### 📟 Expected Output
When running the tool, you will see the variable's value alongside its virtual memory address.

```text
The Value is: 42
The Address is: 0x7fd5e294ac

(Note: The exact address will change with every execution due to ASLR - Address Space Layout Randomization)


```
```
```
