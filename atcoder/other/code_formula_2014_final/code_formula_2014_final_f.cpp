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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n=100;
  vpl ans(n);

  for(ll i=0; i<25; i++){
    ll index=100-1-i;
    ll r=100-i;
    ll rx=300*(i%5);
    ll ry=300*(i/5);
    ans[index].FI=rx+r;
    ans[index].SE=ry+r;
  }

  for(ll i=0; i<25; i++){
    ll index=75-1-i;
    ll r=75-i;
    ll rx=300*(i%5);
    ll ry=300*(i/5);
    ans[index].FI=rx+300-r;
    ans[index].SE=ry+300-r;
  }

  for(ll i=0; i<25; i++){
    ll index=50-1-i;
    ll r=50-i;
    ll rx=300*(i%5);
    ll ry=300*(i/5);
    ans[index].FI=rx+r;
    ans[index].SE=ry+300-r;
  }

  for(ll i=0; i<25; i++){
    ll index=25-1-i;
    ll r=25-i;
    ll rx=300*(i%5);
    ll ry=300*(i/5);
    ans[index].FI=rx+300-r;
    ans[index].SE=ry+r;
  }



  REP(i,n)cout<<ans[i].FI<<" "<<ans[i].SE<<endl;
}

