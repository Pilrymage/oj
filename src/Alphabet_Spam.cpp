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
    string line; cin >> line;
    int len = sz(line);
    vi dat(128,0);
    for(char c : line) { dat[c]++; }
    vi counts(4,0);
    rep(i,33,127) { 
        if(i == '_') {
            counts[0] += dat[i];
        } else if (islower(i)) {
            counts[1] += dat[i];
        } else if (isupper(i)) {
            counts[2] += dat[i];
        } else {
            counts[3] += dat[i];
        }
     }
    for(int i : counts) {
        cout << setprecision(15) << double(i) / len << endl;
    }
    return;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(0);
    solve();

    return 0;
}