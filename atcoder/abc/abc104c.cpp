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

  ll d,g;
  cin>>d>>g;
  vll p(d),c(d);
  REP(i,d)cin>>p[i]>>c[i];

  ll ans=LLINF;
  REP(bit,(1<<d)){
    ll point=0;
    ll cnt=0;
    vll v;
    REP(i,d){
      if((bit>>i)&1){
        point+=(i+1)*100*p[i]+c[i];
        cnt+=p[i];
      }
      else
        v.push_back(i);
    }

    if(g<=point){
      ans=min(ans,cnt);
      continue;
    }

    ll sz=v.size();
    for(ll i=sz-1; i>=0; i--){
      ll base=(v[i]+1)*100;
      if((g-point-1)/base+1<=p[v[i]]-1){
        cnt+=(g-point-1)/base+1;
        point+=((g-point-1)/base+1)*base;
        break;
      }
      else{
        cnt+=p[v[i]]-1;
        point+=base*(p[v[i]]-1);
      }
    }

    if(g<=point)
      ans=min(ans,cnt);
  }

  cout<<ans<<endl;

}

