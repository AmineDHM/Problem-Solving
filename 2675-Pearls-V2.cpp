#include <bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PI;
int dx[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, 1, -1 };
const int oo = 2e9 + 5;
const int N = 1e6 + 5;
const LL MOD = 1e9 + 7;

int t, n, a[N], p[N], dp[1005];

int solve(int curr) {
    if(curr == n) return 0;
    int &ret = dp[curr];
    if(ret != -1) return ret;
    int sum = 0;
    ret = oo;
    for(int i = curr; i < n; i++) {
        sum += a[i];
        ret = min(ret, solve(i + 1) + (sum + 10) * p[i]);
    }
    return ret;
}

int main() {
    io
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i] >> p[i];
        memset(dp, -1, sizeof dp);
        cout << solve(0) << "\n";
    }
    return 0;
}
