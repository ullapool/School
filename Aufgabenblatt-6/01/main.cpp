#include "graph.h"
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


int main()
{

   srand(15);
   Graph g;
   g.randomInit(9, 8, false);
   cout << g << endl;
   //dfs(&g, 0);

   //Aufgabe 1
//      unsigned int start = 7;
//      cout<<(allNodeAreReachable(start) ? "* All nodes are reachable *" : "! They are not all reachable !")<<endl;
//      cout<<endl;

      //Aufgabe 2
//      int start_ = 0;
//      int end = 1;
//      cout<<"Shortest Reach from "<<start_<<" to "<<end<<" = "<<shortestReach(start_, end)<<endl;


   //Aufgabe 3

   int source = 7;
   int target = 4;

   vector<int> path = g.getPath( source, target);

   cout << "Shortest path: ";
   for (const auto& node : path) {
       cout << node << " | ";
   }
       cout <<"\n\n";


   //Aufgabe Test17 N#4

   set<int> res = g.reachableNodes(source,2);
   for(const auto & result : res){
       cout<<result<<", ";

   }

   return 0;

}


