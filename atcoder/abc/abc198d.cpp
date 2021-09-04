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

bool flag=false;
vll un(10);
ll CNT=0;

void dfs_pick(vll& indexes, int rest, std::function<void(vll)> f) {
  if (rest == 0){
    CNT++;
    return f(indexes);
  }
  else {
    REP(i,10){
      if(un[i]!=0)
        continue;
      indexes[rest-1] = i;
      un[i]++;
      dfs_pick(indexes, rest-1, f);
      un[i]--;
    }
  }
}

void run(ll n, ll k, std::function<void(vll)> f) {
  vll indexes(k);
  dfs_pick(indexes, k, f);
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s1,s2,s3;
  cin>>s1>>s2>>s3;
  string s=s1+s2+s3;
  SORT_UNIQUE(s);

  if(s.size()>10){
    cout<<"UNSOLVABLE"<<endl;
    return 0;
  }

  map<char,int> table;
  vll mp(256);

  auto solve=[&](vll p){
    REP(i,s.size())mp[s[i]]=p[i];

    if(flag)
      return;
    if(p[s1[0]]==0 || p[s2[0]]==0 || p[s3[0]]==0)
      return;

    vll t(3);
    int n1=0,n2=0,n3=0;
    REP(i,s1.size())n1=n1*10+p[s1[i]];
    REP(i,s2.size())n2=n2*10+p[s2[i]];
    REP(i,s3.size())n3=n3*10+p[s3[i]];

    if(n1+n2!=n3)
      return;

    cout<<n1<<endl;
    cout<<n2<<endl;
    cout<<n3<<endl;

    flag=true;
  };

  run(10,s.size(),solve);
  if(!flag)
    cout<<"UNSOLVABLE"<<endl;

  cout<<CNT<<endl;
}

