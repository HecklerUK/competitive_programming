#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  int v[n], c[n];
  for(int i = 0; i < n; i++){
	cin >> v[i];
  }
  for(int i = 0; i < n; i++){
	cin >> c[i];
  }
  
  //calc max(X-Y)
  int sum=0;
  for(int i = 0; i < n; i++){
	if(v[i]-c[i] > 0){
		sum += v[i]-c[i];
	}
  }
  
  cout << sum << endl;
  
}
