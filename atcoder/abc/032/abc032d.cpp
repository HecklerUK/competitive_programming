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

  ll n,s;
  cin>>n>>s;
  vll v(n),w(n);
  REP(i,n)cin>>v[i]>>w[i];

  bool flag[3];
  REP(i,3)flag[i]=true;

  REP(i,n){
    if(n>30)
      flag[0]=false;
    if(w[i]>1000)
      flag[1]=false;
    if(v[i]>1000)
      flag[2]=false;
  }


  if(flag[0]){
    vpl vec;
    ll K=n/2;
    REP(bit,(1<<K)){
      ll sum=0;
      ll value=0;
      REP(i,K){
        if((bit>>i)&1){
          sum+=w[i];
          value+=v[i];
        }
      }
      vec.push_back(pll(sum,value));
    }

    sort(ALL(vec));
    vpl target;
    ll now=-1;
    REP(i,vec.size()){
      if(now<vec[i].SE){
        target.push_back(vec[i]);
        now=vec[i].SE;
      }
    }


    ll L=n-K;
    ll ans=0;
    REP(bit,(1<<L)){
      ll sum=0;
      ll value=0;
      REP(i,L){
        if((bit>>i)&1){
          sum+=w[K+i];
          value+=v[K+i];
        }
      }

      if(s<sum)
        continue;

      ll remind=s-sum;
      auto it=upper_bound(ALL(target),pll(remind,LLINF));
      if(it==target.begin())
        continue;
      ans=max(ans,(it-1)->second+value);
    }

    cout<<ans<<endl;
    return 0;
  }

  else if(flag[1]){
    vll weight(n*1000+1);
    REP(i,n){
      for(ll j=(i+1)*1000; j-w[i]>=0; j--)
        weight[j]=max(weight[j-w[i]]+v[i],weight[j]);
    }

    ll ans=0;
    REP(i,min(s,n*1000)+1)
      ans=max(ans,weight[i]);
    cout<<ans<<endl;
    return 0;
  }

  else if(flag[2]){
    vll value(n*1000+1,LLINF);
    value[0]=0;
    REP(i,n){
      for(ll j=(i+1)*1000; j-v[i]>=0; j--)
        value[j]=min(value[j-v[i]]+w[i],value[j]);
    }

    ll ans=0;
    REP(i,n*1000+1){
      if(value[i]<=s)
        ans=max(ans,ll(i));
    }

    cout<<ans<<endl;
    return 0;
  }

  cout<<"error"<<endl;
  return 0;
}

