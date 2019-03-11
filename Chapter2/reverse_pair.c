#include <stdio.h>
/**
逆序对归并算法的实现
*/


int merge(int A[],int p,int q,int r){

    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1],R[n2];
    int i,j,rp,k;
    for (i = 0 ; i < n1 ; ++i)
        L[i] = A[p + i];
    for (j = 0 ; j < n2 ; ++j)
        R[j] = A[q + j + 1];
    i = 0;
    j = 0;
    rp = 0;
    k = p;
    while (i < n1 && j < n2){
        if (L[i] > R[j]){
            rp = rp + n2 - j;
            A[k] = L[i];
            i = i + 1;
        }
        else{
            A[k] = R[j];
            j = j + 1;
        }
        k = k + 1;
    }
    while (i < n1){

        A[k] = L[i];
        i = i + 1;
        k = k + 1;
    }
    while (j < n2){

        A[k] = R[j];
        j = j + 1;
        k = k + 1;
    }
    return rp;
}
int reverse_pair(int A[],int p,int r){
    int rp = 0;
    if (p < r){
        int q = (p + r)/2;
        rp = rp + reverse_pair(A,p,q);
        rp = rp + reverse_pair(A,q+1,r);
        rp = rp + merge(A,p,q,r);
    }
    return rp;
}
void printArray(int a[],int size){
    for(int i = 0 ; i < size ; ++i)
        printf(" %d",a[i]);
    printf("\n");
}
int main(){
    int a[] = {2,3,8,6,1};
    int rp = 0;
    rp = reverse_pair(a,0,4);
    printf("%d\n",rp);
    printArray(a,5);
}
