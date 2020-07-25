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

  ll n,q;
  cin>>n>>q;
  vll a(n);
  REP(i,n)cin>>a[i];

  vvll rem(2,vll(n+1));
  vll cum(n+1);
  REP(i,n){
    REP(j,2){
      if(i%2==j)
        rem[j][i+1]+=rem[j][i]+a[i];
      else
        rem[j][i+1]+=rem[j][i];
    }
    cum[i+1]=cum[i]+a[i];
  }
  vll ao=rem[1],ta=rem[0];
  if(n%2==1)
    swap(ao,ta);

  auto checkDist=[&](ll x, ll d){
    ll l=ll(lower_bound(ALL(a),x-d)-a.begin());
    ll r=ll(upper_bound(ALL(a),x+d)-a.begin());

    ll num_a=r-l;
    ll num_t=n-r;
    return num_a<=num_t;

  };
  REP(i,q){
    ll x;
    cin>>x;

    ll ok=0;
    ll ng=1e9;
    while(ng-ok>1){
      ll mid=(ok+ng)/2;
      if(checkDist(x,mid))
        ok=mid;
      else
        ng=mid;
    }
    ll l=ll(lower_bound(ALL(a),x-ok)-a.begin());
    ll r=ll(upper_bound(ALL(a),x+ok)-a.begin());

    cout<<"ok:"<<ok<<" ta:"<<r<<" ao:"<<l<<endl;

    ll L=max(l-1,0LL);
    cout<<cum[n]<<"-"<<cum[r]<<"+"<<cum[L]<<endl;

    ll ans=cum[n]-cum[r]+cum[L];
    cout<<ans<<endl;
  }
}

