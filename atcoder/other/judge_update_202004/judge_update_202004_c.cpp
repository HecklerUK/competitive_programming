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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n=3;
  vll a(n);
  REP(i,n)cin>>a[i];

  ll sum=0;
  REP(i,n)sum+=a[i];

  vll v(sum);
  REP(i,sum)v[i]=i;



  ll ans=0;
  vll lim(n);
  REP(i,n){
    REP(j,n){
      if(a[j]>i)
        lim[i]++;
    }
  }

  do{
    vector<vll> b(n);
    ll cur=0;
    REP(i,n){
      REP(j,a[i]){
        b[i].push_back(v[cur]);
        cur++;
      }
    }

    bool flag=true;
    REP(i,n){
      if(a[i]<=1)
        continue;
      REP1(j,a[i]){
        if(b[i][j-1]>=b[i][j])
          flag=false;
      }
    }

    REP(i,n){
      if(lim[i]<=1)
        continue;
      REP1(j,lim[i]){
        if(b[j-1][i]>=b[j][i])
          flag=false;
      }
    }

    if(flag)
      ans++;
  }
  while(next_permutation(ALL(v)));

  cout<<ans<<endl;


}


