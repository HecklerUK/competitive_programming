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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  vll x(n),y(n);
  vector<char> u(n);
  REP(i,n)cin>>x[i]>>y[i]>>u[i];

  map<char,ll> index;
  index['U']=0;
  index['R']=1;
  index['D']=2;
  index['L']=3;
  ll MAX_X=2e5+10;
  vector<vvll> mi(4,vvll(2*MAX_X)),pu(4,vvll(2*MAX_X));
  vector<vvll> xax(4,vvll(MAX_X)),yax(4,vvll(MAX_X));

  REP(i,n){
    ll in=index[u[i]];
    ll Xm=x[i]+y[i];
    ll Xp=x[i]-y[i]+MAX_X;
    mi[in][Xm].push_back(y[i]);
    pu[in][Xp].push_back(y[i]);
    xax[in][x[i]].push_back(y[i]);
    yax[in][y[i]].push_back(x[i]);
  }

  REP(i,4){
    REP(j,2*MAX_X){
      sort(ALL(mi[i][j]));
      sort(ALL(pu[i][j]));
    }
    REP(j,MAX_X){
      sort(ALL(xax[i][j]));
      sort(ALL(yax[i][j]));
    }
  }


  ll time=LLINF;
  REP(i,n){
    ll in=index[u[i]];
    if(in%2==0){
      //up
      if(in==0){
        auto it=upper_bound(ALL(xax[(in+2)%4][x[i]]),y[i]);
        if(it!=xax[(in+2)%4][x[i]].end())
          time=min(time,(*it-y[i])*5);
      }
      //down
      else{
        auto it=lower_bound(ALL(xax[(in+2)%4][x[i]]),y[i]);
        if(it!=xax[(in+2)%4][x[i]].begin())
          time=min(time,(y[i]-*(it-1))*5);
      }
    }
    else{
   //right
      if(in==1){
        auto it=upper_bound(ALL(yax[(in+2)%4][y[i]]),x[i]);
        if(it!=yax[(in+2)%4][y[i]].end())
          time=min(time,(*it-x[i])*5);
      }
      //left
      else{
        auto it=lower_bound(ALL(yax[(in+2)%4][y[i]]),x[i]);
        if(it!=yax[(in+2)%4][y[i]].begin())
          time=min(time,(x[i]-*(it-1))*5);
      }
    }

    ll Xm=x[i]+y[i];
    ll Xp=x[i]-y[i]+MAX_X;
    if(in%2==0){
      //up
      if(in==0){
        if(mi[index['R']][Xm].size()!=0){
          auto it1=upper_bound(ALL(mi[index['R']][Xm]),y[i]);
          if(it1!=mi[index['R']][Xm].end())
            time=min(time,(*it1-y[i])*10);
        }

        if(pu[index['L']][Xp].size()!=0){
          auto it2=upper_bound(ALL(pu[index['L']][Xp]),y[i]);
          if(it2!=pu[index['L']][Xp].end())
            time=min(time,(*it2-y[i])*10);
        }
      }

      else{
        //down
        if(mi[index['L']][Xm].size()!=0){
          auto it1=lower_bound(ALL(mi[index['L']][Xm]),y[i]);
          if(it1!=mi[index['L']][Xm].begin())
            time=min(time,(y[i]-*(it1-1))*10);
        }

        if(pu[index['R']][Xp].size()!=0){
          auto it2=upper_bound(ALL(pu[index['R']][Xp]),y[i]);
          if(it2!=pu[index['R']][Xp].begin())
            time=min(time,(y[i]-*(it2-1))*10);
        }
      }
    }

  }

  if(time==LLINF)
    cout<<"SAFE"<<endl;
  else{
    ll ans=time;
    cout<<ans<<endl;
  }
}

