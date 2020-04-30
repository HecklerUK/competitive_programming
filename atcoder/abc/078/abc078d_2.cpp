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

  ll n,z,w;
  cin >> n >> z >> w;
  vll a(n+1);
  a[0] = w;
  REP(i, n)
    cin >> a[i+1];

  ll x[n+1][n+1],y[n+1][n+1];
  REP(i, n+1){
    REP(j, n+1)
      x[i][j] = y[i][j] = 0;
  }


  REP(i, n)
    y[n][i] = x[n][i] = abs(a[n]-a[i]);

  for(ll j = n-1; j>=0; j--){
    ll newx,newy;
    newx = LLINF;
    newy = 0;

    //jを選んだときのスコア
    for(ll i=j+1; i<=n; i++){
      newx = min(newx, y[i][j]);
      newy = max(newy, x[i][j]);
    }

    for(ll i=0; i<j || (i==0&&j==0); i++){
      x[j][i] = newx;
      y[j][i] = newy;
    }
  }

  //0を選んだ時=開始時点
  cout << y[0][0] << endl;
}
