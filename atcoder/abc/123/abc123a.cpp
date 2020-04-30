#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
  int k;
  vector<int> antena(5);

  for(int i = 0; i < 5; i++){
    cin >> antena.at(i);
  }

  cin >> k;

  if(antena.at(4) - antena.at(0) > k)
    cout << ":(" << endl;
  else
    cout << "Yay!" << endl;

}


