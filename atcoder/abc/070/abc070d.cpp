#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;

// macros
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define FI first
#define SE second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define REP1(i,n) for(int i=1;i<((int)n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define PB push_back
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(dist(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
#define MAX_N 100010

struct edge {
  ll to, cost;
};

vector<edge> vertexEdge[MAX_N];
ll dist[MAX_N];
ll n;

void dijkstra(ll s){
  priority_queue<pll, vector<pll>, greater<pll>> que;
  fill(dist, dist+n, LLINF);
  dist[s] = 0;
  que.push(pll(0, s));
  while(!que.empty()){
    pll p = que.top();
    que.pop();
    ll v = p.SE;
    if(dist[v] < p.FI)
      continue;
    for(int i = 0; i < vertexEdge[v].size(); i++){
      edge e = vertexEdge[v][i];
      if(dist[e.to] > dist[v] + e.cost){
        dist[e.to] = dist[v] + e.cost;
        que.push(pll(dist[e.to], e.to));
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  ll a,b,c;
  REP(i, n-1){
    cin >> a >> b >> c;
    a--;
    b--;
    vertexEdge[a].push_back({b,c});
    vertexEdge[b].push_back({a,c});
  }

  ll q,k;
  cin >> q >> k;
  k--;
  vll x(q), y(q);
  REP(i, q){
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }

  dijkstra(k);


  REP(i, q){
    ll a = x[i];
    ll b = y[i];
    cout << dist[a]+dist[b] << endl;
  }

}
