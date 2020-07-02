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

struct SegmentTreeMAX{
  ll n;
  vll tree;

  SegmentTreeMAX(ll len){
    n=1;
    while(len>n)
      n*=2;

    tree.assign(2*n-1, -LLINF);
  }

  void update(ll index, ll value){
    index += n-1;
    tree[index] = value;

    while(index>0){
      index=(index-1)/2;
      tree[index] = max(tree[index*2+1], tree[index*2+2]);
    }
  }


  //[a, b)
  ll query(ll a, ll b){
    return query(a,b,0,0,n);
  }

  ll query(ll a, ll b, ll index, ll l, ll r){
    if(b<=l || r<=a)
      return -LLINF;

    if(a<=l && r<=b)
      return tree[index];

    ll value_l = query(a,b,2*index+1,l,(l+r)/2);
    ll value_r = query(a,b,2*index+2,(l+r)/2,r);
    return max(value_l, value_r);
  }
};



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,p;
  cin>>n>>p;
  vll a(n);
  REP(i,n)cin>>a[i];
  sort(ALL(a));


  const ll q=4010;
  vll remind(q);
  REP(i,n)remind[a[i]]++;
  REP(i,q-1)remind[i+1]+=remind[i];

  ll ma=a[n-1];
  vll ans;
  for(ll x=0; x<=ma; x++){
    bool flag=true;
    REP(j,n){
      ll now=x+j;
      if((remind[now]-j)%p==0)
        flag=false;
    }

    if(flag)
      ans.push_back(x);
  }

  cout<<ans.size()<<endl;
  REP(i,ans.size()){
    if(i!=0)
      cout<<" ";
    cout<<ans[i];
  }
  cout<<endl;
}

