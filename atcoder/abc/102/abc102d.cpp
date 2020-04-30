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

ll calc(ll a, ll b, ll c, ll d){
  ll mi=a;
  ll ma=a;
  mi = min(mi, b);
  mi = min(mi, c);
  mi = min(mi, d);
  ma = max(ma, b);
  ma = max(ma, c);
  ma = max(ma, d);

  return ma-mi;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  vll a(n);
  REP(i,n)cin>>a[i];

  vll rem(n+1);
  REP(i,n)rem[i+1]=rem[i]+a[i];

  //[0,bd), [bd,n)
  ll ans=LLINF;
  for(ll bd=2; bd<=n-2; bd++){
    ll p,q;
    ll pq = rem[bd];
    ll limpq=pq/2+pq%2;
    auto it = lower_bound(rem.begin(), rem.end(), limpq);
    if(it==rem.begin())
      p=*(it+1);
    else if(it-rem.begin()==bd)
      p=*(it-1);
    else if(abs(pq-2*(*it)) > abs(pq-2*(*(it-1))))
      p=*(it-1);
    else
      p=*it;
    q=pq-p;

    ll rs=rem[n]-rem[bd];
    ll limrs = rs/2+rs%2+rem[bd];
    auto it2 = lower_bound(rem.begin(), rem.end(), limrs);
    ll r,s;
    if(it2==rem.begin()+bd)
      r=*(it2+1)-rem[bd];
    else if(it2==rem.begin()+n)
      r=*(it2-1)-rem[bd];
    else if(abs(rs-2*(*it2-rem[bd])) > abs(rs-2*(*(it2-1)-rem[bd])))
      r=*(it2-1)-rem[bd];
    else
      r=*it2-rem[bd];
    s=rs-r;

    ans = min(ans,calc(p,q,r,s));
  }

  cout<<ans<<endl;
}

