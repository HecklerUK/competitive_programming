
#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;

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
  ll n;
  cin>>n;
  vll s(n);
  REP(i,n)cin>>s[i];
  ll q;
  cin>>q;
  vll k(q);
  REP(i,q)cin>>k[i];

  sort(ALL(s));
  REP(i,n){
    if(s[i]==0)
      s[i]=-1;
  }
  REP(i,q){
    ll ok=1000001;
    ll ng=-1;

    auto check=[&](ll b, ll h){
      auto it=lower_bound(ALL(s),b);
      ll res=n-(it-s.begin());
      return res<=h;
    };
    while(ok-ng>1){
      ll mid=(ok+ng)/2;
      if(check(mid, k[i]))
        ok=mid;
      else
        ng=mid;
    }

    cout<<ok<<endl;
  }


}
