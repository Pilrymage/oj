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

ll merge_and_count(vi &a, vi &temp, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = left;
    debug(left, mid, right);
    ll inv_count = 0;
    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j]) 
        {
            temp[k++] = a[i++];
        }
        else if (a[i] > a[j])
        {
            temp[k++] = a[j++];
            inv_count += mid - i + 1;
        }
    }
    while (i <= mid) // 要么是前半部分还有剩余，直接加到队尾
    {
        temp[k++] = a[i++];
    }
    while (j <= right) // 要么是后半部分
    {
        temp[k++] = a[j++];
    }
    // a = temp;
    for(int i = left; i <= right; i++) {
        a[i] = temp[i];
    }
    return inv_count;
}

ll mergesort(vi &a, vi &temp, int left, int right)
{
    ll inv_count = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        debug(left, right, mid);
        inv_count += mergesort(a, temp, left, mid);
        inv_count += mergesort(a, temp, mid + 1, right);
        inv_count += merge_and_count(a, temp, left, mid, right);
    }
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
        for (int &e : seq)
        {
            cin >> e;
        }
        debug(seq);
        vi tmp(n);
        cout << (mergesort(seq, tmp, 0, seq.size() - 1) % 2 == 0 ? "Carlos" : "Marcelo") << endl;
        debug(seq);
    }
    return 0;
}