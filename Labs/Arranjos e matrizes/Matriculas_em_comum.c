#include <stdio.h>
#include <stdlib.h>

int main(){
    int numAlunosAEDS;
    int numAlunosCALC;
    int matriculasAEDS[1000];
    int matriculasCALC[1000];
        scanf("%d", &numAlunosAEDS);
        for (int i = 0; i < numAlunosAEDS; i++){
            scanf("%d", &matriculasAEDS[i]);
        }
        scanf("%d", &numAlunosCALC);
        for (int j = 0; j < numAlunosCALC; j++){
            scanf("%d", &matriculasCALC[j]);
            
        }
    for(int i = 0; i < numAlunosAEDS; i++){
        for(int j = 0; j < numAlunosCALC; j++){
            if(matriculasAEDS[i] == matriculasCALC[j]) {printf("%d\n", matriculasAEDS[i]);
            break;
                
            }
        }
    }
return 0;
}