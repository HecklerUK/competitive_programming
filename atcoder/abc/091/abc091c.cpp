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

ll pair_search(pll match, vector<pll> r){
  pll maxi;
  //r_y, index
  maxi = make_pair(-1, -1);
  REP(i, r.size()){
    if(r[i].FI < match.FI && r[i].SE < match.SE && maxi.FI < r[i].SE){
      maxi.FI = r[i].SE;
      maxi.SE = i;
    }
  }
  //cout << maxi.FI << " " << maxi.SE << endl;
  return maxi.SE;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  
  vector<pll> r(n), b(n);
  REP(i, n)
    cin >> r[i].FI >> r[i].SE;

  REP(i, n)
    cin >> b[i].FI >> b[i].SE;

  sort(r.begin(), r.end());
  sort(b.begin(), b.end());

  ll count = 0;
  REP(i, n){
    ll posi = pair_search(b[i], r);
    if(posi == -1)
      continue;
    else{
      count++;
      r.erase(r.begin() + posi);
    }
  }
  
  cout << count << "\n";  
}
