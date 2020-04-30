#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
  int n;
  cin >> n;
  
  vector<int> w(n);
  for(int i = 0; i < n; i++){
    cin >> w.at(i);
  }


  int zettai = 0;
  int min = 100000000;
  for(int i = 0; i < n; i++){
    int sum1 = 0;
    int sum2 = 0;

    for(int j = 0; j < i; j++){
      sum1 += w.at(j);
    }
    for(int j = i; j < n; j++){
      sum2 += w.at(j);
    }
  
    if(sum1 - sum2 > 0)
      zettai = sum1 - sum2;
    else
      zettai = sum2 - sum1;

    if(min > zettai)
      min = zettai;
    //cout << zettai << ' ' << min << endl;
  }

  cout << min << endl;
}



