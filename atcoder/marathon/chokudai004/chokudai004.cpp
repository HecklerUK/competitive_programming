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



vll b(3);
struct CalcPoint{
  random_device seed_gen;
  default_random_engine engine;

  ll x,y,score;
  vvll cells,remind_y,remind_x;

  CalcPoint(ll x, ll y):x(x),y(y),cells(y,vll(x,0)),remind_y(x,vll(y,0)),remind_x(y,vll(x,0)){
    engine=default_random_engine(seed_gen());
    score=0;
  }

  //rewrite
  void init(vvll& l, vvll& r){
    REP(i,y){
      REP(j,x){
        uniform_int_distribution<ll> dist(l[i][j], r[i][j]);
        ll result=dist(engine);
        cells[i][j]=result;
      }
    }

    updateScore();
  }

  //rewrite
  void climbMountain(vvll& l, vvll& r){
    uniform_int_distribution<ll> distx(0,x-1);
    uniform_int_distribution<ll> disty(0,y-1);
    ll X=distx(engine);
    ll Y=disty(engine);

    //全探索?
//    uniform_int_distribution<ll> dist(l[Y][X], r[Y][X]);
//    ll result=dist(engine);
    ll before=cells[Y][X];
    //cells[Y][X]=result;
    if(before+1<=r[Y][X]){
      cells[Y][X]=before+1;
      if(score < calcScore(X,Y))
        updateScore(X,Y);
      else
        cells[Y][X]=before;
    }

    if(l[Y][X]<=before-1){
      cells[Y][X]=before-1;
      if(score < calcScore(X,Y))
        updateScore(X,Y);
      else
        cells[Y][X]=before;
    }

  }


  ll getScore(){
    return score;
  }


  void updateScore(ll X=-1, ll Y=-1){
    if(X==-1&&Y==-1){
      ll point=0;
      //tate
      REP(i,x){
        REP(j,y)
          remind_y[i][j+1]=remind_y[i][j]+cells[j][i];
        point+=sumScore(remind_y[i]);
      }

      //yoko
      REP(i,y){
        REP(j,x)
          remind_x[i][j+1]=remind_x[i][j]+cells[i][j];
        point+=sumScore(remind_x[i]);
      }

      score=point;
    }
    else{
      ll pre_score=0;
      pre_score+=sumScore(remind_y[X]);
      pre_score+=sumScore(remind_x[Y]);


      ll next_score=0;
      //tate
      REP(j,y)
        remind_y[X][j+1]=remind_y[X][j]+cells[j][X];
      next_score+=sumScore(remind_y[X]);

      //yoko
      REP(j,x)
        remind_x[Y][j+1]=remind_x[Y][j]+cells[Y][j];
      next_score+=sumScore(remind_x[Y]);


      score=score-pre_score+next_score;
    }

  }


  ll sumScore(vll& remind){
    ll res=0;
    REP(k,remind.size()-1){
      //sum[0,k)
      ll before=remind[k]-remind[0];
      REP(j,3){
        ll target=before+b[j];
        auto it=lower_bound(ALL(remind),target);
        if(it==remind.end())
          continue;

        if(*it==target)
          res+=b[j];
      }
    }
    return res;
  }

  //rewrite
  ll calcScore(ll X, ll Y){
    ll pre_score=0;
    pre_score+=sumScore(remind_y[X]);
    pre_score+=sumScore(remind_x[Y]);


    ll next_score=0;
    //tate
    vll remind_tmp_y(y+1);
    REP(j,y)
      remind_tmp_y[j+1]=remind_tmp_y[j]+cells[j][X];
    next_score+=sumScore(remind_tmp_y);

    //yoko
    vll remind_tmp_x(x+1);
    REP(j,x)
      remind_tmp_x[j+1]=remind_tmp_x[j]+cells[Y][j];
    next_score+=sumScore(remind_tmp_x);

    return score-pre_score+next_score;
  }

};



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const ll TIME_LIMIT=2900; //ms
  chrono::system_clock::time_point begin_time,now_time;
  begin_time=chrono::system_clock::now();


  ll n;
  cin>>n;
  REP(i,3)cin>>b[i];

  vvll l(n,vll(n)), r(n,vll(n));
  REP(i,n)REP(j,n)cin>>l[i][j];
  REP(i,n)REP(j,n)cin>>r[i][j];


  CalcPoint cp(n,n);
  cp.init(l,r);

//  cout<<cp.getScore()<<endl;
//  ll cnt=0;
  while(true){
//    cnt++;

    now_time=chrono::system_clock::now();
    ld diff_time=chrono::duration_cast<chrono::milliseconds>(now_time-begin_time).count();
    if (diff_time > TIME_LIMIT) break;

    cp.climbMountain(l,r);
  }


 // ll ans=cp.getScore();
 // cout<<ans<<endl;
 // cout<<"count:"<<cnt<<endl;

  REP(i,n){
    cout<<cp.cells[i][0];
    REP1(j,n)
      cout<<" "<<cp.cells[i][j];
    cout<<endl;
  }
}

