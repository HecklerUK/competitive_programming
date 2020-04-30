#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MAX_H 2000
#define MAX_W 2000

char s[MAX_W][MAX_H];
lli h, w;
lli dx[4] = {1, 0, -1, 0};
lli dy[4] = {0, 1, 0, -1};


void dfs(lli posi_x, lli posi_y, pair<lli, lli> muki){
  if(muki.first == 0 && muki.second == 0){
    vector<pair<lli, lli>> dxdy(4);
    for(int i = 0; i < 4; i++){
      dxdy.at(i).first = dx[i];
      dxdy.at(i).second = dy[i];
    }

    for(int i = 0; i < 4; i++){
      
    }
  }
    


}


int main(){
  cin >> h >> w;


}

