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

  ll n,k;
  cin >> n >> k;
  vll a(n);
  REP(i, n)
    cin >> a[i];

  vll s(n+1, 0);
  REP(i, n)
    s[i+1] = s[i]+a[i];

  map<ll, ll> m;
  ll ans = 0;
  REP(i, s.size()){
    ll t = (s[i]-i)%k;
    if(t<0)
      t += k;

    if(i<k){
      ans += m[t];
      m[t] += 1;
    }
    else{
      ll r = (s[i-k]-(i-k))%k;
      if(r<0)
        r += k;
      m[r] -= 1;
      ans += m[t];
      m[t] += 1;
    }
  }

  cout << ans << endl;

}
