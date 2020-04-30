#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpll;

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

ll memo[3003][3003];
ll n,m;
string s,t;

ll dfs(ll x, ll y){
  if(memo[x][y]>=0)
    return memo[x][y];

  if(x==n || y==m)
    return memo[x][y]=0;

  if(s[x]==t[y])
    return memo[x][y]=dfs(x+1,y+1)+1;

  return memo[x][y]=max(dfs(x+1,y),dfs(x,y+1));
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s >> t;
  n = s.size();
  m = t.size();
  REP(i,3003)REP(j,3003)memo[i][j]=-1;
  dfs(0,0);


  ll i=0;
  ll j=0;
  while(i<n&&j<m){
    if(s[i]==t[j]){
      cout<<s[i];
      i++;
      j++;
    }
    else if(memo[i+1][j]>memo[i][j+1])
      i++;
    else
      j++;
  }
  cout<<endl;

}
