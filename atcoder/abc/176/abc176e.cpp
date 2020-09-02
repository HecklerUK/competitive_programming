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

  ll h,w,m;
  cin>>h>>w>>m;
  vll y(m),x(m);
  vpl hnum(h),wnum(w);
  REP(i,h)hnum[i].SE=i;
  REP(i,w)wnum[i].SE=i;
  map<pll,ll> ex;
  REP(i,m){
    cin>>y[i]>>x[i];
    y[i]--; x[i]--;
    ex[pll(x[i],y[i])]=1;
    hnum[y[i]].FI++;
    wnum[x[i]].FI++;
  }

  sort(ALL(hnum),greater<pll>());
  sort(ALL(wnum),greater<pll>());

  ll ans=0;
  ll hmax=hnum[0].FI;
  ll wmax=wnum[0].FI;
  for(auto p:hnum){
    if(p.FI<hmax)
      break;

    ll r=0;
    for(auto q:wnum){
      if(q.FI<wmax)
        break;
      ll res=p.FI+q.FI;
      res-=ex[pll(q.SE,p.SE)];
      if(ex[pll(q.SE,p.SE)]==1){
        if(r==0)
          r++;
        else
          continue;
      }
      if(res<=ans)
        break;
      ans=max(ans,res);
    }
  }

  cout<<ans<<endl;

}

