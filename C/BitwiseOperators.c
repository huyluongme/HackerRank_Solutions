#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int a = 0, b = 0, c = 0;
  for(int i = 1; i < n; i++) {
    for(int j = i + 1; j <= n; j++) {
        int tmp_a = i & j, tmp_b = i | j, tmp_c = i ^ j;
        if (tmp_a > a && tmp_a < k) a = tmp_a;
        if (tmp_b > b && tmp_b < k) b = tmp_b;
        if (tmp_c > c && tmp_c < k) c = tmp_c;
    }
  }
  printf("%d\n%d\n%d", a, b, c);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
