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


template<typename T>
struct LCA{
  ll root;
  ll n;
  ll max_log;
  vvll edge;
  vvll parent;
  vll depth;
  vector<T> cost;
  vector<vector<T>> co;

  LCA(ll n):n(n),edge(n),depth(n),cost(n),co(n){
    max_log=0;
    while((1<<max_log)<n)
      max_log++;
    parent.assign(max_log+1,vll(n+1,n));
  }

  void addEdge(ll a, ll b, T c=0){
    edge[a].push_back(b);
    edge[b].push_back(a);
    co[a].push_back(c);
    co[b].push_back(c);
  }

  void dfs(ll v, ll p=-1, ll d=0, T c=0){
    if(p!=-1)
      parent[0][v]=p;
    depth[v]=d;
    cost[v]=c;

    for(ll i=0; i<edge[v].size(); i++){
      ll e=edge[v][i];
      if(e==p)
        continue;
      dfs(e,v,d+1,c+co[v][i]);
    }
  }

  void init(ll _root=0){
    root=_root;
    //initialize parent[0] and depth
    dfs(root);
    //initialize parent
    for(ll k=0; k<max_log; k++){
      REP(i,n)
        parent[k+1][i]=parent[k][parent[k][i]];
    }
  }

  //lca query
  ll query(ll u, ll v){
    if(depth[u]>depth[v])
      swap(u,v);
    for(int k=0; k<max_log; k++){
      if((depth[v]-depth[u])>>k & 1)
        v=parent[k][v];
    }

    if(u==v)
      return u;

    for(ll k=max_log-1; k>=0; k--){
      if(parent[k][v]!=parent[k][u]){
        v=parent[k][v];
        u=parent[k][u];
      }
    }
    return parent[0][u];
  }

  ll length(ll u, ll v){
    ll r=query(u,v);
    ll res=depth[u]+depth[v]-2*depth[r];
    return res;
  }

  T dist(ll u, ll v){
    ll r=LCA(u,v);
    ll res=cost[u]+cost[v]-2*cost[r];
    return res;
  }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  LCA<ll> lca(n);

  REP(i,n-1){
    ll x,y;
    cin>>x>>y;
    x--;
    y--;
    lca.addEdge(x,y);
  }

  lca.init();

  ll q;
  cin>>q;
  vll a(q),b(q);
  REP(i,q)cin>>a[i]>>b[i];


  REP(i,q){
    a[i]--;
    b[i]--;
    ll res=lca.length(a[i], b[i])+1;
    cout<<res<<endl;
  }
}

