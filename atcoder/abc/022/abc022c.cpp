#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

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
const int mod = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  cin >> n >> m;

  ll edge[n][n];
  REP(i, n){
    REP(j, n){
      if(i == j)
        edge[i][j] = edge[j][i] = 0;
      else
        edge[i][j] = edge[j][i] = inf;
    }
  }

  ll u, v, l;
  REP(i, m){
    cin >> u >> v >> l;
    u--;
    v--;
    edge[u][v] = edge[v][u] = l;
  }

  //except vertex1 and its edge
  FOR(k, 1, n){
    FOR(i, 1, n){
      FOR(j, 1, n){
        edge[i][j] = min(edge[i][j], edge[i][k]+edge[k][j]);
      }
    }
  }

  ll ans = inf;
  FOR(i, 1, n){
    FOR(j, 1, n){
      if(edge[0][i]==inf || edge[j][0]==inf || edge[i][j]==inf || edge[i][j]==0)
        continue;
      else
        ans = min(ans, edge[0][i] + edge[i][j] + edge[j][0]);
    }
  }
  
  if(ans == inf)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
