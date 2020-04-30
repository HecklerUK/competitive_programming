#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(){
  int a, b;
  cin >> a >> b;

  if(a == b)
    cout << a + b << endl;
  else if(a > b)
    cout << a * 2 - 1 << endl;
  else
    cout << b * 2 - 1 << endl;

}



