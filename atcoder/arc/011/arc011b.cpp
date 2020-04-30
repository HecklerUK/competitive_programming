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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;

  vector<string> buf(n);
  REP(i,n)cin>>buf[i];
  map<char,ll> m;
  m['b']=1;
  m['c']=1;
  m['t']=3;
  m['j']=3;
  m['l']=5;
  m['v']=5;
  m['p']=7;
  m['m']=7;
  m['n']=9;
  m['g']=9;
  m['d']=2;
  m['w']=2;
  m['f']=4;
  m['q']=4;
  m['s']=6;
  m['x']=6;
  m['h']=8;
  m['k']=8;
  m['z']=0;
  m['r']=0;

  string ng= "aeiouy";
  ll cnt=0;
  REP(i, n){
    vector<ll> v;
    REP(j,buf[i].size()){
      if('A'<=buf[i][j] && buf[i][j]<='Z')
        buf[i][j] += 'a'-'A';

      ll c = m[buf[i][j]];
      if(c==0 && !(buf[i][j]=='z' || buf[i][j]=='r'))
        continue;

      bool flag = false;
      REP(k,ng.size()){
        if(ng[k]==buf[i][j])
          flag=true;
      }
      if(flag)
        continue;

      v.push_back(c);
    }
    if(v.size()==0)
      continue;

    if(i!=0 && cnt!=0)
      cout<<" ";
    cnt++;
    REP(j,v.size())cout<<v[j];
  }

  cout<<endl;


//  vector<string> v;
//  while(getline(cin, buf, ' '))
//    v.push_back(buf);
//  REP(i,v.size())
//    cout<<v[i]<<endl;
}

