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

  ll h,w;
  cin>>h>>w;
  vector<string> s(h);
  REP(i,h)cin>>s[i];

  ll ans[h][w];
  REP(i,h)REP(j,w)ans[i][j]=9;

  //0 is lose in(i,j)
  ans[h-1][w-1]=0;
  REP(i,h){
    REP(j,w){
      if(s[i][j]=='#')
        continue;
      if(i+1<h && j+1<w){
        if(s[i+1][j+1]=='#' && s[i][j+1]=='#' && s[i+1][j]=='#')
          ans[i][j]=0;
      }
      else if(j+1<w){
        if(s[i][j+1]=='#')
          ans[i][j]=0;
      }
      else if(i+1<h){
        if(s[i+1][j]=='#')
          ans[i][j]=0;
      }
    }
  }

  for(ll i=h-1; i>=0; i--){
    for(ll j=w-1; j>=0; j--){
      if(ans[i][j]!=9 || s[i][j]=='#')
        continue;

      if(i+1<h && j+1<w){
        if(ans[i+1][j+1]==0 || ans[i][j+1]==0 || ans[i+1][j]==0)
          ans[i][j]=1;
        else
          ans[i][j]=0;
      }
      else if(j+1<w){
        if(ans[i][j+1]==0)
          ans[i][j]=1;
        else
          ans[i][j]=0;
      }
      else if(i+1<h){
        if(ans[i+1][j]==0)
          ans[i][j]=1;
        else
          ans[i][j]=0;
      }
    }
  }



