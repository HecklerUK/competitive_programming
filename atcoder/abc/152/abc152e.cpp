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


//ll gcd(ll x, ll y){
//  if(x<y)
//    return gcd(y,x);
//  if(y==0)
//    return x;
//
//  return gcd(y,x%y);
//}

ll gcd_impl(ll n, ll m){
  for(int i = 0; i < 10; ++i ) {
    ll t = n - m;
    bool q = m > t;
    n = q ? m : t;
    m = q ? t : m;
    if( m == 0 ) { return n; }
  }
  return gcd_impl( m, n % m );
}

ll gcd(ll n, ll m){
  return n > m ? gcd_impl( n, m ) : gcd_impl( m, n );
}

ll lcd(ll x, ll y){
  ll a = gcd(x,y);
  return x*y/a;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  vll a(n);
  REP(i, n)
    cin >> a[i];
  sort(a.begin(), a.end());

  map<ll,ll> m;
  vll ins;
  REP(i, n){
    ll x = a[i];
    for(ll k = 2; k*k<=a[i]; k++){
      ll t = 0;
      if(x%k==0)
        ins.push_back(k);
      while(x%k==0){
        t++;
        x/=k;
      }

      if(m[k]<t)
        m[k]=t;
    }

    if(x!=1 && m[x]==0){
      m[x]=1;
      ins.push_back(x);
    }
  }

  SORT_UNIQUE(ins);

  ll ans = 0;
  REP(i, n){
    ll x = a[i];
    ll b = 1;
    for(ll k = 0; k<ins.size(); k++){
      ll t = 0;
      while(x%ins[k]==0){
        t++;
        x/=ins[k];
      }
      b *= ll(pow(ins[k], m[ins[k]]-t))%MOD;
    }

    ans = (ans+b)%MOD;
  }

  cout << ans << endl;
}
