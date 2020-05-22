#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using ld=long double;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pdd=pair<ld,ld>;
using vll=vector<ll>;
using vld=vector<ld>;
using vpl=vector<pll>;
using vpd=vector<pdd>;
using vvll=vector<vll>;
using vst=vector<string>;

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

const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};


const ll MAX_N=200;
vpl point(MAX_N);


struct Solve{
  ll n;
  vll state;
  ld best_score=0;
  ld pre_score=0;
  vld dist;
  ld start_temp=5000;
  ld end_temp=1000;
  ld grobal_sum;


  random_device seed_gen;
  default_random_engine engine;
  uniform_int_distribution<ll> ram;

  Solve(ll n):n(n),state(n,0),ram(0,n-1),dist(n){
    REP(i,n)state[i]=i;
    engine=default_random_engine(seed_gen());
  }

  void init(){
    best_score=calcScore();
    pre_score=best_score;
  }

  void modify(ll l, ll r){
    swap(state[l],state[r]);
  }

  ld kyori(pdd a, pdd b){
    ld res=(a.FI-b.FI)*(a.FI-b.FI)+(a.SE-b.SE)*(a.SE-b.SE);
    return sqrt(res);
  }

  ld calcScore(){
    ld variance=0;
    ld average;
    ld sum=0;

    REP(i,n){
      dist[i]=kyori(point[state[(i+1)%n]],point[state[i]]);
      sum+=dist[i];
    }
    grobal_sum=sum;

    average=sum/n;
    REP(i,n)variance+=(dist[i]-average)*(dist[i]-average);
    variance/=n;

    ld res=1e6/(1+variance);
    return res;
  }


  void climbMountain(){
    ll l=ram(engine);
    ll r=ram(engine);
    if(l==r)
      return;

    modify(l,r);
    ld now_score=calcScore();
    if(best_score<now_score)
      best_score=now_score;
    else
      modify(r,l);
  }

  void yakinamashi(ll now_cnt, ll end_cnt){

    ll l=ram(engine);
    ll r=ram(engine);
    if(l==r)
      return;

    modify(l,r);
    ld new_score=calcScore();

    ld temp = start_temp + (end_temp - start_temp) * now_cnt / end_cnt;
    ld prob=exp((new_score-pre_score)/temp);

    if(now_cnt<200){
    cout<<"score:"<<pre_score<<":"<<new_score<<endl;
    cout<<"prob:"<<prob<<":"<<(rand()%INF)/(double)INF<<endl;
    cout<<endl;
    }

    if (prob > (ram(engine)%n)/(double)n) {
      pre_score=new_score;
    }
    else{
      modify(r,l);
    }

  }


  void updateScore(ll l, ll r){
    ld before=dist[(l-1+n)%n]+dist[l]+dist[(r-1+n)%n]+dist[r];

    ld variance=0;
    ld average;

    dist[(l-1+n)%n]=kyori(point[state[(l-1+n)%n]],point[state[l]]);
    dist[l]=kyori(point[state[(l+1)%n]],point[state[l]]);
    dist[(r-1+n)%n]=kyori(point[state[(r-1+n)%n]],point[state[r]]);
    dist[r]=kyori(point[state[(r+1)%n]],point[state[r]]);
    ld after=dist[(l-1+n)%n]+dist[l]+dist[(r-1+n)%n]+dist[r];

    grobal_sum=grobal_sum-before+after;

//    average=sum/n;
//    REP(i,n)variance+=(dist[i]-average)*(dist[i]-average);
//    variance/=n;
  }

};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const ll TIME_LIMIT=1900; //ms
  chrono::system_clock::time_point begin_time,now_time;
  begin_time=chrono::system_clock::now();


  ll n;
  cin>>n;

  Solve sl(n);
  REP(i,n)cin>>point[i].FI>>point[i].SE;

  sl.init();
  ll cnt=0;
  ll kosin=0;
  ll end_cnt=450000;
  while(true){
    if(kosin<cnt/40000){
      kosin=cnt/40000;

      now_time=chrono::system_clock::now();
      ld diff_time=chrono::duration_cast<chrono::milliseconds>(now_time-begin_time).count();
      if (diff_time > TIME_LIMIT) break;
    }

    sl.climbMountain();
   // sl.yakinamashi(cnt,end_cnt);
    cnt++;
  }




  REP(i,n)cout<<sl.state[i]<<endl;

//  cout<<Decimal;
//  cout<<"best_score:"<<sl.best_score<<endl;
//  cout<<"pre_score:"<<sl.pre_score<<endl;
//  cout<<"cnt:"<<cnt<<endl;
}

