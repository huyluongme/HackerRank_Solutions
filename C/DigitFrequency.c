#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int digits[10];
    memset(digits, 0, 10 * sizeof(int));

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);

    for(int i = 0; i < strlen(s); i++){
        char c = *(s + i);
        if(c >= '0' && c <= '9'){
            int digit = (int)c - 48;
            digits[digit]++;
        }
    }

    for(int i = 0; i < 10; i++)
        printf("%d ", digits[i]);
    return 0;
}
