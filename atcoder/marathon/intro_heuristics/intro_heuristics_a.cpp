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


const ll MAX_D=365;
const ll NUM=26;

ll d;
vll c(NUM);
vvll s(MAX_D,vll(NUM));
vll ans(MAX_D);
vll decrease(NUM,0);


struct Solve{
  random_device seed_gen;
  default_random_engine engine;
  uniform_int_distribution<ll> day;
  uniform_int_distribution<ll> val;

  ll best_score=0;
  ll pre_score=0;

  Solve():day(0,MAX_D-1),val(0,NUM-1){
//    REP(i,d)ans[i]=i%NUM;
    for(ll i=0; i<d; i++){
      ll m=0;
      ll mi=0;
      REP(j,NUM){
        if(m<s[i][j]){
          m=s[i][j];
          mi=j;
        }
      }
      ans[i]=mi;
    }

    engine=default_random_engine(seed_gen());
  }


  void init(){
    best_score=calcScore();
    pre_score=best_score;
  }


  void modify(ll index, ll value){
    //swap(state[l],state[r]);
    ans[index]=value;
  }

  void modify2(ll index){
    swap(ans[index],ans[index+1]);
  }



  ll calcScore(){

    vll last(NUM,-1);
    ll score=0;
    REP(i,d){
      ll now=ans[i];
      last[now]=i;

      ll cost=0;
      REP(j,NUM){
        cost+=c[j]*(i-last[j]);
        decrease[j]+=c[j]*(i-last[j]);
      }

      score+=s[i][now]-cost;
    }

    //score=max(ll(score+1e6),0LL);
    return score;
  }


  bool climbMountain(){
    ll value=val(engine);
    ll index=day(engine);

//    ll a=0;
//    REP(i,NUM){
//      if(a<decrease[i]){
//        a=decrease[i];
//        value=i;
//      }
//    }

    ll prevalue=ans[index];
    modify(index,value);
    //modify2(index);
    ll now_score=calcScore();


    bool res=best_score<now_score;
    if(best_score<now_score)
      best_score=now_score;
    else
      modify(index,prevalue);

    return res;
  }


};


ll calc(ll x){
  return max(ll(x+1e6),0LL);
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  const ll TIME_LIMIT=1900; //ms
  chrono::system_clock::time_point begin_time,now_time;
  begin_time=chrono::system_clock::now();

  cin>>d;
  REP(i,NUM)cin>>c[i];
  REP(i,d)REP(j,NUM)cin>>s[i][j];


  Solve sl=Solve();
  sl.init();

  ll cnt=0;
  ll kosin=0;
  ll vcosin=0;
  while(true){
    if(kosin<cnt/10000){
      kosin=cnt/10000;

      now_time=chrono::system_clock::now();
      ld diff_time=chrono::duration_cast<chrono::milliseconds>(now_time-begin_time).count();
      if (diff_time > TIME_LIMIT) break;
    }

    if(sl.climbMountain())
      vcosin++;
    cnt++;
  }

  cout<<calc(sl.best_score)<<endl;
  cout<<cnt<<endl;
  cout<<"update:"<<vcosin<<endl;

//  REP(i,d)cout<<ans[i]+1<<endl;
}

