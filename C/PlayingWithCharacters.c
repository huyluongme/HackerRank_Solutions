#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_LEN 100

int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char ch, s[MAX_LEN], sen[MAX_LEN];
    scanf("%c", &ch);
    scanf("%s\n", &s);
    scanf("%[^\n]%*c", sen);
    
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s", sen);
    return 0;
}