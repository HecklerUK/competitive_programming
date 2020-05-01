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

const ll MAX_N=102;
ll n;
vld t(MAX_N),v(MAX_N);

ld f(ld x){
  ld res=LLINF;
  ld l=0;

  REP(i,n+2){
    ll r=l+t[i];
    if(x<l)
      res=min(res,v[i]+(l-x));
    if(l<=x && x<r)
      res=min(res,v[i]);
    if(r<=x)
      res=min(res,v[i]+(x-r));

    l+=t[i];
  }

  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;
  t[0]=0;
  REP(i,n)cin>>t[i+1];
  t[n+1]=0;

  v[0]=0;
  REP(i,n)cin>>v[i+1];
  v[n+1]=0;

  ld sum=0;
  REP(i,n+2)sum+=t[i];

  ld ans=0;
  ld pre=f(0);
  for(ld x=0.5; x<=sum; x+=0.5){
    ld now=f(x);
    ld area=(now+pre)*0.5/2;
    ans+=area;
    pre=now;
  }

  cout<<Decimal;
  cout<<ans<<endl;
}

