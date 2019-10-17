#include <bits/stdc++.h>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ALL(x) x.begin(),x.end()
#define SZ(x) x.size()
#define PB push_back
#define MP make_pair
#define F first
#define S second
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PI;
int dx[] = { -1, 1, 0, 0, -1, 1, -1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, 1, -1 };
const int oo = 2e9;
const int N = 1e6;

string a, b;
int dp[102][102];

int solve(int i, int j) {
    if(i == SZ(a) || j == SZ(b)) return 0;
    int &ret = dp[i][j];
    if(ret != -1) return ret;
    ret = 0;
    if(a[i] == b[j]) 
        ret = max(ret, 1 + solve(i + 1, j + 1));
    ret = max(ret, solve(i + 1, j));
    ret = max(ret, solve(i, j + 1));
    return ret;
}

int main() {
    io;
    for(int i = 1;;i++){
        getline(cin, a);
        if(a == "#") return 0;
        getline(cin, b);
        memset(dp, -1, sizeof dp);
        cout << "Case #" << i << ": you can visit at most " << solve(0,0) << " cities.\n";
    }
    return 0;
}
