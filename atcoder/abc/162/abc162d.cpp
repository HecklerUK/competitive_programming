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

  ll n;
  cin>>n;
  string s;
  cin>>s;

  vll r,g,b;
  REP(i,n){
    if(s[i]=='R')
      r.push_back(i);
    if(s[i]=='G')
      g.push_back(i);
    if(s[i]=='B')
      b.push_back(i);
  }


  auto f=[](ll i, vll a, vll b){
    ll sum=0;
    auto it=lower_bound(ALL(a),i);

    for(ll j=it-a.begin(); j<a.size(); j++){
      ll dif=a[j]-i;

      auto it2=lower_bound(ALL(b), a[j]);
      if(it2==b.end())
        continue;
      ll cnt=(b.size()-(it2-b.begin()));

      auto find=lower_bound(ALL(b), a[j]+dif);
      if(find!=b.end() && *find==a[j]+dif)
        cnt--;
       // cout<<"find"<<endl;

      sum+=cnt;
    }

    return sum;
  };



  ll sum=0;
  REP(i,n){
    if(s[i]=='R'){
      sum +=f(i,g,b);
      sum +=f(i,b,g);
    }
    else if(s[i]=='G'){
      sum +=f(i,r,b);
      sum +=f(i,b,r);
    }

    else if(s[i]=='B'){
      sum +=f(i,g,r);
      sum +=f(i,r,g);
    }
  }

  cout<<sum<<endl;
}

