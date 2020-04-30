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

ll n,d,x,y;
const ll MAX_N=1010;
ld comb[MAX_N][MAX_N];

ld solve(){
  if(x%d!=0 || y%d!=0)
    return 0;
  x=abs(x/d);
  y=abs(y/d);

  ll remind=n-x-y;
  if(remind%2!=0 || x+y>n)
    return 0;

  REP(i,MAX_N)REP(j,MAX_N)comb[i][j]=0;
  comb[0][0]=1;
  REP1(i,MAX_N){
    REP(j,MAX_N){
      comb[i][j]+=0.5*comb[i-1][j];
      if(j!=0)
        comb[i][j]+=0.5*comb[i-1][j-1];
    }
  }

//  REP(i,MAX_N){
//    REP(j,MAX_N)
//      cout<<comb[i][j]<<" ";
//    cout<<endl;
//  }

  ld res=0;
  for(ll r=x; r<=n-y; r+=2){
    ll rem_x=r-x;
    ll rem_y=n-r-y;
//    res+=comb[n][r]*comb[r][x]*comb[rem_x][rem_x/2]
    res+=comb[n][r]*comb[r][rem_x/2]
      *comb[n-r][rem_y/2];
//      *comb[n-r][y]*comb[rem_y][rem_y/2];
  }

  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n>>d>>x>>y;
  cout<<Decimal;
  cout<<solve()<<endl;

}

