#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;

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
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
#define MAX_H 50
#define MAX_W 50

string s[MAX_H];
ll value[MAX_H][MAX_W];
ll h, w;

ll bfs(ll x, ll y){
  queue<pll> que;
  REP(i, h){
    REP(j, w)
      value[j][i] = LLINF;
  }

  que.push(make_pair(x, y));
  value[x][y] = 1;

  while(!que.empty()){
    pll p = que.front();
    que.pop();

    if(p.FI == w-1 && p.SE == h-1)
      break;

    REP(i, 4){
      ll nx = p.FI+dx[i];
      ll ny = p.SE+dy[i];

      if(w <= nx || nx < 0 || h <= ny || ny < 0)
        continue;

      if(value[nx][ny] != LLINF || s[ny][nx] == '#')
        continue;

      que.push(pll(nx, ny));
      value[nx][ny] = value[p.FI][p.SE]+1;
    }
  }

  return value[w-1][h-1];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> h >> w;
  REP(i, h)
    cin >> s[i];

  ll white_cnt = 0;
  REP(i, h){
    REP(j, w){
      if(s[i][j] == '.')
        white_cnt++;
    }
  }

  ll path_value = bfs(0, 0);
  if(path_value == LLINF)
    cout << -1 << endl;
  else
    cout << white_cnt - bfs(0, 0) << endl;


}
