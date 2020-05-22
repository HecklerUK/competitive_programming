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
  vector<string> v(n);
  REP(i,n)cin>>v[i];

  ll l=0,r=0;
  REP(i,n){
    REP(j,v[i].size()){
      if(v[i][j]=='(')
        l++;
      else
        r++;
    }
  }
  if(l!=r){
    no;
    return 0;
  }

  vpl before, after;
  REP(i,n){
    ll k=v[i].size();
    ll a=0,b=0;
    REP(j,k){
      if(v[i][j]==')'){
        if(b>0)
          b--;
        else
          a++;
      }
      else
        b++;
    }

    for(ll j=k-1; j>=0; j--){
      if(v[i][j]=='('){
        if(a>0)
          a--;
        else
          b++;
      }
      else
        a++;
    }

    if(b-a>0)
      before.push_back(pll(a,i));
    else
      after.push_back(pll(b,i));
  }


  sort(ALL(before));
  sort(ALL(after),greater<pll>());

  string ans="";
  for(auto b:before)
    ans+=v[b.SE];
  for(auto a:after)
    ans+=v[a.SE];

  ll k=ans.size();
  ll a=0;
  REP(j,k){
    if(ans[j]==')'){
      if(a>0)
        a--;
      else{
        no;
        return 0;
      }
    }
    else
      a++;
  }

  yes;


}

