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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  vll a(n);
  REP(i,n)cin>>a[i];

  ll maxa=a[0];
  ll mina=a[0];
  set<ll> s;
  map<ll,ll> m;
  REP(i,n){
    maxa=max(maxa,a[i]);
    mina=min(mina,a[i]);
    s.insert(a[i]);
    m[a[i]]+=1;
  }

  bool ans;
  ll diff=maxa-mina;
  if(diff==0){
    if(a[0]==n-1 || 2*a[0]<=n)
      ans=true;
    else
      ans=false;
  }
  else if(diff==1){
    ll x=m[mina];
    if(2*(maxa-x)<=m[maxa] && maxa-x>0)
      ans=true;
    else
      ans=false;
  }
  else
    ans=false;

  if(ans)
    yes;
  else
    no;
}

