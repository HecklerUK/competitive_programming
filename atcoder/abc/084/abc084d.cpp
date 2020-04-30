#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;

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
#define MAX_N 100010

bool primeNumber(ll x){
  if(x == 1)
    return false;
  for(int i = 2; i <= sqrt(x); i++){
    if(x % i == 0)
      return false;
  }

  return true;
}

bool match2017(ll x){
  if(x % 2 == 0)
    return false;
  else
    return primeNumber(x) && primeNumber((x+1)/2);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll q;
  cin >> q;
  vll l(q), r(q);
  REP(i, q)
    cin >> l[i] >> r[i];

  ll now = 0;
  vll cumlative(MAX_N, 0);
  REP1(i, MAX_N){
    if(match2017(i))
      now++;
    cumlative[i] = now;
  }


  REP(i, q)
    cout << cumlative[r[i]] - cumlative[l[i]-1] << endl;


}
