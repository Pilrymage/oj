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

enum degree
{
    D_90,
    D_180,
    D_270
};

bool equal_mat(vs a, vs b)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

vs rotate_mat(vs a, degree deg)
{
    int n = a.size();
    vs new_mat(n, "");
    switch (deg)
    {
    case D_90:
        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                new_mat[i] += a[j][i];
            }
        }
        return new_mat;
        break;
    case D_180:
        return rotate_mat(rotate_mat(a, D_90), D_90);
        break;
    case D_270:
        return rotate_mat(rotate_mat(a, D_180), D_90);
        break;
    }
}

vs vref_mat(vs a)
{
    int n = a.size();
    vs new_mat(n);
    for (int i = 0; i < n; i++)
    {
        new_mat[n - 1 - i] = a[i];
    }
    return new_mat;
}

int main()
{
    int n, tc = 1;
    while (cin >> n)
    {
        vs mat(n), matrev(n);
        // 输入
        for (int i = 0; i < n; i++)
        {
            // 一行
            cin >> mat[i] >> matrev[i];
        }

        string output = "";
        if (equal_mat(matrev, mat))
            output = "preserved.";
        else if (equal_mat(matrev, rotate_mat(mat, D_90)))
            output = "rotated 90 degrees.";
        else if (equal_mat(matrev, rotate_mat(mat, D_180)))
            output = "rotated 180 degrees.";
        else if (equal_mat(matrev, rotate_mat(mat, D_270)))
            output = "rotated 270 degrees.";
        else if (equal_mat(matrev, vref_mat(mat)))
            output = "reflected vertically.";
        else if (equal_mat(matrev, rotate_mat(vref_mat(mat), D_90)))
            output = "reflected vertically and rotated 90 degrees.";
        else if (equal_mat(matrev, rotate_mat(vref_mat(mat), D_180)))
            output = "reflected vertically and rotated 180 degrees.";
        else if (equal_mat(matrev, rotate_mat(vref_mat(mat), D_270)))
            output = "reflected vertically and rotated 270 degrees.";
        else
            output = "improperly transformed.";

        // 输出
        cout << "Pattern " << tc++ << " was " << output << endl;
    }
    return 0;
}