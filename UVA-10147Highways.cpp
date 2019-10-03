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
const double eps = 1e-9;

struct edge {
    int f, t;
    double w;
    edge(int f, int t, double w) : f(f), t(t), w(w) {}
};

bool cmp(edge a, edge b) {
    return a.w < b.w;
}


int n, m, x, y;
vector<vector<pair<int,double>>> g;
PI p[1000];

int parent[N];

void UnionFind(int n) {
    for(int i = 1; i <= n; i++)
        parent[i] = i;
}

int find_set(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find_set(parent[u]);
}

bool union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if(u != v) 
        parent[u] = v;
    return u != v;
}

double dist(int xa, int ya, int xb, int yb) {
    return sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
}


int main() {
    io;
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        g.clear();
        g.resize(n+1);
        for(int i = 1; i <= n; i++)
            cin >> p[i].F >> p[i].S;
        for(int i = 1; i < n; i++) {
            for(int j = i + 1; j <= n; j++) {
                double d = dist(p[i].F, p[i].S, p[j].F, p[j].S);
                g[i].PB({j,d});
            }
        }
        UnionFind(n);
        cin >> m;
        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            x = find_set(x);
            y = find_set(y);
            if(x != y) parent[x] = y;
        }
        vector<edge> v;
        for(int i = 1; i <= n; i++) {
            for(auto u : g[i]) {
                edge e(i, u.F, u.S);
                v.PB(e);
            }
        }
        sort(ALL(v), cmp);
        vector<edge> ans;
        for(edge e : v) {
            if(union_set(e.f, e.t)) 
                ans.PB(e);
        }
        for(int i = 0; i < SZ(ans); i++)
                cout << ans[i].f << " " << ans[i].t << (i == SZ(ans) ? "" : "\n");
        if(ans.empty())
            cout << "No new highways need\n";
        cout << (!t ? "" : "\n");
    }
    return 0;
}
