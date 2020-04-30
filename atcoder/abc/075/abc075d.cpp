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

  ll n,k;
  cin >> n >> k;

  vll x(n), y(n);
  vll xary(n), yary(n);
  REP(i, n){
    cin >> x[i] >> y[i];
    xary[i] = x[i];
    yary[i] = y[i];
  }

  sort(xary.begin(), xary.end());
  sort(yary.begin(), yary.end());

  ll ans = (xary[n-1]-xary[0])*(yary[n-1]-yary[0]);
  REP(xi, n){
    for(ll xj=xi+1; xj<n; xj++){
      REP(yi, n){
        for(ll yj=yi+1; yj<n; yj++){
          ll c=0;
          REP(i, n){
            if(xary[xi]<=x[i] && x[i]<=xary[xj] && yary[yi]<=y[i] && y[i]<=yary[yj])
              c++;
          }

          if(c==k)
            ans = min(ans, (xary[xj]-xary[xi])*(yary[yj]-yary[yi]));
        }
      }
    }
  }

  cout << ans << endl;

}

