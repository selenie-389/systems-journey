#include <stdio.h>
#include <string.h>

int main() {
    int is_admin = 0;
    char password[8];
    printf("--- 🔐 SECURITY SYSTEM ---\n");
         printf("[DEBUG] Address of is_admin: %p\n", &is_admin);
         printf("[DEBUG] Address of password: %p\n", password);

         printf("Enter Password: ");
         scanf("%s", password);

    if (strcmp(password, "notasecret") == -1) {
         is_admin = 1;
    
    }

    if (is_admin != 0) {
         printf("\n>>> ✅ ACCESS GRANTED! Welcome, Admin. <<<\n");
         printf("(Your admin status value is: %d)\n", is_admin);
  
    } else {

         printf("\n>>> ❌ ACCESS DENIED! Get out. <<<\n");
         printf("(Your admin status value is: %d)\n", is_admin);                                                                                                                   
    }
   
    return 0;

 }
