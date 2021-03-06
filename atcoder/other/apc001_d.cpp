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


ll forest_size=0;
vll a(1e5);
vll visited(1e5);
vvll edge(1e5);

void la(ll i, vll& v){
  if(visited[i])
    return;

  visited[i]=1;
  v.push_back(a[i]);
  for(auto e:edge[i]){
    la(e,v);
  }

  return;
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,m;
  cin>>n>>m;
  REP(i,n)cin>>a[i];
  vll x(m),y(m);
  REP(i,m)cin>>x[i]>>y[i];

  REP(i,m){
    edge[x[i]].push_back(y[i]);
    edge[y[i]].push_back(x[i]);
  }

  ll cost=0;
  vll p;
  REP(i,n){
    if(visited[i])
      continue;

    vll v;
    la(i,v);
    sort(ALL(v));

    cost+=v[0];
    for(ll i=1; i<ll(v.size()); i++)
      p.push_back(v[i]);

    forest_size++;
  }

  sort(ALL(p));

  if(n<(forest_size-1)*2){
    cout<<"Impossible"<<endl;
    return 0;
  }
  if(forest_size==1){
    cout<<0<<endl;
    return 0;
  }

  REP(i,forest_size-2)
    cost+=p[i];


  cout<<cost<<endl;



}

