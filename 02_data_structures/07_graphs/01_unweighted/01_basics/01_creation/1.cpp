#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    vector<Node*> neigh;

    Node(int val) {
        data = val;
    }
};

class Graph {
    
};