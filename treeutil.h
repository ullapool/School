#ifndef TREEUTIL_H
#define TREEUTIL_H
#include <vector>
using namespace std;


class TreeUtil
{
public:
    static bool isBinarySearchTree (vector<int> values, int idx, int min, int max);
};

#endif // TREEUTIL_H
