#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

while(1){
    printf("$ ");
    fflush(stdout);

    char input[100];
    fgets(input, 100, stdin);

    input[strlen(input) - 1] = '\0'; 

    if (!strcmp(input, "exit 0"))
      exit(0);
    
    if (strncmp(input, "echo", strlen("echo")) == 0) {
      printf("%s\n", input + 5);
      continue;
    }

    char words[][10] = {"exit", "echo", "type"};
    char *p = strtok(input, " ");

      if (strcmp(p, "type") == 0) {
            int found = 0;
            p = strtok(NULL, " ");
            if (p != NULL) {
                for (int i = 0; i < 3; i++) {
                    if (strcmp(p, words[i]) == 0) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    printf("%s is a shell builtin\n", p);
                } else {
                    printf("%s: not found\n", p);
                }
            } 
        } else {
          printf("%s: command not found\n", input);
        }

    

  }
  return 0;
}