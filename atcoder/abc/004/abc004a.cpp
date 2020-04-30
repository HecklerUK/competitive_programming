#include <bits/stdc++.h>
#include <math.h>

using namespace std;
int main() {
  int n; 
  double max=0;
  double distance = 1;
  cin >> n;

  int x[n], y[n];
  for(int i=0; i<n; i++){
    cin >> x[i] >> y[i];
  }
  
  
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      distance = sqrt((x[i]-x[j])*(x[i]-x[j])-(y[i]-y[j])*(y[i]-y[j]));
      if(max < distance){
        max=distance;
      }
    }
  }
  
  cout << max << endl;
  
}
