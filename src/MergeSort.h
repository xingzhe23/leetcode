#ifndef __MERGE_SORT_H
#define __MERGE_SORT_H

class MergeSort
{
public:
    static void sort(int a[], int n) {
        if(n <= 0)
            return;

        int *p = new int [n];
        mergeSort(a, 0, n-1, p);
    }

private:
    static void mergeSort(int a[], int first, int last, int temp[]) {
        if(first < last) {
            int mid = (first + last) / 2;
            mergeSort(a, first, mid, temp);
            mergeSort(a, mid+1, last, temp);
            merge(a, first, mid, last, temp);
        }
    }

    static void merge(int a [], int first, int mid, int last, int temp[]) {
        int i = first, j = mid + 1;
        int m = mid, n = last;
        int k = 0;

        while(i <=m && j <= n) {
            if(a[i] <= a[j]) {
                temp[k++] = a[i++];
            } else {
                temp[k++] = a[j++];
            }
        }

        while(i <= m) {
            temp[k++] = a[i++];
        }

        while(j <= n) {
            temp[k++] = a[j++];
        }

        for(int i = 0; i < k; i++) {
            a[i+first] = temp[i];
        }
        
    }
};


#endif