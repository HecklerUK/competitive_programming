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

  ll n;
  cin>>n;

  vpl xy(n);
  REP(i,n)cin>>xy[i].SE>>xy[i].FI;

  sort(ALL(xy));
  vpl y_mx,y_px;
  REP(i,n){
    y_mx.push_back(pll(xy[i].FI-xy[i].SE,i));
    y_px.push_back(pll(xy[i].FI+xy[i].SE,i));
  }
  sort(ALL(y_mx),greater<pll>());
  sort(ALL(y_px),greater<pll>());

  vll idm(n),idp(n);
  REP(i,n){
    idm[i]=y_mx[i].SE;
    idp[i]=y_px[i].SE;
  }

  vll tablem(n,-1);
  vll tablep(n,-1);
  ll nowm=0;
  ll nowp=0;
  REP(i,n){
    if(nowm<idm[i]){
      for(ll j=nowm; j<idm[i]; j++){
        tablem[j]=idm[i];
      }
      nowm=idm[i];
    }
    if(nowp<idp[i]){
      for(ll j=nowp; j<idp[i]; j++){
        tablep[j]=idp[i];
      }
      nowp=idp[i];
    }
  }

  ll ans=0;
  REP(i,n){
    ll dm=-LLINF;
    ll dp=-LLINF;

    if(i!=n-1){
      ll im=tablem[i];
      dm=abs(xy[i].FI-xy[im].FI)+abs(xy[i].SE-xy[im].SE);
    }

    if(i!=n-1){
      ll ip=tablep[i];
      dp=abs(xy[i].FI-xy[ip].FI)+abs(xy[i].SE-xy[ip].SE);
    }

    ans=max(ans,max(dm,dp));
  }

  cout<<ans<<endl;

}

