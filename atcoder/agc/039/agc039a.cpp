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

  ll k;
  cin >> k;
  
  ll cnt = 0;
  ll f_cnt = 0;
  ll now = 1;
  ll n = s.size();
  ll f_flag = true;
  REP1(i, n){
    if(s[i-1] != s[i]){
      if(f_flag){
        f_cnt = now / 2;
        f_flag = false;
      }
      else
        cnt += now / 2;
      now = 1;
    }
    else
      now++;
  }

  ll e_now = now;
  ll e_cnt = 0;
  bool sysflag = false;
  REP(i, n){
    if(s[i] != s[n-1]){
      sysflag = true;
      break;
    }
    else
      e_now++;
  }

  ll ans;
  if(s[0] != s[n-1])
    ans = k*(f_cnt+cnt+e_now/2);
  else if(sysflag)
    ans = k*cnt + (k-1)*(e_now/2) + now / 2 + f_cnt;
  else
    ans = n * k / 2;
  cout << ans << endl;


  
  
}
