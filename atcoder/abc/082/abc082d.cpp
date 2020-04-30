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

  string s;
  cin >> s;
  ll X,Y;
  cin >> X >> Y;

  ll n = s.size();
  vll x, y;
  ll now = 0;
  ll cur = 0;
  REP(i, n){
    if(s[i] == 'T'){
      if(cur%2==0)
        x.push_back(now);
      else
        y.push_back(now);
      cur++;
      now = 0;
    }
    else
      now++;
  }
  if(cur%2==0)
    x.push_back(now);
  else
    y.push_back(now);

  if(y.size() == 0)
    y.push_back(0);

  //0 to n:-n to 0, n to 2n: 0 to n
  vector<vector<bool>> dpx(n, vector<bool>(2*n+1, false));
  vector<vector<bool>> dpy(n, vector<bool>(2*n+1, false));
  dpx[0][x[0]+n] = true;
  dpy[0][y[0]+n] = dpy[0][-y[0]+n] = true;
  REP1(i, x.size()){
    REP(j, 2*n+1){
      if(0 <= j-x[i])
        dpx[i][j] = dpx[i-1][j-x[i]] || dpx[i][j];

      if(j+x[i] < 2*n)
        dpx[i][j] = dpx[i-1][j+x[i]] || dpx[i][j];
    }
  }

  REP1(i, y.size()){
    REP(j, 2*n+1){
      if(0 <= j-y[i])
        dpy[i][j] = dpy[i-1][j-y[i]] || dpy[i][j];
      if(j+y[i] < 2*n)
        dpy[i][j] = dpy[i-1][j+y[i]] || dpy[i][j];
    }
  }


  if(dpx[x.size()-1][X+n] && dpy[y.size()-1][Y+n])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;


}
