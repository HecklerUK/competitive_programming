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

  ll n;
  cin>>n;
  vll c(n);
  vvll edge(n);
  REP(i,n-1){
    ll a,b;
    cin>>a>>b;
    a--;
    b--;
    edge[a].push_back(b);
    edge[b].push_back(a);
  }

  REP(i,n)cin>>c[i];
  sort(ALL(c));
  ll sum=0;
  REP(i,n-1)sum+=c[i];

  vll ans(n);
  ll cur=n-1;
  REP(i,n){
    if(edge[i].size()==1)
      continue;

    queue<pll> que;
    que.push(pll(i,-1));
    while(!que.empty()){
      ll v=que.front().FI;
      ll par=que.front().SE;
      que.pop();
      ans[v]=c[cur];

      for(auto e:edge[v]){
        if(e==par)
          continue;

        que.push(pll(e,v));
      }
      cur--;
    }

    break;
  }


  cout<<sum<<endl;
  cout<<ans[0];
  REP1(i,n)cout<<" "<<ans[i];
  cout<<endl;

}

