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
const int MOD = 998244353;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,s;
  cin>>n>>s;
  vll a(n);
  REP(i,n)cin>>a[i];

  ll ans=0;
  ll dp[n+2][3010];
  REP(i,n+2)REP(j,3010)dp[i][j]=0;

  REP(i,n){
    dp[i][0] += 1;
    dp[i][0] %= MOD;
    for(ll j=3010-1; j>=0; j--){
      dp[i+1][j]+=dp[i][j];
      dp[i+1][j]%=MOD;
      if(j-a[i]>=0)
        dp[i+1][j] += dp[i][j-a[i]];
      dp[i+1][j]%=MOD;
    }
    ans = (ans+dp[i+1][s])%MOD;
  }

  cout<<ans<<endl;
}

