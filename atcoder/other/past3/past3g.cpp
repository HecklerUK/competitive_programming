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
const int dx[6] = {-1, 0, 1, 0,1,-1};
const int dy[6] = {0, -1, 0, 1,1,1};

const ll xlim=1000;
const ll ylim=1000;
ll preve[2*xlim][2*ylim];
ll f[2*xlim][2*ylim];


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,x,y;
  cin>>n>>x>>y;

  REP(i,2*xlim)REP(j,2*ylim)preve[i][j]=0;

  REP(i,n){
    ll px,py;
    cin>>px>>py;
    preve[px+xlim][py+ylim]=1;
  }

  REP(i,2*xlim)REP(j,2*ylim)f[i][j]=LLINF;
  f[xlim+0][ylim+0]=0;

  queue<pair<ll,pll>> que;
  que.push(make_pair(0,pll(0,0)));
  while(!que.empty()){
    pair<ll,pll> p=que.front();
    que.pop();
    ll dist=p.FI;
    ll px=p.SE.FI;
    ll py=p.SE.SE;
    if(f[xlim+px][ylim+py]<dist)
      continue;


    REP(i,6){
      ll nx=px+dx[i];
      ll ny=py+dy[i];
      if(xlim+nx<0 || 2*xlim<=xlim+nx || ylim+ny<0 || 2*ylim<=ylim+ny)
        continue;
      if(preve[xlim+nx][ylim+ny]==1)
        continue;
      if(f[xlim+nx][ylim+ny]<=dist+1)
        continue;

      f[xlim+nx][ylim+ny]=dist+1;
      que.push(make_pair(dist+1,pll(nx,ny)));
    }
  }

  if(f[xlim+x][ylim+y]==LLINF)
    cout<<-1<<endl;
  else
    cout<<f[xlim+x][ylim+y]<<endl;
}

