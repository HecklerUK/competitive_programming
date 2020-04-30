#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
  int n, x;
  cin >> n >> x;

  vector<lli> l(n);
  for(int i = 0; i < n; i++){
    cin >> l[i];
  }

  lli now_pt = 0;
  
  int i;
  for(i = 0; i < n; i++){
    now_pt += l[i];
    if(now_pt > x)
      break;
  }

  // 1 <= x <= 1000
  cout << i + 1 << endl;

}



