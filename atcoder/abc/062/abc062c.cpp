#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

// macros
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

// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int mod = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

ll bfs(ll h, ll w){
  ll diff = h*w;
  //atleast 1 length of edge
  REP1(a, w){
    if((w-a) % 2 == 0)
      diff = min(diff, abs((w-a)*h/2 - h*a));
    else{
      ll shorter = min(h*a, h*((w-a-1)/2));
      ll longer = max(h*a, h*((w-a-1)/2+1));
      diff = min(diff, abs(longer - shorter));
    }
  }

  REP1(a, w){
    if(h % 2 == 0)
      diff = min(diff, abs((w-a)*h/2 - h*a));
    else{
      ll shorter = min(h*a, (h-1)/2*(w-a));
      ll longer = max(h*a, ((h-1)/2+1)*(w-a));
      diff = min(diff, abs(longer - shorter));
    }
  }

  return diff;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll h, w;
  cin >> h >> w;

  //cout << bfs(h, w) << endl;
  //cout << bfs(w, h) << endl;
  cout << min(bfs(h, w), bfs(w, h)) << endl;

  
  
}
