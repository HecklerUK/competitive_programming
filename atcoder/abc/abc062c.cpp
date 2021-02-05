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

ll solve(ll x, ll y, ll z){
  ll maxs=0;
  ll mins=LLINF;
  maxs=max(maxs,x);
  maxs=max(maxs,y);
  maxs=max(maxs,z);

  mins=min(mins,x);
  mins=min(mins,y);
  mins=min(mins,z);

  return maxs-mins;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll H,W;
  cin>>H>>W;

  ll ans=LLINF;
  for(ll hx=1; hx<=H; hx++){
    ll x=hx*W;

    ll h=H-hx;
    ll y=(W-W/2)*h;
    ll z=W/2*h;
    ans=min(ans,solve(x,y,z));

    y=(h-h/2)*W;
    z=h/2*W;
    ans=min(ans,solve(x,y,z));
  }

  for(ll wx=1; wx<=W; wx++){
    ll x=wx*H;

    ll w=W-wx;
    ll y=(H-H/2)*w;
    ll z=H/2*w;
    ans=min(ans,solve(x,y,z));

    y=(w-w/2)*H;
    z=w/2*H;
    ans=min(ans,solve(x,y,z));
  }

  cout<<ans<<endl;
}

