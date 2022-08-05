#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int m,n;
int a[N], s[N];

vector<int> alls;  // 用来存储被 加 或 查询 过的位置
vector<PII> add, query;  // 用来存储 加操作 和 查询操作

// 在 vector<int> alls 中找到某一原始位置对应的vector位置
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while(l < r)
    {
        int mid  = l + r >> 1;
        if (alls[mid] >= x){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return r + 1;
}

// 迭代器，去除重复值并返回去除后的容器末位置
vector<int>::iterator unique(vector<int > &a)
{
    int j = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if(!i || a[i] != a[i - 1]){
            a[j++] = a[i];
        }
    }
    // a[0] ~ a[j - 1] 所有a中不重复的数

    return a.begin() + j;
}

int main()
{
    // 读入操作数和查询数
    cin >> n >> m;
    // 读入
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }

    // 进行查询
    for (int i = 0 ; i < m ; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        
        alls.push_back(l);
        alls.push_back(r);
    }

    // 排序和去重
    sort(alls.begin(), alls.end());
    // alls.erase(unique(alls.begin(), alls.end()), alls.end());
    alls.erase(unique(alls), alls.end());

    // 处理插入
    for (auto item : add)
    {
        int x = find(item.first);
        a[x] += item.second;
    }

    // 预处理前缀和
    for (int i = 1; i <= alls.size(); i++){
        s[i] = s[i - 1] + a[i];
    }
    
    // 处理查询
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
}