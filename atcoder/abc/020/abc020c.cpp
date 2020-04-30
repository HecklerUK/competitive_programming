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
#define MAX_H 10
#define MAX_W 10

char fieldMap[MAX_H][MAX_W];
ll minDistance[MAX_H][MAX_W];

ll h, w, t;
pll st, go;
ll X;


ll dfs(ll y, ll x, ll now){
  if(minDistance[y][x] < now)
    return inf;

  if(fieldMap[y][x] == 'G'){
    minDistance[y][x] = now+1;
    return 0;
  }
  else if(fieldMap[y][x] == '.')
    now += 1;
  else if(fieldMap[y][x] == '#')
    now += X;

  minDistance[y][x] = now;

  REP(i, 4){
    if(0 <= x+dx[i] && x+dx[i] <= w-1 && 0 <= y+dy[i] && y+dy[i] <= h-1){
      dfs(y+dy[i], x+dx[i], now);
    }
  }

  return 0;

}

ll searchX(ll hi, ll lo){
  if(hi - lo <= 1){
    return lo;
  }

  REP(i, h){
    REP(j, w)
      minDistance[i][j] = linf;
  }
  //cout << hi << ' ' << lo << endl;
  X = (hi + lo)/2;
  dfs(st.FI, st.SE, 0);
  if(minDistance[go.FI][go.SE] > t)
    searchX(X, lo);
  else
    searchX(hi, X);
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> h >> w >> t;

  REP(i, h){
    REP(j, w){
      cin >> fieldMap[i][j];
      if( fieldMap[i][j] == 'S')
        st = make_pair(i, j);
      else if(fieldMap[i][j] == 'G')
        go = make_pair(i, j);
    }
  }

  cout << searchX(t, 0) << endl;


  
  
}
