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

  ll n,k;
  cin>>n>>k;
  vll p(n),c(n);
  REP(i,n)cin>>p[i];
  REP(i,n)p[i]--;

  REP(i,n)cin>>c[i];


  ll ans=-LLINF;
  REP(i,n){
    //detect cycle
    vll v;
    ll all = 0;
    ll now = i;

    while(true){
      now=p[now];
      all+=c[now];
      v.push_back(now);
      if(now==i)
        break;
    }

    ll sum = 0;
    ll sz=v.size();
    for (ll i = 0; i < sz; i++)
    {
      sum += c[v[i]];
      ll g=max(all, 0LL);
      if(i+1<=k)
      ans = max(ans, sum + (k - 1 - i) / sz * g);
    }
  }

  cout<<ans<<endl;
}

