#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

int main(){
    int n; 
    int arr_i;
    int64_t sum=0;
    int64_t  *arr;
    int64_t  *p;
    
    scanf("%d", &n);
    arr = malloc(n * sizeof(int64_t));
    p = arr;
    
    for(arr_i = 0; arr_i < n; arr_i++){
    	scanf("%lld", p);
        sum += *p;
        p++;
    }
    
    printf("%lld\n", (long long) sum);
    return 0;
}
