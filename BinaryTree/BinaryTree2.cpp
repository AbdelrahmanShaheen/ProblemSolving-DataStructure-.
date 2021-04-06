// Generate a binary tree from traversals
//from Preorder and Inorder
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

Node *BuildTree(int In[], int Pre[], int start, int end) {
    static int PreIndex = 0;
    //bace case :
    if (start > end)
        return nullptr;

    Node *newNode = new Node;
    /* Pick current node from Preorder
    traversal using PreIndex
    and increment PreIndex */
    CreatNode(newNode, Pre[PreIndex++]);
    /* If this node has no children then return */
    if (start == end)
        return newNode;
    /*find the index of this node in inorder traversal */
    int index = Search(In, Pre[PreIndex - 1], start, end);
    /* Using index in preorder traversal, construct left and
    right sub tree */
    newNode->lchild = BuildTree(In, Pre, start, index - 1);
    newNode->rchild = BuildTree(In, Pre, index + 1, end);

    return newNode;
}

void PreTraversal(Node *newPtr) {
    if (!newPtr)return;

    cout << newPtr->data << " ";
    PreTraversal(newPtr->lchild);
    PreTraversal(newPtr->rchild);
}

int main() {
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};

    Node *root = BuildTree(inorder, preorder, 0, 8);
    cout << "Preorder traversal of the constructed tree is \n";
    PreTraversal(root); // print in preorder.
    cout << endl;
}
