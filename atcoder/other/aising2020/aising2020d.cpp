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

ll popcount(ll x){
  ll cnt=0;
  ll res=0;
  while((1<<cnt)<=x){
    if((1<<cnt)&x)
      res++;
    cnt++;
  }

  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  string x;
  cin>>x;

  ll t=0;
  REP(i,n){
    if(x[i]=='1')
      t++;
  }

  vll p(2);
  p[0]=t+1;
  p[1]=t-1;
  vll X(2,0);
  vvll base(2,vll(n+1,1));
  REP(j,2){
    if(p[j]<=0)
      continue;
    REP(i,n){
      if(x[n-1-i]=='1'){
        X[j]=(X[j]+base[j][i])%p[j];
      }

      base[j][i+1]=base[j][i]*2%p[j];
    }
  }


  REP(i,n){
    ll now;
    ll k;
    if(x[i]=='1'){
      k=1;
      if(p[1]==0){
        cout<<0<<endl;
        continue;
      }

      now=(X[k]-base[k][n-1-i]+p[k])%p[k];
    }
    else{
      k=0;
      now=(X[k]+base[k][n-1-i])%p[k];
    }

    ll ans=1;
    while(now!=0){
      now=now%popcount(now);
      ans++;
    }
    cout<<ans<<endl;

  }

}

