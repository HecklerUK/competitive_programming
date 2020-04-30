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

string before(string s){
  if(s[3]-'0'>5)
    s[3]='5';
  if(s[3]-'0'<5)
    s[3]='0';
return s;
}

string after(string s){
  if(s[3]-'0'>5){
    s[3]='0';
    if((s[2]-'0'+1)%6==0){
      s[1]=(s[1]-'0'+1)%10+'0';
      if(s[1]=='0')
        s[0] += 1;
    }
    s[2]=(s[2]-'0'+1)%6+'0';
  }
  if(s[3]-'0'<5 && s[3]-'0'!=0)
    s[3]='5';
  return s;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  vector<pair<string,string>> b(n);
  REP(i,n){
    string s;
    cin>>s;
    b[i].FI = before(s.substr(0,4));
    b[i].SE = after(s.substr(5,4));
  }


  sort(ALL(b));
  string p;
  REP(i,n){
    if(i==0){
      cout<<b[i].FI<<"-";
      p=b[i].SE;
    }
    else{
      if(p<b[i].FI){
        cout<<p<<endl;
        cout<<b[i].FI<<"-";
        p=b[i].SE;
      }
      else{
        p=max(p,b[i].SE);
      }
    }
  }

  cout<<p<<endl;
}

