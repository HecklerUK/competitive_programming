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

  int deg;
  double dis;
  cin >> deg >> dis;
  
  vector<string> dirMap = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", \
    "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};

  int dir = (deg*10 + 1125) / 2250 % 16;


  //dis round
  //dis = round(dis/60.0*10) / 10.0;
  vector<double> wMap = {0.3, 1.6, 3.4, 5.5, 8.0, 10.8, \
    13.9, 17.2, 20.8, 24.5, 28.5, 32.7};
  vector<int>disn={2, 15, 33, 54, 79, 107, 138, 171, 207, 244, 284, 326, 1000};
  int w = 12;
  REP(i, 12){
    //if(dis <= wMap[i] - 0.1){
    if(dis<disn[i]*6+3){
      w = i;
      break;
    }
  }

  if(w == 0)
    cout << "C";
  else
    cout << dirMap[dir];
  cout << " " << w << endl;
  
}
