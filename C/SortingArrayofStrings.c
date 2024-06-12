#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b) > 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(a, b) < 0;
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int cnt1 = 0, cnt2 = 0, hsh1[26] = {0}, hsh2[26] = {0};
    
    for(int i = 0; i < len_a; i++)
        hsh1[(int)a[i] - 'a'] = 1;
    
    for(int i = 0; i < len_b; i++)
        hsh2[(int)b[i] - 'a'] = 1;

    for(int i = 0; i < 26; i++){
        cnt1 += hsh1[i];
        cnt2 += hsh2[i];
    }

    if(cnt1 != cnt2) return cnt1 > cnt2;
    else return strcmp(a, b) > 0;
}

int sort_by_length(const char* a, const char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    if(len_a == len_b) return strcmp(a, b) > 0;
    return len_a > len_b;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    for(int i = 0; i < len - 1; i++){
        for(int j = len - 1; j > i; j--){
            if((*cmp_func)(arr[i], arr[j]) > 0){
                char* tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}