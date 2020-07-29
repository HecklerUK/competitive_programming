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


vll call(vpl h){
  ll n=h.size();
  sort(ALL(h));

  vll res(n+1);

  vvll dp(20,vll(20,LLINF));
  dp[0][0]=0;
  REP(l,n){
    for(ll r=l+1; r<=n; r++){
      ll now=LLINF;
      for(ll k=l; k<r; k++){
        ll s=0;
        for(ll i=l; i<r; i++)
          s+=abs(h[i].FI-h[k].FI)*h[i].SE;
        now=min(now,s);
      }


      REP(j,n)
        dp[r][j+1]=min(dp[l][j]+now,dp[r][j+1]);


      //axis check
      now=0;
      for(ll i=l; i<r; i++)
        now+=abs(h[i].FI)*h[i].SE;
      REP(j,n)
        dp[r][j]=min(dp[l][j]+now,dp[r][j]);
    }
  }


  REP(i,n+1)res[i]=dp[n][i];
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  vll x(n),y(n),p(n);
  REP(i,n)cin>>x[i]>>y[i]>>p[i];

  vll ans(2*n+1,LLINF);
  REP(i,(1<<n)){
    vpl ax,ay;
    REP(j,n){
      if((i>>j)&1)
        ax.push_back(pll(x[j],p[j]));
      else
        ay.push_back(pll(y[j],p[j]));
    }

    vll rx=call(ax);
    vll ry=call(ay);

    REP(j,rx.size())REP(k,ry.size())ans[j+k]=min(ans[j+k],rx[j]+ry[k]);
  }

  REP(i,n+1)cout<<ans[i]<<endl;

}

