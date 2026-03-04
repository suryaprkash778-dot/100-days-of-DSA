#include <stdio.h>
#include 
#include 

int main() {
    char str[1000];
    scanf("%s", str);
    
    int left = 0;
    int right = strlen(str) - 1;
    bool isPalindrome = true;
    
    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }
    
    printf("%s\n", isPalindrome ? "YES" : "NO");
    return 0;
}
