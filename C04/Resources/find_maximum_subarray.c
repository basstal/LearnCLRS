#include <stdio.h>
#include <limits.h>
#include "subarray.h"
#include <stdlib.h>
#include <sys/timeb.h>
Subarray find_maximum_subarray_brute(int a[],int low ,int high);
Subarray find_crossing_subarray(int a[],int low,int mid , int high){
    int left_max = INT_MIN;
    int sum = 0;
    int left;
    for(int i = mid ; i >= low ; --i){

        sum = sum + a[i];
        if(sum > left_max){
            left_max = sum;
            left = i;
        }
    }
    int right_max = INT_MIN,right;
    sum = 0;
    for(int j = mid+1 ; j <= high ; ++j){
        sum = sum + a[j];
        if(sum > right_max){
            right_max = sum;
            right = j;
        }
    }
    Subarray sa = {left,right,left_max + right_max};
    return sa;
}
Subarray find_maximum_subarray(int a[],int low, int high){
    if(high < 700)
        return find_maximum_subarray_brute(a,low,high);
    if(low == high){
        Subarray sa = {low,high,a[low]};
        return sa;
    }
    else{
        int mid = (low+high)/2;
        Subarray left_maximum = find_maximum_subarray(a,low,mid);
        Subarray right_maximum = find_maximum_subarray(a,mid+1,high);
        Subarray crossing_maximum = find_crossing_subarray(a,low,mid,high);
        if(left_maximum.maximum >= right_maximum.maximum && left_maximum.maximum >= crossing_maximum.maximum){
            return left_maximum;
        }
        else if(right_maximum.maximum >= left_maximum.maximum && right_maximum.maximum >= crossing_maximum.maximum){
            return right_maximum;
        }
        else
            return crossing_maximum;
    }
}

long long getSystemTime() {
    struct timeb t;
    ftime(&t);
    return 1000 * t.time + t.millitm;
}

// int main(){
//     int a[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
//     int low = 0,high = 15;
//     Subarray sa = find_maximum_subarray_brute(a,low,high);
//     printf("%d",sa.maximum);
//     printf("[%d,%d]\n",sa.low,sa.high);
// }


int main(){
    int n;
    while(1){
        scanf("%d",&n);
        int a[n];
        for(int i = 0 ; i < n ; ++i){
            a[i] = rand()%100 - 50;
        }

        int low = 0,high = n-1;
        long long start_brute = getSystemTime();
        Subarray sa = find_maximum_subarray_brute(a,low,high);
        long long end_brute = getSystemTime();
        long long start = getSystemTime();
        Subarray sa1 = find_maximum_subarray(a,low,high);
        long long end = getSystemTime();
        printf("brute = %lld ms,%d[%d,%d] \n",end_brute - start_brute,sa.maximum,sa.low,sa.high);
        printf("divide = %lld ms, %d[%d,%d] \n",end - start,sa1.maximum,sa1.low,sa1.high);
    }
}


