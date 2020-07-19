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

  string s;
  cin>>s;
  ll n=s.size();

  bool flag=false;
  if(s[0]==0 || s[n-1]=='1')
    flag=true;

  for(ll i=0; i+1<=n-(i+1); i++){
    ll l=i;
    ll r=n-(i+1)-1;
    if(s[l]!=s[r])
      flag=true;
  }

  if(flag){
    cout<<-1<<endl;
    return 0;
  }


  vpl edge;
  ll last=0;
  ll now=1;
  REP(i,n-1){
    if(s[i]==1){
      edge.push_back(pll(last,now));
      last=now;
      now++;
    }
    else{
      edge.push_back(pll(last,now));
      now++;
    }
  }

  for(auto e:edge)
    cout<<e.FI+1<<" "<<e.SE+1<<endl;
}

