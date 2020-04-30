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

  ll n,m,s;
  cin>>n>>m>>s;
  vector<vvll> edge(n);
  REP(i,m){
    ll u,v,a,b;
    cin>>u>>v>>a>>b;
    u--;
    v--;
    edge[u].push_back({v,a,b});
    edge[v].push_back({u,a,b});
  }

  vll c(n),d(n);
  REP(i,n)cin>>c[i]>>d[i];


  s=min(s,n*50);
  priority_queue<pll,vpl,greater<pll>> que;
  que.push(pll(0,s));
  vvll ds(n,vll(n*50+1,LLINF));
  ds[0][s]=0;

  while(!que.empty()){
    pll p=que.top();
    que.pop();
    ll t=p.FI;
    ll v=p.SE/10000;
    ll m=p.SE%10000;

    if(ds[v][m]<t)
      continue;

    if(m+c[v]<=n*50 && t+d[v]<ds[v][m+c[v]]){
      ll nt=t+d[v];
      ll nv=v;
      ll nm=m+c[v];
      pll np;
      np.FI=nt;
      np.SE=nv*10000+nm;

      ds[nv][nm]=nt;
      que.push(np);
    }

    for(auto e:edge[v]){
      ll nv=e[0];
      ll nm=m-e[1];
      ll nt=t+e[2];
      if(nt<ds[nv][nm] && 0<=nm){
        ds[nv][nm]=nt;
        pll np;
        np.FI=nt;
        np.SE=nv*10000+nm;
        que.push(np);
      }
    }
  }


  REP1(i,n){
    ll ans=LLINF;
    REP(j,ds[i].size())ans=min(ans,ds[i][j]);
    cout<<ans<<endl;
  }


}

