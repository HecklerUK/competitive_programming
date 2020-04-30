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

ll voiceResult(ll speaker, char voice, ll neighbor){
  if(voice == 'o'){
    if(speaker == 0)
      return neighbor;
    else
      return (neighbor+1)%2;
  }
  else{
    if(speaker == 0)
      return (neighbor+1)%2;
    else
      return neighbor;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin >> n;
  string s;
  cin >> s;

  vll zoo(n);
  REP(a, 2){
    REP(b, 2){
      zoo[0] = a;
      zoo[1] = b;
      REP1(i, n-1){
        zoo[i+1] = voiceResult(zoo[i], s[i], zoo[i-1]);
      }
      if(voiceResult(zoo[0], s[0], zoo[n-1]) == zoo[1] &&
          voiceResult(zoo[n-1], s[n-1], zoo[n-2]) == zoo[0]){
        REP(i, n){
          if(zoo[i] == 0)
            cout << 'S';
          else
            cout << 'W';
        }
        cout << endl;
        return 0;
      }
    }

  }

  cout << -1 << endl;
}
