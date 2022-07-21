#include<iostream>
using namespace std;
class Node{
    public:
    int data ;
    Node* next;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}
void insert(Node* &head,int d){
    Node* temp =new Node(d);
    temp->next=head;
    head=temp;
}

Node* reversKnode(Node* & head , int k ){
    if (head == NULL){
        return NULL;
    }
    Node* prev= NULL;
    Node* curr = head;
    Node* next = NULL;
    int cnt= 0;
    while (curr!= NULL&& cnt < k)
    {
        /* code */
        cnt++;
        next= curr->next;
        curr->next= prev;
        prev= curr ;
        curr = next;
    }
    if(next!=NULL){
        head->next=reversKnode(next,k);
    }
    return prev;
}



int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    insert(head,15);
    insert(head,16);
    insert(head,12);
    insert(head,1);
    print(head);
    Node* de = reversKnode(head,3);
    print(de);
    return 0;
}