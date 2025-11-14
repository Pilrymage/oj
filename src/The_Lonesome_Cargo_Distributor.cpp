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

    int SET;
    cin >> SET;
    for (int tc = 0; tc < SET; tc++)
    {
        int n, s, q;
        cin >> n >> s >> q;
        debug(n, s, q);
        vector<queue<int>> station(n);

        int total_cargo = 0;

        for (int i = 0; i < n; i++)
        {
            int count;
            cin >> count;
            assert(count <= q);
            total_cargo += count;
            int temp = 0;
            for (int j = 0; j < count; j++)
            {
                cin >> temp;
                debug(temp);
                station[i].push(temp);
            }
        }

        int time = 0;
        stack<int> carrier;
        int curr = 0;

        while (true)
        {
            // unloading
            // <= is necessary, for carrier.top() == curr + 1 is still needed to be checked
            while (!carrier.empty() && station[curr].size() <= q)
            {
                // not target country
                assert (station[curr].size() <= q);
                if (carrier.top() == (curr + 1))
                {
                    total_cargo -= 1;
                }
                else
                {
                    if (station[curr].size() == q)
                        break;
                    station[curr].push(carrier.top());
                }
                assert (station[curr].size() <= q);
                carrier.pop();
                time += 1;
            }

            debug(total_cargo);

            // loading
            while (!station[curr].empty() && carrier.size() < s)
            {
                carrier.push(station[curr].front());
                station[curr].pop();
                time += 1; // one cargo
            }
            if (total_cargo == 0)
            {
                cout << time << endl;
                break;
            }
            else
            {
                curr += 1;
                curr %= n;
                time += 2;
            }
        }
    }

    return 0;
}