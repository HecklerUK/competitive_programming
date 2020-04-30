#include <iostream>
#include <vector>
#include <set>
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


struct UnionFind {
  vector<int> par;

  UnionFind(int n) : par(n, -1) { }
  void init(int n) { par.assign(n, -1); }

  int root(int x) {
    if (par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }

  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x, y); // merge technique
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) {
    return -par[root(x)];
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m,k;
  cin>>n>>m>>k;

  UnionFind uf(n);

  vll A[n],B[n];
  REP(i,m){
    ll a,b;
    cin>>a>>b;
    a--;
    b--;
    A[a].push_back(b);
    A[b].push_back(a);
    uf.merge(a,b);
  }

  REP(i,k){
    ll c,d;
    cin>>c>>d;
    d--;
    c--;
    B[d].push_back(c);
    B[c].push_back(d);
  }

  vll t(n,0);

  map<ll,ll> p;
  REP(i,n){
    ll x = uf.root(i);
    p[x] += 1;
  }

  REP(i,n){
    ll x = uf.root(i);
    t[i] = p[x]-1;
    REP(j,A[i].size()){
      ll y = A[i][j];
      if(x==uf.root(y))
        t[i]--;
    }
    REP(j,B[i].size()){
      ll y = B[i][j];
      if(x==uf.root(y))
        t[i]--;
    }
  }


  cout<<t[0];
  REP1(i,n)cout<<" "<<t[i];
  cout<<endl;
}
