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

  ll n,k;
  cin>>n>>k;
  vll a(n);
  REP(i,n)cin>>a[i];

  ll cnt=1;
  ll base=1;
  while(base<n){
    base*=2;
    cnt++;
  }


  vll ans(n);
  copy(ALL(a),ans.begin());
  while(k>0){
    vll imos(n+1);
    REP(j,n){
      ll l=max(0LL,j-ans[j]);
      ll r=min(j+ans[j]+1,n);
      imos[l]++;
      imos[r]--;
    }

    REP(j,n)imos[j+1]+=imos[j];
    imos.pop_back();
    if(ans==imos)
      break;
    else
      ans=imos;
    k--;
  }

  cout<<ans[0];
  REP(i,n-1)cout<<" "<<ans[i+1];
  cout<<endl;
}

