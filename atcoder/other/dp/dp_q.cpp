#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpl;

// macros
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

// constants
const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

//struct SegmentTree{
//  ll n=1;
//  vll node;
//
//  SegmentTree(ll N, vll a){
//    while(n<N)
//      n*=2;
//
//    node=vll(n, -LLINF);
//    REP(i, a.size())
//      node[n-1+i]=a[i];
//
//    for(ll i=n-2; i>=0; i--)
//      node[i]=max(node[2*i+1], node[2*i+2]);
//  }
//
//
//  void update(ll index, ll value){
//    ll cur = index+n-1;
//    node[cur] = value;
//    while(cur>0){
//      cur = (cur-1)/2;
//      node[cur]=max(node[2*cur+1], node[2*cur+2]);
//    }
//  }
//
//  ll find(ll qs, ll qe, ll index=0, ll l=0, ll r=-1){
//    if(r<0)
//      r=n;
//    if(r<=qs || qe<= l)
//      return -LLINF;
//    else if(qs<=l && r<=qe)
//      return node[index];
//
//    ll vl = find(qs,qe,2*index+1,l,(l+r)/2);
//    ll vr = find(qs,qe,2*index+2,(l+r)/2,r);
//    return max(vl, vr);
//  }
//};


struct SegmentTree {
  private:
    int n;
    vll node;

  public:
    SegmentTree(vll v) {
      int sz = v.size();
      n = 1; while(n < sz) n *= 2;
      node.resize(2*n-1, -LLINF);
      for(int i=0; i<sz; i++) node[i+n-1] = v[i];
      for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }

    void update(int x, int val) {
      x += (n - 1);
      node[x] = val;
      while(x > 0) {
        x = (x - 1) / 2;
        node[x] = max(node[2*x+1], node[2*x+2]);
      }
    }

    ll getmin(int a, int b, int k=0, int l=0, int r=-1) {
      if(r < 0) r = n;
      if(r <= a || b <= l) return -LLINF;
      if(a <= l && r <= b) return node[k];

      int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
      int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
      return max(vl, vr);
    }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  vll a(n),h(n);
  REP(i,n)cin>>h[i];
  REP(i,n)cin>>a[i];

  vll dp(n+1,0);
  SegmentTree sg(dp);
  REP(i,n){
    ll now = sg.getmin(0,h[i]);
    dp[h[i]] = max(dp[h[i]], now+a[i]);
    sg.update(h[i], dp[h[i]]);
  }

  ll ans = sg.getmin(0,n);
  cout<<ans<<endl;

}
