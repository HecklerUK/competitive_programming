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
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dh[2] = {1, 0};
const int dw[2] = {0, 1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll h,w;
  cin>>h>>w;
  vector<string> s(h);
  REP(i,h)cin>>s[i];


  ll dist[h][w];
  REP(i,h)REP(j,w)dist[i][j]=LLINF;
  dist[0][0]=0;
  if(s[0][0]=='#')
    dist[0][0]++;

  deque<pair<pll,ll>> que;
  que.push_back(make_pair(pll(0,0),0));
  while(!que.empty()){
    pair<pll,ll> p=que.front();
    que.pop_front();

    pll point = p.FI;
    ll cnt = p.SE;

    if(cnt>dist[point.SE][point.FI])
      continue;

    REP(i,2){
      if(point.FI+dw[i]>=w || point.SE+dh[i]>=h)
        continue;

      pll np = pll(point.FI+dw[i], point.SE+dh[i]);
      pair<pll,ll> next=make_pair(np, dist[point.SE][point.FI]);
      if(s[np.SE][np.FI]=='#' && s[point.SE][point.FI]=='.')
        next.SE++;

      if(next.SE>=dist[np.SE][np.FI])
        continue;
      dist[np.SE][np.FI] = min(dist[np.SE][np.FI], next.SE);
      que.push_back(next);
    }


  }

  cout<<dist[h-1][w-1]<<endl;
}

