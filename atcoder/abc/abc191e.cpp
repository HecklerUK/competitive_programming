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

  ll n,m;
  cin>>n>>m;
  vll a(m),b(m),c(m);
  REP(i,m)cin>>a[i]>>b[i]>>c[i];

  vector<vpl> v(n);
  REP(i,m){
    a[i]--;
    b[i]--;
    if(a[i]==b[i])
      continue;

    v[a[i]].push_back(pll(c[i],b[i]));
  }

  vvll dist(n,vll(n,LLINF));
  REP(i,n){
    ll st=i;
    priority_queue<pll,vpl,greater<pll>> que;
    for(auto e:v[st]){
      ll cost=e.FI;
      ll next=e.SE;
      if(cost<dist[st][next]){
        que.push(pll(cost,next));
        dist[st][next]=cost;
      }
    }

    while(!que.empty()){
      pll p=que.top();
      que.pop();
      ll now=p.SE;
      if(dist[st][now]<p.FI)
        continue;

      for(auto e:v[now]){
        ll cost=e.FI;
        ll next=e.SE;
        if(dist[st][now]+cost<dist[st][next]){
          dist[st][next]=dist[st][now]+cost;
          que.push(pll(dist[st][next],next));
        }
      }

    }
  }

  REP(i,m){
    if(c[i]<dist[a[i]][b[i]])
      dist[a[i]][b[i]]=c[i];
  }

  REP(i,n){
    if(dist[i][i]==LLINF)
      cout<<-1<<endl;
    else
      cout<<dist[i][i]<<endl;
  }
}

