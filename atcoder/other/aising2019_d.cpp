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


ll N_MAX=1e5+10;
vll a(N_MAX);
vll cum_e(N_MAX),cum(N_MAX);

bool check(ll mid, ll n, ll x){
  ll num=n-mid;
  ll l=mid;
  ll r=l+num/2;

  return abs(a[l]-x)<=abs(a[r]-x);
}

ll calc(ll l){
  if(l<0)
    return 0;
  return cum_e[l+1];
}

ll calc(ll n, ll r){
  return cum[n]-cum[r];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,q;
  cin>>n>>q;
  REP(i,n)cin>>a[i];


  //prep
  REP(i,n)cum[i+1]+=cum[i]+a[i];
  //ex...cum_e[3]=a[2]+a[0]
  REP(i,n)cum_e[i+1]=((i>=1)?cum_e[i-1]:0)+a[i];

  REP(i,q){
    ll x;
    cin>>x;

    ll ok=n-1;
    ll ng=-1;
    while(abs(ng-ok)>1){
      ll mid=(ok+ng)/2;
      if(check(mid,n,x))
        ok=mid;
      else
        ng=mid;
    }
    ll num=n-ok;
    ll l=ok;
    ll r=l+num/2;
    ll ans=calc(l-1-(num%2==1?1:0))+calc(n,r);

    cout<<ans<<endl;
  }

}

