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


ll mpow(ll m, ll p){
  ll power = m;
  ll res = 1;
  while(p>0){
    if(p&1)
      res = res*power%MOD;
    power = (power*power)%MOD;
    p /= 2;
  }

  return res;
}

ll mod_inv(ll m){
  return mpow(m, MOD-2);
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n,k;
  cin>>n>>k;
  vll a(n);
  REP(i,n)cin>>a[i];

  vpl b(n);
  REP(i,n){
    b[i].FI=abs(a[i]);
    b[i].SE=a[i];
  }
  sort(ALL(b), greater<pll>());

  multiset<ll> s_plus, s_minus;
  REP(i,n){
    if(0<b[i].SE)
      s_plus.insert(b[i].FI);
    else if(b[i].SE<0)
      s_minus.insert(b[i].FI);
  }


  ll ans=1;
  ll cnt_minus=0;
  ll min_minus=LLINF, min_plus=LLINF;
  ll rev_ans=1;
  REP(i,k){
    rev_ans=rev_ans*b[n-1-i].FI%MOD;
    if(b[i].SE<0){
      min_minus=b[i].FI;
      cnt_minus++;

      auto it=s_minus.find(b[i].FI);
      s_minus.erase(it);
    }

    if(0<b[i].SE){
      min_plus=b[i].FI;
      auto it=s_plus.find(b[i].FI);
      s_plus.erase(it);
    }

    if(0==b[i].FI){
      cout<<0<<endl;
      return 0;
    }

    ans=ans*b[i].FI%MOD;
  }

  if(n==k){
    if(cnt_minus%2!=0)
      cout<<(MOD-ans)%MOD<<endl;
    else
      cout<<ans<<endl;
    return 0;
  }


  if(cnt_minus%2!=0){
    bool mok=(s_plus.size()!=0);
    ll pnum=k-cnt_minus;
    bool pok=(s_minus.size()!=0 && pnum!=0);

    //swap both
    if(pok && mok){
      auto it_minus=s_minus.rbegin();
      auto it_plus=s_plus.rbegin();

      ll l=(*it_plus)*min_plus;
      ll r=(*it_minus)*min_minus;
      if(l<r){
        ans=ans*mod_inv(min_plus)%MOD;
        ans=ans*(*it_minus)%MOD;
      }
      else{
        ans=ans*mod_inv(min_minus)%MOD;
        ans=ans*(*it_plus)%MOD;
      }
    }
    //swap minus to plus
    else if(mok){
      auto it_plus=s_plus.rbegin();
      ans=ans*mod_inv(min_minus)%MOD;
      ans=ans*(*it_plus)%MOD;
    }
    //swap plus to minus
    else if(pok){
      auto it_minus=s_minus.rbegin();
      ans=ans*mod_inv(min_plus)%MOD;
      ans=ans*(*it_minus)%MOD;
    }
    //no swap
    else
      ans=(MOD-rev_ans)%MOD;
  }


  cout<<ans<<endl;

}

