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
#define REP(i,n) for(ll i=0;i<((ll)n);i++)
#define REP1(i,n) for(ll i=1;i<((ll)n);i++)
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

ll mpow(ll m, ll p){
  ll power = m;
  ll res = 1;
  while(p>0){
    if(p&1)
      res = res*power%MOD;
    power = (power*power)%MOD;
    p /= 2;
  }

  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  vll t(n),a(n);
  REP(i,n)cin>>t[i];
  REP(i,n)cin>>a[i];

  ll lim=0;
  bool flag=true;
  bool ansflag=false;
  REP(i,n){
    if(t[i]==a[i]){
      flag=false;
      lim=t[i];
    }
    if(flag){
      if(t[i]>a[i])
        ansflag=true;
    }
    else{
      if(t[i]<a[i])
        ansflag=true;
    }
  }
  REP(i,n){
    if(t[i]>lim || a[i]>lim)
      ansflag=true;
  }
  if(ansflag){
    cout<<0<<endl;
    return 0;
  }


  ll l=n-1,r=0;
  REP(i,n){
    if(t[i]==a[i]){
      l=min(l,i);
      r=max(r,i);
    }
  }

  ll ptl=1;
  for(ll i=1; i<=l; i++){
    if(t[i-1]==t[i])
      ptl=ptl*t[i]%MOD;
  }

  ll ptr=1;
  for(ll i=n-2; i>=r; i--){
    if(a[i+1]==a[i])
      ptr=ptr*a[i]%MOD;
  }

  ll ans=ptl*ptr%MOD;
  ans = ans*mpow(lim,max(r-l-1,0LL))%MOD;
  cout<<ans<<endl;

}

