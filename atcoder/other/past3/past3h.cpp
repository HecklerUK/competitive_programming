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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,l;
  cin>>n>>l;
  vll h(l+5,0);
  REP(i,n){
    ll x;
    cin>>x;
    h[x]=1;
  }
  ll t1,t2,t3;
  cin>>t1>>t2>>t3;

  vll dp(l+5,LLINF);
  dp[0]=0;
  REP(i,l){
    ll t=0;
    if(h[i]==1)
      t=t3;

    dp[i+1]=min(dp[i+1],dp[i]+t1+t);
    dp[i+2]=min(dp[i+2],dp[i]+t1+t2+t);
    dp[i+4]=min(dp[i+4],dp[i]+t1+3*t2+t);
  }

  ll ans=dp[l];
  ans=min(ans,dp[l-3]+h[l-3]*t3+t1/2+t2/2*5);
  ans=min(ans,dp[l-2]+h[l-2]*t3+t1/2+t2/2*3);
  ans=min(ans,dp[l-1]+h[l-1]*t3+t1/2+t2/2*1);

  cout<<ans<<endl;
}

