#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpll;

// macros
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

// constants
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
  vll a(n*3);
  REP(i,n*3)cin>>a[i];

  priority_queue<ll,vll,greater<ll>> ql;
  priority_queue<ll> qr;
  ll lsum=0;
  ll rsum=0;
  REP(i,n){
    ql.push(a[i]);
    lsum += a[i];
  }
  REP(i,n){
    qr.push(a[i+2*n]);
    rsum+=a[i+2*n];
  }

  ll sum=lsum;
  vll s(n+1);
  s[0]+=lsum;
  REP(i,n){
    ll p=ql.top();
    ql.push(a[i+n]);
    ql.pop();
    sum+=a[i+n];
    sum-=min(p,a[i+n]);

    s[i+1]+=sum;
  }

  sum=rsum;
  //cout<<s[n]<<":"<<sum<<endl;
  s[n]-=rsum;
  ll ans=s[n];
  REP(i,n){
    ll p=qr.top();
    qr.push(a[2*n-1-i]);
    qr.pop();
    sum+=a[2*n-1-i];
    sum-=max(a[2*n-1-i],p);

    //cout<<s[n-1-i]<<":"<<sum<<endl;
    s[n-1-i]-=sum;
    ans = max(s[n-1-i], ans);
  }

  cout<<ans<<endl;


}
