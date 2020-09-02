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

  ll t;
  cin>>t;
  REP(i,t){
    ll n,m;
    cin>>n>>m;
    vpl a(m),b(m);
    vll c(m);
    REP(j,m){
      cin>>a[j].FI>>b[j].FI;
      a[j].SE=j;
      b[j].SE=j;
      c[j]=a[j].FI;
    }

    sort(ALL(a),greater<pll>());
    sort(ALL(b),greater<pll>());
    sort(ALL(c));

    vll taken(m);
    ll cnt=0;
    ll ans=0;
    vll remind(m+1);
    REP(j,m){
      if(a[j]<b[0])
        break;
      ans+=a[j].FI;
      taken[a[j].SE]=1;
      remind[j+1]+=remind[j]+a[j].SE;
      cnt++;
    }

    map<ll,ll> amap;
    REP(j,m)amap[a[j].SE]=a[j].FI;

    ll rest=0;
  //  cout<<"cnt:"<<cnt<<endl;
    REP(j,m){
      auto it=lower_bound(ALL(c),b[j].FI);
      ll diff=remind[m-cnt]-remind[ll(it-c.begin())];
      ll diffcnt=m-ll(it-c.begin())-cnt;
  //    cout<<"b:"<<b[j].FI;
  //    cout<<" diff:"<<diff;
  //    cout<<" diffcnt:"<<diffcnt<<endl;

      if(taken[b[j].SE] || b[j].FI<=amap[b[j].SE])
        rest=max(rest,b[j].FI*(n-cnt-diffcnt)+diff);

      else
        rest=max(rest,b[j].FI*(n-cnt-1-diffcnt)+amap[b[j].SE]+diff);
    }

    cout<<ans+rest<<endl;
  }
}

