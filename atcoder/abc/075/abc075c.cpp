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

#define MAX_N 50
int n, m;
bool edge[MAX_N][MAX_N];
bool visited[MAX_N];

bool rf(int v){
  if(visited[v])
    return true;
  
  visited[v] = true;
  REP(i, n){
    if(edge[v][i])
      rf(i);
  }

  REP(i, n){
    //cout << visited[i] << endl;
    if(visited[i] == false)
      return false;
  }

  return true;

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  REP(i, n){
    visited[i] = false;
    REP(j, n)
      edge[i][j] = false;
  }

  vector<int> a(m), b(m);
  REP(i, m){
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    edge[a[i]][b[i]] = true;
    edge[b[i]][a[i]] = true;
  }

  ll ans = 0;
  REP(i, m){
    REP(i, n)
      visited[i] = false;
    edge[a[i]][b[i]] = false;
    edge[b[i]][a[i]] = false;
    if(!rf(0))
      ans++;

    edge[a[i]][b[i]] = true;
    edge[b[i]][a[i]] = true;
  }

  cout << ans << endl;
}
