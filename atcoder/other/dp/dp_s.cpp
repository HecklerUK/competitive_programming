#include <bits/stdc++.h>
using namespace std;

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

ll dp[2][102];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string k;
  ll d;
  cin >> k >> d;

  REP(i, 2)REP(j, 102)dp[i][j] = 0;
  REP(i, k[0] - '0')dp[1][i % d]=1;
  dp[0][(k[0] - '0') % d] = 1;

  ll n = k.size();
  ll num = 10 / d;
  REP1(i, n) {
    vector<vll> cum(2, vll(d + 3));
    REP(t,2)REP(j, d)cum[t][j + 1] += cum[t][j] + dp[t][j];

    REP(j, n) {
      ll index = (j - (k[i] - '0') + d) % d;
      dp[0][j] = cum[0][index+1]+cum[0][index];
      vll l(2), r(2);
      l[0]=l[1] = j % d;
      r[0] = j % d + (k[i] - '1') % d;
      r[1] = j % d + 9 % d;

      REP(t, 2) {
        if (r[t] >= d) {
          dp[1][j] += ((cum[t][d] - cum[t][l[t]]) + (cum[t][r[t] % d + 1] - cum[t][0]) + (cum[t][d] - cum[t][0]) * num) % MOD;
          dp[1][j] = (dp[1][j] + MOD) % MOD;
        }
        else
          dp[1][j] += (MOD + cum[t][r[t] + 1] - cum[t][l[t]]) % MOD;
      }
    }

  }

  ll ans = (dp[0][0] + dp[1][0])%MOD;
  cout << ans << endl;


}



