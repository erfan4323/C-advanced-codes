#include<iostream>
#include<string>

using namespace std;

class Node { // General Tree Node
private:
	Node * leftChild;
	Node * rightSib;
public:
	string value; // extentions: Null > folder, .txt/.cpp/.pdf files
	Node(string name, Node* lc, Node* rs): value(name), leftChild(lc), rightSib(rs) {};
	void setLeftChild(Node* child) {
		leftChild = child;
	}
	void setRightSib(Node* rc) {
		rightSib = rc;
	}
	Node* getLeftChild() {
		return leftChild;
	}
	Node* getRightSib() {
		return rightSib;
	}
	string getFileAddressByName(string name);
};	

class Drive {
	private:
		Node* first;
	public:
		Drive(Node* f): first(f) {};
		
};

string Node::getFileAddressByName(string name) {
	// find and make file address
	// Block Condition
	cout << this->value << ", ";
	if (name.compare(this->value) == 0) {
		return name;
	}
	for(Node* temp = this->getLeftChild(); temp; temp = temp->rightSib) {
		string result = getFileAddressByName(name);
		if (result.length() > 0) {
			return this->value + "/" + result;	
		}
	}
	return "";
}

int main() {
	Node* C = new Node(
		"C",
		new Node ("a", new Node("d",NULL,new Node("e", NULL, NULL)), new Node("b",new Node("f", NULL, new Node("g", NULL, NULL)),new Node("c", NULL, NULL))),NULL
	); 
	
	cout << C->getFileAddressByName("g");
	// you should define the tree here and assign it to driveC 
	return 0;
}
