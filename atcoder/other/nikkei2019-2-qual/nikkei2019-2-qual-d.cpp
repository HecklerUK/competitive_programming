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
#define MAX_N 100000

vll d(MAX_N, LLINF);
struct edge{
  ll cost, to;
  edge(ll t, ll c){
    cost = c;
    to = t;
  }
};


void dijkstra(ll s, vector<vector<edge>> e){
  priority_queue<pll, vector<pll>, greater<pll>> que;
  d[s] = 0;
  que.push(pll(0, s));

  while(!que.empty()){
    pll p = que.top();
    que.pop();
    ll v = p.SE;
    if(d[v] < p.FI)
      continue;
    for(ll i = 0; i < e[v].size(); i++){
      edge g = e[v][i];
      if(d[g.to] > d[v] + g.cost){
        d[g.to] = d[v] + g.cost;
        que.push(pll(d[g.to], g.to));
      }
    }

  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin >> n >> m;
  vector<pair<ll, pll>> clr(m);
  REP(i, m){
    cin >> clr[i].SE.FI >> clr[i].SE.SE >> clr[i].FI;
    clr[i].SE.FI--;
    clr[i].SE.SE--;
  }
  sort(clr.begin(), clr.end());

  //to, cost
  vector<vector<edge>> e(n);
  REP(i, m){
    ll l = clr[i].SE.FI;
    ll r = clr[i].SE.SE;
    ll c = clr[i].FI;

    e[l].push_back(edge(r, c));
  }

  REP1(i, n){
    e[i].push_back(edge(i-1, 0));
  }

  dijkstra(0, e);
  if(d[n-1] == LLINF)
    cout << -1 << endl;
  else
    cout << d[n-1] << endl;

}
