#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char str1[20];
    fgets(str1, 20, stdin);
    str1[strcspn(str1, "\n")] = '\0';
    
    char C1;
    scanf(" %c", &C1);
    char C2;
    scanf(" %c", &C2);
    int i;
    
    for(i = 0; str1[i] != '\0'; i++){
        if(str1[i] == C1) {str1[i] = C2;
        break; }
        printf("%c", str1[i]);
    }
    
    printf("%c", str1[i]);
    i++;
    
    for(; str1[i] != '\0'; i++){
        printf("%c", str1[i]);
    }
    
return 0;
    }