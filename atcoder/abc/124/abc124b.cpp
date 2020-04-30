#include <bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >> n;

  vector<int> h(n);
  for(int i = 0; i < n; i++){
    cin >> h.at(i);
  }

  int sea_count = 0;
  for(int i = 0; i < n; i++){
    bool sea_flag = true;

    for(int j = 0; j < i; j++){
      if(h.at(i) < h.at(j))
        sea_flag = false;
    }

    if(sea_flag)
      sea_count +=1;
  }

  cout << sea_count << endl;
}
