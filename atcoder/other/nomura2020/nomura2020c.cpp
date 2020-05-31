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

const ll MAX_A=1e14;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  n++;
  vll d(n);
  REP(i,n)cin>>d[i];
  if(1<d[0]){
    cout<<-1<<endl;
    return 0;
  }

  vll lim(n);
  lim[0]=1;
  REP(i,n-1)lim[i+1]=min(2*(lim[i]-d[i]),MAX_A);

  vll v(n);
  v[n-1]=d[n-1];
  ll ans=d[n-1];
  for(ll i=n-1; i>=1; i--){
    ll l=v[i]/2+v[i]%2+d[i-1];
    ll r=v[i]+d[i-1];
    if(lim[i-1]<l){
      cout<<-1<<endl;
      return 0;
    }
    v[i-1]=min(lim[i-1],r);
    ans+=v[i-1];
  }
  cout<<ans<<endl;
}


