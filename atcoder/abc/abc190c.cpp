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



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin >> n >> m;
	vll a(m), b(m);
	REP(i, m)cin >> a[i] >> b[i];
	REP(i, m) {
		a[i]--;
		b[i]--;
	}

	ll k;
	cin >> k;
	vll c(k), d(k);
	REP(i, k)cin >> c[i] >> d[i];
	REP(i, k) {
		c[i]--;
		d[i]--;
	}



	ll ans = 0;
	REP(bit, (1 << k)) {
		vll dish(n);
		REP(i, k) {
			if (bit & (1 << i))
				dish[c[i]]++;
			else
				dish[d[i]]++;
		}

		ll cnt = 0;
		REP(i, m) {
			if (dish[a[i]] >= 1 && dish[b[i]] >= 1)
				cnt++;
		}

		ans = max(ans, cnt);
	}

	cout << ans << endl;

}




