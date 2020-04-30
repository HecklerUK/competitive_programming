#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<pll> vpl;

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
#define yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define no cout<<"No"<<endl
#define NO cout<<"NO"<<endl
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

struct ST{
  ll ud;
  ll value;
  ll cnt=1;
  ST(ll y):ud(0),value(y){
  }

  void update(ll num){
    if(ud==0){
      if(num==value)
        return;
      if(num<value)
        ud=-1;
      else
        ud=1;

      cnt++;
    }
    else if(ud==1){
      if(num<value){
        ud*=-1;
        cnt++;
      }
    }
    else if(ud==-1){
      if(value<num){
        ud*=-1;
        cnt++;
      }
    }

    value=num;
    return;
  }

};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  vll a(n);

  REP(i,n)cin>>a[i];

  ST st(a[0]);
  REP1(i,n)st.update(a[i]);
  if(st.cnt<=2)
    cout<<0<<endl;
  else
    cout<<st.cnt<<endl;
}

