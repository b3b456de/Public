// Samuel Spry
// 4-17-2015
//
// Shortest path file

#include "shortest_path.h"
#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include <set>

using namespace std;

// returns a vector containing the neighbors of a city
vector<int> get_neighbors(int city, int** const weights, int max, const set<int>& unvisited){
  vector<int> neighbors;
  for( int i = 0; i < max; ++i){
    if(weights[city][i] != 0 && unvisited.find(i) != unvisited.end())
      neighbors.push_back(i);
  }
  return neighbors;
}

// returns the distance to a city from a city
int distance_to(int city_current, int** const weights, int city_target){
  int distance;
  distance = weights[city_current][city_target];
  return distance;
}

// prints the shortest path, recursively
void print_path(int* const distance, const vector<city>& cities, int pos, int** const weights,
		const set<int>& sets){
  int min_p;
  int min = numeric_limits<int>::max();
  if(pos > 0){
    vector<int> neighbors = get_neighbors(pos, weights, cities.size(), sets);
    for(unsigned int i = 0; i < neighbors.size(); ++i){
      // checking if distance from start and weight to get to
      // neighbor is less than min
      if(distance[neighbors[i]] + weights[pos][neighbors[i]] < min){
	min = distance[neighbors[i]] + weights[pos][neighbors[i]];
	min_p = neighbors[i];
      }
    }
    print_path(distance, cities, min_p, weights, sets);
  }
  // end case / base case
  cout << cities[pos].name << " ";
}

void shortest_path(int** const weights, const vector<city>& cities){

  int n = cities.size();

  set<int> unvisited;		            // initializing set of unvisited cities
  for(int i = 0; i < n; ++i){		    // setting start node as unvisited for convienence
    unvisited.insert(i);
  }
  set<int> sets = unvisited;	            // for printing

  int *distance = new int[n];               // creating array of distances from start
  distance[0] = 0;			    // start has a distance of 0 from start
  for(int i = 1; i < n; ++i)		    
    distance[i] = numeric_limits<int>::max(); // initializing to max value

  int current = 0;	                    // setting current node bto city 0 (start)
  int tentative;			    // variable for keeping track of tentative distance
  
  // variables for keeping track of the smallest distance
  int min, min_p;
  while(unvisited.size() && current != n-1){  // while there are still unvisited nodes
                                              // and the target node is not the current node
    min = numeric_limits<int>::max();
    vector<int> neighbors = get_neighbors(current, weights, n, unvisited); // getting list of neighbors

    // break if there are no unvisited neighbors
    if(neighbors.size() == 0)
      break;
    
    // setting new distances
    for(unsigned int i = 0; i < neighbors.size(); ++i){
      tentative = distance_to(current, weights, neighbors[i]) + distance[current];
      if(tentative < distance[neighbors[i]]){
	distance[neighbors[i]] = tentative;
      }

      // setting minimum node to neighbor
      if(tentative < min ){
	min = tentative;
	min_p = neighbors[i];
      }
    }

    // removing current node from unvisited
    unvisited.erase(current);

    //cout << "current: " << current << endl;
    // setting next node to the node with minimum distance
    current = min_p;
  }

  print_path(distance, cities, n-1, weights,sets);
  cout << distance[n-1] << endl;
}

