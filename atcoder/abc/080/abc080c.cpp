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

  ll n;
  cin >> n;
  ll f[n][10], p[n][10];
  REP(i, n){
    REP(j, 10)
      cin >> f[i][j];
  }
  REP(i, n){
    REP(j, 11)
      cin >> p[i][j];
  }

  ll ans = -LLINF;
  for(ll bit = 1; bit < (1<<10); bit++){
    vll now(10, 0);
    ll profit = 0;
    REP(i, 10){
      if(bit & (1<<i))
        now[i] = 1;
    }

    REP(i, n){
      ll sameCount = 0;
      REP(j, 10){
        if(now[j] == 1 && f[i][j] == 1)
          sameCount++;
      }
      profit += p[i][sameCount];
    }
    ans = max(ans, profit);
  }

  cout << ans << endl;

  
  
}
