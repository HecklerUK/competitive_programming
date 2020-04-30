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

map<ll,ll> m;
ll calc(ll bit){
  bit+=(1<<24);

  ll res=24;
  ll p=0;
  REP1(i,25){
    if((bit>>i)&1){
      res=min(res,i-p);
      p=i;
    }
  }

  return res;
}


ll dfs(ll cur, ll bit){
  if(cur==13)
    return calc(bit);

  if(cur==0){
    if(m[cur]>=1)
      return 0;
    bit+=1;
    return dfs(cur+1,bit);
  }


  if(m[cur]>=3)
    return 0;

  if(m[cur]==2){
    if(cur==12)
      return 0;
    return dfs(cur+1,bit+(1<<cur)+(1<<(24-cur)) );
  }

  if(m[cur]==1)
    return max(dfs(cur+1,bit+(1<<cur)), dfs(cur+1,bit+(1<<(24-cur) )));

  return dfs(cur+1,bit);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  vll d(n);
  REP(i,n)cin>>d[i];

  REP(i,n)m[d[i]]+=1;

  ll ans=dfs(0,0);
  cout<<ans<<endl;

}

