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
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,q;
  cin>>n>>q;
  vll s(n),t(n),x(n);
  REP(i,n)cin>>s[i]>>t[i]>>x[i];

  vll d(q);
  REP(i,q)cin>>d[i];

  //-1:insert
  //0:delete
  //1:ans
  vector<tuple<ll,ll,ll>> v;
  REP(i,n){
    s[i]-=x[i];
    t[i]-=x[i];
    v.push_back(forward_as_tuple(s[i],-1,x[i]));
    v.push_back(forward_as_tuple(t[i],0,x[i]));
  }
  REP(i,q)
    v.push_back(forward_as_tuple(d[i],1,i));

  sort(v.begin(), v.end());

  vll dist(q,-1);
  multiset<ll> se;
  REP(i,v.size()){
    ll l,q,w;
    tie(l,q,w) = v[i];
    if(q==-1)se.insert(w);
    if(q==0)se.erase(se.lower_bound(w));
    if(q==1 && !se.empty())
      dist[w] = *se.begin();
  }

  REP(i,q)
    cout<<dist[i]<<endl;

}
