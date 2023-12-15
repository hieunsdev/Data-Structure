#include<iostream>
#include<string>
#include"linkedList.h"
#include"queue.h"
#include<cstdlib>

using namespace std;

struct Node_information {
	string nameOfNode;
	int theNumberOfEdges = 0;
	string* nameOfNeighbors;
	int* pathCosts;
};

template<typename type>
type* myRealloc(type* input, int oldSize, int newSize) {
	type* temp = new type[newSize];
	for (int i = 0; i < oldSize; i++) {
		*(temp + i) = *(input + i);
	}
	delete[] input;
	input = NULL;
	return temp;
}

class Graph {
private:
	int numberOfNodes;
	Node_information* vertices;
public:
	Graph(int numberOfNodes) {
		this->numberOfNodes = numberOfNodes;
		this->vertices = new Node_information[numberOfNodes];
		for (int i = 0; i < numberOfNodes; i++) {
			cout << "Node " << i << ": ";
			getline(cin, this->vertices[i].nameOfNode);
		}
		cout << "Graph now has no edges yet" << endl;
	}
	void addNewNode(string nameOfNewNode) {

		//check if name of node has already existed yet
		for (int i = 0; i < this->numberOfNodes; i++) {
			if (nameOfNewNode.compare(this->vertices[i].nameOfNode)) {
				cout << "This name has already existed !!!" << endl;
				return;
			}
		}

		this->vertices = myRealloc(this->vertices, this->numberOfNodes, this->numberOfNodes + 1);
		this->numberOfNodes++;

		this->vertices[this->numberOfNodes - 1].nameOfNode = nameOfNewNode;
	}
	void deleteNode(string nameOfNode) {


	}
	void showNodeInformation(string nameOfNode) {

	}
	void showAllInformation() {

	}
	// interface to manipulate shit
	void modifyNode() {

	}
};

int main() {
	return 0;
}