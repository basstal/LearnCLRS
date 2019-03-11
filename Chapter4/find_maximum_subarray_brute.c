#include <stdio.h>
#include <limits.h>
#include "subarray.h"

Subarray find_maximum_subarray_brute(int a[],int low ,int high){

    int max = INT_MIN;
    int i = 0;
    int size = high+1;
    for (i = low ; i < size; ++i){

        int sum = 0,j;
        for (j = i ; j < size ; ++j){

            sum = sum + a[j];
            if (sum > max){

                max = sum;
                low = i;
                high = j;
            }
        }
    }
    Subarray sa = {low,high,max};
    return sa;
}

// int main(){
//     int a[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
//     int low = 0,high = 15;
//     Subarray sa = find_maximum_subarray_brute(a,low,high);
//     printf("%d",sa.maximum);
//     printf("[%d,%d]\n",sa.low,sa.high);
// }