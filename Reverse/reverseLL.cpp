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

void recursionReversLL(Node* &head,Node* curr, Node* pre){
    //Base case when will stop 
    if(curr == NULL){
        head=pre;
        return;
    }
    cout << "runnning "<<endl;
    Node* forw=curr->next;
    recursionReversLL(head,forw,curr);
    curr->next=pre;
    cout << "runnning 2"<<endl; 
}

// It will return head of the list 
Node* revers1(Node* head){
    //base case 
    if(head==NULL||head->next==NULL){
        return head;
    }
    Node* smallHead=revers1(head->next);
    head->next->next=head;
    head->next=NULL;
    return smallHead;


}

//Node* reverseLL(Node* &head){
  //  return revers1(head);
    // Node* prev=NULL;
    // Node* curr= head;
    // Node* forward=NULL;
    // cout << "This is frist time "<<endl;
    // print(head);
    // while(curr!=NULL){
    //     forward=curr->next;
    //     curr->next=prev;
    //     prev=curr;
    //     curr=forward;
    // }
    // cout << "This is second time "<<endl;
    // print(head);
    // head = prev; //<--------------------------------------------This is important in the function-------------

//}



int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    insert(head,15);
    insert(head,16);
    insert(head,12);
    insert(head,1);
    cout << "head at value " << head->data<<endl;
    print(head);
    head=revers1(head);
    print(head);
    return 0;
}