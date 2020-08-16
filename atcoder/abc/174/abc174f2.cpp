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

struct Mo
{
  vector< int > left, right, order;
  vector< bool > v;
  int width;
  int nl, nr, ptr;

  Mo(int n) : width((int) sqrt(n)), nl(0), nr(0), ptr(0), v(n) {}

  void insert(int l, int r) /* [l, r) */
  {
    left.push_back(l);
    right.push_back(r);
  }

  /* ソート */
  void build()
  {
    order.resize(left.size());
    iota(begin(order), end(order), 0);
    sort(begin(order), end(order), [&](int a, int b)
    {
      if(left[a] / width != left[b] / width) return left[a] < left[b];
      return right[a] < right[b];
    });
  }

  /* クエリを 1 つぶんすすめて, クエリのidを返す */
  int process()
  {
    if(ptr == order.size()) return (-1);
    const auto id = order[ptr];
    while(nl > left[id]) distribute(--nl);
    while(nr < right[id]) distribute(nr++);
    while(nl < left[id]) distribute(nl++);
    while(nr > right[id]) distribute(--nr);
    return (order[ptr++]);
  }

  inline void distribute(int idx)
  {
    v[idx].flip();
    if(v[idx]) add(idx);
    else del(idx);
  }

  void add(int idx);

  void del(int idx);
};


const ll MAX_N=5e5+2;
vll A(MAX_N);
int ans[MAX_N];
int cnt[MAX_N], sum;

void Mo::add(int idx)
{
  if(cnt[A[idx]]++ == 0) ++sum;
}

void Mo::del(int idx)
{
  if(--cnt[A[idx]] == 0) --sum;
}




int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,q;
  cin>>n>>q;

  REP(i,n)cin>>A[i];
  vll l(q), r(q);
  REP(i,q){
    cin>>l[i]>>r[i];
    l[i]--;
    r[i];
  }

  Mo mo(n);
  REP(i,q)
    mo.insert(l[i],r[i]);
  mo.build();


  REP(i,q)ans[mo.process()]=sum;
  REP(i,q)cout<<ans[i]<<endl;


}

