#include <bits/stdc++.h>
#include <algorithm>
#include <random>
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
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

ll n = 40;
ll m = 100;
ll b = 300;
ll gy,gx;
const char R[4] = {'U', 'D', 'L', 'R'};
#define MAX_N 20000



void ansGen(vector<pll>& yx, vector<char>& r, mt19937 engine){
  uniform_int_distribution<> dist(0, 3);

  //REP(i, yx.size()){
  //  yx[i].FI = i/n;
  //  yx[i].SE = i%n;
  //}
  REP(i, r.size())
    r[i] = R[dist(engine)];
  shuffle(yx.begin(), yx.end(), engine);
}

void ansUpdate(vector<pll>& yx, vector<pll>& avoidB, vector<char>& r, ll k, mt19937 engine){
  uniform_int_distribution<> distin(0, k-1);
  uniform_int_distribution<> distout(k+avoidB.size(), n*n-1);

  //swap
  ll swapin = distin(engine);
  ll swapout = distout(engine);
  pll tmp = yx[swapin];
  yx[swapin] = yx[swapout];
  yx[swapout] = tmp;

  char tmp_c = r[swapin+avoidB.size()];
  r[swapin+avoidB.size()] = r[swapout+avoidB.size()];
  r[swapout+avoidB.size()] = tmp_c;

  uniform_int_distribution<> remake(0+avoidB.size(), k-1+avoidB.size());
  uniform_int_distribution<> dist(0, 3);
  r[remake(engine)] = R[dist(engine)];

}



ll repairCur(ll now){
  if(now < 0)
    now += 40;
  if(40 <= now)
    now -= 40;
  return now;
}



ll calcScore(vector<vector<char>> field, ll k, vector<pll> yx,  vector<pll> avoidB, vector<char> r, vll ry, vll rx, vector<char> c){
  vector<vll> path(n, vll(n, 0));
  ll goal = 0;

  REP(i, avoidB.size()){
    if(field[yx[i].FI][yx[i].SE] == 'a')
      field[yx[i].FI][yx[i].SE] = r[i];
  }

  REP(i, k){
    if(field[yx[i].FI][yx[i].SE] == 'a')
      field[yx[i].FI][yx[i].SE] = r[i+avoidB.size()];
  }
//    cout << yx[i].FI << ":" << yx[i].SE << ":" << r[i] << endl;

  //robots
  REP(i, m){
    pll now = pll(ry[i], rx[i]);
    pll pre1 = pll(ry[i], rx[i]);
    pll pre2 = pll(ry[i], rx[i]);
    ll cnt = 0;
    while(cnt < 1600){
      //prep
      //============
      path[now.FI][now.SE] = 1;
      if(field[now.FI][now.SE] == 'G'){
        goal++;
        break;
      }
      REP(j, 4){
        if(R[j] == field[now.FI][now.SE])
          c[i] = R[j];
      }
      pre2 = pre1;
      pre1 = pll(now.FI, now.SE);
      //============

      REP(j, 4){
        if(R[j] == c[i]){
          now.FI = repairCur(now.FI+dy[j]);
          now.SE = repairCur(now.SE+dx[j]);
        }
      }

      if(field[now.FI][now.SE] == 'B'){
        break;
      }

      if(now.FI == pre2.FI && now.SE == pre2.SE)
        break;
      cnt++;
    }
  }


  ll sum = 0;
  REP(i, n){
    REP(j, n)
      sum += path[i][j];
  }

  ll score = 1000*goal - 10*k + sum;
  return score;
}




int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  //==============================
  cin >> n >> m >> b;
  cin >> gy >> gx;
  vll ry(m), rx(m);
  vector<char> c(m);
  REP(i, m)
    cin >> ry[i] >> rx[i] >> c[i];

  vll by(b), bx(b);
  REP(i, b)
    cin >> by[i] >> bx[i];

  vector<vector<char>> field(n, vector<char>(n));
  REP(i, n){
    REP(j, n)
      field[i][j] = 'a';
  }

  REP(i, b)
    field[by[i]][bx[i]] = 'B';
  field[gy][gx] = 'G';

  //==============================

  vector<pll> avoidB;
  REP(i, b){
    REP(j, 4)
      avoidB.push_back(pll(repairCur(by[i]+dy[j]), repairCur(bx[i]+dx[j])));
  }

  sort(avoidB.begin(), avoidB.end());
  auto it = unique(avoidB.begin(), avoidB.end());
  avoidB.erase(it, avoidB.end());

  vector<pll> others;
  ll cur = 0;
  REP(i, n*n){
    ll y = i/n;
    ll x = i%n;
    if(avoidB[cur].FI == y && avoidB[cur].SE == x){
      cur++;
      continue;
    }
    others.push_back(pll(y, x));
  }


  random_device seed_gen;
  mt19937 engine(seed_gen());
  //mt19937 engine(114);
  uniform_int_distribution<> dist(50, 100);


  vector<pll> ans_yx;
  vector<char> ans_r;
  ll ans_score = -LLINF;
  ll cnt = 0;
  ll ans_k;
  ll pre_score = -LLINF;

  ll k = dist(engine);
  vector<char> r(n*n);
  while(cnt < MAX_N){
    //k = 10;
    //cout << k << endl;
    ansGen(others, r, engine);

    ll score = calcScore(field, k, others, avoidB, r, ry, rx, c);
    if(score > pre_score){
      k += 1;
      if(score > ans_score){
        ans_score = score;
        ans_yx = others;
        ans_r = r;
        ans_k = k;
      }
    }
    else{
      k -= 1;
    }
    pre_score = score;
    cnt++;
  }
 // cout << "ans_score:" << ans_score << endl;


  //ansGen(yx, r, engine);
//  cnt = 0;
//  vector<pll> pre_yx = others;
//  while(cnt < MAX_N){
//    REP(i, 10){
//      ansUpdate(others, avoidB, r, k, engine);
//    }
//
//
//    ll score = calcScore(field, k, others, avoidB, r, ry, rx, c);
//    if(score > pre_score){
//      k += 1;
//      pre_yx = others;
//      if(score > ans_score){
//        ans_score = score;
//        ans_yx = others;
//        ans_r = r;
//        ans_k = k;
//      }
//    }
//    else{
//      k -= 1;
//      others = pre_yx;
//    }
//    pre_score = score;
//    cnt++;
//  }
//
//  cout << "ans_score:" << ans_score << endl;

  cout << ans_k+avoidB.size() << endl;
  REP(i, avoidB.size())
    cout << avoidB[i].FI << ' ' <<  avoidB[i].SE << ' ' << ans_r[i] << endl;
  REP(i, ans_k)
    cout << ans_yx[i].FI << ' ' << ans_yx[i].SE << ' ' << ans_r[i+avoidB.size()] << endl;

}
