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
    int K; while(cin >> K) {
        vector<vi> arrays(K, vi(K, 0));
        for(auto &v : arrays) {
            for(auto &e : v) {
                cin >> e;
            }
            sort(all(v));
        }
        std::priority_queue<int> reducedSums;
        for(int i = 0; i < K-1; i++) {
            auto& v1 = arrays[i];
            auto& v2 = arrays[i+1];
            for(int j = 0; j < K; j++){
                for(int k = 0; k < K; k++) {
                    int sum = v1[j]+v2[k];
                    if(sz(reducedSums) < K ) {
                        reducedSums.push(sum);
                    } else if (sum < reducedSums.top()){
                        reducedSums.push(sum);
                        reducedSums.pop();
                    } else {
                        break;
                    }
                }
            }

            assert(sz(reducedSums) == K);
            v2 = vi();
            while(!reducedSums.empty()) {
                v2.push_back(reducedSums.top()); reducedSums.pop();
            }
            reverse(all(v2));
        }
        int g = 0;
        for(auto& e: arrays[K-1]) {
            if(g++) cout << " ";
            cout << e;
        }
        cout << endl;
    }

    return;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(0);
    // cin.exceptions(cin.failbit);
    solve();

    return 0;
}