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

enum Class
{
    LOWER = 1,
    MIDDLE,
    UPPER
};

void __print(Class x) { std::cerr << (x == LOWER ? "LOWER" : x == MIDDLE ? "MIDDLE"
                                                                         : "UPPER"); }

struct Person
{
    string name;
    vector<Class> tokens;
};

void __print(Person x)
{
    debug(x.name);
    debug(x.tokens);

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    for (int tc = 0; tc < TC; tc++)
    {
        int n;
        cin >> n;
        cin.ignore();
        vector<Person> persons(n);
        string line;
        for (int i = 0; i < n; i++)
        {
            getline(cin, line);
            stringstream ss(line);
            string name;
            getline(ss, name, ':');

            ss >> ws; // 特殊的，清理所有空白字符的輸入
            string description;
            getline(ss, description);
            stringstream desc_ss(description);
            string token_name;
            vector<Class> tokens(0);
            while (getline(desc_ss, token_name, '-'))
            {
                // debug(token_name);
                switch (token_name[0])
                {
                case 'l':
                    tokens.push_back(LOWER);
                    break;
                case 'm':
                    tokens.push_back(MIDDLE);
                    break;
                case 'u':
                    tokens.push_back(UPPER);
                    break;
                }
            }
            // debug(tokens);
            persons[i] = {name, tokens};
        }
        debug(persons);
        sort(persons.begin(), persons.end(), [](auto &pa, auto &pb)
             {

                auto ia = pa.tokens.rbegin();
                auto ib = pb.tokens.rbegin();
            while (true)
            {
                if (ia == pa.tokens.rend() && ib == pb.tokens.rend())
                {
                    return pa.name < pb.name;
                }
                else if (ia == pa.tokens.rend())
                {
                    Class b = *ib;
                    if (b == UPPER)
                        return false;
                    else if (b == LOWER)
                        return true;
                    ib++;
                }
                else if (ib == pb.tokens.rend())
                {
                    Class a = *ia;
                    if (a == UPPER)
                        return true;
                    else if (a == LOWER)
                        return false;
                    ia++;
                }
                else
                {
                    Class a = *ia;
                    Class b = *ib;
                    if(pa.name=="unclebob" || pb.name=="unclebob"){
                        debug(pa.name, pb.name, a, b);
                    }
                    if (a != b)
                        return a > b;
                    ia++;
                    ib++;
                }
            } });
        for (int i = 0; i < n; i++)
        {
            cout << persons[i].name << endl;
        }
        cout << "==============================" << endl;
    }

    return 0;
}