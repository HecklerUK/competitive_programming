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


bool dfs(string& a, string& b, ll remain, vll& f){
  if(remain==0){
    string k=a;
    if(f[0]==f[1]||f[2]==f[3]||f[4]==f[5])
      return false;
    swap(k[f[0]],k[f[1]]);
    swap(k[f[2]],k[f[3]]);
    swap(k[f[4]],k[f[5]]);


    return k==b;
  }

  ll n=a.size();
  bool res=false;
  REP(i,n){
    if(remain%2==1){
      if(i<=f[6-remain-1])
        continue;
    }
    f[6-remain]=i;
    res=res||dfs(a,b,remain-1,f);
  }
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string a,b;
  cin>>a>>b;

  ll n=a.size();
  string c,d,e;
  if(a.size()>6){
    REP(i,n){
      if(a[i]!=b[i]){
        c+=a[i];
        d+=b[i];
      }
      else
        e+='A';
    }

    if(c.size()>6){
      NO;
      return 0;
    }

    c+=e;
    d+=e;
    if(c.size()>6)
      c=c.substr(0,6),d=d.substr(0,6);
  }
  else
    c=a,d=b;

  vll f(6);
  bool ans=dfs(c,d,6,f);

  if(ans)
    YES;
  else
    NO;

}

