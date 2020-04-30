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

  ll n,d,a;
  cin>>n>>d>>a;
  vll x(n),h(n);
  REP(i,n)cin>>x[i]>>h[i];

  vector<pll> p(n);
  REP(i,n){
    p[i].FI=x[i];
    p[i].SE=h[i];
  }

  map<ll,ll> m;
  sort(x.begin(), x.end());
  sort(p.begin(), p.end());
  REP(i,n)
    m[p[i].FI]=i;


  ll ans=0;
  vll imos(n+2,0);

  REP(i,n){
    ll health = p[i].SE;
    if(i!=0)
      imos[i] += imos[i-1];
    health -= imos[i]*a;

    if(health<=0)
      continue;

    auto it = upper_bound(x.begin(), x.end(), x[i]+2*d);
    ll t = it-x.begin();

    ll k = health/a;
    if(health%a!=0)
      k++;

    imos[i] += k;
    imos[t] -= k;


    ans += k;
  }

  cout << ans << endl;
}
