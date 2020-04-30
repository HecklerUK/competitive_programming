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

struct UnionFind {
  vll d;
  UnionFind(ll n=0): d(n,-1) {}
  ll find(ll x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(ll x, ll y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(ll x, ll y) { return find(x) == find(y);}
  ll size(ll x) { return -d[find(x)];}
};


const ll MAX_H=400;
const ll MAX_W=400;
bool visited[MAX_H][MAX_W];
vector<string> s(MAX_H);
ll h,w;
void dfs(ll y, ll x, ll root, UnionFind& uf, char pre){
  if(visited[y][x])
    return;

  char now=s[y][x];
  if(pre==now)
    return;

  visited[y][x]=true;

  ll num=y*w+x;
  uf.unite(root,num);
  REP(i,4){
    if(x+dx[i]<0 || w<=x+dx[i] || y+dy[i]<0 || h<=y+dy[i])
      continue;
    if(s[y+dy[i]][x+dx[i]]!=now)
      dfs(y+dy[i],x+dx[i],root,uf,now);
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>h>>w;
  REP(i,h)cin>>s[i];

  REP(i,h)REP(j,w)visited[i][j]=false;


  UnionFind uf(h*w);
  REP(i,h){
    REP(j,w){
      ll num=i*w+j;
      char pre='a';
      dfs(i,j,num,uf,pre);
    }
  }

  ll ans=0;
  vpl p(h*w);
  REP(i,h){
    REP(j,w){
      ll num=w*i+j;
      ll par=uf.find(num);
      if(s[i][j]=='#')
        p[par].FI++;
      else
        p[par].SE++;
    }
  }

  REP(i,h*w)ans+=p[i].FI*p[i].SE;

  cout<<ans<<endl;

}

