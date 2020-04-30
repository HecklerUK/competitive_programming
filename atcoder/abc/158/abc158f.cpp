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
const int MOD = 998244353;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};


const ll MAX_N=300010;

ll n,dat[2*MAX_N-1];
void init(int n_){
  n=1;
  while(n<n_)
    n*=2;
  for (int i = 0; i < 2*n-1; i++) {
    dat[i]=-LLINF;
  }
}

void update(ll k, ll a){
  k+=n-1;
  dat[k]=a;
  while(k>0){
    k = (k-1)/2;
    dat[k] = max(dat[k*2+1], dat[k*2+2]);
  }
}


ll query(ll a, ll b, ll k, ll l, ll r){
  if(r<=a || b<=l)
    return -LLINF;

  if(a<=l && r<=b)
    return dat[k];
  else{
    ll vl = query(a,b,k*2+1, l, (l+r)/2);
    ll vr = query(a,b,k*2+2, (l+r)/2, r);
    return max(vl,vr);
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll N;
  cin>>N;
  init(N);
  vpl p(N);
  REP(i,N)cin>>p[i].FI>>p[i].SE;
  sort(p.begin(), p.end());
  vll v(N);
  REP(i,N)v[i]=p[i].FI;

  //bit set
  REP(i,N){
    ll index = N-1-i;
    ll l=index;
    ll value = p[index].FI+p[index].SE;
    ll r = lower_bound(v.begin(), v.end(), value)-v.begin();

    ll max_i = query(l,r,0,0,n);
    if(max_i==-LLINF)
      update(l, l);
    else
      update(l, max_i);
  }


  ll dp[N][2];
  REP(i,N)REP(j,2)dp[i][j]=LLINF;

  for(ll i=N-1; i>=0; i--){
    if(i==N-1)
      dp[i][0]=dp[i][1]=1;
    else{
      dp[i][0]=(dp[i+1][0]+dp[i+1][1])%MOD;

      ll l=i;
      ll value = p[i].FI+p[i].SE;
      ll r = lower_bound(v.begin(), v.end(), value)-v.begin();
      ll t = query(l,r,0,0,n);

      if(t==l)
        dp[i][1]=dp[i][0];
      else
        dp[i][1]=dp[t][1];
    }
  }
  ll ans = (dp[0][0]+dp[0][1])%MOD;
  cout<<ans<<endl;
}
