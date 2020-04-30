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
#define MAX_N 300

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  ll n,m,l;
  cin >> n >> m >> l;

  ll distance[n][n];
  REP(i, n){
    REP(j, n)
      distance[i][j] = LLINF;
  }

  ll a,b,c;
  REP(i, m){
    cin >> a >> b >> c;
    if(c <= l){
      a--;
      b--;
      distance[a][b] = distance[b][a] = c;
    }
  }

  ll q;
  cin >> q;
  vector<pll> query(q);
  REP(i, q)
    cin >> query[i].FI >> query[i].SE;


  REP(k, n){
    REP(i, n){
      REP(j, n)
        distance[i][j] = min(distance[i][j], distance[i][k]+distance[k][j]);
    }
  }

  ll fuel[n][n];
  REP(i, n){
    REP(j, n){
      if(distance[i][j] <= l)
        fuel[i][j] = 1;
      else
        fuel[i][j] = LLINF;
    }
  }

  REP(k, n){
    REP(i, n){
      REP(j, n)
        fuel[i][j] = min(fuel[i][j], fuel[i][k]+fuel[k][j]);
    }
  }

  ll s,t;
  REP(i, q){
    s = query[i].FI;
    t = query[i].SE;
    s--;
    t--;
    if(distance[s][t] != LLINF)
      cout << fuel[s][t]-1 << endl;
    else
      cout << -1 << endl;
  }

}
