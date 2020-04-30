#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpl;

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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin>>s;
  ll k;
  cin>>k;

  ll n=s.size();
  ll dp[n][2][k+1];
  REP(i,n)REP(j,2)REP(r,k+1)dp[i][j][r]=0;

  ll cnt=0;
  REP(i,n){
    if(s[i]!='0')
      cnt++;

    REP(j, k+1){
      if(cnt!=j)
        dp[i][0][j]=0;
      else
        dp[i][0][j]=1;
    }

    if(i==0){
      dp[i][1][0]=1;
      dp[i][1][1]=(s[i]-'0')-1;
    }
    else{
      dp[i][1][0]=1;
      REP1(j,k+1){
        dp[i][1][j]=dp[i-1][1][j-1]*9 + dp[i-1][1][j]*1 +
          dp[i-1][0][j-1]*max(s[i]-'0'-1,0) + dp[i-1][0][j]*min(s[i]-'0',1);
      }
    }
  }

  cout<<dp[n-1][0][k]+dp[n-1][1][k]<<endl;

}
