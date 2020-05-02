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

  ll t;
  cin>>t;

  vll n(t),k(t);
  vector<string> s(t);
  REP(i,t)cin>>n[i]>>k[i]>>s[i];

  REP(i,t){
    vector<char> v(n[i]);
    REP(j,n[i])v[j]=s[i][j];
    sort(ALL(v));

    vector<char> vv=v;
    SORT_UNIQUE(vv);
    if(vv.size()==1){
      ll num=n[i]/k[i];
      if(n[i]%k[i]!=0)
        num++;
      REP(j,num)cout<<vv[0];
      cout<<endl;
      continue;
    }

    map<char,ll> m;
    REP(j,n[i])m[v[j]]+=1;

    if(m[vv[0]]==k[i]){
      if(m[vv[0]]+m[vv[1]]==n[i]){
        string ans="";
        REP(j,m[vv[0]]/k[i])ans+=vv[0];

        ll num=m[vv[1]]/k[i];
        if(m[vv[1]]%k[i]!=0)
          num++;
        REP(j,num)ans+=vv[1];
        cout<<ans<<endl;
        continue;
      }
    }

    vector<string> ans(k[i],"");
    for(ll j=0; j<k[i]; j++)ans[j]+=v[j];
    for(ll j=k[i]; j<n[i]; j++)ans[0]+=v[j];
    if(ans[0]<ans[k[i]-1])
      cout<<ans[k[i]-1]<<endl;
    else
      cout<<ans[0]<<endl;

  }

}

