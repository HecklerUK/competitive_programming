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
  vector<string> s(n);
  REP(i,n)cin>>s[i];

  vector<char> ans(n);
  bool isAns=true;
  for(ll i=0; i<(n+1)/2; i++){
    ll l=i;
    ll r=n-1-l;

    map<ll,ll> ml,mr;
    REP(j,n)ml[s[l][j]-'a']+=1;
    REP(j,n)mr[s[r][j]-'a']+=1;

    bool flag=false;
    REP(j,26){
      if(ml[j]>0 && mr[j]>0){
        ans[l]='a'+j;
        ans[r]='a'+j;
        flag=true;
        break;
      }
    }
    if(!flag)
      isAns=false;
  }

  if(isAns){
    REP(i,n)cout<<ans[i];
    cout<<endl;
  }
  else
    cout<<-1<<endl;
}

