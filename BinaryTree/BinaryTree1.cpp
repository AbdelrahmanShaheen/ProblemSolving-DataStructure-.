// Generate a binary tree from traversals
//from postorder and inorder

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *lchild;
    Node *rchild;
};

void CreatNode(Node *newNode, int value) {
    newNode->data = value;
    newNode->rchild = nullptr;
    newNode->lchild = nullptr;
}

int Search(int arr[], int val, int start, int end) {
    int ind;
    for (int i = start; i < end; i++) {
        if (arr[i] == val) {
            ind = i;
            break;
        }
    }
    return ind;
}

Node *BuildTree(int In[], int Post[], int start, int end) {
    static int PostIndex = 0;
    Node *newNode = new Node;
    /* Pick current node from Postorder
    traversal using PostIndex
    and increment PostIndex */
    CreatNode(newNode, Post[PostIndex++]);
    if (start > end) //base case :
        return nullptr;
    /* If this node has no children then return */
    if (start == end)
        return newNode;
    /* Else find the index of this node in Inorder traversal */
    int index = Search(In, newNode->data, start, end);
    /* Using index in postorder traversal, construct left and
    right sub tree */
    newNode->rchild = BuildTree(In, Post, index + 1, end);
    newNode->lchild = BuildTree(In, Post, start, index - 1);

    return newNode;
}

void PostTraversal(Node *newPtr) {
    if (!newPtr)return;

    PostTraversal(newPtr->lchild);
    PostTraversal(newPtr->rchild);
    cout << newPtr->data << " ";
}

int main() {
    int in[8] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[8] = {8, 4, 5, 2, 6, 7, 3, 1};

    reverse(post, post + 8);

    Node *root = BuildTree(in, post, 0, 7);
    cout << "Inorder traversal of the constructed tree is \n";
    PostTraversal(root); // print in postorder.
    cout<<endl;
}