#include <bits/stdc++.h>
using namespace std;

int r, d;
int year = 2000;


bool weight_zanka(int xi){
  int xi1;
  
  if(year >= 2010)
    return false;

  if(year < 2000)
    return false;

  xi1 = r * xi - d;
  cout << xi1 << endl;
  year ++;
  return weight_zanka(xi1);
}


int main(){
  int x2000;

  cin >> r >> d >> x2000;
  weight_zanka(x2000);

}

