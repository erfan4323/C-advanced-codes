#include <bits/stdc++.h>
using namespace std;

class Node{
private:
    //the data that stores in the tree
public:
    //childs
    int data;
    Node* left;
    Node* right;
    //constructors
    Node(int value): data(value), left(nullptr), right(nullptr) {}
    Node(): data(0), left(nullptr), right(nullptr) {}
    //adding node *with the childs*
    Node* createNode(int value){
        Node* newNode = new Node(value);
        return newNode;
    }
    //print the whole tree
    void printTree(Node* root){ //preorder
        if(root == nullptr) return;
        
        cout << root->data << endl;
        printTree(root->left);
        printTree(root->right);
    }
    //search the value
    bool findInTree(Node* root, int value){
        if(root == nullptr) return false;
        if(value == root->data) return true;
        
        return findInTree(root->left, value) || findInTree(root->right, value);
    }
    //count all nodes
    int countNodes(Node* root){
        if(root == nullptr) return 0;
        
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
    //find the parent
    Node* findParent(Node* root, int value){
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)) return nullptr;
        if((root->left != nullptr && root->left->data == value) || (root->right != nullptr && root->right->data == value)) return root;
        
        Node* leftchild = findParent(root->left, value);
        if(leftchild != nullptr) return leftchild;
        
        Node* rightchild = findParent(root->right, value);
        if(rightchild != nullptr) return rightchild;
    }
    
};

int main(){
    //line 1
    Node* root = new Node(1);
    //line 2
    root->left = root->createNode(2);
    root->right = root->createNode(3);
    //line 3
    root->left->left = root->createNode(4);
    root->left->right = root->createNode(5);
    root->right->left = root->createNode(6);
    root->right->right = root->createNode(7);
    //line 4
    root->right->right->left = root->createNode(15);
    //print
    root->printTree(root);
    //finding data
    if(root->findInTree(root, 11)){
        cout << "found" << endl;
    }else{
        cout << "not found" << endl;
    }
    //count the nodes
    cout << "there are " << root->countNodes(root) << " nodes" << endl;
    //finding parent
    Node* curr = curr->findParent(root, root->right->left->data);
    cout << "the current parent of node " << root->right->left->data << " is " << curr->data << endl;
}