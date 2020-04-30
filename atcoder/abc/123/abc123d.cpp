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

  vll xyz(3, 0);
  ll k;
  cin >> xyz[0] >> xyz[1] >> xyz[2] >> k;
  vector<vll> v(3, vll(*max_element(xyz.begin(), xyz.end())));

  REP(i, 3){
    REP(j, xyz[i])
      cin >> v[i][j];
  }

  sort(v[0].rbegin(), v[0].rend());
  sort(v[1].rbegin(), v[1].rend());
  sort(v[2].rbegin(), v[2].rend());
 // REP(i, 3){
 //   REP(j, xyz[i])
 //     cout << v[i][j] << ' ';
 //   cout << endl;
 // }

  map<pair<int,pair<int,int>>, bool> visi;

 
  vll index(3, 0);

  priority_queue<pair<ll, vll>> que;
  pair<ll, vll> p = make_pair(0, index);
  REP(j, 3)
    p.FI += v[j][p.SE[j]];

  ll x,y,z;
  que.push(p);
  ll kCount = 0;
  while(que.empty() != true){
    pair<ll, vll> now = que.top();
    que.pop();
    cout << now.FI << "\n";
    //REP(i, 3)
    //  cout << now.SE[i] << ' ';
    //cout << endl;

    kCount++;
    if(kCount >= k)
      break;

    REP(i, 3){
      now.SE[i]++;
      x = now.SE[0];
      y = now.SE[1];
      z = now.SE[2];
      if(now.SE[i] >= xyz[i]){
        now.SE[i]--;
        continue;
      }
      if(!visi[MP(x, MP(y, z))]){
        visi[MP(x, MP(y, z))] = 1;
        now.FI = v[0][x] + v[1][y] + v[2][z];
        que.push(now);
      }
      now.SE[i]--;
    }
  }

}
