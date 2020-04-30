#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;


lli calc_formula(string s, queue<int> index){
  lli sum = 0, current_num = 0;
  for(lli i = 0; i < s.size() -1; i++){
    current_num += (lli)(s[i] - '0');
    if(index.front() == i && index.size() != 0){
      sum += current_num;
      current_num = 0;
      index.pop();
      }
    else
      current_num *= 10;
  }
  current_num += (lli)(s[s.size()-1] - '0');
  sum += current_num;
  return sum;
}

int main(){
  string s;
  cin >> s;
  lli sum = 0;
  lli n = s.size()-1;
  for(lli bit = 0; bit < (1<<n); bit++){
    queue<int> index;
    for(lli i=0; i < n; i++){
      if(bit & (1<<i))
        index.push(i);
    }
    sum += calc_formula(s, index);
  }

  cout << sum << endl;

}
