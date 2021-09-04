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

  ll k;
  cin>>k;
  string s,t;
  cin>>s>>t;

  ll h=9*1e5+100;
  vll taka(h+10);
  map<ll,ll> taka_num,ao_num;
  REP(i,4){
    taka_num[s[i]-'0']+=1;
    ao_num[t[i]-'0']+=1;
  }


  map<ll,ll> taka_mem;
  for(ll i=1; i<=9; i++){
    ll rem_i=k-taka_num[i]-ao_num[i];

    //calc pt
    ll pt=0;
    for(ll j=1; j<=9; j++){
      ll od=taka_num[j];
      if(i==j)
        od++;
      pt+=j*pow(10,od);
    }

    taka_mem[i]=pt;
    taka[pt]+=rem_i;
  }

  vll rem_taka(h+10);
  REP(i,h)rem_taka[i+1]=rem_taka[i]+taka[i];

  ll all=0;
  ll win=0;
  for(ll i=1; i<=9; i++){
    ll rem_i=k-taka_num[i]-ao_num[i];

    //calc pt
    ll pt=0;
    for(ll j=1; j<=9; j++){
      ll od=ao_num[j];
      if(i==j)
        od++;
      pt+=j*pow(10,od);
    }

    ll alpha=taka_mem[i]<=pt?0:1;

    win+=(rem_taka[h]-rem_taka[pt+1]-alpha)*rem_i;
    all+=(rem_taka[h]-rem_taka[0]-1)*rem_i;
  }


  ld ans=win*1.0/all;
  cout<<Decimal;
  cout<<ans<<endl;


}

