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
    int TC; cin >> TC; while(TC--) {
        int n; cin >> n; 
        string _, order_type;
        int x, y;
        std::priority_queue<pii> buys;        
        std::priority_queue<pii,vii,greater<pii>> sells;        
        int buyPrice=-1, sellPrice=-1, stockPrice=-1;
        rep(i,0,n) {
            cin >> order_type >> x >> _ >> _ >> y;
            order_type == "buy" ? buys.push({y, x}) : sells.push({y, x});
            while(!buys.empty() && !sells.empty()) {
                auto [askPrice, askCount] = buys.top();
                auto [bidPrice, bidCount] = sells.top();
                if(askPrice >= bidPrice) {
                    stockPrice = bidPrice;
                    int purchasedCount = min(askCount, bidCount);
                    buys.pop();  sells.pop();
                    int leftBuyCount = askCount - purchasedCount;
                    int leftSellCount = bidCount - purchasedCount;
                    debug(leftBuyCount, leftSellCount);
                    if(leftBuyCount > 0)
                        buys.push({askPrice, leftBuyCount});
                    if(leftSellCount > 0)
                        sells.push({bidPrice, leftSellCount});
                } else break;
            }
            if(!buys.empty()) buyPrice = buys.top().first;
            else buyPrice = -1;
            if(!sells.empty()) sellPrice = sells.top().first;
            else sellPrice = -1;
            (sellPrice == -1 ? cout << "-" : cout << sellPrice) << " ";
            (buyPrice == -1 ? cout << "-" : cout << buyPrice) << " ";
            (stockPrice == -1 ? cout << "-" : cout << stockPrice) << endl;
        }
    }
    return;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(0);
    solve();

    return 0;
}