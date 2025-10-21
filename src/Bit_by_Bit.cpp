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

char And(char a, char b) {
    switch(a) {
        case '0':
            return '0';
        case '1':
            return b == '?' ? '?' : (b == '0' ? '0' : '1' );
        case '?':
            return b == '0' ? '0' : '?';
    }
}


char Or(char a, char b) {
    switch(a) {
        case '1':
        return '1';
        case '0':
        return b == '?' ? '?' : (b == '1' ? '1' : '0');
        case '?':
        return b == '1' ? '1' : '?';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    assert (And('1', '0') == And('0', '1'));
    assert (And('1', '?') == And('?', '1'));
    assert (And('?', '0') == And('0', '?'));
    int n;
    while (cin >> n >> ws, n)
    {
        string reg(32, '?') ;
        string line;
        while(n--) {
            getline(cin, line);
            stringstream ss(line);
            string op;
            ss >> op;
            
            int dst, src;
            switch(op[0]) {
                case 'C': 
                    ss >> dst;
                    reg[dst] = '0';
                    break;
                case 'S':
                    ss >> dst;
                    reg[dst] = '1';
                    break;
                case 'O':
                    ss >> dst >> src;
                    reg[dst] = Or(reg[src], reg[dst]); 
                    break;
                case 'A': 
                    ss >> dst >> src;
                    reg[dst] = And(reg[src], reg[dst]); 
                    break;
                default: debug("wrong");
            }
        }
        reverse(reg.begin(), reg.end());
        cout << reg << endl;
    }


    return 0;
}