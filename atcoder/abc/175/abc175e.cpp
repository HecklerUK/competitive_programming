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


ll dp[4][3010][3010];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll r,c,k;
  cin>>r>>c>>k;

  vvll field(r, vll(c));
  REP(i,k){
    ll x,y,v;
    cin>>y>>x>>v;
    y--;
    x--;
    field[y][x]=v;
  }

  REP(i,4)REP(j,r)REP(k,c)dp[i][j][k]=0;

  dp[1][0][0]=field[0][0];
  REP(y,r){
    REP(x,c){
      if(x!=c-1){
        dp[1][y][x+1]=max(max(dp[1][y][x+1],dp[1][y][x]), dp[0][y][x]+field[y][x+1]);
        dp[2][y][x+1]=max(max(dp[2][y][x+1],dp[2][y][x]), dp[1][y][x]+field[y][x+1]);
        dp[3][y][x+1]=max(max(dp[3][y][x+1],dp[3][y][x]), dp[2][y][x]+field[y][x+1]);
      }
      ll dd=0;
      dd=max(dd,dp[0][y][x]);
      dd=max(dd,dp[1][y][x]);
      dd=max(dd,dp[2][y][x]);
      dd=max(dd,dp[3][y][x]);
      if(y!=r-1){
        dp[0][y+1][x]=max(dp[0][y+1][x],dd);
        dp[1][y+1][x]=max(dp[0][y+1][x],dd)+field[y+1][x];
      }
    }
  }

  ll ans=0;
  ans=max(ans,dp[0][r-1][c-1]);
  ans=max(ans,dp[1][r-1][c-1]);
  ans=max(ans,dp[2][r-1][c-1]);
  ans=max(ans,dp[3][r-1][c-1]);
  cout<<ans<<endl;

//  REP(y,r){
//    REP(x,c)cout<<dp[0][y][x]<<" ";
//    cout<<endl;
//  }
//    cout<<endl;
//  REP(y,r){
//    REP(x,c)cout<<dp[1][y][x]<<" ";
//    cout<<endl;
//  }
//    cout<<endl;
//  REP(y,r){
//    REP(x,c)cout<<dp[2][y][x]<<" ";
//    cout<<endl;
//  }
//    cout<<endl;
//  REP(y,r){
//    REP(x,c)cout<<dp[3][y][x]<<" ";
//    cout<<endl;
//  }




}

