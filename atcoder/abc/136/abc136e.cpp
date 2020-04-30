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

ll n, k;

ll gcdSearch(vll a, ll gcd){
  vll modPlus(n), modMinus(n);
  ll A, B;
  A = B = 0;
  REP(i, n){
    modPlus[i] = a[i] % gcd;
    //modMinus[i] = gcd - a[i] % gcd;
    B += gcd - modPlus[i];
  }
  sort(modPlus.begin(), modPlus.end());
  //sort(modMinus.begin(), modMinus.end());

  ll mpIndex, mmIndex, counter, kCounter;
  mpIndex = mmIndex = counter = kCounter = 0;
  ll need = LLINF;
  REP(i, n){
    A += modPlus[i];
    B -= gcd - modPlus[i];
    need = min(need, max(A, B));

    //if(modPlus[mpIndex] > modMinus[mmIndex]){
    //  modPlus[mpIndex] -= modMinus[mmIndex];
    //  kCounter += modMinus[mmIndex];
    //  mmIndex++;
    //  counter++;
    //}
    //else if(modPlus[mpIndex] < modMinus[mmIndex]){
    //  modMinus[mmIndex] -= modPlus[mpIndex];
    //  kCounter += modPlus[mpIndex];
    //  mpIndex++;
    //  counter++;
    //}
    //else{
    //  kCounter += modPlus[mpIndex];
    //  mmIndex++;
    //  mpIndex++;
    //  counter += 2;
    //}
    //if(kCounter > k)
    //  return false;
    //if(counter == n)
    //  return true;
  }
  return need;

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;
  vll a(n);
  ll sum = 0;
  REP(i, n){
    cin >> a[i];
    sum += a[i];
  }
  set<ll> gcd;
  for(ll i = 1; i*i <= sum; i++){
    if(sum % i == 0){
      gcd.insert(i);
      gcd.insert(sum/i);
    }
  }

  ll ans = 1;
  for(ll x : gcd){
    if(gcdSearch(a, x) <= k)
      ans = max(ans, x);
  }

  cout << ans << "\n";
  
  
}
