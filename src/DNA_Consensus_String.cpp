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
enum DNA {
    A = 0, C, G, T
};
void solve() {
    int TC; cin >> TC; while(TC--) {
        int dnaCount, dnaLen; cin >> dnaCount >> dnaLen;
        vector<vi> dnaApperance(dnaLen,vi(4,0));
        string line;
        rep(i,0,dnaCount) {
            cin >> line;
            for(int j = 0; j < dnaLen; j++) {
                switch (line[j]) {
                    case 'A': dnaApperance[j][A]++; break;
                    case 'C': dnaApperance[j][C]++; break;
                    case 'G': dnaApperance[j][G]++; break;
                    case 'T': dnaApperance[j][T]++; break;
                }
            }
        }
        int errorTotal = 0;
        for(auto p : dnaApperance) {
            int maxCount = 0;            
            int maxIndex = -1;
            rep(i, 0, 4) {
                if(p[i]> maxCount) {
                    maxIndex = i;
                    maxCount = p[i];
                }
            }
            errorTotal += dnaCount - maxCount;
            switch (maxIndex) {
                case A: cout << 'A'; break;
                case C: cout << 'C'; break;
                case G: cout << 'G'; break;
                case T: cout << 'T'; break;
            }
        }
        cout << endl << errorTotal << endl;

    }
    return;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(0);
    solve();

    return 0;
}