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
typedef vector<vll> vvll;

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
#define yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define no cout<<"No"<<endl
#define NO cout<<"NO"<<endl
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

ll mpow(ll m, ll p){
  ll power = m;
  ll res = 1;
  while(p>0){
    if(p&1)
      res = res*power%MOD;
    power = (power*power)%MOD;
    p /= 2;
  }

  return res;
}

ll mod_inv(ll m){
  return mpow(m, MOD-2);
}

struct COM{
  vll fact, fact_inv;
  COM(ll n): fact(n+1,1), fact_inv(n+1,1){
    for(ll i=1; i<=n; i++)
      fact[i] = fact[i-1]*i%MOD;

    fact_inv[n] = mod_inv(fact[n]);
    for(ll i=n; i>=1; i--)
      fact_inv[i-1] = fact_inv[i]*i%MOD;
  }

  ll calc(ll n, ll k){
    if(k<0 || n<k)
      return 0;
    ll res = fact[n]*fact_inv[n-k]%MOD*fact_inv[k]%MOD;
    return res;
  }
};



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  vll x(n);
  REP(i,n)cin>>x[i];

  vll remind(n);
  for(ll i=1; i<=n; i++){
    remind[i+1]=(remind[i]+mod_inv(i))%MOD;
  }


  COM com(n);
  ll ans=0;
  REP(i,n-1){
    ll dist=x[i+1]-x[i];
    ll l=1;
    ll r=i+2;
    ll plus=dist*((remind[r]-remind[l]+MOD)%MOD)%MOD;
    ans=(ans+plus)%MOD;
  }

  ans=ans*com.fact[n-1]%MOD;

  cout<<ans<<endl;
}

