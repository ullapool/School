#include "graph.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

Graph::Graph() {
}

void Graph::addNode(vector<int> neighbours, vector<int> weights) {
  this->neighbours.push_back(neighbours);
  this->weights.push_back(weights);
}

void Graph::randomInit(int nNodes, int nConnections, bool directed) {
  vector<int> v;
  for (int i=0; i<nNodes; i++) {
    neighbours.push_back(v);
  }
  int counter = 0;
  int max = nConnections * 4;
  while (counter < nConnections || counter > max) {
    int source = rand() % nNodes;
    int target = rand() % nNodes;
    if (source != target) {
      if (find(neighbours[source].begin(), neighbours[source].end(), target) == neighbours[source].end()) {
        neighbours[source].push_back(target);
        if (!directed) {
            neighbours[target].push_back(source);
        }
        counter++;
      }
    }
  }
  for (int i=0; i<nNodes; i++) {
    sort(neighbours[i].begin(), neighbours[i].end());
  }

  for (vector<int> v : neighbours) {
       vector<int> w;
    for (unsigned int i=0; i<v.size(); i++) {
        int cost = rand() % 20 + 1;
        w.push_back(cost);
    }
    weights.push_back(w);
  }


  if (!directed) {
    for (unsigned int i=0; i<weights.size(); i++) {
      for (unsigned int j=0; j<weights.at(i).size(); j++) {
        int source = i;
        int target = neighbours.at(i).at(j);
        int weight = weights.at(i).at(j);
        int index = find(neighbours.at(target).begin(), neighbours.at(target).end(), source) - neighbours.at(target).begin();
        weights[target][index] = weight;
      }
    }
  }
}

int Graph::getNumberOfNodes() {
  return neighbours.size();
}

vector<int> Graph::getNeighbours(int node) {
  return neighbours.at(node);
}

vector<int> Graph::getWeights(int node) {
  return weights.at(node);
}

std::ostream& operator<<(std::ostream& s, const Graph & obj) {
  for (unsigned int i=0; i<obj.neighbours.size(); i++) {
    vector<unsigned int>::iterator it;
    s << "Node " << i << "\t";
    for (unsigned int j=0; j<obj.neighbours[i].size(); j++) {
      s << obj.neighbours[i].at(j) << "(" << obj.weights[i].at(j) << "), ";
    }
    s << endl;
  }

  return s;
}


//Aufgabeblatt 6 ########################################################################

//Aufgabe 1
void Graph::dfs(int current, set< int>& grassedNodes, vector<int>& result) {
    //Abbruch falls goesser als size
    if (grassedNodes.find(current) != grassedNodes.end())
        return;

    grassedNodes.insert(current);
    result.push_back(current);

    vector<int> neighbours = getNeighbours(current);
    for (int n : neighbours) {
         dfs(n, grassedNodes, result);
    }
}

vector <int> Graph:: dfs(int start) {

    vector<int> result;
    set< int> grassedNodes;
          dfs(start, grassedNodes, result );

         return result;
}

bool Graph:: allNodeAreReachable(int start){
  vector<int> reachableNodes = dfs( start);
  cout<<endl;
  cout << "Reachable: " << reachableNodes.size() << ", of Total: " << getNumberOfNodes() << endl;
  return reachableNodes.size() == getNumberOfNodes();
}





//Aufgabe 2

int Graph::shortestReach(int start, int end){

    // return 0 if start and end are the same
        if (start == end) return 0;

        // Init
        vector<int> visited;  // processed nodes
        vector<int> hops;     // number of hops to visited node
        vector<bool> detected(getNumberOfNodes(), false);  // tracks detected node


        // Add start node
        visited.push_back(start);
        hops.push_back(0);
        detected.at(start) = true;

        // Loop neighbours
        int i = 0;  // index of next node to process
        while (i < visited.size()) {
            for (const auto &neighbour : neighbours.at(visited.at(i))) {
                // end node found
                if (neighbour == end) return hops.at(i) + 1;

                // add neighbours
                if (!detected.at(neighbour)) {           //equal to : deceted.at(neighbour) == 0)
                    visited.push_back(neighbour);
                    hops.push_back(hops.at(i) + 1);
                    detected.at(neighbour) = true;
                }
            }
            i++;
        }

        return -1;
}



