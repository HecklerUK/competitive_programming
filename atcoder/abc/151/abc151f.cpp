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
typedef vector<vll> vvll;

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



struct P{
  ld x,y;
};

const ll MAX_N=50;
ll n;
vector<P> v(MAX_N);

ld dist(P a, P b){
  ld xd=a.x-b.x;
  ld yd=a.y-b.y;
  return sqrt(xd*xd+yd*yd);
}

ld f(P p){
  ld res=0;
  REP(i,n)
    res=max(res,dist(p,v[i]));
  return res;
}

ld fx(ld x){
  ld l=0;
  ld r=1000;
  REP(i,80){
    ld gl=(l*2+r)/3.0;
    ld gr=(l+r*2)/3.0;
    if(f(P{x,gl})<f(P{x,gr}))
      r=gr;
    else
      l=gl;
  }

  return f(P{x,l});
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>n;
  REP(i,n)cin>>v[i].x>>v[i].y;

  ld l=0;
  ld r=1000;
  REP(i,80){
    ld gl=(l*2+r)/3.0;
    ld gr=(l+r*2)/3.0;
    if(fx(gl)<fx(gr))
      r=gr;
    else
      l=gl;
  }

  cout<<Decimal;
  cout<<fx(l)<<endl;


}
