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
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

ll n,k;
vll a;

ll check(ll b){
  ll sum=0;
  REP(i,n){
    if(a[i]!=0){
      ll p = b/a[i];

      if(b>0 && b%a[i]!=0){
        if(a[i]>0)
          p++;
        else
          p--;
      }

      if(a[i]>0){
        ll index = max(ll(lower_bound(a.begin(), a.end(), p)-a.begin()),ll(i+1));
        ll num = max(n-index,0LL);
        sum += num;
 //       cout<<"index:"<<upper_bound(a.begin(), a.end(), p)-a.begin()-(i+1)<<" num:"<<num<<endl;
      }
      else{
        ll num = max(ll(upper_bound(a.begin(), a.end(), p)-a.begin()-(i+1)),0LL);
        sum += num;
  //      cout<<p<<endl;
  //      cout<<"index:"<<upper_bound(a.begin(), a.end(), p)-a.begin()-(i+1)<<" num:"<<num<<endl;
      }



    }
    else{
      if(b<=0)
        sum+=n-(i+1);
    }

   // cout<<a[i]<<":"<<sum<<endl;
  }

  return sum;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;
  cin>>k;
  a.assign(n,0);
  REP(i,n)cin>>a[i];

  sort(a.begin(), a.end());
//  check(-12);

//ok:border
  ll ok=1e18;
  ll ng=-1e18;
  while(ok-ng>1){
    ll mid = (ok+ng)/2;
    if(check(mid)<=n*(n-1)/2-k)
      ok = mid;
    else
      ng = mid;
    //cout<<ng<<endl;
  }

  if(check(ok)==k)
  cout<<ok<<endl;
  else
  cout<<ng<<endl;
}
