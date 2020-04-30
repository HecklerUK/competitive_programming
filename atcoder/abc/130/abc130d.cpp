#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main(){
  lli n, k;
  cin >> n >> k;

  vector<lli> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  lli patterns = 0;

  //a[0] to a[i] >= k
  int end_point = n;
  lli sum = 0;
  
  for(int i = 0; i < n; i++){
    sum += a[i];
    
    if(sum >= k){
      end_point = i;
      //first patterns
      patterns += n - i;
      break;
      }
  }

  //0 patterns
  if(end_point == n){
    cout << 0 << endl;
    return 0;
    }

  // after second array
  for(int i = 1; i < n; i++){
    sum -= a[i - 1];
    if(sum >= k){
      patterns += n - end_point;
      continue;
    }
    //cout << i << endl;

    // search end_point
    for(int j = end_point + 1; j < n; j++){
      //cout << a[j] << endl;
      sum += a[j];
      if(sum >= k){
        end_point = j;
        patterns += n - j;
        break;
      }
    }
  }

  cout << patterns << endl;
}


