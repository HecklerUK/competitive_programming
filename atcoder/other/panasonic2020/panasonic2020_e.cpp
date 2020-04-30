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


bool eq(string a, string b){
  REP(i, a.size()){
    if(a[i]==b[i] || a[i]=='?' || b[i]=='?')
      continue;
    else
      return false;
  }

  return true;
}


bool check(string a, string b, ll x){
  string as = a.substr(a.size()-x, x);
  string bs = b.substr(0, x);
  return eq(as,bs);
}


ll calc(string a, string b){
  ll maxeq=0;
  for(ll i=min(a.size(), b.size()); i>=1; i--){
    if(check(a,b,i)){
      maxeq=i;
      break;
    }
  }

  ll res = a.size()+b.size()-maxeq;
  return res;
}


ll solve(string a, string b, string c){
  ll res = calc(a,b)+calc(b,c)-b.size();
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string a,b,c;
  cin>>a>>b>>c;
  ll ans = a.size()+b.size()+c.size();

  ans = min(ans, solve(a,b,c));
  ans = min(ans, solve(a,c,b));
  ans = min(ans, solve(b,a,c));
  ans = min(ans, solve(b,c,a));
  ans = min(ans, solve(c,a,b));
  ans = min(ans, solve(c,b,a));

  cout<<ans<<endl;

}

