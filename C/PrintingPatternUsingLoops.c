#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
    int size = 2 * n - 1;
    int min_1, min_2, min;

    for(int i = 1; i <= size; i++){
        min_1 = i <= size - i ? i - 1 : size - i;
      for(int j = 1; j <= size; j++){
        min_2 = j <= size - j ? j - 1 : size - j;
        min = min_1 <= min_2 ? min_1 : min_2;
        printf("%d ", n - min);
      }
      printf("\n");
    }
    return 0;
}