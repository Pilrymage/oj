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
    std::cerr << "}" << endl;
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
// string s = "hello";
// int a = 10, b = 20;
// vi v = {1,2,3,4,5};
// debug(s, a, b, v);
// for (int i = 0; i < 3; i++) {
//     int result = i * 10;
//     debug(i, result);
// }
// assert(index >= 0 && index < v.size());
#define debug(x...)                    \
    std::cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vs mat(n);
    vector<vi> imat(n + 2, vi(m + 2, 0)); // 擴大一圈

    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == '.')
                imat[i + 1][j + 1] = 0;
            else
                imat[i + 1][j + 1] = -1;
        }
    }

    int count = 0;
    while (true)
    {
        bool modified = false;
        vector<vi> nmat(imat);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (imat[i][j] == -1 &&
                    (imat[i - 1][j] == count || imat[i + 1][j] == count || imat[i][j - 1] == count || imat[i][j + 1] == count))
                {
                    nmat[i][j] = count + 1;
                    modified = true;
                }
            }
        }

        debug(nmat);
        if (!modified)
            break;
        imat = nmat;
        count++;
    }

    if (count < 10)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (imat[i][j] == 0)
                    cout << "..";
                else
                    cout << right << setw(2) << setfill('.') << imat[i][j];
            }
            cout << endl;
        }
    }
    else if (count >= 10)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (imat[i][j] == 0)
                    cout << "...";
                else
                    cout << right << setw(3) << setfill('.') << imat[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}