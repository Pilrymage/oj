#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const int LLINF = 4e18;
const double EPS = 1e-9;

int main() {
    int N;
    cin >> N;
    vi height(1000000,0);
    for(int i = 0; i < N; i++){
        cin >> height[i];
    }
    vi arrow(1000000,0);
    int count = 0;
    for(int i = 0; i < N; i++){
        if (arrow[height[i]] == 0) {
            count++;
            if (height[i] > 1) {
                arrow[height[i]-1] += 1;
            }
        } else if (arrow[height[i]] > 0) {
            arrow[height[i]] -= 1;
            if (height[i] > 1) {
                arrow[height[i]-1] += 1;
            }
        }
    }
    cout << count << endl;
    return 0;
}