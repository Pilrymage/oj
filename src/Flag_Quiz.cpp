#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<string> vs;

const int INF = 1e9;
const int LLINF = 4e18;
const double EPS = 1e-9;

// 函数重载，用于打印不同类型的数据
void __print(int x) {std::cerr << x;}
void __print(long long x) {std::cerr << x;}
void __print(double x) {std::cerr << x;}
void __print(char x) {std::cerr << '\'' << x << '\'';}
void __print(const char *x) {std::cerr << '\"' << x << '\"';}
void __print(const std::string &x) {std::cerr << '\"' << x << '\"';}
void __print(bool x) {std::cerr << (x ? "true" : "false");}
// 模板，用于打印 pair 和 tuple
template<typename T, typename V>
void __print(const std::pair<T, V> &x) {std::cerr << '{'; __print(x.first); std::cerr << ','; __print(x.second); std::cerr << '}';}
// 模板，用于打印容器 (vector, set, map, etc.)
template<typename T>
void __print(const T &x) {int f = 0; std::cerr << '{'; for (auto &i: x) std::cerr << (f++ ? "," : ""), __print(i); std::cerr << "}";}
// 递归展开可变参数模板
void _print() {std::cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) std::cerr << ", "; _print(v...);}
// 关键的宏定义
#ifdef LOCAL // 这个宏通常在在线评测系统上会自动定义
#define debug(x...) std::cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

int main()
{
    string quest;
    getline(cin, quest);
    int n;
    cin >> n;
    cin.ignore();
    string buffer;
    vector<vs> flag(n);

    // 讀入輸入
    for (int i = 0; i < n; i++)
    {
        getline(cin, buffer);
        stringstream ss(buffer);
        string item;
        while (getline(ss, item, ','))
        {
            // cerr << item << '-' ;
            if (item[0] == ' ')
                item.erase(0, 1);
            flag[i].push_back(item);
        }
    }

    vector<int> incongruence(n, -1);
    int m = flag[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int count = 0;
            for (int k = 0; k < m; k++)
            {
                count += (flag[i][k] != flag[j][k] ? 1 : 0);
            }

            incongruence[i] = max(incongruence[i], count);
        }
        debug(incongruence);

    }

    queue<int> minInd;
    int minCount = INF;
    for (int i = 0; i < n; i++)
    {
        if(incongruence[i] < minCount) {
            while(!minInd.empty())
                minInd.pop();
            minInd.push(i);
            minCount = incongruence[i];
        } else if (incongruence[i] == minCount) {
            minInd.push(i);
        }
    }

    while (!minInd.empty())
    {
        int index = minInd.front();
        minInd.pop();
        for (auto ii = flag[index].begin(); ii != flag[index].end(); ii++)
        {
            if (ii != flag[index].begin())
                cout << ", ";
            cout << *ii;
        }
        if (!minInd.empty())
            cout << endl;
    }

    return 0;
}