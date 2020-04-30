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

  //whether centor or not, height
  pair<bool, ll> c[101][101];
  REP(i, 101){
    REP(j, 101)
      c[i][j] = make_pair(true, LLINF);
  }

  ll n;
  cin >> n;
  vll X(n), Y(n), H(n);
  vll initialize(3);
  REP(i, n){
    cin >> X[i] >> Y[i] >> H[i];
    if(H[i] != 0){
      initialize[0] = X[i];
      initialize[1] = Y[i];
      initialize[2] = H[i];
    }
  }

  REP(x, 101){
    REP(y, 101){
      c[x][y].SE = initialize[2] + abs(x-initialize[0]) + abs(y-initialize[1]);
      REP(i, n){
        if(!c[x][y].FI)
          continue;
        if(c[x][y].SE == LLINF && H[i] != 0)
          c[x][y].SE = H[i] + abs(x-X[i]) + abs(y-Y[i]);
        else{
          ll v = c[x][y].SE - (abs(x-X[i]) + abs(y-Y[i]));
          v = max(v, 0LL);
          if(v != H[i])
            c[x][y].FI = false;
        }
      }
    }
  }

  REP(x, 101){
    REP(y, 101){
      if(c[x][y].FI)
        cout << x << ' ' << y << ' ' << c[x][y].SE << endl;
    }
  }


}
