// merge_sort
#include <iostream>
using namespace std;

int n;

void merge_sort(int *q, int l, int r, int *tmp,long int &count)
{
    if(l>=r) return;
    int mid = l + r >> 1;
    merge_sort(q, l, mid, tmp, count);
    merge_sort(q, mid + 1, r, tmp, count);

    int k = 0, i = l, j = mid + 1;
    while( i <= mid && j <= r){
        if(q[i] <= q[j]){
            tmp[k++] = q[i++];
        }
        else{
            tmp[k++] = q[j++];
            count = count + (mid+1-i);
        }
    }
    while(i<=mid){
        tmp[k++] = q[i++];
        // count = count+1;
    }
    while(j<=r) tmp[k++]=q[j++];

    for(int i = l, j = 0 ; i <= r ;  ){
        q[i++] = tmp[j++];
    }
}

int main()
{
    scanf("%d",&n);
    int *q = new int[n];
    int *tmp = new int[n];
    for(int i = 0 ; i < n ; i++ ){
        scanf("%d",&q[i]);
    }
    long int count = 0;
    merge_sort(q, 0, n-1, tmp, count);
    printf("%lld", count);
}