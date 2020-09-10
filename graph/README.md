# Graph
## Graph Representation
```c++
#include<iostream>
#include<list>

using namespace std;

#using list Representation
class Graph
{
	int V; //No. of vertices

	//pointer to an array
	list<int> *adj;
}

#using stl Representation
class Node
{
	int val;
	vector<Node*> neighbors;
}
```