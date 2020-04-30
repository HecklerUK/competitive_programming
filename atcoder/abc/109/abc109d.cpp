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

  ll h,w;
  cin >> h >> w;
  vector<vll> a(h, vll(w));
  REP(i, h){
    REP(j, w)
      cin >> a[i][j];
  }

  ll cur = 0;
  vector<pair<pll, pll>> ans(h*w);
  REP(i, h){
    REP(j, w-1){
      ll in = i%2==0 ? j : w-1-j;
      ll out = i%2==0 ? j+1 : w-2-j;

      if(a[i][in]%2 ==0)
        continue;
      ans[cur].FI = make_pair(i+1, in+1);
      ans[cur].SE = make_pair(i+1, out+1);
      a[i][out]++;
      cur++;
    }
    ll out = i%2==0 ? w-1 : 0;
    if(i != h-1 && a[i][out]%2 != 0){ 
      ans[cur].FI = make_pair(i+1, out+1);
      ans[cur].SE = make_pair(i+2, out+1);
      a[i+1][out]++;
      cur++;
    }
  }

  cout << cur << endl;
  REP(i, cur){
    cout << ans[i].FI.FI << " " << ans[i].FI.SE << " ";
    cout << ans[i].SE.FI << " " << ans[i].SE.SE << endl;
  }



}
