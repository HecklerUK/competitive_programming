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
  string s;
  cin >> s;

  // left to right
  stack<char> left;
  ll l = 0;
  for(int i = n-1; i >= 0; i--){
    if(')' == s[i])
      l++;
    else if(l != 0)
      l--;

    left.push(s[i]);
  }
  while(l > 0){
    left.push('(');
    l--;
  }

  //right to left
  queue<char> right;
  ll r = 0;
  while(!left.empty()){
    char now = left.top();
    if('(' == now)
      r++;
    else if(r != 0)
      r--;

    right.push(now);
    left.pop();
  }
  while(r > 0){
    right.push(')');
    r--;
  }

  while(!right.empty()){
    cout << right.front();
    right.pop();
  }

  cout << endl;

}
