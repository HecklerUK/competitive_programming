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


struct SegmentTreeMIN{
  ll n;
  vll tree;

  SegmentTreeMIN(ll len){
    n=1;
    while(len>n)
      n*=2;

    tree.assign(2*n-1, LLINF);
  }

  void update(ll index, ll value){
    index += n-1;
    tree[index] = value;

    while(index>0){
      index=(index-1)/2;
      tree[index] = min(tree[index*2+1], tree[index*2+2]);
    }
  }


  //[a, b)
  ll query(ll a, ll b){
    return query(a,b,0,0,n);
  }

  ll query(ll a, ll b, ll index, ll l, ll r){
    if(b<=l || r<=a)
      return LLINF;

    if(a<=l && r<=b)
      return tree[index];

    ll value_l = query(a,b,2*index+1,l,(l+r)/2);
    ll value_r = query(a,b,2*index+2,(l+r)/2,r);
    return min(value_l, value_r);
  }
};




int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll t;
  cin>>t;
  REP(i,t){
    ll n;
    cin>>n;
    vll k(n),l(n),r(n);
    REP(j,n)cin>>k[j]>>l[j]>>r[j];

    vpl d(n);
    ll L=0,R=0,N=0;
    REP(j,n){
      d[j].FI=abs(l[j]-r[j]);
      d[j].SE=j;
      if(l[j]-r[j]<0)
        R++;
      if(l[j]-r[j]>0)
        L++;
      if(l[j]-r[j]==0)
        N++;
    }
    sort(ALL(d),greater<pll>());

    SegmentTreeMAX stmax(n);
    SegmentTreeMIN stmin(n);

    REP(j,n)stmax.update(j,j);
    REP(j,n)stmin.update(j,j);

    ll ans=0;
    REP(j,n){
      ll index=d[j].SE;
      ll v=l[index]-r[index];

      //l志望
      if(v>0){
        ll q=stmax.query(0,k[index]);
        if(q==-1){
          ll ni=stmax.query(0,L);
          stmax.update(ni,-1);
          ans+=r[index];
        }
        else{
          stmax.update(q,-1);
          ans+=l[index];
        }
      }

      //r志望
      if(v<0){
        ll q=stmin.query(k[index],n);
        if(q==LLINF){
          ll ni=stmin.query(n-R,n);
          stmin.update(ni,LLINF);
          ans+=l[index];
        }
        else{
          stmin.update(q,LLINF);
          ans+=r[index];
        }
      }

      if(v==0)
        ans+=l[index];
    }

    cout<<ans<<endl;


  }
}

