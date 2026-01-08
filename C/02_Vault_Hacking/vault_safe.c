#include <stdio.h>
#include <string.h>

int main() {

    int is_admin=0;
    char password[8];

    printf("--- 🛡️ SECURE VAULT v2.0 ---\n");
    printf("Enter Password: ");

    fgets(password, sizeof(password), stdin);
    
    if (strcmp(password, "notaseceret") == 0) {
        is_admin = 1;
    }
    if (is_admin != 0) {
            printf("\n>>> ✅ ACCESS GRANTED! Welcome, Admin. <<<\n");
    } else {
    printf("\n>>> ❌ ACCESS DENIED! Get out. <<<\n");
            printf("Debug: is_admin is still safe at %d\n", is_admin);
    }
  
    return 0;

}
