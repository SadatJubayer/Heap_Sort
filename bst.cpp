#include <iostream>
using namespace std;

class Node{

public:
int data;
Node *left;
Node *right;

};

class binarySearchTree{

private:
    Node *root;
    bool rootInserted;

public:

    binarySearchTree(){
        root = NULL;
        rootInserted = false;
    }

    Node *getRoot(){
        return root;
    }

    Node *getNewNode(){
        Node *c = new Node;
        c->left = NULL;
        c->right = NULL;
        return c;
    }


    void addData(Node *n, int x){
        n->data = x;
    }

    Node *createNewNode(int x){
        Node *c = getNewNode();
        addData(c,x);
        return c;
    }

    Node *insertInTree(Node *r, Node *n){
        if(r==NULL){
            r=n;
            if(!rootInserted){
                rootInserted = true;
                root = r;
            }
        }
        else if(n->data < r->data){
            r->left = insertInTree(r->left,n);
        }
        else{
            r->right = insertInTree(r->right,n);
        }

        return r;
    }

    bool searching (int num)
	{
	    Node *temp = root;

        while (temp != NULL)
        {
            if (temp->data == num)
                break;

            if (num > temp->data)
                temp = temp->right;
            else if (num < temp->data)
                temp = temp->left;
        }

        if (temp == NULL)
            return false;

        if (temp->data == num)
            return true;

        return false;

	}

	void inorder(Node *rootReference)
	{
      if (rootReference!=NULL)
      {
        inorder(rootReference->left);
        cout<<rootReference->data<<" ";
        inorder(rootReference->right);
      }
	}

	void preorder (Node *rootReference)
	{
      if (rootReference!=NULL)
      {
          cout<<rootReference->data<<" ";
          preorder(rootReference->left);
          preorder(rootReference->right);
      }
	}

	void postorder (Node *rootReference)
	{
      if (rootReference!=NULL)
      {
        postorder(rootReference->left);
        postorder(rootReference->right);
        cout<<rootReference->data<<" ";
      }
	}






};



int main(){
//char i;
int a[11] = {100,105,95,80,97,103,108,115,112,60,70};
int x;

binarySearchTree bst;

for(int i=0;i<11;i++){
    x = a[i];
    bst.insertInTree(bst.getRoot(), bst.createNewNode(x));
}
    bst.inorder (bst.getRoot());


    if (bst.searching(97)==true ) cout <<"Found";
    else
        cout <<"go off";

return 0;
}

