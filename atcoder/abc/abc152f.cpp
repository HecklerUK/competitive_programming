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
#define REP(i,n) for(ll i=0;i<((ll)n);i++)
#define REP1(i,n) for(ll i=1;i<((ll)n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
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



vll u,v;
vector<vpl> edge;
ll m;
ll n;

bool dfs(ll now, ll pre, ll target, ll& p){
  if(now==target){
    p=0;
    return true;
  }

  for(auto e:edge[now]){
    if(e.FI==pre)
      continue;

    if(dfs(e.FI,now,target,p)){
      p|=(1LL<<e.SE);
      return true;
    }
  }
  return false;
}


void solve(){
  vll paths(m,0);
  REP(i,m)dfs(u[i],-1,v[i],paths[i]);

  ll ans=0;
  REP(bit,(1LL<<m)){
    ll p=0;
    REP(i,m){
      if((1LL<<i)&bit)
        p|=paths[i];
    }

    ll cnt=__builtin_popcount(bit);
    ll cnt_p=__builtin_popcount(p);

    if(cnt%2==0)
      ans+=(1LL<<(n-1-cnt_p));
    else
      ans-=(1LL<<(n-1-cnt_p));
  }

  cout<<ans<<endl;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;
  edge.assign(n,vpl());
  REP(i,n-1){
    ll a,b;
    cin>>a>>b;
    a--;
    b--;
    edge[a].push_back(pll(b,i));
    edge[b].push_back(pll(a,i));
  }

  cin>>m;
  u.resize(m),v.resize(m);
  REP(i,m){
    cin>>u[i]>>v[i];
    u[i]--;
    v[i]--;
  }
  solve();

}

