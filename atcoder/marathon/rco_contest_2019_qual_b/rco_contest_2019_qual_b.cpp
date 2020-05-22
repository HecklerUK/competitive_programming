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


const ll MAX_N=50;


//struct Solve{
//  ll n,m;
//  vvll state;
//  vvll yard;
//  ld best_score=0;
//  ld pre_score=0;
//  ld start_temp=5000;
//  ld end_temp=1000;
//  ld grobal_sum;
//
//  vvll visited;
//
//
//  random_device seed_gen;
//  default_random_engine engine;
//  uniform_int_distribution<ll> ram;
//
//  Solve(ll n, ll m):n(n),m(m),state(m,vll(3,0)),yard(n,vll(n)),visited(n,vll(n,0)),ram(0,n-1){
//    REP(i,m){
//      state[i][0]=2;
//      state[i][1]=i/n;
//      state[i][2]=i%n;
//    }
//
//    engine=default_random_engine(seed_gen());
//  }
//
//  void init(){
//    best_score=calcScore();
//    pre_score=best_score;
//  }
//
//  void modify(ll l, ll r){
//    swap(state[l],state[r]);
//  }
//
//  ld kyori(pdd a, pdd b){
//    ld res=(a.FI-b.FI)*(a.FI-b.FI)+(a.SE-b.SE)*(a.SE-b.SE);
//    return sqrt(res);
//  }
//
//
//  ll dfs(ll x, ll y, ll k){
//    ll res=0;
//
//    if(yard[y][x]!=k || k==-1 || visited[y][x])
//      return res;
//
//    visited[y][x]=1;
//    res+=1;
//
//    REP(i,4){
//      if(x+dx[i]<0 || n<=x+dx[i] || y+dy[i]<0 || n<=y+dy[i])
//        continue;
//      cout<<n<<":"<<x<<":"<<y<<":"<<k<<endl;
//      if(yard[y+dy[i]][x+dx[i]]!=k)
//        continue;
//      res+=dfs(x+dx[i],y+dy[i],k);
//    }
//    return res;
//  }
//
//
//  ll calcScore(){
//    REP(i,n)REP(j,n)yard[i][j]=point[i][j];
//    ll res=0;
//    REP(i,m){
//      cout<<i<<endl;
//      ll y=state[i][1];
//      ll x=state[i][2];
//      if(state[i][0]==1)
//        yard[y][x]++;
//      else{
//        ll k=yard[y][x];
//        res+=dfs(x,y,k);
//      }
//    }
//    return res;
//  }
//
//
//  void climbMountain(){
//    ll l=ram(engine);
//    ll r=ram(engine);
//    if(l==r)
//      return;
//
//    modify(l,r);
//    ld now_score=calcScore();
//    if(best_score<now_score)
//      best_score=now_score;
//    else
//      modify(r,l);
//  }
//
//  void yakinamashi(ll now_cnt, ll end_cnt){
//
//    ll l=ram(engine);
//    ll r=ram(engine);
//    if(l==r)
//      return;
//
//    modify(l,r);
//    ld new_score=calcScore();
//
//    ld temp = start_temp + (end_temp - start_temp) * now_cnt / end_cnt;
//    ld prob=exp((new_score-pre_score)/temp);
//
//    if(now_cnt<200){
//    cout<<"score:"<<pre_score<<":"<<new_score<<endl;
//    cout<<"prob:"<<prob<<":"<<(rand()%INF)/(double)INF<<endl;
//    cout<<endl;
//    }
//
//    if (prob > (ram(engine)%n)/(double)n) {
//      pre_score=new_score;
//    }
//    else{
//      modify(r,l);
//    }
//
//  }
//
//
//  void updateScore(ll l, ll r){
//  }
//
//};



ll n,m;
ll dfs(ll x, ll y, ll k, vvll& yard){
  ll res=0;

  if(yard[y][x]!=k)
    return res;

  res+=k;
  yard[y][x]=-1;
  REP(i,4){
    if(x+dx[i]<0 || n<=x+dx[i] || y+dy[i]<0 || n<=y+dy[i])
      continue;
    res+=dfs(x+dx[i],y+dy[i],k,yard);
  }
  return res;
}





int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

//  const ll TIME_LIMIT=1900; //ms
//  chrono::system_clock::time_point begin_time,now_time;
//  begin_time=chrono::system_clock::now();


  cin>>n>>m;

//  Solve sl(n,m);
  vvll point(n,vll(n));
  REP(i,n)REP(j,n)cin>>point[i][j];

  vvll best_state(m,vll(3));
  ll best_score=0;

//determin value
  ll k=9;
  {
    ll sum=0;
    vvll yard=point;
    vvll now_state(m,vll(3));
    REP(i,m)now_state[i][0]=2;

    REP(i,n){
      REP(j,n){
        if(6<=yard[i][j] && sum<m){
          ll p=k-yard[i][j];
          if(m<=sum+p)
            continue;

          REP(h,k-yard[i][j])
            now_state[sum+h]={1,i,j};
          sum+=k-yard[i][j];
          yard[i][j]=k;
        }
      }
    }

    //  REP(i,n){
    //    cout<<yard[i][0];
    //    REP1(j,n)
    //      cout<<" "<<yard[i][j];
    //    cout<<endl;
    //  }

    bool flag=false;
    pll p;
    REP(i,n){
      REP(j,n){
        vvll now=yard;
        ll now_score=dfs(i,j,k,now);
        if(best_score<now_score){
          flag=true;
          p=pll(i,j);
        }
        best_score=max(best_score,now_score);
      }
    }

    cout<<best_score<<endl;
    now_state[sum]={2,p.FI,p.SE};
    swap(best_state,now_state);
  }

//  cout<<best_score<<endl;
  REP(i,m){
    cout<<best_state[i][0];
    REP1(j,3)
      cout<<" "<<best_state[i][j];
    cout<<endl;
  }

}

