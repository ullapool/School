#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <sstream>
#include <unordered_set>
#include <set>
using namespace std;


class Graph {
private:
  vector< vector<int> > neighbours;
  vector< vector<int> > weights;
private:
  void dfs(vector<int>& check, int start);
public:
  Graph();
  void randomInit(int nNodes=10, int nConnections=15, bool directed=false);
  int getNumberOfNodes();
  vector<int> getNeighbours(int node);
  vector<int> getWeights(int node);
  void addNode(vector<int> neighbours, vector<int> weights);
  bool allNodeAreReachable(int start); //
  vector<int> dfs(int start); //g
  int shortestReach( int start, int end ); //g
  vector<int> getPath( int start, int end);//g
  void dfs(int current, set< int> & grassedNodes, vector<int>& result); //g
  void getPath(vector<int>& predecessor, int start, int end, vector<int>& result);
  void getPath(vector<int>& reachableNodes, vector<int>& distance, vector<bool>& marked, vector<int>& predecessor);//g
  //vector<int> dfs(int start);
 // vector<int> dfs_(Graph *g, int start);
  friend std::ostream& operator<<(std::ostream& s, const Graph & obj);

  set<int> reachableNodes(int startNode, int MaxHops);


};

std::ostream& operator<<(std::ostream& s, const Graph & obj);


#endif // GRAPH_H
