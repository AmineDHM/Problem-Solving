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

struct edge {
    int f, t, w;
};

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

int p[111];
int t, n, m, x, y, w;

void unionfind() {
    for(int i = 1; i <= n; i++)
        p[i] = i;
}

int find_set(int u) {
    if(p[u] == u) return u;
    return p[u] = find_set(p[u]);
}

bool compare(edge a, edge b) {
    return (a.f == b.f && a.t == b.t && a.w == b.w);
}

int main() {
    io;
    cin >> t;
    while(t--) {
        vector<edge> v, g;
        cin >> n >> m;
        for(int i = 1; i <= m; i++) {
            cin >> x >> y >> w;
            edge e;
            e.f = x;
            e.t = y;
            e.w = w;
            v.PB(e);
        }
        sort(ALL(v), cmp);
        int ans1 = 0;
        unionfind();
        for(int i = 0; i < SZ(v); i++) {
            int x = find_set(v[i].f);
            int y = find_set(v[i].t);
            if(x != y) {
                p[x] = y;
                g.PB(v[i]);
                ans1 += v[i].w;
            }
        }
        int ans2 = oo;
        sort(ALL(g), cmp);
        for(int i = 0; i < SZ(g); i++) {
            unionfind();
            int cnt = 0, cost = 0;
            for(int j = 0; j < SZ(v); j++) {
                if(compare(v[j], g[i])) continue;
                int x = find_set(v[j].f);
                int y = find_set(v[j].t);
                if(x != y) {
                    p[x] = y;
                    cnt++;
                    cost += v[j].w;
                }
            }
            if(cost >= ans1) ans2 = min(ans2, cost);
        }
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
