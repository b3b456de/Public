// Samuel Spry
// 4-17-2015
//
// Shortest path, gives the shortest path given a map
// 

#include <iostream>
#include <string>
#include <vector>
#include "shortest_path.h"

using namespace std;

int main(){
  int n, t;
  cin >> t;

  // for testing purposes only
  //t = 1;


  for(int i = 0; i < t; ++i){
    cin >> n;
    
    // declaring dynamic array of size nxn
    int** weights = new int*[n];
    for(int i = 0; i < n; ++i)
      weights[i] = new int[n];

    // reading in names of cities
    string name;
    city temp;
    vector<city> cities;
    for(int i = 0; i < n; ++i){
      cin >> name;
      temp.name = name;
      temp.num = i+1;
      cities.push_back(temp);
    }

    // reading in array
    for(int row = 0; row < n; ++row){
      for(int col = 0; col < n; ++col){
	cin >> weights[row][col];
      }
    }

    /*
    // testing input
    for(int i = 0; i < n; ++i){
      cout << cities[i].name << endl;
    }
    cout << endl;
    for(int i=0; i < n; ++i){
      for(int j = 0; j < n; ++j){
	cout << weights[i][j] << " ";
      }
      cout << endl;
    }
    */
    // for testing only

    shortest_path(weights, cities);

    // cleaning up dynamic memory
    for(int i = 0; i <n; ++i)
      delete[] weights[i];
    delete[] weights;
    cities.erase(cities.begin(), cities.end());
  }
}
