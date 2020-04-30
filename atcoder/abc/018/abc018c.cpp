#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

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
const int mod = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll r, c, k;
  cin >> r >> c >> k;

  vector<string> s(r);
  REP(i, r)
    cin >> s[i];

  ll minMap[r][c];
  REP(i, r){
    REP(j, c){
      if(s[i][j] == 'x'){
        minMap[i][j] = 0;
        continue;
      }
      ll countWhite = 1;
      ll minUp = min(i, (int)(r-i-1));
      for(int p = 1; p <= minUp; p++){
        if(s[i-p][j] == 'o' && s[i+p][j] == 'o')
          countWhite++;
        else
          break;
      }
      minMap[i][j] = countWhite;
    }
  }
  
  ll ans = 0;
  REP(i, r){
    REP(j, c){
      if(minMap[i][j] < k || j-(k-1) < 0 || j+(k-1) >= c)
        continue;
      bool sysflag = true;
      for(ll p = 1; p <=k-1; p++){
        if(minMap[i][j-p] < k-p || minMap[i][j+p] < k-p){
          sysflag = false;
          break;
        }
      }
      if(sysflag)
        ans++;
    }
  }

  /*REP(i, r){
    REP(j, c)
      cout << minMap[i][j] << ' ';
    cout << endl;
  }*/
  cout << ans << "\n";

          

  
  
}
