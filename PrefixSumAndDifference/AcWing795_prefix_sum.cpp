#include <iostream>
using namespace std;

const int N = 100010;

int m,n;

int main()
{
    scanf("%d%d", &n, &m);
    int *a = new int[n+1];
    int *s = new int[n+1];

    for (int i = 1 ; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1 ; i <=n ; i++) s[i] = s[i-1] + a[i];
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", s[r] - s[l-1]);
    }
    return 0;
}