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


const ll MAX_B=2e5+1;
multiset<ll> s[MAX_B];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,q;
  cin>>n>>q;
  vll a(n),b(n),c(q),d(q);
  REP(i,n){
    cin>>a[i]>>b[i];
    b[i]--;
  }
  REP(i,q){
    cin>>c[i]>>d[i];
    c[i]--;
    d[i]--;
  }

  REP(i,n)
    s[b[i]].insert(a[i]);
  vll table(n);
  REP(i,n)table[i]=b[i];

  SegmentTreeMIN st(MAX_B);
  REP(i,MAX_B){
    if(s[i].size()==0)
      continue;
    auto it=s[i].rbegin();
    st.update(i,*it);
  }


  REP(i,q){
    ll k=c[i];
    s[table[k]].erase(a[k]);
    if(s[table[k]].size()==0)
      st.update(table[k],LLINF);
    else{
      auto itb=s[table[k]].rbegin();
      st.update(table[k],*itb);
    }

    s[d[i]].insert(a[k]);
    auto itd=s[d[i]].rbegin();
    st.update(d[i],*itd);
    table[k]=d[i];

    ll ans=st.query(0,MAX_B);
    cout<<ans<<endl;
  }


}

