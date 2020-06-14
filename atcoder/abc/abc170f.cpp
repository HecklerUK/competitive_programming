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

  ll h,w,k;
  cin>>h>>w>>k;
  vll x(2),y(2);
  REP(i,2){
    cin>>y[i]>>x[i];
    x[i]--;
    y[i]--;
  }

  vector<string> f(h);
  REP(i,h)cin>>f[i];

  queue<vll> que;
  que.push({0,x[0],y[0]});
  vvll dist(w,vll(h,LLINF));
  dist[x[0]][y[0]]=0;
  while(!que.empty()){
    vll v=que.front();
    que.pop();
    ll d=v[0];
    pll now=pll(v[1],v[2]);
    if(dist[now.FI][now.SE]<v[0])
      continue;

    for(ll dx=1; dx<=k; dx++){
      if(now.FI+dx<0 || w-1<now.FI+dx)
        break;
      if(f[now.SE][now.FI+dx]=='@')
        break;

      ll nd=d+1;
      if(nd<=dist[now.FI+dx][now.SE]){
        if(nd<dist[now.FI+dx][now.SE]){
          dist[now.FI+dx][now.SE]=nd;
          que.push({nd,now.FI+dx,now.SE});
        }
      }
      else
        break;
    }
    for(ll dx=-1; dx>=-k; dx--){
      if(now.FI+dx<0 || w-1<now.FI+dx)
        break;
      if(f[now.SE][now.FI+dx]=='@')
        break;

      ll nd=d+1;
      if(nd<=dist[now.FI+dx][now.SE]){
        if(nd<dist[now.FI+dx][now.SE]){
          dist[now.FI+dx][now.SE]=nd;
          que.push({nd,now.FI+dx,now.SE});
        }
      }
      else
        break;

    }

    for(ll dy=1; dy<=k; dy++){
      if(now.SE+dy<0 || h-1<now.SE+dy)
        break;
      if(f[now.SE+dy][now.FI]=='@')
        break;

      ll nd=d+1;
      if(nd<=dist[now.FI][now.SE+dy]){
        if(nd<dist[now.FI][now.SE+dy]){
          dist[now.FI][now.SE+dy]=nd;
          que.push({nd,now.FI,now.SE+dy});
        }
      }
      else
        break;

    }

    for(ll dy=-1; dy>=-k; dy--){
      if(now.SE+dy<0 || h-1<now.SE+dy)
        break;
      if(f[now.SE+dy][now.FI]=='@')
        break;

      ll nd=d+1;
      if(nd<=dist[now.FI][now.SE+dy]){
        if(nd<dist[now.FI][now.SE+dy]){
          dist[now.FI][now.SE+dy]=nd;
          que.push({nd,now.FI,now.SE+dy});
        }
      }
      else
        break;

    }
  }

//  REP(i,h){
//    REP(j,w)cout<<dist[j][i]<<"\t";
//    cout<<endl;
//  }


  ll ans=dist[x[1]][y[1]];
  if(ans==LLINF)
    cout<<-1<<endl;
  else
    cout<<ans<<endl;

}

