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

ll n=10;
vector<string> s(n);


ll dfs(ll x, ll y, vector<vll>& memo){
  if(memo[x][y]==1)
    return 0;

  memo[x][y]=1;
  ll sum=1;
  REP(i,4){
    if(x+dx[i]<0 || 9<x+dx[i] || y+dy[i]<0 || 9<y+dy[i])
      continue;

    if(s[x+dx[i]][y+dy[i]]=='x')
      continue;

    sum+=dfs(x+dx[i], y+dy[i], memo);
  }

  return sum;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

 REP(i,n)cin>>s[i];

  ll sum=0;
  REP(i,n){
    REP(j,n){
      if(s[i][j]=='o')
        sum++;
    }
  }

  bool flag=false;
  REP(i,n){
    REP(j,n){
      vector<vll> memo(10,vll(10,0));
      ll res=dfs(i,j,memo);
      if(res==sum+1){
        flag=true;
      }
    }
  }


  if(flag)
    YES;
  else
    NO;

}

