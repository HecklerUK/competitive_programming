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
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL

const int inf = 1e9;
const ll linf = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

ll h,w,k;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>h>>w>>k;
  vector<string> s(h);
  REP(i,h)cin>>s[i];

  ll check=0;
  REP(i,h){
    REP(j,w){
      if(s[i][j]=='1')
        check++;
    }
  }

  if(check<=k){
    cout<<0<<endl;
    return 0;
  }


  vector<vll> remind(h+1,vll(w+1));
  REP(i,h){
    REP(j,w){
      remind[i][j+1] = remind[i][j];
      if(s[i][j]=='1')
        remind[i][j+1]++;
    }
  }

  ll ans=LLINF;
  REP(bit, (1<<(h-1))){
    ll lw=0;
    ll rw=0;
    ll cnt=0;
    bool canflag=true;
    REP(i,w){
      rw = i+1;
      ll sum=0;
      ll maxsum=0;
      REP(j,h){
        sum+=remind[j][rw]-remind[j][lw];
        maxsum = max(maxsum,sum);
        if((bit>>j)&1)
          sum=0;
      }

      if(maxsum>k){
        if(lw==rw-1){
          canflag=false;
          break;
        }
        else
          lw=rw-1;
        cnt++;
      }
    }

    REP(j,h){
      if((bit>>j)&1)
        cnt++;
    }

    if(canflag)
      ans = min(ans,cnt);
  }

  cout<<ans<<endl;

}

