#include <stdio.h>

void update(int *a,int *b) {
    int tmp = *a;
    *a += *b;
    *b = tmp - *b;
    if(*b < 0) *b = -*b; 
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}