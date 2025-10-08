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

void __print(int x) { std::cerr << x; }
void __print(long long x) { std::cerr << x; }
void __print(double x) { std::cerr << x; }
void __print(char x) { std::cerr << '\'' << x << '\''; }
void __print(const char *x) { std::cerr << '\"' << x << '\"'; }
void __print(const std::string &x) { std::cerr << '\"' << x << '\"'; }
void __print(bool x) { std::cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const std::pair<T, V> &x)
{
    std::cerr << '{';
    __print(x.first);
    std::cerr << ',';
    __print(x.second);
    std::cerr << '}';
}

template <typename T>
void __print(const T &x)
{
    int f = 0;
    std::cerr << '{';
    for (auto &i : x)
        std::cerr << (f++ ? "," : ""), __print(i);
    std::cerr << "}";
}

void _print() { std::cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        std::cerr << ", ";
    _print(v...);
}

#ifdef LOCAL
#define debug(x...)                    \
    std::cerr << "[" << #x << "] = ["; \
    _print(x)
#else
// string s = "hello";
// int a = 10, b = 20;
// vi v = {1,2,3,4,5};
// debug(s, a, b, v);
// for (int i = 0; i < 3; i++) {
//     int result = i * 10;
//     debug(i, result);
// }
// assert(index >= 0 && index < v.size());
#define debug(x...)
#endif

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while (cin >> n, n)
    {
        vs name(n);
        for (int i = 0; i < n; i++)
        {
            cin >> name[i];
        }

        sort(name.begin(), name.end(), [](string a, string b)
             { return a < b; });
        string prefix;
        string m1 = name[n / 2 - 1], m2 = name[n / 2];
        string result = "";
        // 核心逻辑：尝试构造所有可能的候选字符串 S
        // i 代表我们尝试在 m1 的哪一位上进行修改，以构造 S
        // S 的长度将是 i + 1
        for (int i = 0; i < m1.length(); i++)
        {
            if (i < m1.length() - 1 && m1[i] == 'Z')
            {
                continue;
            }
            // 截取字符串：前綴本身與前綴+1都有可能成爲答案
            // 
            string candidate_R = m1.substr(0, i + 1);
            string candidate_S = m1.substr(0, i);
            
            // 雖然udebug沒有這個邊界情況，但是也把以Z結尾的字符串加1給求出來
            if (m1[i] == 'Z')
            {
                candidate_S += "ZA";
            }
            else
            {
                candidate_S += m1[i] + 1;
            }

            // 從更小的開始嘗試
            if (candidate_R >= m1 && candidate_R < m2)
            {
                result = candidate_R;
                break;
            }
            if (candidate_S >= m1 && candidate_S < m2)
            {
                result = candidate_S;
                break;
            }
        }

        // 输出最终找到的分割字符串
        cout << result << endl;
    }

    return 0;
}