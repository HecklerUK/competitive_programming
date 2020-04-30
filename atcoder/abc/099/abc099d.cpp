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

  ll n,c;
  cin >> n >> c;
  vector<vll> d(c, vll(c));
  REP(i, c){
    REP(j, c)
      cin >> d[i][j];
  }

  vector<vll> color(n, vll(n));
  REP(i, n){
    REP(j, n){
      cin >> color[i][j];
      color[i][j]--;
    }
  }



  vector<vector<vll>> dd(3, vector<vll>(c, vll(c, 0)));
  REP(i, n){
    REP(j, n){
      ll remind = (i+j)%3;
      ll X = color[i][j];
      REP(Y, c)
        dd[remind][X][Y] += d[X][Y];
    }
  }

  ll ans = LLINF;
  REP(i, c){
    REP(j, c){
      REP(k, c){
        if(i == j || i == k || j == k)
          continue;

        ll sum = 0;
        REP(X, c){
          sum += dd[0][X][i];
          sum += dd[1][X][j];
          sum += dd[2][X][k];
        }

        ans = min(ans, sum);
      }
    }
  }

  cout << ans << endl;
}
