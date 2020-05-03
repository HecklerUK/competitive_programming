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

const ll MAX_N=1e5;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,a,b,c;
  cin>>n>>a>>b>>c;

  vector<string> s(n);
  REP(i,n)cin>>s[i];

  vector<string> ans(n);
  REP(i,n){
    if(s[i]=="AB"){
      if((a==1 && b==1) && i!=n-1){
        if(s[i+1]=="AC"){
          a++;
          b--;
          ans[i]="A";
        }
        else{
          a--;
          b++;
          ans[i]="B";
        }
      }
      else if(a<b){
        a++;
        b--;
        ans[i]="A";
      }
      else{
        a--;
        b++;
        ans[i]="B";
      }
    }


    if(s[i]=="BC"){
      if((b==1 && c==1) && i!=n-1){
        if(s[i+1]=="AB"){
          b++;
          c--;
          ans[i]="B";
        }
        else{
          b--;
          c++;
          ans[i]="C";
        }
      }
      else if(b<c){
        b++;
        c--;
        ans[i]="B";
      }
      else{
        b--;
        c++;
        ans[i]="C";
      }
    }


    if(s[i]=="AC"){
      if((a==1 && c==1) && i!=n-1){
        if(s[i+1]=="AB"){
          a++;
          c--;
          ans[i]="A";
        }
        else{
          a--;
          c++;
          ans[i]="C";
        }
      }
      else if(a<c){
        a++;
        c--;
        ans[i]="A";
      }
      else{
        a--;
        c++;
        ans[i]="C";
      }
    }

    if(a<0 || b<0 || c<0){
      cout<<"No"<<endl;
      return 0;
    }
  }


  cout<<"Yes"<<endl;
  REP(i,n)cout<<ans[i]<<endl;
}

