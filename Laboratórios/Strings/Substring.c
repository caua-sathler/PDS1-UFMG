#include <stdio.h>
#include <string.h>

int main()
{
    char S1[20];
    char S2[20];
    

    fgets(S1, 20, stdin);
    fgets(S2, 20, stdin);
    
    
    S1[strcspn(S1, "\n")] = '\0';
    S2[strcspn(S2, "\n")] = '\0';
    
  
    if (strstr(S1, S2) != NULL) {
        printf("É substring\n");
    } else {
        printf("Não é substring\n");
    }
    
    return 0;
}