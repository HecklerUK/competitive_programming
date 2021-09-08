#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define sz(a) (int)(a).size()
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<(n);i++)
#define drep(i,n) for(int i=(n)-1;i>=0;i--)
#define srep(i,n,s) for(int i=(s);i<(n);i++)
#define dsrep(i,n,s) for(int i=(n)-1;i>=(s);i--)
#define pb push_back
#define eb emplace_back
#define mp(a,b) make_pair(a,b)
#define getp(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define yes cout<<"Yes"<<endl
#define YES cout<<"YES"<<endl
#define no cout<<"No"<<endl
#define NO cout<<"NO"<<endl
#define Decimal fixed<<setprecision(20)

using namespace std;
template<typename T> using vc = vector<T>;
template<typename T> using vv = vc<vc<T>>;
template<typename T> using pc = pair<T, T>;
template<typename T> using pq = priority_queue<T, vc<T>, greater<T>>;
using ll = long long;
using ld = long double;
using T3 = tuple<ll,ll,ll>;
using vll = vc<ll>;
using vld = vc<ld>;
using pll = pc<ll>;
using pld = pc<ld>;
using vpl = vc<pll>;
using vs = vc<string>;
using vvll = vv<ll>;
using vt = vc<T3>;


template<typename T>istream& operator>>(istream&i,vc<T>&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const vc<T>&v,const string& d=""){stringstream s;rep(i,sz(v))(i?s<<d:s)<<v[i];return s.str();}
template<typename T>ostream& operator<<(ostream&o,const vc<T>&v){if(sz(v))o<<join(v," ");return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const vc<T>&a){ll res(0);for(auto&&x:a)res+=x;return res;}
// template<typename T>void uni(vc<T>& a){sort(all(a));a.erase(unique(rng(a)),a.end());}
template<typename T>void uni(T& a){sort(all(a));a.erase(unique(all(a)),a.end());}

const int INF = 1001001001;
const ll LINF = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n;
  cin>>n;
  vpl xc(n);
  rep(i,n)cin>>xc[i];

  vll c(n);
  rep(i,n)c[i]=xc[i].se;
  uni(c);
  map<ll,ll> m;
  ll szc=sz(c);
  rep(i,szc)m[c[i]]=i;


  vpl pt(szc+1,pll(LINF,-LINF));
  pt[0]=pll(0,0);
  rep(i,n){
    mins(pt[m[xc[i].se]+1].fi,xc[i].fi);
    maxs(pt[m[xc[i].se]+1].se,xc[i].fi);
  }

  vvll dp(szc+1,vll(2));
  rep(i,szc){
    ll dist=pt[i+1].se-pt[i+1].fi;

    dp[i+1][0]=dist+min(dp[i][0]+abs(pt[i+1].se-pt[i].fi),dp[i][1]+abs(pt[i+1].se-pt[i].se));
    dp[i+1][1]=dist+min(dp[i][0]+abs(pt[i+1].fi-pt[i].fi),dp[i][1]+abs(pt[i+1].fi-pt[i].se));
  }

  ll ans=min(dp[szc][0]+abs(pt[szc].fi),dp[szc][1]+abs(pt[szc].se));
  cout<<ans<<endl;
}

