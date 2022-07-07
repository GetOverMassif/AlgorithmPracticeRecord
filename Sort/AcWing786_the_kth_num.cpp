// quick sort
#include <iostream>

using namespace std;

int n,k;

void quick_sort(int *q, int l, int r)
{
    if(l>=r) return;
    int x = q[l];
    int i = l - 1, j = r + 1;
    while(i<j){
        while(q[++i]<x){}
        while(q[--j]>x){}
        if (i < j)
            swap(q[i],q[j]);
    }
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}

int main()
{
    scanf("%d %d",&n,&k);
    if (k > n){
        cout << "Error: k shouldn't be larger than n." << endl;
        return 0;
    }
    int *q = new int[n];
    for(int i = 0 ; i < n ; i++ ){
        scanf("%d",&q[i]);
    }
    quick_sort(q,0,n-1);
    printf("%d", q[k-1]);
    return 0;
}
