#include <vector>
#include <string>

struct city{
  std::string name;
  int num;
};

// uses Dijkstra algorithm
void shortest_path(int** const, const std::vector<city>&);
