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
const ll LLMAX=9223372036854775807;

map<ll,ll> m;

ll dfs(ll value, ll a, ll b, ll c, ll d){
  if(m[value]!=0)
    return m[value];
  if(value==0)
    return 0;
  if(value==1)
    return d;

  ll res=LLINF;
  if(value<res/d)
    res=d*value;

  ll l2=value/2*2;
  ll r2=(value+1)/2*2;
  ll l3=value/3*3;
  ll r3=(value+2)/3*3;
  ll l5=value/5*5;
  ll r5=(value+4)/5*5;
  res=min(res,dfs(l2/2,a,b,c,d)+(value-l2)*d+a);
  res=min(res,dfs(r2/2,a,b,c,d)+(r2-value)*d+a);
  res=min(res,dfs(l3/3,a,b,c,d)+(value-l3)*d+b);
  res=min(res,dfs(r3/3,a,b,c,d)+(r3-value)*d+b);
  res=min(res,dfs(l5/5,a,b,c,d)+(value-l5)*d+c);
  res=min(res,dfs(r5/5,a,b,c,d)+(r5-value)*d+c);

  m[value]=res;
  return res;

}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;
  vll n(t),a(t),b(t),c(t),d(t);
  REP(i,t)cin>>n[i]>>a[i]>>b[i]>>c[i]>>d[i];

  REP(i,t){
    m.clear();
    ll ans=dfs(n[i],a[i],b[i],c[i],d[i]);
    cout<<ans<<endl;
  }
}

