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

  ll h,w,n,sr,sc;
  cin>>h>>w>>n>>sr>>sc;
  sr--;
  sc--;

  string s,t;
  cin>>s>>t;

  pll height,width;
  height=pll(0,h-1);
  width=pll(0,w-1);

  for(ll i=n-1; i>=0; i--){
    if(t[i]=='L'){
      width.SE=min(width.SE+1,w-1);
    }
    if(t[i]=='R'){
      width.FI=max(width.FI-1,0LL);
    }
    if(t[i]=='U'){
      height.SE=min(height.SE+1,h-1);
    }
    if(t[i]=='D'){
      height.FI=max(height.FI-1,0LL);
    }


    if(s[i]=='L'){
      width.FI+=1;
    }
    if(s[i]=='R'){
      width.SE-=1;
    }
    if(s[i]=='U'){
      height.FI+=1;
    }
    if(s[i]=='D'){
      height.SE-=1;
    }


    if(width.FI>width.SE || height.FI>height.SE){
      NO;
      return 0;
    }

  }



  if((width.FI<=sc && sc<=width.SE) && (height.FI<=sr && sr<=height.SE))
    YES;
  else
    NO;
}

