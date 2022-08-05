#include <iostream>
using namespace std;

const int N = 100010;

int m,n,q;

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    // 创建适合大小的数组
    int **a = new int*[n+1];
    int **s = new int*[n+1];
    for (int i = 0 ; i <= n ; i++){
        a[i] = new int[m];
        s[i] = new int[m];
    }

    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    for(int i = 1 ; i <= n ; i++ ){
        for(int j = 1 ; j <= m ; j++){
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    while (q--)
    {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
    }
    return 0;
}