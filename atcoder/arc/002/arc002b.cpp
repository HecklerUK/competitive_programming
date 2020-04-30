#include <bits/stdc++.h>
using namespace std;

// types
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpll;

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

  string Y,M,D;
  int y,m,d;
  scanf("%d/%d/%d\n", &y, &m, &d);
 // y = stoi(Y);
 // m = stoi(M);
 // d = stoi(D);
  while(1){
    if(y%(m*d) == 0){
      printf("%d/%02d/%02d\n", y, m, d);
      break;
    }
    d++;
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
      if(31<d){
        d = 1;
        m++;
      }
    }
    else if(m==4 || m==6 || m==9 || m==11){
      if(30<d){
        d = 1;
        m++;
      }
    }
    else{
      if( y % 400 == 0 ){
        if( 29 < d ){ d = 1; m++; }
      }
      else if (y % 100 == 0 ){
        if( 28 < d ){
          d = 1;
          m++;
        }
      }
      else if ( y % 4 == 0 ){
        if( 29 < d ){
          d = 1;
          m++;
        }
      }
      else {
        if( 28 < d ){
          d = 1;
          m++;
        }
      }
    }

    if(12<m){
      m = 1;
      y++;
    }
  }

  return 0;
}
