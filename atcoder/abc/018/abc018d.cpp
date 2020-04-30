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

const ll MAX_N=18;
ll n,m,p,q,r;
ll value[MAX_N][MAX_N];


ll solve(vll girls){
    vll v(m);
    REP(i,m){
      REP(j,girls.size())
        v[i] += value[girls[j]][i];
    }

    sort(ALL(v),greater<ll>());
    ll res=0;
    REP(i,q)res+=v[i];
    return res;
}


ll dfs_pick(vll& indexes, int s, int rest) {
  if (rest == 0) {
    return solve(indexes);
  } else {
    if (s < 0)
      return 0;

    ll res=dfs_pick(indexes, s - 1, rest);
    indexes[rest - 1] = s;
    res=max(res,dfs_pick(indexes, s - 1, rest - 1));
    return res;
  }
}




int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  cin>>n>>m>>p>>q>>r;
  vll x(r),y(r),z(r);
  REP(i,n)REP(j,n)value[i][j]=0;
  REP(i,r){
    cin>>x[i]>>y[i]>>z[i];
    x[i]--;
    y[i]--;
    value[x[i]][y[i]]=z[i];
  }

  vll indexes(p);
  ll ans=dfs_pick(indexes, n - 1, p);
  cout<<ans<<endl;



}

