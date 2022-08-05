#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010;

vector<PII> segs;
int n;

void merge(vector<PII> &segs)
{
    vector<PII> res;
    sort(segs.begin(),segs.end());

    int st = -2e9, ed = -2e9;
    for(auto &seg:segs)
    {
        // 如果 当前区间右边界 < 新区间的左边界
        if(ed < seg.first){
            if(st != -2e9){
                res.push_back({st, ed});
            }
            st = seg.first, ed = seg.second;
        }
        else{
            ed = max(ed, seg.second);
        }
    }
    if(st != -2e9){
        res.push_back({st, ed});
    }
    segs = res;
}

int main()
{
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l,r});
    }
    merge(segs);
    cout << segs.size() << endl;
    return 0;
}

/*
第1步：按区间左端点排序
第2步：扫描，每次维护一个当前的区间
*/