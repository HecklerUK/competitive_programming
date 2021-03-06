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

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

ll n;

void solve(ll x, vll g){
  ll ok=n-1;
  ll ng=-1;

  while(ok-ng>1){
    ll mid=(ok+ng)/2;
    if(gcd(g[mid],x)==1)
      ok=mid;
    else
      ng=mid;
  }

  ll ans=ok+1;
  if(ans==n && gcd(g[ok],x)!=1)
    ans=gcd(g[ok],x);

  cout<<ans<<endl;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll q;
  cin>>n>>q;
  vll a(n),s(q);
  REP(i,n)cin>>a[i];
  REP(i,q)cin>>s[i];

  vll g(n);
  g[0]=a[0];
  REP1(i,n)g[i]=gcd(g[i-1],a[i]);

  REP(i,q)solve(s[i],g);

}

