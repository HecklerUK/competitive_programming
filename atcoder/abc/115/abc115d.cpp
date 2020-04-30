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
#define MAX_N 51
ll all[MAX_N];
ll patty[MAX_N];


ll solve(ll l, ll e){
  if(e == 0)
    return 0;

  else if(l == 0 && e == 1)
    return 1;

  else if(1 <= e && e <= all[l-1]+1)
    return solve(l-1, e-1);

  else if(e == all[l-1]+2)
    return patty[l-1]+1;

  else if(all[l-1] + 3 <= e && e <= 2*all[l-1] + 2)
    return patty[l-1]+1+solve(l-1, e-(all[l-1] + 2));

  else
    return 2*patty[l-1]+1;



}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, x;
  cin >> n >> x;

  all[0] = 1;
  patty[0] = 1;
  REP1(i, MAX_N){
    all[i] = 3+2*all[i-1];
    patty[i] = 1+2*patty[i-1];
  }


  ll ans = solve(n, x);

  cout << ans << endl;

}
