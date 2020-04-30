#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
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
#define ZERO(a) memset(a,0,sizeof(a))

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

ld dp[310][310][310];
ll n;

ld rec(ll i, ll j, ll k){
  if(i<0 || j<0 || k<0)
    return 0;
  if(i>n || j>n || k>n)
    return 0;

  if(dp[i][j][k]!=-1)
    return dp[i][j][k];
  if(i==0 && j==0 && k==0)
    return dp[i][j][k]=0;

  ld res = 1*(n/ld(i+j+k));
  res += rec(i-1,j,k)*i/ld(i+j+k);
  res += rec(i+1,j-1,k)*j/ld(i+j+k);
  res += rec(i,j+1,k-1)*k/ld(i+j+k);

  return dp[i][j][k] = res;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;
  ll a;
  vll v(3);
  REP(i,n){
    cin>>a;
    a--;
    v[a]++;
  }
  REP(i,310)REP(j,310)REP(k,310)dp[i][j][k]=-1;

  ld ans = rec(v[0],v[1],v[2]);
  cout<<Decimal;
  cout<<ans<<endl;

}


