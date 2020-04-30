#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


lli calc_formula(queue<lli> index, string s){
  lli n = s.size() - 1, sum = 0;
  sum += s[0] - '0';
  for(lli i = 0; i < n; i++){
    if(index.size() != 0 && index.front() == i){
      sum += s[i+1] - '0';
      index.pop();
    }
    else
      sum -= s[i+1] - '0';
  }
  return sum;

}

int main(){
  string s;
  lli n;
  cin >> s;
  n = s.size() - 1;
  for(lli bit = 0; bit < (1<<n); bit++){
    queue<lli> index;
    for(lli i = 0; i < n; i++){
      if(bit & (1 << i))
        index.push(i);
    }

    if(calc_formula(index, s) == 7){
      for(lli i = 0; i < n; i++){
        cout << s[i];
        if(index.size() != 0 && index.front() == i){
          cout << '+';
          index.pop();
        }
        else
          cout << '-';
      }
      cout << s[n] << "=7" << endl;
      break;
    }
  }


}



