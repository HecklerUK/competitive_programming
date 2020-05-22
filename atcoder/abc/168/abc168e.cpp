#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpl;
typedef vector<pld> vpd;
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

ll mpow(ll m, ll p){
  ll power = m;
  ll res = 1;
  while(p>0){
    if(p&1)
      res = res*power%MOD;
    power = (power*power)%MOD;
    p /= 2;
  }

  return res;
}

ll gcd(ll a, ll b){
  if(b==0)
    return a;
  if(a<b)
    return gcd(b,a);

  return gcd(b,a%b);
}

pll relativePrimes(ll a, ll b){
  if(a==0&&b==0)
    return pll(0,0);
  else if(a==0)
    return pll(0,1);
  else if(b==0)
    return pll(1,0);

  ll x=a;
  ll y=b;
  if(y<0){
    x*=-1;
    y*=-1;
  }
  ll z=gcd(abs(x),abs(y));

  return pll(x/z,y/z);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  vll a(n),b(n);
  REP(i,n)cin>>a[i]>>b[i];

  map<pll,ll> m;
  vpl x;

  REP(i,n){
    pll t=relativePrimes(a[i],b[i]);
    m[t]+=1;
    x.push_back(t);
  }
  SORT_UNIQUE(x);


  ll ans=1;
  ll k=x.size();

  vector<bool> visited_x(k, false);
  REP(i,k){
    if(visited_x[i])
      continue;

    ll q=mpow(2,m[x[i]]);
    ll w=0;
    visited_x[i]=true;

    pll target;
    if(x[i].FI==0&&x[i].SE==0)
      continue;
    else if(x[i].FI==0||x[i].SE==0){
      target.FI=x[i].SE;
      target.SE=x[i].FI;
    }
    else{
      target.FI=-x[i].SE;
      target.SE=x[i].FI;
      if(target.SE<0){
        target.FI*=-1;
        target.SE*=-1;
      }
    }

    auto it=lower_bound(ALL(x),target);
    if(it!=x.end()){
      ll index=it-x.begin();
      if(*it==target){
        visited_x[index]=true;
        w=mpow(2,m[target])-1;
      }
    }

    ans=ans*(q+w)%MOD;
  }
  //remove no choise
  ans=(ans-1+m[pll(0,0)]+MOD)%MOD;

  cout<<ans<<endl;


}

