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
typedef vector<pll> vpll;

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

  string s,t;
  cin>>s>>t;

  ll n = s.size();
  ll m = t.size();
  ll dp[n+1][m+1];
  REP(i,n+1)REP(j,m+1)dp[i][j]=0;

  REP(i,n){
    REP(j,m){
      if(s[i]==t[j]){
        dp[i+1][j+1] = max(dp[i][j]+1,dp[i+1][j+1]);
      }
      else{
        dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
        dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
      }
    }
  }

  REP(i,n+1){
    REP(j,m+1)cout<<dp[i][j]<<" ";
    cout<<endl;
  }

  ll i = n;
  ll j = m;
  string ans="";
  while(!(i==0 && j>=0)){
    if(s[i]==t[j])
      ans = s[i]+ans;

    cout << i<<":"<<j<<endl;
    if(i>=1&&j>=1&&dp[i][j] == dp[i-1][j-1]+1){
      i--;
      j--;
    }
    else if(i>=1&&dp[i][j]==dp[i-1][j])
      i--;
    else if(j>=1)
      j--;
  }
  cout << ans << endl;

  cout << dp[n][m] << endl;
}
