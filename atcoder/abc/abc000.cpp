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

ll seedPlus(ll now){
  ll next = (now*0x41C64E6D+0x6073)%0x100000000;
  return next;
}

ll seedMinus(ll now){
  ll prev = (now*0xEEB9EB65+0xA3561A1)%0x100000000;
  ll mask = 0xFFFFFFFF;
  prev = prev&mask;
  return prev;
}

bool checkTidseed(ll now){
  ll mask = 0xFFFF;
  return now==(mask&now);
}

void searchTidseed(ll seedSeeked, ll depth){

  ll now=seedSeeked;
  REP(i,depth){
    now=seedMinus(now);
    if(checkTidseed(now))
      cout<<dec<<i<<" : tid="<<now<<endl;
  }
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll seedSeeked, depth;
  cin>>hex>>seedSeeked;
  cin>>dec>>depth;
  ll next=seedPlus(seedSeeked);
  ll prev=seedMinus(seedSeeked);

  cout<<"0x"<<hex<<seedSeeked<<", depth:"<<dec<<depth<<endl;
  cout<<"next:0x"<<hex<<next<<endl;
  cout<<"prev:0x"<<hex<<prev<<endl;

  searchTidseed(seedSeeked, depth);

}




