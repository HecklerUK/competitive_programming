#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpll;

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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,u,v;
  cin >> n >> u >> v;
  u--;
  v--;

  vector<vll> g(n);
  REP(i, n-1){
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  bool visited[n];
  REP(i, n)
    visited[i] = false;

  queue<pll> que;
  que.push(pll(v,0));
  visited[v] = true;
  vll dist(n, 0);
  ll cur;
  while(!que.empty()){
    pll now = que.front();
    que.pop();
    for(ll i = 0; i<g[now.FI].size(); i++){
      ll next = g[now.FI][i];
      if(visited[next])
        continue;

      visited[next] = true;
      dist[next] = now.SE+1;
      que.push(pll(next, now.SE+1));
    }
  }


  REP(i, n)
    visited[i] = false;

  que.push(pll(u, 0));
  visited[u] = true;
  pll ans = pll(dist[u],0);
  while(!que.empty()){
    pll now = que.front();
    que.pop();
    for(ll i = 0; i<g[now.FI].size(); i++){
      ll next = g[now.FI][i];
      if(visited[next] || dist[next]<=now.SE+1)
        continue;

      visited[next] = true;
      if(ans.FI < dist[next]){
        ans.FI = dist[next];
        ans.SE = now.SE+1;
      }
      que.push(pll(next, now.SE+1));
    }
  }

  cout << ans.FI-1 << endl;
}
