#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N];
int c[N];

int main()
{
    cin >> n;
    for(int i = 0 ; i <n ; i++){
            scanf("%d", &q[i]);
    }
    int max_length = 0;
    for(int i = 0, j = 0; i < n ; i++)
    {
        c[ q[ i ] ] ++;
        while( c[q[i]] > 1 ){
            c[ q[ j ] ] --;
            j++;
        }
        max_length = max(max_length, i - j + 1);
    }
    cout << max_length << endl;
    return 0;
}