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

  ll n;
  cin>>n;
  vll a(3),b(3);
  REP(i,3)cin>>a[i];
  REP(i,3)cin>>b[i];

  vll dp(5010);
  for(ll i=0; i<5010; i++){
    vll t(3);
    REP(j,3){
      if(i>=a[j])
        t[j]=dp[i-a[j]]+b[j];
    }
    dp[i]=max({t[0],t[1],t[2],i});
  }

  vll dp2(5010*5010);
  for(ll i=0; i<5010*5010; i++){
    vll t(3);
    REP(j,3){
      if(i>=b[j])
        t[j]=dp2[i-b[j]]+a[j];
    }
    dp2[i]=max({t[0],t[1],t[2],i});
  }

  ll tmp=dp[n];
  ll ans=dp2[tmp];
  cout<<ans<<endl;

}

