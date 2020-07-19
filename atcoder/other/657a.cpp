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

  ll t;
  cin>>t;

  string target="abacaba";
  ll m=7;
  REP(i,t){
    ll n;
    cin>>n;
    string s;
    cin>>s;

    ll cnt=0;
    bool ans=false;
    ll start=0;
    for(ll k=0; k+m-1<n; k++){
      string tmp=s.substr(k,m);

      //check cnt
      if(tmp==target){
        cnt++;
        if(1<cnt)
          break;
      }


      bool flag=true;
      REP(j,m){
        if(tmp[j]!=target[j] && tmp[j]!='?')
          flag=false;
      }

      if(flag){
        ll l=max(0LL,k-7);
        ll r=min(n-1,k+7);
        REP(j,m)
          s[k+j]=target[j];

        ll kcnt=0;
        for(ll j=l; j<=r; j++){
          string ktmp=s.substr(j,m);
          if(ktmp==target)
            kcnt++;
        }

        REP(j,m)
          s[k+j]=tmp[j];

        if(kcnt==1){
          ans=true;
          start=k;
        }
      }
    }

    if(1<cnt)
      no;

    if(cnt==1){
      yes;
      REP(j,n){
        if(s[j]=='?')
          cout<<'z';
        else
          cout<<s[j];
      }
      cout<<endl;
    }

    if(cnt==0){
      if(ans){
        yes;
        REP(j,m){
          s[start+j]=target[j];
        }
        REP(j,n){
          if(s[j]=='?')
            cout<<'z';
          else
            cout<<s[j];
        }
        cout<<endl;
      }
      else
        no;
    }

  }

}

