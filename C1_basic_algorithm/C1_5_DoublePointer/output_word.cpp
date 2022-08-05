#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string str;
    getline(cin,str);
    int n = str.size();
    for(int i = 0; i < n ; i++)
    {
        int j = i;
        while (j < n && str[j] != ' ' ){
            j++;
        }
        for (int k = i ; k < j ; k++ ){
            cout << str[k];
        }
        cout << endl;
        i = j;
    }
    return 0;
}

// 双指针算法模板
/*
for(int i = 0, int j = 0; i < n ; i++)
{
    while( j < i && check(i,j)) j++;
}
*/