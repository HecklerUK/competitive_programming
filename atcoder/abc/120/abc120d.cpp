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

struct UnionFind{
  vll tree;
  vll rank;
  vll size;

  UnionFind(ll n = 1){
    init(n);
  }

  void init(ll n){
    tree.resize(n);
    rank.resize(n);
    size.resize(n);
    REP(i, n){
      tree[i] = i;
      rank[i] = 0;
      size[i] = 1;
    }
  }

  ll root(ll i){
    if(tree[i] == i)
      return i;
    else{
      tree[i] = root(tree[i]);
      return tree[i];
    }
  }

  bool same(ll a, ll b){
    return root(a) == root(b);
  }

  ll len(ll a){
    return size[root(a)];
  }

  bool merge(ll ga, ll gb){
    ll x = root(ga);
    ll y = root(gb);
    if(x == y)
      return false;

    if(rank[x] < rank[y])
      swap(x, y);
    if(rank[x] == rank[y])
      rank[x]++;
    size[x] += size[y];
    tree[y] = x;
    return true;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  cin >> n >> m;

  vll a(m), b(m);
  REP(i, m){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
  }

  vll ans(m, 0);
  ans[m-1] = n*(n-1)/2;

  UnionFind uf(n);
  REP(i, m-1){
    ll x = a[m-1-i];
    ll y = b[m-1-i];
    if(uf.same(x, y))
      ans[m-2-i] = ans[m-1-i];
    else
      ans[m-2-i] = ans[m-1-i] - uf.len(x)*uf.len(y);

    uf.merge(x, y);
  }

  REP(i, m)
    cout << ans[i] << endl;
  
}
