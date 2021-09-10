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
template<typename T>void uni(T& a){sort(all(a));a.erase(unique(rng(a)),a.end());}

const int INF = 1001001001;
const ll LINF = 1LL << 50;
const double eps = 1e-10;
const int MOD = 1e9 + 7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

const ll MAX_X=16;
const ll MAX_Y=16;
const ll MAX_A=8;
const ll MAX_B=16;
ll memo[MAX_X][MAX_Y][2][MAX_A][MAX_B];


ll h,w,a,b;
ll dfs(ll x, ll y, ll s, ll an, ll bn){
  ll res=0;
  if(an<0 || bn<0 || w<x || h<y)
    return 0;

  if(memo[x][y][s][an][bn]!=-1)
    return memo[x][y][s][an][bn];

  //okanai
  if(s==0){
    ll left=dfs(x,y+1,1,an,bn)+dfs(x,y+1,0,an,bn);
    ll right=dfs(x+1,y,1,an,bn)+dfs(x+1,y,0,an,bn);
    if(left==0 && right==0)
      res=0;
    else
      res=max(1LL,left)*max(1LL,right);
    cout<<x<<","<<y<<","<<s<<","<<an<<","<<bn<<":"<<res<<endl;
  }
  if(s==1){
    ll tate=dfs(x,y+1,0,an-1,bn)*(dfs(x+1,y,1,an-1,bn)+dfs(x+1,y,0,an-1,bn));
    ll yoko=(dfs(x,y+1,1,an-1,bn)+dfs(x,y+1,0,an-1,bn))*dfs(x+1,y,0,an-1,bn);

    ll left=dfs(x,y+1,1,an,bn-1)+dfs(x,y+1,0,an,bn-1);
    ll right=dfs(x+1,y,1,an,bn-1)+dfs(x+1,y,0,an,bn-1);
    ll square=max(1LL,left)*max(1LL,right);
    if(left==0 && right==0)
      square=0;
    res=tate+yoko+square;
    cout<<x<<","<<y<<","<<s<<","<<an<<","<<bn<<":"<<tate<<","<<yoko<<","<<square<<endl;
  }


  memo[x][y][s][an][bn]=res;
  return res;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin>>h>>w>>a>>b;
  h--;
  w--;
  rep(i,MAX_X)rep(j,MAX_Y)rep(k,2)rep(q,MAX_A)rep(r,MAX_B)memo[i][j][k][q][r]=-1;
  rep(k,2)rep(q,MAX_A)rep(r,MAX_B)memo[w][h][k][q][r]=0;
  memo[w][h][0][0][0]=1;
  memo[w][h][1][0][1]=1;
  memo[w][h][0][1][0]=1;

  ll ans=0;
  ans+=dfs(0,0,1,a,b);

  rep(j,h+1){
  rep(i,w+1)cout<<memo[i][j][1][1][0]<<",";
  cout<<endl;
  }

  cout<<ans<<endl;
}