//Aufgabe 3

void Graph::getPath(vector<int>& predecessor, int start, int end, vector<int>& result){
    if (predecessor.at(end)==start){
        result.push_back(end);
        result.push_back(start);
        return;
    }

    result.push_back(end);
    end = predecessor.at(end);
    getPath(predecessor, start, end, result);

}

void Graph::getPath(vector<int>& reachableNodes, vector<int>& distance, vector<bool>& marked, vector<int>& predecessor){

    for (int i=0; i<reachableNodes.size(); i++){
        if (marked.at(reachableNodes.at(i)))break;
        if (i==reachableNodes.size()-1 && marked.at(i))return;
    }
    int min = INT_MAX;
    int pos = INT_MAX;
    for(int i=0; i<reachableNodes.size(); i++){
        if (distance.at(reachableNodes.at(i))<min && marked.at(reachableNodes.at(i)) == 0){
            min = distance.at(reachableNodes.at(i));
            pos = reachableNodes.at(i);
        }
    }
    if (pos >=marked.size())return;
    marked.at(pos)=true;

    vector <int> neighbourvalues = getNeighbours(pos);
    vector <int> neighbourdistance = getWeights(pos);



    for (int i=0; i<neighbourvalues.size(); i++){
        if (min+neighbourdistance.at(i)<distance.at(neighbourvalues.at(i))){
            distance.at(neighbourvalues.at(i))=min+neighbourdistance.at(i);
            predecessor.at(neighbourvalues.at(i))=pos;
        }
    }

    getPath(reachableNodes, distance, marked, predecessor);
}

vector<int> Graph:: getPath(int start, int end){
    if (start ==end) {
        vector<int> startisend;
        startisend.push_back(start);
        return startisend;
    }

    vector<int> unreachable(1,-1);
    int numberofNodes = getNumberOfNodes();
    vector<int> reachableNodes = dfs(start);
    if (find(reachableNodes.begin(), reachableNodes.end(), end) == reachableNodes.end()) return unreachable;
    vector <int> distance (numberofNodes, INT_MAX);
    distance.at(start) = 0;
    vector <bool> marked (numberofNodes, 0); //initialized with false (0)
    vector <int> predecessor(numberofNodes, -1);  //or INT_MIN instead of -1
    predecessor.at(start) = start; //gets start value

    getPath(reachableNodes, distance, marked, predecessor);

    vector<int> result;
    getPath(predecessor, start, end, result);

    reverse(result.begin(), result.end());
    cout << "Distance Cost: " << distance.at(end) << endl;

    return result;
}

set<int> Graph::reachableNodes(int startNode, int MaxHops){

       set<int> result;

        // Init
        vector<int> visited;  // processed nodes
        vector<int> hops;     // number of hops to visited node
        vector<bool> detected(getNumberOfNodes(), false);  // tracks detected node


        // Add start node
        visited.push_back(startNode);
        hops.push_back(0);
        detected.at(startNode) = true;

        // Loop neighbours
        int i = 0;  // index of next node to process
        while (i < visited.size() && MaxHops >= hops.at(i) ) {
                result.insert(visited.at(i));

                for (const auto &neighbour : neighbours.at(visited.at(i))) {
                // add neighbours
                    if (!detected.at(neighbour)) {  //equal to : deceted.at(neighbour) == 0)
                        visited.push_back(neighbour);
                        hops.push_back(hops.at(i) + 1);
                        detected.at(neighbour) = true;
                    }
                }
                i++;
        }


        return result;
}















