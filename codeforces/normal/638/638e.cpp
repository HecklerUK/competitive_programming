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
  ll suma=0;
  ll sumb=0;

  vll a(n),b(n);
  REP(i,n)
    cin>>a[i]>>b[i];

  REP(i,n)suma+=a[i];
  REP(i,n)sumb+=b[i];
  ll ans=suma/k+sumb/k;
  if(suma%k+sumb%k<k){
    cout<<ans<<endl;
    return 0;
  }

  bool dp[n+1][k];
  REP(i,n+1)REP(j,k)dp[i][j]=false;
  dp[0][0]=true;

  REP(i,n){
    REP(j,k){
      if(!dp[i][j])
        continue;
      dp[i+1][j]=dp[i][j];
      for(ll r=0; r<=min(a[i],k-1); r++){
        ll remind=k-r;
        if(remind<=b[i])
          dp[i+1][(j+r)%k]=dp[i][j];
      }
    }
  }


  bool flag=false;
  for(ll r=0; r<=suma%k; r++){
    if(k-r<=sumb%k)
      flag=flag || dp[n][r];
  }

  if(flag)
    ans++;

  cout<<ans<<endl;
}

