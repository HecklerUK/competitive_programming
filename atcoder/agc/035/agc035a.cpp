#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

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
const int mod = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;  

  vector<ll> a(n);
  REP(i, n)
    cin >> a[i];
  vector<ll> b = a;

  sort(a.begin(), a.end());
  decltype(a)::iterator result = unique(a.begin(), a.end());
  a.erase(result, a.end());
  if(a.size() == 1 && a[0] == 0)
    cout << "Yes" << endl;
  else if(n % 3 != 0)
    cout << "No" << endl;
  else if(a.size() == 3 && a[0] ^ a[1] == a[2]){
    ll sum = 0;
    REP(i, n)
      sum ^= b[i];
    if(sum == 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  else if(a.size() == 2 && a[0] == 0 && \
      accumulate(b.begin(), b.end(), 0LL) == a[1] * n / 3 * 2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  
  
}
