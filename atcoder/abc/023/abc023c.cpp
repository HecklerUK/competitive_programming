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
  
  ll R, C, k, n;
  cin >> R >> C >> k >> n;
  
  vector<ll> r(n), c(n);
  REP(i, n)
    cin >> r[i] >> c[i];
  
  map<ll, ll> r_map, c_map;
  REP(i, n){
    r_map[r[i]-1]++;
    c_map[c[i]-1]++;
  }
  
  map<ll, ll> band_count_r_map, band_count_c_map;
  REP(i, R)
	  band_count_r_map[r_map[i]]++;
  REP(i, C)
	  band_count_c_map[c_map[i]]++;
  
  ll ans = 0;
  REP(i, k+1)
    ans += band_count_r_map[i] * band_count_c_map[k-i];
  
  REP(i, n){
    if(r_map[r[i]-1]+c_map[c[i]-1] == k+1)
      ans++;
    if(r_map[r[i]-1]+c_map[c[i]-1] == k)
      ans--;
  }
  cout << ans << endl;
 
}
