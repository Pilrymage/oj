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
    while(cin >> n) {
        int ALL_CORNER = 1 << n;
        // debug(n, ALL_CORNER);
        vi weight(ALL_CORNER);
        for(int i = 0; i < ALL_CORNER; i++) 
            cin >> weight[i];
        vi potent(ALL_CORNER);
        for(int node = 0; node < ALL_CORNER; node++) {
            for(int mask = 0b1; mask < 1 << n; mask <<= 1) {
                // debug(mask);
                int neighbor = node ^ mask;
                potent[node] += weight[neighbor];
                // debug(neighbor, weight[neighbor]);
            }
        }

        int maxsum = 0;
        for(int node = 0; node < ALL_CORNER; node++) {
            for(int mask = 0b1; mask < 1 << n; mask <<= 1) {
                int neighbor = node ^ mask;
                int sum = potent[node] + potent[neighbor];
                maxsum = max(sum, maxsum);
            }
        }
        cout << maxsum << endl;
        debug(potent);
    }
    return 0;
}