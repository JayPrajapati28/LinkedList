#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d ){
        this->data=d;
        this->next=NULL;
    }
};

void insertion(Node* &tail, int ele , int d){
    if(tail==NULL){
        Node* newNode= new Node(d);
        tail= newNode;
        newNode->next=tail;
    }
    else {
        Node* curr = tail;
        while(curr->data!=ele){
            curr = curr->next;
        }
        Node* temp= new Node(d);

        temp->next=curr->next;
        curr->next=temp; 
    }
}


void print (Node* tail){
    if(tail==NULL){
        cout << "Link list null " << endl;
        return;
    }
    else {
        Node* temp = tail;
        do{
            cout << temp->data << " ";
            temp = temp->next;
        }while(temp != tail);
        cout << endl;
        }
}

int main()
{
    Node* tail = NULL;
    insertion(tail,1,10);
    insertion(tail,1,5);
    print(tail);
    return 0 ;
}