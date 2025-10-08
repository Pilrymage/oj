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

struct Contestant
{
    bool is_submitted = false;
    int number = 0;
    int count = 0;
    int time = 0;
    set<int> solved;
};

void __print(Contestant x) { std::cerr << (x.is_submitted ? "true" : "false") << ' '
                                       << x.number << ' ' << x.count << ' ' << x.time << endl; }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    cin >> TC;
    cin.ignore();
    cin.ignore();
    for (int tc = 0; tc < TC; tc++)
    {
        string buffer;
        vector<Contestant> contestants(101);
        vector<vi> all_time(101, vi(10, 0)); // 所有的惩罚时间

        while (getline(cin, buffer), buffer.length() > 1)
        {
            stringstream ss(buffer);
            int contest_number;
            int problem;
            int time;
            char status;
            ss >> contest_number >> problem >> time >> status;

            contestants[contest_number].is_submitted = true;
            contestants[contest_number].number = contest_number;
            switch (status)
            {
            case 'C':
                if (contestants[contest_number].solved.count(problem))
                    continue;
                contestants[contest_number].count++;
                contestants[contest_number].time += time + all_time[contest_number][problem];
                if (contest_number == 82)
                {
                    debug(all_time[contest_number]);
                }
                contestants[contest_number].solved.insert(problem);
                break;
            case 'I':
                all_time[contest_number][problem] += 20;
                debug(all_time[contest_number]);
                break;
            case 'R':
                break;
            case 'U':
                break;
            case 'E':
                break;
            }
        }
        sort(contestants.begin() + 1, contestants.end(), [](Contestant &a, Contestant &b)
             {
                   if (a.count != b.count)
                       return a.count > b.count;
                   else if(a.time != b.time)
                       return a.time < b.time;
                    else return a.number < b.number; });
        debug(contestants);
        for (int i = 1; i < 101; i++)
        {
            if (!contestants[i].is_submitted)
                continue;
            cout << contestants[i].number << ' '
                 << contestants[i].count << ' '
                 << (contestants[i].count > 0 ? contestants[i].time : 0) << endl;
        }
        if (tc < TC - 1)
            cout << endl;
    }
    return 0;
}