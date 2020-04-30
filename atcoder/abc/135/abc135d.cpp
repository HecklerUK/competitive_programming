#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

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
  cin >> s;

  ll n = s.size();
  ll dp[n][13];
  REP(i, n){
    REP(j, 13)
      dp[i][j] = 0;
  }

  if(s[0] == '?'){
    REP(i, 10)
      dp[0][i] = 1;
  }
  else
    dp[0][(int)(s[0] - '0')] = 1;


  REP(i, n-1){
    if(s[i+1] == '?'){
      REP(k, 10){
        REP(j, 13){
          dp[i+1][(j*10+k)%13] += dp[i][j];
          dp[i+1][(j*10+k)%13] %= MOD;
        }
      }
      continue;
    }
    ll now = s[i+1] - '0';
    REP(j, 13){
      dp[i+1][(j*10+now)%13] += dp[i][j];
      dp[i+1][(j*10+now)%13] %= MOD;
    }
  }


  cout << dp[n-1][5] << endl;
  
  /*
  REP(i, n){
    REP(j, 13)
      cout << dp[i][j] << " ";
    cout << endl;
  }
  */


  
}
