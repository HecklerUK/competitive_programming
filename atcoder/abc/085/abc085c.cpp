#include <bits/stdc++.h>

using namespace std;
int main(){
  int n,y;
  cin >> n >> y;
  for(int mai_1k=0; mai_1k<=n; mai_1k++){
    for(int mai_5k=0; mai_5k<=n-mai_1k; mai_5k++){
      int mai_10k = n-mai_1k-mai_5k;
      int sum = 1000*mai_1k + 5000*mai_5k + 10000*mai_10k;
      if(sum == y){
        cout << mai_10k << " " << mai_5k << " " << mai_1k << endl;
        return 0;
        }
    }
  }

  cout << -1 << " " << -1 << " " << -1 << endl; 

}
