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
    enum hand {
        LEFT,
        RIGHT
    };
    string line;
    while(cin >> line) {
        cout << line << ": ";
        int ballCount = 0;
        line += line + line;
        std::priority_queue<pair<int,hand>> times;
        int t = 0;
        for( char &c : line) {
            ballCount += c - '0'; t++;
            hand currentHand = (t%2==1)?LEFT:RIGHT;
            if((c - '0')%2==1)
                switch (currentHand) {
                    case LEFT: currentHand=RIGHT; break;
                    case RIGHT: currentHand=LEFT; break;
                }

            times.push({t + c - '0', currentHand});
        }
        if (ballCount % sz(line) != 0) {
            cout << "invalid # of balls" << endl;
            continue;
        }
        ballCount /= sz(line);
        bool isValid = true;
        pair<int, hand> prevTime;
        while(!times.empty()) {
            cerr << "["<< times.top().first << ' ' << times.top().second <<"] ";
            if (times.top() == prevTime) {
                isValid = false;
                break;
            }
            prevTime = times.top(); times.pop(); 
        }
        cerr << endl;
        isValid 
        ? cout << "valid with "  << ballCount << " balls" << endl
        : cout << "invalid pattern" << endl;
    }
    return;
}

int main()
{
    cin.tie(NULL)->sync_with_stdio(0);
    solve();

    return 0;
}