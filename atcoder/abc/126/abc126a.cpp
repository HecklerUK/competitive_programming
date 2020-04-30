#include <bits/stdc++.h>
#include <math.h>
 
using namespace std;
int main() {
  int n,k;
  cin >> n >> k;
  char c[n];
 
  for(int i = 0; i < n; i++){
    cin >> c[i];
  }
  
  for(int i = 0; i < n; i++){
    if(i == k-1){
      cout << (char)(c[i]+32);
      continue;
    }
    cout << c[i];
  }
  cout << endl;
}