#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;
};

class LinkedList{
private:
    Node *head;
    Node *tail;
    int nodeCount;
public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        nodeCount = 0;
    }
    Node *getHead() {return head;};
    Node *getTail() {return tail;};
    Node *getNewNode()
    {
        Node *newNode = new Node;
        newNode -> next = NULL;
        newNode -> prev = NULL;
        return newNode;
    }
    int getData ()
    {
        int data;
        cin >> data;
        return data;
    }
    void setData (Node *n, int d)
    {
        n->data = d;
    }
    Node *createNewNode ()
    {
        Node *newNode = getNewNode();
        setData(newNode, getData());
        return newNode;
    }
    void createList (int ele)
    {
        head = tail = getNewNode();
        setData(tail, getData());

        Node *c;
        for (int i=1; i<ele; i++)
        {
            c =tail;
            tail->next = createNewNode();
            tail = tail->next;
            tail->prev = c;
        }
        nodeCount = ele;

    }

    void insertAtHead(Node *newNode){
    if(head!=NULL){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else{
        head = newNode;
        tail = newNode;
    }

    nodeCount++;
}


void insertAtTail(Node *newNode)
{
    if(head!=NULL)
        {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    else{
        head = newNode;
        tail = newNode;
    }

    nodeCount++;
}


void insertAtPos(int pos, Node *newNode){
    if(pos<=0){
        cout<<"Invalid position or index. Use insertAtHead() to insert a node at the beginning of the list.\n";
    }
    else if(pos>=nodeCount){
        cout<<"Invalid position or index.\n";
    }
    else{
        Node *cr = head;
        for(int j=1; j<pos; j++){
            cr = cr->next;
        }
        Node *c = cr->next;
        newNode->next = c;
        newNode->prev = cr;
        cr->next = newNode;
        c->prev = newNode;
        nodeCount++;
    }
}


void deleteHead(){

    if(head==NULL){
        cout<<"List is empty! Nothing to delete.\n";
    }

    else{
        Node *c = head;
        //cout<<"Deleting first node...\n";
        head = c->next;
        if(head!=NULL)
            head->prev = NULL;

        delete c;
        nodeCount--;
    }
}

void deleteTail(){

    if(tail==NULL){
        cout<<"List is empty! Nothing to delete.\n";
    }
    //cout<<"Deleting last node...\n";

    else if(head->next==NULL){
        delete head; //which is also the tail because this is the only node in the list
        head = NULL;
        tail = NULL;
        nodeCount--;
    }
    else{
        Node *c1 = tail;
        Node *c2 = tail->prev;

        c2->next = NULL;
        tail = c2;

        delete c1;
        nodeCount--;
    }
}

void deleteAtPos(int pos){
    if(pos<=0){
        cout<<"Invalid position. Use deleteHead() to delete a node at the beginning of the list.\n";
    }
    else if(pos>=nodeCount){
        cout<<"Invalid position or index.\n";
    }
    else{
        Node *cr = head;
        for(int j=1; j<pos; j++){
            cr = cr->next;
        }
        Node *c1 = cr->next;
        Node *c2 = c1->next;
        cr->next = c2;
        if(c2!=NULL)
            c2->prev = cr;
        else tail = cr;
        delete c1;
        nodeCount--;
    }
}

bool searchElementExists(int element){
    Node *cr = head;

    while(cr!=NULL){
        if(cr->data==element){
            cout<<element<<" is in the linked list\n";
            return true;
        }
        cr = cr->next;
    }

    cout<<element<<" is not in the linked list\n";
    return false;
}


int indexOfSearchedElement(int element){
    Node *cr = head;
    int c=0;

    while(cr!=NULL){
        if(cr->data==element){
            cout<<element<<" is in the linked list and the index where it first occurs is "<<c<<endl;
            return c;
        }
        cr = cr->next;
        c++;
    }

    cout<<element<<" is not in the linked list\n";
    return -1;
}

    void showlist ()
    {
        Node *headRef = head;
        while (headRef != NULL)
        {
            cout << headRef -> data << " ";
            headRef = headRef ->next;
        }

    }


};







int main()
{
    LinkedList L1;
    L1.createList(4);
    L1.showlist();
}
