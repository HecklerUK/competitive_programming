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
  vll a(n);
  REP(i,n)cin>>a[i];

  vector<vvll> m(200);
  vvll ans;
  REP(i,n){
    ll q=a[i]%200;
    if(m[q].size()==1){
      ans.push_back(m[q][0]);
      ans.push_back(vll(1,i));
      break;
    }

    m[q].push_back(vll(1,i));

    vector<vvll> s=m;
    REP(j,200){
      if(j==q || m[j].size()==0)
        continue;

      ll w=(j+q)%200;
      vll t=m[j][0];
      t.push_back(i);

      if(m[w].size()==1){
        ans.push_back(m[w][0]);
        ans.push_back(t);
        break;
      }
      s[w].push_back(t);
    }
    swap(s,m);
  }


  if(ans.size()==0)
    no;
  else{
    yes;
    REP(j,2){
      cout<<ans[j].size();
      REP(i,ans[j].size())cout<<" "<<ans[j][i]+1;
      cout<<endl;
    }
  }
}

