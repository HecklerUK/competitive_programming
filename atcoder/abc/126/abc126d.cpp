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
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
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
struct edge{
  ll to, cost;
};

ll d[MAX_N];
vector<edge> vertex[MAX_N];
ll n;

bool bfs(ll s, ll count){
  priority_queue<pll, vector<pll>, greater<pll>> que;
  que.push(pll(0, s));

  REP(i, n)
    d[i] = LLINF;
  d[s] = 0;

  while(!que.empty()){
    pll p = que.top();
    que.pop();

    ll dist = p.FI;
    ll v = p.SE;
    if(d[v] < dist)
      continue;

    for(ll i = 0; i < vertex[v].size(); i++){
      edge e = vertex[v][i];
      if(d[e.to] > dist+e.cost){
        d[e.to] = dist + e.cost;
        que.push(pll(d[e.to], e.to));
      }
    }
  }



}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  ll u, v, w;
  REP(i, n-1){
    cin >> u >> v >> w;
    u--;
    v--;
    vertex[u].push_back({v, w});
    vertex[v].push_back({u, w});
  }

  ll s = 0;
  bfs(s, 0);
  REP(i, n){
    cout << d[i]%2 << endl;
  }

}
