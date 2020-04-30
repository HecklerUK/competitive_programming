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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll l;
  cin>>l;

  ll n=0;
  while(pow(2,n)<=l)n++;

  vector<tuple<ll,ll,ll>> ans;
  REP(i,n-1)ans.push_back(make_tuple(i+1,i+2,pow(2,i)));
  REP(i,n-1)ans.push_back(make_tuple(i+1,i+2,0));

  ll sum=pow(2,n-1);
  for(ll i=n-1-1; i>=0; i--){
    if(l&ll(pow(2,i))){
      ans.push_back(make_tuple(i+1,n,sum));
      sum += pow(2,i);
    }
  }

  cout<<n<<" "<<ans.size()<<endl;
  for(auto a:ans){
    cout<<get<0>(a)<<" "<<get<1>(a)<<" "<<get<2>(a)<<endl;
  }
}

