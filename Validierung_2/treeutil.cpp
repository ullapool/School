<<<<<<< HEAD:treeutil.cpp
#include "treeutil.h"
#include <iostream>
#include <vector>
using namespace std;

bool TreeUtil::isBinarySearchTree(vector<int> value, int idx, int min, int max)
{
    unsigned int left = idx * 2 + 1;
    unsigned int right = idx * 2 + 2;

    // Abbruchbedingung


    if (left > value.size() - 1) return true;

    if (value.at(left) < min || value.at(left) > value.at(idx)) return false;

    if (value.at(right) > max || value.at(right) < value.at(idx)) return false;

    if (right > value.size() - 1 ) return true;



    return (isBinarySearchTree(value, left, min, value.at(idx)) &&
            isBinarySearchTree(value, right, value.at(idx), max));


}
=======
#include "treeutil.h"
#include <iostream>
#include <vector>
using namespace std;

bool TreeUtil::isBinarySearchTree(vector<int> value, int idx, int min, int max)
{
    unsigned int left = idx * 2 + 1;
    cout<<"left: "<<left<<endl;
    unsigned int right = idx * 2 + 2;


    cout<<"right: "<<right<<endl;

    // Abbruchbedingung


    if (left > value.size() - 1) return true;

    if (value.at(left) < min || value.at(left) > value.at(idx)) return false;

    if (value.at(right) > max || value.at(right) < value.at(idx)) return false;

    if (right > value.size() - 1 ) return true;



    return (isBinarySearchTree(value, left, min, value.at(idx)) &&
            isBinarySearchTree(value, right, value.at(idx), max));


}
>>>>>>> bfe0b5a5baff950864266614d7b98807b4f2df50:Validierung_2/treeutil.cpp
