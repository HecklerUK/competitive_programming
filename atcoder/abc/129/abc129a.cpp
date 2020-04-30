#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#include <algorithm>

int main(){
  vector<int> p(3);
  cin >> p[0] >> p[1] >> p[2];
  cout << p[0] + p[1] + p[2] - *max_element(p.begin(), p.end()) << endl;

 }



