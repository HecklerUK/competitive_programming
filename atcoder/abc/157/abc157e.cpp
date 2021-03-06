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


struct BIT{
  vll tree;
  ll n;

  BIT(ll n_):tree(n_+1,0),n(n_){
  }

  ll cumulativeSum(ll i){
    ll s=0;
    while(i>0){
      s += tree[i];
      i -= i&-i;
    }
    return s;
  }

  //[l, r)
  ll sum(ll l, ll r){
    ll res = cumulativeSum(r) - cumulativeSum(l);
    return res;
  }

  void add(ll i, ll x){
    i++;
    while(i<=n){
      tree[i] += x;
      i += i&-i;
    }
  }
};




int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  string s;
  cin>>s;
  ll q;
  cin>>q;

  vector<BIT> bit(26, BIT(n));
  REP(i,n){
    ll x=s[i]-'a';
    bit[x].add(i,1);
  }

  REP(i,q){
    ll query;
    cin>>query;
    if(query==1){
      ll iq;
      char cq;
      cin>>iq>>cq;
      iq--;

      ll x=s[iq]-'a';
      s[iq]=cq;
      bit[x].add(iq,-1);
      bit[cq-'a'].add(iq,1);
    }
    else{
      ll l, r;
      cin>>l>>r;
      l--;
      r--;

      ll ans=0;
      REP(j,26){
        ll sum=bit[j].sum(l,r+1);
        if(sum!=0)
          ans++;
      }
      cout<<ans<<endl;
    }
  }


}
