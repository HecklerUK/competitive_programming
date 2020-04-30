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

  ll n,m;
  cin >> n >> m;
  vll a(n);
  REP(i, n)
    cin >> a[i];

  sort(a.begin(), a.end());

  ll oklim = 0;
  ll nglim = 1e11;
  while(nglim-oklim>1){
    ll midlim = (oklim+nglim)/2;

    ll sum = 0;
    REP(i, n){
      if(a[i]+a[n-1]<midlim)
        continue;
      auto it = lower_bound(a.begin(), a.end(), midlim-a[i]);
      sum += a.end()-it;
    }
    if(sum>=m)
      oklim = midlim;
    else
      nglim = midlim;
  }


  vll cum(n+1, 0);
  REP(i, n)
    cum[i+1] = cum[i]+a[i];

  ll ans = 0;
  ll more = 0;
  REP(i, n){
    if(a[i]+a[n-1]<oklim)
      continue;
    auto it = upper_bound(a.begin(), a.end(), oklim-a[i]);
    ll ok = it-a.begin();
    ans += cum[n]-cum[ok];
    ans += (n-ok)*a[i];
    more += n-ok;
  }
  ans += oklim*(m-more);

  cout << ans << endl;
}
