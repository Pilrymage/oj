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

enum Direction
{
    U = 0,
    D,
    L,
    R
};

void __print(int x) { std::cerr << x; }
void __print(long long x) { std::cerr << x; }
void __print(double x) { std::cerr << x; }
void __print(Direction x) { std::cerr << x; }
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

#ifdef NLOCAL
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

void move(int &x, int &y, Direction dir)
{
    switch (dir)
    {
    case U:
        y--;
        break;
    case D:
        y++;
        break;
    case L:
        x--;
        break;
    case R:
        x++;
        break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, l;
    int tc = 1;
    while (cin >> w >> l, w && l)
    {
        vs mat(l);
        int x, y;
        for (int i = 0; i < l; i++)
        {
            cin >> mat[i];
            if (mat[i].find('*') != string::npos)
            {
                y= i; x = mat[i].find('*');
            }
        }

        Direction dir;
        if (x == 0)
        {
            dir = R;
        }
        else if (x == w - 1)
        {
            dir = L;
        }
        else if (y == 0)
        {
            dir = D;
        }
        else if (y == l - 1)
        {
            dir = U;
        }
        debug(dir);
        do
        {
            debug(x, y, dir);
            move(x, y, dir);
            assert (x >= 0 && x <= w - 1 && y >= 0 && y <= l - 1);
            if (mat[y][x] == 'x')
            {
                mat[y][x] = '&';                
                break;
            }
            else if (mat[y][x] == '/')
            {
                switch (dir)
                {
                case U:
                    dir = R;
                    break;
                case D:
                    dir = L;
                    break;
                case L:
                    dir = D;
                    break;
                case R:
                    dir = U;
                    break;
                }
            }
            else if (mat[y][x] == '\\')
            {
                switch (dir)
                {
                case U:
                    dir = L;
                    break;
                case D:
                    dir = R;
                    break;
                case L:
                    dir = U;
                    break;
                case R:
                    dir = D;
                    break;
                }
            }
        } while (true);

        cout << "HOUSE " << tc++ << endl;
        for (auto &s : mat)
        {
            cout << s << endl;
        }
    }
    return 0;
}