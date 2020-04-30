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

  int n;
  cin >> n;
  
  vector<string> s(n);
  REP(i, n)
    cin >> s[i];
  sort(s.begin(), s.end());
  unique(s.begin(), s.end());
  
  map<char, int> c_index;
  c_index['M'] = 0;
  c_index['A'] = 1;
  c_index['R'] = 2;
  c_index['C'] = 3;
  c_index['H'] = 4;

  vector<ll> count(5, 0);
  REP(i, n){
    char c = s[i][0];
    if(c != 'M' && c != 'A' && c != 'R' && c != 'C' && c != 'H')
      continue;
    else
      count[c_index[c]]++;

  }

  ll sum = 0;
  REP(i, (1<<5)){
    ll num = 0;
    ll tmp = 1;
    REP(j, 5){
      if((i>>j) & 1){
        num++;
        tmp *= count[j];
      }
    }
    //cout << tmp << endl;
    if(num == 3)
      sum += tmp;
  }
  cout << sum << "\n";  
}
