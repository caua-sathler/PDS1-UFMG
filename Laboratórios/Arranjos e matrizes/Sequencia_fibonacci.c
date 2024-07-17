#include <stdio.h>
#include <stdlib.h>

int Fibonacci(int fib[], int A){
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= A; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
        
    }
    return fib[A];
};

int main(){
int fib[801];
int A;
while (1){
    scanf("%d", &A);
    if(A >= 0 && A <= 800){ Fibonacci(fib, A); printf("%d\n", fib[A]);}
    else break;
}
return 0; }