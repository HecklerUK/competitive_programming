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

  ll n, k;
  cin >> n >> k;
  vll v(n);
  REP(i, n)
    cin >> v[i];

  ll ans = -LLINF;
  priority_queue<ll, vector<ll>, greater<ll>> que;
  for(int a = 0; a <= min(n, k); a++){
    for(int b=0; b<=min(n, k)-a; b++){
     for(int c=0; c <= min(n, k-a-b); c++){
       REP(i, a)
         que.push(v[i]);
       REP(i, b)
         que.push(v[n-i-1]);

       REP(i, c){
         if(!que.empty() && que.top() < 0)
           que.pop();
       }

       ll sum = 0;
       while(!que.empty()){
         sum += que.top();
         que.pop();
       }
       ans = max(ans, sum);

     }
    }
  }

  cout << ans << endl;
  
}
