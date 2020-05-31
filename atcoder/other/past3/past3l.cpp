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

struct SegmentTreeMax{
  ll n;
  vll tree;
  SegmentTreeMax(ll len){
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

struct SegmentTreeSum{
  ll n;
  vll tree;
  SegmentTreeSum(ll len){
    n=1;
    while(len>n)
      n*=2;

    tree.assign(2*n-1, 0);
  }
  void update(ll index, ll value){
    index += n-1;
    tree[index] = value;

    while(index>0){
      index=(index-1)/2;
      tree[index] = tree[index*2+1]+tree[index*2+2];
    }
  }
  //[a, b)
  ll query(ll a, ll b){
    return query(a,b,0,0,n);
  }
  ll query(ll a, ll b, ll index, ll l, ll r){
    if(b<=l || r<=a)
      return 0;

    if(a<=l && r<=b)
      return tree[index];

    ll value_l = query(a,b,2*index+1,l,(l+r)/2);
    ll value_r = query(a,b,2*index+2,(l+r)/2,r);
    return value_l+value_r;
  }

  ll lower_bound(ll header, ll max_n, ll x){
    if(query(header,header+max_n)<x)
      return -1;
    ll ok=max_n;
    ll ng=0;
    while(ok-ng>1){
      ll mid=(ok+ng)/2;
      if(x<=query(header,header+mid))
        ok=mid;
      else
        ng=mid;
    }

    return ok;
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  vll k(n);
  vvll t(n);
  REP(i,n){
    cin>>k[i];
    REP(j,k[i]){
      ll x;
      cin>>x;
      t[i].push_back(x);
    }
  }
  ll m;
  cin>>m;
  vll a(m);
  REP(i,m)cin>>a[i];

  vll remind(n+1);
  REP(i,n)remind[i+1]=remind[i]+k[i];
  SegmentTreeMax sgm1(n);
  SegmentTreeMax sgm2(n);
  SegmentTreeSum sgs(remind[n]);

  //set
  map<ll,pll> tana;
  REP(i,n){
    REP(j,k[i]){
      ll index=remind[i]-remind[0];
      sgs.update(index+j,1);
      tana[t[i][j]]=pll(i,j);
    }
  }
  REP(i,n){
    ll two;
    if(k[i]==1)
      two=0;
    else
      two=t[i][1];
    sgm1.update(i,t[i][0]);
    sgm2.update(i,max(t[i][0],two));
  }

  //query
  REP(i,m){

    ll pick;
    if(a[i]==1)
      pick=sgm1.query(0,n);
    else
      pick=sgm2.query(0,n);
    cout<<pick<<endl;

    pll p=tana[pick];

    ll index=remind[p.FI]-remind[0];
    sgs.update(index+p.SE,0);

    ll one=sgs.lower_bound(index,k[p.FI],1);
    ll two=sgs.lower_bound(index,k[p.FI],2);

    ll oneA,twoA;
    if(one<0)
      oneA=0;
    else
      oneA=t[p.FI][one-1];

    if(two<0)
      twoA=0;
    else
      twoA=t[p.FI][two-1];

    sgm1.update(p.FI,oneA);
    sgm2.update(p.FI,max(oneA,twoA));
  }

}

