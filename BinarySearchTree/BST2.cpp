//Iterative approach.
//generate bst from preorder traversal only : {30 ,20 ,10 ,15 ,25 ,40 ,50 ,45}.
//solve it using stack.
//you have 3 casses to solve this problem.
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Node{
public:
    int data;
    Node *lchild;
    Node *rchild;
};
Node* CreateBst(int post[] ,int n)
{
    reverse(post ,post+n);
    Node *root ,*ptr;
    int i = 0; //pointer to postorder(arr) elements.
    stack<Node *>address;
    root = new Node;
    root->data = post[i++];
    root->lchild = root->rchild = nullptr;
    ptr = root;

    while (i < n)
    {
        // right child case
        if(post[i] > ptr->data)
        {
            //create new node.
            Node *newNode = new Node;
            newNode->data = post[i++];
            newNode->lchild = newNode->rchild = nullptr;
            //link :
            ptr->rchild = newNode;
            address.push(ptr);
            ptr = newNode;

        }
        else
        {   // left child cases
            if((post[i] < ptr->data) && ((address.empty()) || (post[i] > address.top()->data)))
            {

                //create new node.
                Node *newNode = new Node;
                newNode->data = post[i++];
                newNode->lchild = newNode->rchild = nullptr;
                //link :
                ptr->lchild = newNode;
                ptr = newNode;
            }
            else if((post[i] < ptr->data) && (post[i] < address.top()->data))
            {

                ptr = address.top();
                address.pop();
            }
        }
    }

    return root;
}
void InOrder(Node * ptr)
{
    if(ptr){
        InOrder(ptr->lchild);
        cout<<ptr->data<<" ";
        InOrder(ptr->rchild);
    }

}

int main() {
    int arr[8] = {15 ,10 ,25 ,20 ,45 ,50 ,40 ,30}; //postorder of bst.
    InOrder(CreateBst(arr ,8));
}
//Time complexity : O(n).
