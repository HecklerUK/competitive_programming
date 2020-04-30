#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

typedef pair<string, pair<lli, lli>> S;
#include <algorithm>
#include <functional>

//pair in pair ver
int main(){
  int n;
  cin >> n;

  //Si, Pi, No
  vector<S> rest(n);

  for(lli i = 0; i < n; i++){
    cin >> rest.at(i).first >> rest.at(i).second.first;
    rest.at(i).second.first *= -1;
    rest.at(i).second.second = i + 1;
  }

  //sort(rest.begin(), rest.end(), greater<int>())
  //return true if bigger
  sort(rest.begin(), rest.end());

  for(lli i = 0; i < n; i++){
  cout << rest.at(i).second.second ;
  cout << ' ' << rest.at(i).first << ' ' << rest.at(i).second.first;
  cout << endl;
  }

}


