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

void printMat(vs &m)
{
    for (auto &s : m)
        cout << s << endl;
    cout << endl;
}

void solve(int n, int m)
{
    // 輸入
    vs BMat(n), SMat(m);
    for (int i = 0; i < n; i++)
        cin >> BMat[i];
    for (int i = 0; i < m; i++)
        cin >> SMat[i];
    // printMat(BMat);
    // printMat(SMat);
    vs NMat;
    for (auto ii = SMat.begin(); ii != SMat.end(); ii++)
    {
        if ((*ii).find('*') != string::npos)
            NMat.push_back(*ii);
    }
    SMat = NMat;
    int h = NMat.size();
    NMat = vs(h);
    for (int j = 0; j < m; j++)
    {
        bool isDotCol = true;
        for (auto &s : SMat)
        {
            if (s[j] != '.')
            {
                isDotCol = false;
                break;
            }
        }
        if (!isDotCol)
        {
            for (int i = 0; i < h; i++)
            {
                NMat[i] += SMat[i][j];
            }
        }
    }
    SMat = NMat;
    int l = NMat[0].size();
    // cerr << '(' << NMat.size() << ' ' << NMat[0].size() << ')';
    // printMat(NMat);
    int pairedCount = 0;
    for (int i = 0; i < n - h + 1; i++)
    {
        for (int j = 0; j < n - l + 1; j++)
        {
            // 比較兩個矩陣：只要小矩陣的每一個星號都能在大矩陣裏找到，就可以接受
            bool isMatch = true;
            for (int k = 0; k < h; k++)
            {
                for (int p = 0; p < l; p++)
                {
                    if (SMat[k][p] == '*' && BMat[k + i][p + j] != '*')
                        isMatch = false;
                }
            }
            if (isMatch)
            {
                pairedCount++;
                for (int k = 0; k < h; k++)
                {
                    for (int p = 0; p < l; p++)
                    {
                        if (SMat[k][p] == '*' && BMat[k + i][p + j] == '*')
                            BMat[k+i][p+j] = '.';
                    }
                }
            }
        }
    }
    if (pairedCount == 2)
        cout << 1 << endl;
    else cout << 0 << endl;
    return;
}
int main()
{
    int n, m;
    while (cin >> n >> m, n && m)
    {
        solve(n, m);
    }
    return 0;
}