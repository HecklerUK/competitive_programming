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

ll gcd(ll a, ll b){
  if(a<b)
    return gcd(b,a);

  if(b==0)
    return a;

  return gcd(b, a%b);
}

ll lcm(ll a, ll b){
  return a*b/gcd(a,b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin >> n >> m;
  vll a(n);
  REP(i, n)
    cin >> a[i];

  SORT_UNIQUE(a);
  n = a.size();

  ll now;
  if(n!=1){
    now = lcm(a[0]/2, a[1]/2);
    for(ll i = 1; i+1<n; i++){
      now = lcm(now, a[i+1]/2);
      if(now>m){
        cout << 0 << endl;
        return 0;
      }
    }
  }
  else
    now = a[0]/2;


  bool flag = true;
  REP(i, n){
    if(now%a[i] != a[i]/2)
      flag = false;
  }

  ll ans = 0;
  if(flag){
    ans = m/now;
    ans = ans/2+ans%2;
  }
  cout << ans << endl;

}
