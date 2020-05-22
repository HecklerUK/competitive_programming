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

  bool same(ll x, ll y) {
    return find(x) == find(y);
  }

  ll size(ll x) {
    return -d[find(x)];
  }
};



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  string s,t;
  cin>>s>>t;

  UnionFind uf(26);
  vll isAlphaS(n);
  vll isAlphaT(n);
  vll exist(26);

  vll value(26,10);

  REP(i,n){
    if(s[i]<'A'||'Z'<s[i])
      continue;
    isAlphaS[i]++;
    exist[s[i]-'A']++;
  }
  REP(i,n){
    if(t[i]<'A'||'Z'<t[i])
      continue;
    isAlphaT[i]++;
    exist[t[i]-'A']++;
  }

  REP(i,n){
    if(isAlphaS[i]*isAlphaT[i]){
      value[uf.find(s[i]-'A')]=min(value[uf.find(s[i]-'A')],value[uf.find(t[i]-'A')]);
      uf.unite(s[i]-'A',t[i]-'A');
      if(i==0&&value[uf.find(s[i]-'A')]==10)
        value[uf.find(s[i]-'A')]--;
    }
    else if(isAlphaS[i])
      value[uf.find(s[i]-'A')]=1;
    else if(isAlphaT[i])
      value[uf.find(t[i]-'A')]=1;
  }


  ll ans=1;
  REP(i,26){
    if(exist[i]&&uf.find(i)==i)
      ans=ans*value[i];
  }
  cout<<ans<<endl;
}

