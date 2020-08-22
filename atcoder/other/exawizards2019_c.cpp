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



ll n,q;
string s;
ll Q_MAX=2e5;
vector<char> t(Q_MAX),d(Q_MAX);

bool lcheck(ll m){
  if(m==-1)
    return true;

  char now=s[m];
  REP(i,q){
    if(t[i]==now){
      if(d[i]=='L')
        m--;
      else
        m++;

      if(m==-1)
        return true;
      if(m==n)
        return false;

      now=s[m];
    }
  }

  return false;
}


bool rcheck(ll m){
  if(m==n)
    return true;

  char now=s[m];
  REP(i,q){
    if(t[i]==now){
      if(d[i]=='L')
        m--;
      else
        m++;

      if(m==n)
        return true;
      if(m==-1)
        return false;

      now=s[m];
    }
  }

  return false;
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n>>q;
  cin>>s;
  REP(i,q)cin>>t[i]>>d[i];

  ll ok=-1;
  ll ng=n;
  while(abs(ng-ok)>1){
    ll mid=(ng+ok)/2;
    if(lcheck(mid))
      ok=mid;
    else
      ng=mid;
  }

  ll l=ok;


  ok=n;
  ng=-1;
  while(abs(ok-ng)>1){
    ll mid=(ng+ok)/2;
    if(rcheck(mid))
      ok=mid;
    else
      ng=mid;
  }

  ll r=ok;
  ll ans=n-(l+1)-(n-r);
  cout<<ans<<endl;

}

