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

ld calcVolume(ld r, ld h, ld x, ld i){
  if(i-x>=h || i-x<0)
    return 0;
  ld volume = pow(r*1.0*(h-(i-x))/h, 2) * M_PI * (h-(i-x)) / 3.0;

  return volume;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, q;
  cin >> n >> q;
  vll x(n), r(n), h(n);
  REP(i, n)
    cin >> x[i] >> r[i] >> h[i];

  vll a(q), b(q);
  REP(i, q)
    cin >> a[i] >> b[i];

  ll xlim = 10000;
  vld cum(xlim+1, 0);
  REP(i, xlim){
    ld diff = 0;
    REP(j, n){
      if(i<x[j] || i-x[j]>=h[j])
        continue;
       diff += calcVolume(r[j], h[j], x[j], i) - calcVolume(r[j], h[j], x[j], i+1);
    }
    cum[i+1] = cum[i]+diff;
  }

  cout << Decimal;
  REP(i, q){
    cout << cum[b[i]]-cum[a[i]] << endl;
  }

}
