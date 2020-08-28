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

ll MAX_H=1e3;
ll MAX_W=1e3;
vll a(MAX_H*MAX_W,-1);
vector<string> s(MAX_H);

ll h,w;



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>h>>w;
  ll ch,cw,dh,dw;
  cin>>ch>>cw>>dh>>dw;
  ch--;
  cw--;
  dh--;
  dw--;
  REP(i,h)cin>>s[i];


  auto valid=[&](ll x, ll y){
    if(x<0 || w<=x || y<0 || h<=y)
      return false;
    return true;
  };

  vll d(h*w,LLINF);
  deque<vll> que;
  vll v={cw,ch,0};
  que.push_back(v);
  d[ch*w+cw]=0;

  while(!que.empty()){
    ll x=que.front()[0];
    ll y=que.front()[1];
    ll dist=que.front()[2];
    que.pop_front();

    REP(i,4){
      ll nx=x+dx[i];
      ll ny=y+dy[i];
      if(valid(nx,ny) && s[ny][nx]=='.' && d[ny*w+nx]>dist){
        d[ny*w+nx]=dist;
        vll p={nx,ny,dist};
        que.push_front(p);
      }
    }

    for(ll dxx=-2; dxx<=2; dxx++){
      for(ll dyy=-2; dyy<=2; dyy++){
        ll nx=x+dxx;
        ll ny=y+dyy;
        if(valid(nx,ny) && s[ny][nx]=='.' && d[ny*w+nx]>dist+1){
          d[ny*w+nx]=dist+1;
          vll p={nx,ny,dist+1};
          que.push_back(p);
        }
      }
    }
  }

//  REP(i,h){
//    REP(j,w)cout<<d[i*w+j]<<" ";
//    cout<<endl;
//  }

  ll ans=d[dh*w+dw];
  if(ans==LLINF)
    ans=-1;
  cout<<ans<<endl;

}

