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

const ll MAX_H=1500;
const ll MAX_W=1500;
ll field[MAX_H][MAX_W];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll h,w,n,m;
  cin>>h>>w>>n>>m;
  vll a(n),b(n),c(m),d(m);
  REP(i,n)cin>>a[i]>>b[i];
  REP(i,m)cin>>c[i]>>d[i];

  REP(y,h)REP(x,w)field[y][x]=0;

  REP(i,n){
    a[i]--;
    b[i]--;
    field[b[i]][a[i]]=1;
  }
  REP(i,m){
    c[i]--;
    d[i]--;
    field[d[i]][c[i]]=2;
  }

  auto check=[&](ll i, ll j, ll k){
      if(field[j][i]==1)
        k=-1;
      else if(field[j][i]==2)
        k=0;
      else if(field[j][i]==-1)
        ;
      else
        field[j][i]=k;

      return k;
  };

  for(ll y=0; y<h; y++){
    ll d=0;
    for(ll x=0; x<w; x++)
      d=check(x,y,d);
    for(ll x=w-1; x>=0; x--)
      d=check(x,y,d);
  }
  for(ll x=0; x<w; x++){
    ll d=0;
    for(ll y=0; y<h; y++)
      d=check(x,y,d);
    for(ll y=h-1; y>=0; y--)
      d=check(x,y,d);
  }


  ll ans=0;
  REP(y,h){
    REP(x,w){
      if(abs(field[y][x])==1)
        ans++;
    }
  }

  cout<<ans<<endl;
}

