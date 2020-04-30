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
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

vpl candi;
vpl v;
bool check(pll now){
  bool rst = false;
  REP(i,v.size()){
    if(now.FI == v[i].FI || now.SE == v[i].SE)
      rst=true;
    if(ll(abs(now.FI-v[i].FI)-abs(now.SE-v[i].SE))==0)
      rst=true;
  }
  return rst;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s[8];
  REP(i,8)cin>>s[i];

  REP(i,8){
    REP(j,8){
      if(s[i][j]=='Q'){
        if(check(pll(i,j))){
          cout<<"No Answer"<<endl;
          return 0;
        }
        else
          v.emplace_back(pll(i,j));
      }
    }
  }

  REP(i,8){
    REP(j,8){
      bool flag=true;
      REP(k,v.size())flag = !check(pll(i,j));

      if(flag)
        candi.emplace_back(pll(i,j));
    }
  }


  ll n=candi.size();
  REP(i,n){
    if(check(candi[i]))continue;
    else
      v.emplace_back(candi[i]);

    for(ll j=i+1; j<n; j++){
      if(check(candi[j]))continue;
      else
        v.emplace_back(candi[j]);

      for(ll k=j+1; k<n; k++){
        if(check(candi[k]))continue;
        else
          v.emplace_back(candi[k]);

        for(ll l=k+1; l<n; l++){
          if(check(candi[l]))continue;
          else
            v.emplace_back(candi[l]);

          for(ll r=l+1; r<n; r++){
            if(check(candi[r]))continue;
            else{
              v.emplace_back(candi[r]);
              for(auto a:v)s[a.FI][a.SE]='Q';
              REP(q,8)cout<<s[q]<<endl;
              return 0;
            }
          }
          v.pop_back();
        }
        v.pop_back();
      }
      v.pop_back();
    }
    v.pop_back();
  }

  cout<<"No Answer"<<endl;
}
