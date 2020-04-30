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

map<ll, pll> pointMap;
vector<vector<ll>> board(3, vector<ll>(3));

vector<vector<ll>> b(2, vector<ll>(3)), c(3, vector<ll>(2));

ll dfs(ll cur){
  ll point = 0;

  if(cur == 9){
    point = 0;
    REP(i, 2){
      REP(j, 3){
        if(board[i][j] == board[i+1][j])
          point += b[i][j];
        else
          point -= b[i][j];
      }
    }
    REP(i, 3){
      REP(j, 2){
        if(board[i][j] == board[i][j+1])
          point += c[i][j];
        else
          point -= c[i][j];
      }
    }
    return point;
  }


  //chokudai's turn
  point = cur%2==0 ? -inf : inf;
  REP(i, 3){
    REP(j, 3){
      if(board[i][j] != 0)
        continue;
      if(cur % 2 == 0){
        board[i][j] = 1;
        point = max(point, dfs(cur+1));
      }
      else{
        board[i][j] = -1;
        point = min(point, dfs(cur+1));
      }
      board[i][j] = 0;
    }
  }
  return point;

}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  
  ll plus = 0;
  REP(i, 2){
    REP(j, 3){
      cin >> b[i][j];
      plus += b[i][j];
    }
  }

  REP(i, 3){
    REP(j, 2){
      cin >> c[i][j];
      plus += c[i][j];
    }
  }
  
  REP(i, 3){
    REP(j, 3)
      board[i][j] = 0;
  }
  
  ll minus = dfs(0);
  cout << (plus + minus) / 2 << endl;
  cout << (plus - minus) / 2 << endl;

}

