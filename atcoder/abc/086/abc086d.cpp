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
typedef vector<vll> vvll;

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
#define yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define no cout<<"No"<<endl
#define NO cout<<"NO"<<endl
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

  ll n,k;
  cin>>n>>k;
  vll x(n),y(n);
  REP(i,n){
    char c;
    cin>>x[i]>>y[i]>>c;
    if(c=='W')
      x[i]+=k;
    x[i]%=2*k;
    y[i]%=2*k;
  }


  vvll blacks(4*k+1, vll(4*k+1));
  REP(i,n){
    blacks[x[i]+1][y[i]+1]++;
    blacks[x[i]+1][y[i]+2*k+1]++;
    blacks[x[i]+2*k+1][y[i]+1]++;
    blacks[x[i]+2*k+1][y[i]+2*k+1]++;
  }

  REP(i,4*k+1){
    REP(j,4*k)
      blacks[i][j+1]+=blacks[i][j];
  }
  REP(j,4*k+1){
    REP(i,4*k)
      blacks[i+1][j]+=blacks[i][j];
  }

  auto calcPoint=[&](ll a, ll b){
    ll res=blacks[a+k][b+k]-blacks[a+k][b]-blacks[a][b+k]+blacks[a][b];
    return res;
  };


  ll ans=0;
  REP(i,2*k){
    REP(j,2*k)
      ans=max(ans,calcPoint(i,j)+calcPoint(i+k,j+k));
  }

  cout<<ans<<endl;

}

