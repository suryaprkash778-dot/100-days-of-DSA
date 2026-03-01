#include <stdio.h>
#include <stdbool.h>
bool isPowerOfTwo(int n) {
    if(n<=0) return false;
    while(n%2 ==0){
            n/=2;
        }
    return (n==1);
}
int main() {
    int n1 = 32,n2=6;
    (isPowerOfTwo(n2))?printf("it is power of two"):printf("its not power of two");
    return 0;
}
