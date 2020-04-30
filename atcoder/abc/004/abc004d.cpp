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


ll r,g,b;
ll dif=1000;
ll rmid=dif-100;
ll gmid=dif+0;
ll bmid=dif+100;
const ll MAX_REM=900;
ll dp[2000][MAX_REM+1];

ll dpCost(ll p, ll remind){
  if(remind>g+b)
    return abs(p-rmid);
  if(remind>b)
    return abs(p-gmid);
  if(remind>0)
    return abs(p-bmid);

  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>r>>g>>b;
  ll remind=r+g+b;
  REP(i,2000)REP(j,remind+1)dp[i][j]=LLINF;
  dp[0][remind]=0;
  REP1(i,2000){
    REP(j,remind+1){
      if(j==remind)
        dp[i][j]=dp[i-1][j];
      else
        dp[i][j]=min(dp[i-1][j+1]+dpCost(i,j+1),dp[i-1][j]);
    }
  }

  ll ans=LLINF;
  REP(i,2000)
    ans=min(ans,dp[i][0]);
  cout<<ans<<endl;


}

