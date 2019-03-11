/**
插入排序
*/
void insertion_sort(int[] a,int length){
    for(int j = 1; j < length; ++j){
        int key = a[j];
        //insert a[j] into the sorted sequence A[1..j-1]
        int i = j-1;
        while(i > -1 && a[i] > key){
            a[i+1] = a[i];
            --i;
        }
        a[i+1] = key;
    }
}