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
typedef vector<vll> vvll;

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
#define yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define no cout<<"No"<<endl
#define NO cout<<"NO"<<endl
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};


struct UnionFind {
  vll d;
  UnionFind(ll n=0): d(n,-1) {}
  ll find(ll x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(ll x, ll y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(ll x, ll y) { return find(x) == find(y);}
  ll size(ll x) { return -d[find(x)];}
};



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin>>n>>m;


  vector<vll> g(m);
  REP(i,n){
    ll k;
    cin>>k;

    REP(j,k){
      ll l;
      cin>>l;
      l--;
      g[l].push_back(i);
    }
  }

  UnionFind uf(n);
  REP(i,m){
    REP(j,g[i].size())
      uf.unite(g[i][0],g[i][j]);
  }


  bool flag=true;
  ll x=uf.find(0);
  if(uf.find(0)<0)
    x=0;

  REP1(i,n){
    if(x!=uf.find(i))
      flag=false;
  }

  if(flag)
    YES;
  else
    NO;
}

