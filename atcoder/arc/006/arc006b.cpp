
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

  ll n, line;
  cin >> n >> line;

  cin.ignore(1);
  vector<string> s(line);
  REP(i, line)
    getline(cin, s[i]);

  string b;
  getline(cin, b);

 // REP(i, line)
 //   cout << s[i] << endl;
 // cout << b << endl;

  ll now = b.find_first_of("o", 0);
  ll len = 2*n-1;
  for(ll i=line-1; i >= 0; i--){
    //cout << "len:" << s[i].size() << endl;
    ll l = now-1;
    ll r = now+1;
    if(0 <= l && l <= len-1){
      if(s[i][l] == '-')
        now -= 2;
    }
    if(0 <= r && r <= len-1){
      if(s[i][r] == '-')
        now += 2;
    }
  }

  cout << now/2+1 << endl;



}

