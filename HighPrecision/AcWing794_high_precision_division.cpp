#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> div(vector<int> &A, int &b)
{
    vector<int> C,D;
    int r = 0;
    for (int i = A.size()-1; i >= 0; i--)
    {
        r = 10 * r + A[i];
        C.push_back(r / b);
        r %= b;
    }

    for(int i = C.size() - 1 ; i >= 0 ; i--) {D.push_back(C[i]);}

    while(D.size() > 1 && D.back() == 0) D.pop_back();
    D.push_back(r);
    return D;
}

int main()
{
    string a;
    int b;
    vector<int> A;
    cin >> a >> b;
    for(int i = a.size() - 1 ; i >= 0 ; i-- ){
        A.push_back(a[i]-'0');
    }
    auto C = div(A,b);
    for(int i = C.size()-2 ; i >= 0 ; i-- ){
        printf("%d",C[i]);
    }
    printf("\n%d",C.back());
    return 0;
}