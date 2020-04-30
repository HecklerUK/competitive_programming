#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;

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

  ll n, a;
  cin >> n >> a;

  vll x(n);
  REP(i, n)
    cin >> x[i];

  //  ll dp[n+2][n+2][n*50+2];
  vector<vector<vll>> dp(n+2, vector<vll>(n+2, vll((n+2)*50, 0)));
  /*
  REP(i, n+2){
    REP(j, n+2){
      REP(k, n*50+2)
        dp[i][j][k] = 0;
    }
  }
  */

  dp[0][0][0] = 1; 
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= i; j++){
      if(j == 0){
        dp[i][j][0] = 1;
        continue;
      }
      for(int s = 1*j; s <= 50*j; s++){
        //x[i-1] is index, but i means pick mount.
        if(s >= x[i-1])
          dp[i][j][s] = dp[i-1][j-1][s-x[i-1]] + dp[i-1][j][s];
        else
          dp[i][j][s] = dp[i-1][j][s];
      }
    }
  }

  ll ans = 0;
  for(int j = 1; j <= n; j++){
    ans += dp[n][j][a*j];
  }

  cout << ans << endl;
  
}
