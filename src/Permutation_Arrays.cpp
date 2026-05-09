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

const int INF = (int)1e9;
const int LLINF = (int)4e18;
const double EPS = 1e-9;

void __print(int x) { std::cerr << x; }
void __print(long long x) { std::cerr << x; }
void __print(double x) { std::cerr << x; }
void __print(char x) { std::cerr << '\'' << x << '\''; }
void __print(const char *x) { std::cerr << '\"' << x << '\"'; }
void __print(const std::string &x) { std::cerr << '\"' << x << '\"'; }
void __print(bool x) { std::cerr << (x ? "true" : "false"); }

template <typename T, typename V> void __print(const std::pair<T, V> &x) { std::cerr << '{'; __print(x.first); std::cerr << ','; __print(x.second); std::cerr << '}'; }
template <typename T> void __print(const T &x) { int f = 0; std::cerr << '{'; for (auto &i : x) std::cerr << (f++ ? "," : ""), __print(i); std::cerr << "}"; }
void _print() { std::cerr << "]\n"; }
template <typename T, typename... V> void _print(T t, V... v) { __print(t); if (sizeof...(v)) std::cerr << ", "; _print(v...); }

#ifdef LOCAL
#define debug(x...)                    \
    std::cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

void solve() {
    int TC;
    cin >> TC;
    cin.ignore();
    rep(tc, 0, TC) {
        cin.ignore();
        if(tc) cout << endl;

        vi orders;
        
        string line;
        getline(cin, line);
        stringstream ss(line);

        int i;
        while(ss >> i) {
            orders.push_back(i);
        }

        vs lst(sz(orders));
        getline(cin, line);
        stringstream st(line);
        
        string floatNum;
        for(int i = 0; i < sz(orders); i++) {
            st >> floatNum;
            lst[orders[i]-1] = floatNum;
        }

        for(auto s : lst) {
            cout << s << endl;
        }
        

    }

    return;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();

    return 0;
}