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

  ll n,m,x,y;
  cin>>n>>m>>x>>y;
  x--;
  y--;
  vll a(m),b(m),t(m),k(m);
  REP(i,m)cin>>a[i]>>b[i]>>t[i]>>k[i];

  vector<vpl> edge(n);
  REP(i,m){
    a[i]--;
    b[i]--;
    edge[a[i]].push_back(pii(b[i],i));
    edge[b[i]].push_back(pii(a[i],i));
  }

  priority_queue<pii,vector<pii>,greater<pii>> que;
  vll dist(n,LLINF);
  dist[x]=0;
  que.push(pii(0,x));
  while(!que.empty()){
    pii p=que.top();
    ll v=p.SE;
    que.pop();
    if(dist[v]<p.first)
      continue;

    for(auto e:edge[v]){
      ll next=e.FI;
      ll e_num=e.SE;
      ll gg=(dist[v]/k[e_num]+1);

      if(dist[v]%k[e_num]==0)
        gg=dist[v]/k[e_num];

      ll cost=gg*k[e_num]+t[e_num];
      if(dist[next]>cost){
        dist[next]=cost;
        que.push(pii(dist[next],next));
      }
    }

  }


  ll ans=dist[y];
  if(ans==LLINF)
    ans=-1;

  cout<<ans<<endl;

}

