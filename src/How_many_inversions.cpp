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

ll merge_and_count(vi &seq, vi &tmp, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;

    ll inv_count = 0;
    while (i <= mid && j <= right)
    {
        if (seq[i] <= seq[j])
            tmp[k++] = seq[i++];
        else if (seq[i] > seq[j])
        {
            tmp[k++] = seq[j++];
            inv_count += mid - i + 1;
        }
    }
    while (i <= mid)
        tmp[k++] = seq[i++];
    while (j <= right)
        tmp[k++] = seq[j++];

    for (int i = left; i <= right; i++)
        seq[i] = tmp[i];
    return inv_count;
}
ll mergesort(vi &seq, vi &tmp, int left, int right)
{
    ll inv_count = 0;
    int mid = left + (right - left) / 2;

    if (left < right)
    {
        inv_count += mergesort(seq, tmp, left, mid);
        inv_count += mergesort(seq, tmp, mid + 1, right);
        inv_count += merge_and_count(seq, tmp, left, mid, right);
    }
    // debug(mergesort);
    return inv_count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n, n)
    {
        vi seq(n);
        for (auto &e : seq)
            cin >> e;
        vi tmp(n);
        debug(seq);
        cout << mergesort(seq, tmp, 0, n - 1) << endl;
    }

    return 0;
}