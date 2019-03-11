/**
归并排序
*/
void merge(int a[], int p, int q, int r){
    int n1 = q - p +1;
    int n2 = r - q;
    int larr[n1],rarr[n2];
    int i,j;
    for(i = 0 ; i < n1 ; ++i)
        larr[i] = a[p + i];

    for(j = 0 ; j < n2 ; ++j)
        rarr[j] = a[q + j + 1];

    i = j = 0;
    for(int k = p; k <= r; ++k){
        if(i != n1&& j != n2)
            a[k] = (larr[i] <= rarr[j] ? larr[i++] : rarr[j++]);
        else if(i == n1)
            a[k] = rarr[j++];
        else
            a[k] = larr[i++];
    }
}

void merge_sort(int a[],int p, int r){
    if(p < r){
        int q = (p+r)/2;
        merge_sort(a,p,q);
        merge_sort(a,q+1,r);
        merge(a,p,q,r);
    }
}