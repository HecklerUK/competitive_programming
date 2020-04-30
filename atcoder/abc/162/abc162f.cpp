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

  ll n;
  cin>>n;
  vll a(n);
  REP(i,n)cin>>a[i];

  ll dp[2][n+1][2];
  REP(i,2)REP(j,n+1)REP(k,2)dp[i][j][k]=0;

  REP(i,n/2){
    dp[0][i+1][0]=dp[0][i][0]+a[i*2];
    dp[0][i+1][1]=max(dp[0][i][0],dp[0][i][1])+a[i*2+1];

    if(i!=0){
      dp[1][i+1][0]=max(max(dp[0][i][0],dp[0][i][1]),
          dp[1][i][0]+a[i*2]);
      dp[1][i+1][1]=max(max(dp[0][i][0],dp[0][i][1]),
          max(dp[1][i][0],dp[1][i][1])+a[i*2+1]);
    }
  }

  ll ans=max(dp[0][n/2][0],dp[0][n/2][1]);
  if(n%2==1)
    ans=max(ans,dp[1][n/2][0]+a[n-1]);


  cout<<ans<<endl;
}

