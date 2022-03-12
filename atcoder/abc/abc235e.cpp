#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define sz(a) (int)(a).size()
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<(n);i++)
#define drep(i,n) for(int i=(n)-1;i>=0;i--)
#define srep(i,n,s) for(int i=(s);i<(n);i++)
#define dsrep(i,n,s) for(int i=(n)-1;i>=(s);i--)
#define pb push_back
#define eb emplace_back
#define mp(a,b) make_pair(a,b)
#define getp(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define no cout<<"No"<<endl
#define NO cout<<"NO"<<endl
#define Decimal fixed<<setprecision(20)

using namespace std;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using pc = pair<T, T>;
template<typename T> using pq = priority_queue<T, vc<T>, greater<T>>;
using ll = long long;
using ld = long double;
using T3 = tuple<ll,ll,ll>;
using vll = vc<ll>;
using vld = vc<ld>;
using pll = pc<ll>;
using pld = pc<ld>;
using vpl = vc<pll>;
using vs = vc<string>;
using vvll = vv<ll>;
using vt = vc<T3>;
using plpll = pair<ll,pll>;


template<typename T>istream& operator>>(istream&i,vc<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vc<T>&v,const string& d=""){stringstream s;rep(i,sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<typename T>ostream& operator<<(ostream&o,const vc<T>&v){if(sz(v))o<<join(v," ");return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const vc<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}
// template<typename T>void uni(vc<T>& a){sort(all(a));a.erase(unique(rng(a)),a.end());}
template<typename T>void uni(T& a){sort(all(a));a.erase(unique(all(a)),a.end());}

const int INF = 1001001001;
const ll LINF = 1LL << 50;
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

  ll n,m,q;
  cin>>n>>m>>q;

  vector<plpll> edge(m+q);
  rep(i,m){
    ll a,b,c;
    cin>>a>>b>>c;
    a--;
    b--;
    if(a>b)
      swap(a,b);
    edge[i].fi=c;
    edge[i].se=pll(a,b);
  }

  map<plpll,ll> query;
  vector<plpll> q_edge(q);
  rep(i,q){
    ll u,v,w;
    cin>>u>>v>>w;
    u--;
    v--;
    if(u>v)
      swap(u,v);
    query[plpll(w,pll(u,v))]=1;
    edge[m+i].fi=w;
    edge[m+i].se=pll(u,v);
    q_edge[i]=edge[m+i];
  }

  sort(all(edge));
  UnionFind uf(n);
  vll ans(q);
  rep(i,m+q){
    ll cost=edge[i].fi;
    ll a=edge[i].se.fi;
    ll b=edge[i].se.se;
    if(query[edge[i]]==0){
      if(!uf.same(a,b))
        uf.unite(a,b);
    }
    else{
      if(uf.same(a,b))
        query[edge[i]]=1;
      else
        query[edge[i]]=2;
    }
  }


  rep(i,q){
    if(query[q_edge[i]]==2)
      yes;
    if(query[q_edge[i]]==1)
      no;
  }
}

