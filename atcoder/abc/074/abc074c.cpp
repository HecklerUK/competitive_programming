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

  int a,b,c,d,e,f;
  cin >> a >> b >> c >> d >> e >> f;

  pii maxmass = make_pair(100,-1);
  for(int i = 0; a*i <= f/100; i++){
    for(int j = 0; a*i+b*j <= f/100; j++){
      int maxsolt = (a*i+b*j) * e;
      for(int k = 0; k*c <= min(maxsolt, f-(a*i+b*j)*100); k++){
        int l = (min(maxsolt, f-(a*i+b*j)*100) - k*c) / d;
        if(i==0 && j == 0)
          continue;
        long double mass = 100.0 * (k*c+l*d) / ((a*i+b*j)*100+k*c+l*d);
        //cout << maxsolt << " " << f-(a*i+b*j)*100 << endl;
        //cout << i << " " << j << " " << k << " " << l << endl;
        //cout << mass << "\n";
        if(maxmass.SE * 100.0 / (maxmass.FI + maxmass.SE) < mass){
          maxmass.FI = (a*i+b*j)*100;
          maxmass.SE = k*c+l*d;
        }

      }
    }
  }

  cout << maxmass.SE + maxmass.FI << " " << maxmass.SE << endl;
  
}
