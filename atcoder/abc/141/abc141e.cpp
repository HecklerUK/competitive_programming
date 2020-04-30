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


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  string S;
  cin >> S;

  //cout << S << endl;

  vll A(n+1);
  A[0] = -1;
  int j = -1;
  for (int i = 0; i < S.size(); i++) {
    while (j >= 0 && S[i] != S[j])
      j = A[j];


    j++;
  //if (S[i+1] == S[j])
  //    A[i+1] = A[j]; 
  //  else
      A[i+1] = j;
    
    cout << "i:" << i << " j:" << j << endl;
  }

  ll ans = 0;
  REP(i, n+1){
    cout << A[i] << endl;
    ans = max(ans, A[i]);
  }
  if(ans >= n/2)
    ans = n/2;
  cout << ans << endl;

  
}
