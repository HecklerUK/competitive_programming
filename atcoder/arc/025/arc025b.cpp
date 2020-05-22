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
  ll field1[h][w],field2[h][w];
  REP(i,h){
    REP(j,w){
      ll c;
      cin>>c;
      if(abs(j-i)%2==0){
        field1[i][j]=c;
        field2[i][j]=0;
      }
      else{
        field1[i][j]=0;
        field2[i][j]=c;
      }
    }
  }

  vvll remind1(h+1,vll(w+1,0)),remind2(h+1,vll(w+1,0));
  REP(i,h){
    REP(j,w){
      remind1[i+1][j+1]+=remind1[i+1][j]+field1[i][j];
      remind2[i+1][j+1]+=remind2[i+1][j]+field2[i][j];
    }
  }

  REP(j,w){
    REP(i,h){
      remind1[i+1][j+1]+=remind1[i][j+1];
      remind2[i+1][j+1]+=remind2[i][j+1];
    }
  }

  ll ans=0;
  REP(i,h){
    REP(j,w){
      for(ll k=1; k+i<=h; k++){
        for(ll t=1; t+j<=w; t++){
          ll rem1=remind1[i+k][j+t]-remind1[i+k][j]-remind1[i][j+t]+remind1[i][j];
          ll rem2=remind2[i+k][j+t]-remind2[i+k][j]-remind2[i][j+t]+remind2[i][j];
          if(rem1==rem2)
            ans=max(ans,k*t);
        }
      }
    }
  }

  cout<<ans<<endl;

}

