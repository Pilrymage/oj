#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const int LLINF = 4e18;
const double EPS = 1e-9;

int n = 0;

int transpose(vector<vi> &m)
{
    vector<vi> new_mat(n, vi(n,-1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            new_mat[j][i] = m[i][j];
    m = new_mat;
    return 0;
}

int row(vector<vi> &m, int a, int b)
{
    vi tmp = m[a - 1];
    m[a - 1] = m[b - 1];
    m[b - 1] = tmp;
    return 0;
}

int col(vector<vi> &m, int a, int b)
{
    transpose(m);
    row(m, a, b);
    transpose(m);
    return 0;
}

void inc(vector<vi> &m)
{
    for (auto &v : m)
        for (auto &e : v)
        {
            e += 1;
            if (e >= 10)
                e = 0;
        }
    return;
}

void dec(vector<vi> &m)
{
    for (auto &v : m)
        for (auto &e : v)
        {
            e -= 1;
            if (e < 0)
                e = 9;
        }
    return;
}

int main()
{
    int tc;
    cin >> tc;
    for (int TC = 1; TC <= tc; TC++)
    {
        cin >> n;
        cin.ignore();
        //cerr << n;
        vector<vi> mat(n, vi(n));
        for (auto &v : mat)
        {
            string buffer;
            getline(cin, buffer);
            //cerr << '(' << buffer << ')' << endl;
            for (int i = 0; i < n; i++)
            {
                v[i] = buffer[i] - '0';
            }
        }
        int m = 0;
        cin >> m;
        cin.ignore();
        string op = "";
        while (m--)
        {
            //cerr << '(' << m << ')';

            getline(cin, op);
            //cerr << '(' << op << ')' << endl;
            if (op[0] == 'r') // row
            {
                int a = op[4] - '0', b = op[6] - '0';
                //cerr << '[' << a << ' ' << b << ']';
                row(mat, a, b);
            }
            else if (op[0] == 'c') // row
            {
                int a = op[4] - '0', b = op[6] - '0';
                col(mat, a, b);
            }
            else if (op[0] == 'i') // row
            {
                inc(mat);
            }
            else if (op[0] == 'd') // row
            {
                dec(mat);
            }
            else if (op[0] == 't') // row
            {
                transpose(mat);
            }
            else
            {
                //cerr << "Fucked up" << endl;
            }
        }
        cout << "Case #" << TC << endl;
        for (auto &v : mat)
        {
            for (auto &e : v)
                cout << e;
            cout << endl;
        }
        // if(TC<tc) 
        cout << endl;

    }
    return 0;
}