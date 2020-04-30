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

ll n;

ll dfs(ll num, ll sum, vector<ll> v){
  ll now = 10 * sum;
  now += num;
  if(now == sum)
    return inf;

  if(now >= n){
    return now;
  }

  ll ans = dfs(v[0], now, v);
  REP1(i, v.size())
    ans = min(ans, dfs(v[i], now, v));
  
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll k;
  cin >> n >> k;

  vector<ll> d(n);
  REP(i, n)
    cin >> d[i];

  vector<ll> likenum;
  REP(i, 10){
    bool sflag = true;
    REP(j, k){
      if(i == d[j])
        sflag = false;
    }
    if(sflag){
      //cout << i << endl;
      likenum.push_back(i);
    }
  }

  ll ans = 9999999;
  REP(i, likenum.size())
    ans = min(ans, dfs(likenum[i], 0, likenum));
  
  cout << ans << endl;
}
