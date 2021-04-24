#include <iostream>
#include <stack>
using namespace std;
class Node{
public:
    int data;
    Node *lchild;
    Node *rchild;
};
Node* CreateBst(int pre[] ,int n)
{
    Node *root ,*ptr;
    int i = 0; //pointer to preorder(arr) elements.
    stack<Node *>address;
    root = new Node;
    root->data = pre[i++];
    root->lchild = root->rchild = nullptr;
    ptr = root;

    while (i < n)
    {
        // Left child case
        if(pre[i] < ptr->data)
        {
            //create new node.
            Node *newNode = new Node;
            newNode->data = pre[i++];
            newNode->lchild = newNode->rchild = nullptr;
            //link :
            ptr->lchild = newNode;
            address.push(ptr);
            ptr = newNode;

        }
        else
        {   // Right child cases
            if((pre[i] > ptr->data) && ((address.empty()) || (pre[i] < address.top()->data)))
            {

                //create new node.
                Node *newNode = new Node;
                newNode->data = pre[i++];
                newNode->lchild = newNode->rchild = nullptr;
                //link :
                ptr->rchild = newNode;
                ptr = newNode;
            }
            else if((pre[i] > ptr->data) && (pre[i] > address.top()->data))
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
    int arr[8] = {30 ,20 ,10 ,15 ,25 ,40 ,50 ,45}; //preorder of bst.
    InOrder(CreateBst(arr ,8));
}
//Time complexity : O(n).
