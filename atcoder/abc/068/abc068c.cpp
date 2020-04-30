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

#define N_LIM 200000
bool edge[N_LIM][2];
bool visited[N_LIM];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  cin >> n >> m;

  REP(i, n){
    REP(j, 2)
      edge[i][j] = false;
  }

  vector<ll> a(m), b(m);
  REP(i, m){
    cin >> a[i] >> b[i];
    if(a[i] == 1){
      b[i]--;
      edge[b[i]][0] = true;
    }
    else if(b[i] == n){
      a[i]--;
      edge[a[i]][1] = true;
    }
  }

  bool ansflag = false;
  REP(i, n){
    if(edge[i][0] && edge[i][1])
      ansflag = true;
  }

  if(ansflag)
    cout << "POSSIBLE" << endl;
  else
    cout << "IMPOSSIBLE" << endl;
}
