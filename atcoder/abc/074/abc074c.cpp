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

  ll a,b,c,d,e,f;
  cin>>a>>b>>c>>d>>e>>f;

  vector<bool> isx(f+10,false);
  vector<bool> isy(f+10,false);
  for(ll i=0; i*a*100<=f; i++){
    for(ll j=0; i*a*100+j*b*100<=f; j++){
      ll now=i*a*100+j*b*100;
      isx[now]=true;
    }
  }

  isx[0]=false;

  for(ll i=0; i*c<=f; i++){
    for(ll j=0; i*c+j*d<=f; j++){
      ll now=i*c+j*d;
      isy[now]=true;
    }
  }


  ld maxn=-1;
  ll ans_all,ans_sugar;
  for(ll x=0; x<=f; x++){
    for(ll y=0; x+y<=f; y++){
      if(isx[x]&&isy[y]){
        if(y<=x/100*e){
          ld p=100.0*y/(x+y);
          if(maxn<p){
            maxn=p;
            ans_all=x+y;
            ans_sugar=y;
          }
        }
      }
    }
  }


  cout<<ans_all<<" "<<ans_sugar<<endl;
}

