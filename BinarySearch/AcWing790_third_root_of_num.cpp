// binary search
#include <iostream>
using namespace std;

double n;

double search_third_root(double n){
    if(n<0.0){
        return -search_third_root(-n);
    }
    double l = 0.0, r = n;
    if (n < 1.0){
        l = n;
        r = 1;
    }
    double mid = (l+r)/2.0;
    while(r-l > 1e-7){
        if(mid*mid*mid - n > 0.0) r = mid;
        else l = mid;
        mid = (l+r)/2.0;
    }
    return mid;
}

int main(){
    cin >> n;
    double result = search_third_root(n);
    printf("%.6f", result);
    return 0;
}