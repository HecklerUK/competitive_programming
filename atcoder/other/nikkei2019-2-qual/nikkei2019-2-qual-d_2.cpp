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
#define MAX_N 100000

vll d(MAX_N, LLINF);


struct segTree{
  ll N;
  vll dat;
  void init(ll n){
    N = 1;
    while(N < n)
      N *= 2;

    dat = vll(2*N, LLINF);
  }

  void update(ll k, ll a){
    k += N-1; //leaf
    dat[k] = a;
    while(k > 0){
      k = (k-1)/2;
      dat[k] = min(dat[k*2+1], dat[k*2+2]);
    }
  }

  ll query(ll a, ll b){
    if(a > b)
      return query(b,a,0,0,N);
    else
      return query(a,b,0,0,N);
  }

  ll query(ll a, ll b, ll k, ll l, ll r){
    if(b <= l || r <= a)
      return LLINF;

    if(a <= l && r <= b)
      return dat[k];
    else{
      ll m = (l+r)/2;
      ll vl = query(a, b, k*2+1, l, m);
      ll vr = query(a, b, k*2+2, m, r);
      return min(vl, vr);
    }
  }

  ll at(ll a){
    return dat[a+N-1];
  }
};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin >> n >> m;
  vector<pair<pll, ll>> lrc(m);
  REP(i, m){
    cin >> lrc[i].FI.FI >> lrc[i].FI.SE >> lrc[i].SE;
    lrc[i].FI.FI--;
    lrc[i].FI.SE--;
  }
  sort(lrc.begin(), lrc.end());

  segTree seg;
  seg.init(n);
  seg.update(0, 0);
  REP(i, m){
    ll l = lrc[i].FI.FI;
    ll r = lrc[i].FI.SE;
    ll c = lrc[i].SE;

    ll k = seg.query(l, r+1);
    seg.update(r, min(k+c, seg.at(r)));
  }

  ll ans = seg.at(n-1);
  if(ans == LLINF)
    cout << -1 << endl;
  else
    cout << ans << endl;

}
