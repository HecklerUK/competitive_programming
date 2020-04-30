#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

#include <algorithm>


struct Restaurant{
  string si;
  lli point, nom;
};

//bool comp(const Restaurant& a, const Restaurant& b){
bool comp(Restaurant a, Restaurant b){
  if(a.si != b.si)
    return a.si < b.si;
  if(a.point != b.point)
    return a.point > b.point;
  return a.nom < b.nom;

}

int main(){
  int n;
  cin >> n;

  vector<Restaurant> rest(n);

  for(lli i = 0; i < n; i++){
    cin >> rest.at(i).si >> rest.at(i).point;
    rest.at(i).nom = i + 1;
  }

  sort(rest.begin(), rest.end(), comp);

  for(lli i = 0; i < n; i++){
  cout << rest.at(i).nom;
  cout << ' ' << rest.at(i).si << ' ' << rest.at(i).point;
  cout << endl;
  }

}


