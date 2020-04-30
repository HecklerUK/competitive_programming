#include <bits/stdc++.h>
#include <math.h>
 
using namespace std;
 
void formatcheck(int begin, int end){
  if((begin >= 1 && begin <= 12) && (end >= 1 && end <= 12))
    cout << "AMBIGUOUS";
  
  if((begin >= 1 && begin <= 12) && (end < 1 || end > 12))
    cout << "MMYY";
  
  if((begin < 1 || begin > 12) && (end >= 1 && end <= 12))
    cout << "YYMM";
  
  if((begin < 1 || begin > 12) && (end < 1 || end > 12))
    cout << "NA";
}
 
int main(){
  char c[4];
  int begin;
  int end;
  for(int i = 0; i < 4; i++){
    cin >> c[i];
  }
  
  begin = (c[0]-'0') * 10 + c[1]-'0';
  end = (c[2]-'0') * 10 + c[3]-'0';
  formatcheck(begin, end);
  cout << endl;
  
}