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

  ll n,m;
  cin >> n >> m;

  ll a[n][m], b[n][m];

  REP(i, n){
    string s;
    cin >> s;
    REP(j, m){
      b[i][j] = s[j]-'0';
      a[i][j] = 0;
    }
  }


  REP(i, n){
    REP(j, m){
      ll tmp = 0;

      if(j-1>=0)
        tmp += a[i][j-1];
      if(j+1<m)
        tmp += a[i][j+1];
      if(i-1>=0)
        tmp += a[i-1][j];

      if(i+1<n)
        a[i+1][j] = b[i][j]-tmp;
    }
  }

  REP(i, n){
    REP(j, m)
      cout << a[i][j];
    cout << endl;
  }

}
