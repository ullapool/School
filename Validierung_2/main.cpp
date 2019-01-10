#include <iostream>
#include "treeutil.h"
#include <vector>
#include <climits>

using namespace std;

int main()
{


     //lets make even more changes
    //lets make some changes ldkfkjdsifhfighfd
    //vector<int> values = {20, 12, 34, 9, 19, 29};                                 // is search tree
    //vector<int> values = {100, 50, 150, 25, 75, 125, 175};                      // is search tree
    //vector<int> values = {10, 8, 12, 4, 9, 11, 16};                             // is search tree
    vector<int> values = {10, 8, 12, 9};   //, 15, 11, 16                         // is no search tree
    //vector<int> values = {10, 8, 12, 4, 15, 9, 16, 2, 5, 4, 18, 8, 14, 10, 8};  // is no search tree
    //vector<int> values = {10, 5, 15, 3, 7, 5, 18};                              // is no search tree
    //vector<int> values = {10, 5, 15, 3, 7, 12, 18};                             // is search tree
    //vector<int> values = {20, 10, 30, 12, 15, 25, 35};
    if (TreeUtil::isBinarySearchTree(values, 0, INT_MIN, INT_MAX) == true)
        cout<<"is a Binary Search Tree"<<endl;
    else
        cout<<"is a Binary Tree"<<endl;

    return 0;
}
