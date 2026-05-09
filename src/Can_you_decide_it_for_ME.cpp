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
    int N; cin >> N; while(N--) {
        string line; cin >> line; int len = sz(line);
        bool isTheorem = true;
        int Mp = -1, Ep = -1;
        int x=0, y=0, z=0;
        rep(i,0,len) {
            if(line[i] == 'M') Mp = i;
            else if(line[i] == 'E') Ep = i;
            else if(line[i] != '?') isTheorem = false;
        }
        if (Mp == -1 || Ep == -1) isTheorem = false;
        x = Mp; y = Ep - Mp - 1; z = len - Ep - 1;
        assert (x + y + z + 2 == len);
        debug(x,y,z,Mp,Ep);
        if(y + x != z) isTheorem = false;
        if(x < 1 || y < 1 || z < 2) isTheorem = false;
        isTheorem? cout << "theorem" << endl : cout << "no-theorem" << endl;
    }
    return;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(0);
    solve();

    return 0;
}