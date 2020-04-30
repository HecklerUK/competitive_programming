#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpl;

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

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  vll r(n),h(n);
  REP(i,n)cin>>r[i]>>h[i];

  ll rate[100010][3];
  REP(i,100010)REP(j,3)rate[i][j]=0;

  REP(i,n){
    h[i]--;
    rate[r[i]][h[i]]++;
  }

  vll x=r;
  sort(ALL(x));
  REP(i,n){
    auto it=lower_bound(ALL(x),r[i]);
    ll down = it-x.begin();
    it=upper_bound(ALL(x),r[i]);
    ll up = x.end()-it;
    ll eq=0;

    up += rate[r[i]][(h[i]-1+3)%3];
    down += rate[r[i]][(h[i]+1)%3];
    eq += rate[r[i]][h[i]]-1;
    cout<<down<<" "<<up<<" "<<eq<<endl;
  }



}

