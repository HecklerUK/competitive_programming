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

ll involve(ll x){
  ll res=0;
  if(x>=4)
    res++;
  if(x>=9)
    res++;
  return res;
}

ll calc(ll x){
  ll dp[2][2][2];
  REP(i,2)REP(j,2)REP(k,2)dp[i][j][k]=0;

  string s=to_string(x);
  ll n=s.size();

  REP(i,n){
    ll now = s[i]-'0';
    if(i==0){
      if(now==4 || now==9)
        dp[0][0][1]=1;
      else
        dp[0][0][0]=1;

      dp[0][1][0]=now-involve(now-1);
      dp[0][1][1]=involve(now-1);
    }
    else{
      if(now==4 || now==9)
        dp[1][0][0]=0;
      else
        dp[1][0][0]=dp[0][0][0];

      if(now==4 || now==9)
        dp[1][0][1]=1;
      else
        dp[1][0][1]=dp[0][0][1];

      dp[1][1][0]=dp[0][0][0]*(now-involve(now-1))+dp[0][1][0]*8;
      dp[1][1][1]=dp[0][0][0]*involve(now-1)+dp[0][0][1]*now+dp[0][1][0]*2+dp[0][1][1]*10;
      dp[0][0][0]=dp[1][0][0];
      dp[0][0][1]=dp[1][0][1];
      dp[0][1][0]=dp[1][1][0];
      dp[0][1][1]=dp[1][1][1];

    }
  //  REP(i,2)REP(j,2)cout<<dp[0][i][j]<<":";
  //  cout<<endl;
  }

  ll res = dp[0][0][1]+dp[0][1][1];
  return res;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll a,b;
  cin>>a>>b;
  ll ans = calc(b)-calc(a-1);
  cout<<ans<<endl;
}

