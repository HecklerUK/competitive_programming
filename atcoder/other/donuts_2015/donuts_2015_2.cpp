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

ll n,m;
ll a[16],b[50],c[50],l[50][16];

ll f(vll& indexes){
  ll base=0;

  REP(i,n){
    if(lower_bound(ALL(indexes),i)!=upper_bound(ALL(indexes),i))
      base+=a[i];
  }

  ll bonus=0;
  REP(i,m){
    ll cnt=0;
    REP(j,c[i]){
      if(lower_bound(ALL(indexes),l[i][j])!=upper_bound(ALL(indexes),l[i][j]))
        cnt++;
    }

    if(cnt>=3)
      bonus+=b[i];
  }

  return base+bonus;
}

ll dfs_pick(vll& indexes, int s, int rest) {
  if (rest == 0) {
    return f(indexes);
  } else {
    if (s < 0)
      return 0;

    ll res=0;
    res=max(res,dfs_pick(indexes, s - 1, rest));
    indexes[rest - 1] = s;
    res=max(res,dfs_pick(indexes, s - 1, rest - 1));
    return res;
  }
}

ll run(ll n, ll k) {
  vll indexes(k);
  return dfs_pick(indexes, n - 1, k);
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n>>m;
  REP(i,n)cin>>a[i];
  REP(i,m){
    cin>>b[i]>>c[i];
    REP(j,c[i]){
      cin>>l[i][j];
      l[i][j]--;
    }
  }

  ll ans=run(n,9);
  cout<<ans<<endl;
}

