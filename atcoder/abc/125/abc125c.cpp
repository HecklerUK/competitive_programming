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

ll gcd(ll a, ll b){
  if(b==0)
    return a;
  if(a<b)
    return gcd(b,a);

  return gcd(b,a%b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin>>n;
  vll a(n);
  REP(i,n)cin>>a[i];

  vll gcd_fro(n), gcd_back(n);
  REP(i,n){
    if(i==0)
      gcd_fro[i]=a[i];
    else
      gcd_fro[i]=gcd(a[i],gcd_fro[i-1]);
  }

  for(ll i=n-1; i>=0; i--){
    if(i==n-1)
      gcd_back[i]=a[i];
    else
      gcd_back[i]=gcd(a[i],gcd_back[i+1]);
  }

  ll ans=1;
  REP(i,n){
    ll l=1,r=1;
    if(i!=0)
      l=gcd_fro[i-1];
    if(i!=n-1)
      r=gcd_back[i+1];

    ll now;
    if(i!=0 && i!=n-1)
     now=gcd(l,r);
    else
      now=l*r;
    ans=max(ans,now);
  }

  cout<<ans<<endl;
}

