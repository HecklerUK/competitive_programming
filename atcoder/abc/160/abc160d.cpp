#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpl;

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

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  ll n,x,y;
  cin>>n>>x>>y;
  x--;
  y--;
  ll dist[n][n];
  REP(i,n)dist[i][i]=0;

  REP(i,n){
    for(ll j=i+1; j<n; j++){
      dist[i][j] = dist[i][j-1]+1;
      dist[j][i]=dist[i][j];
    }
  }
  dist[x][y] = 1;

  vll ans(n+1);
  REP(i,n){
    for(ll j=i+1; j<n; j++){
      dist[i][j] = min(dist[i][j], dist[i][x]+dist[y][j]+1);
      ll d = dist[i][j];
      ans[d]++;
    }
  }

  REP1(i,n)cout<<ans[i]<<endl;



}

