#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
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

ll _sieve_size;
bitset<(int)1e7+10> bs;
vector<ll> p;
ll upper = 1000000;

void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set(); // 初始化为1
    bs[0] = bs[1] = 0;
    
    for(ll i = 2; i < _sieve_size ; i++) {
        if (bs[i]) {
            for(ll j = i*i ; j < _sieve_size; j+= i)
                bs[j] = 0;
            p.push_back(i);
        }
    }
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    vi primes;
    sieve(upper);
    bs[2] = 0;
    
    ll n;
    while(cin >> n, n) {
        for(ll i : p) {
            ll j = n - i;            
            if (bs[j]) {
                cout << n << " = " << i << " + " << j << endl;
                break;
            }
        }

    }

    return 0;
 }