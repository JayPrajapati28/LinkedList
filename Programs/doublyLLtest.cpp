#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prv;
    Node* next;
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prv=NULL;
    }
};
void print (Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data<<"  ";
        temp=temp->next;
    }
    cout << endl;
}
int getLen(Node* head){
    int len =0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void insertAtHead(Node* &head,int d){

    //Empty head then 
    if(head==NULL){
        Node* temp =new Node(d);                
        head=temp;                                              
    }                   
    else{
        Node* temp = new Node(d);
        temp->next=head;
        head->prv=temp;
        head=temp;
    }
}
void insertAtTail(Node* &tail,int d){
    if(tail==NULL){
        Node* temp = new Node(d);
        tail=temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next=temp;
        temp->prv=tail;
        tail=temp;
    }
    
}
void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    //position at frist
    if(position==1){
        insertAtHead(head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt < position-1){
        temp=temp->next;
        cnt++;
    }
    //position at last 
    if(temp->next==NULL){
        insertAtTail(tail,d);
        return;
    }
    //now at the position
    Node* nodeToIn=new Node(d);
    nodeToIn->next=temp->next;
    temp->next->prv=nodeToIn;
    temp->next=nodeToIn;
    nodeToIn->prv=temp;
}
void deletenode(Node* &head,int ps){
    if(ps==1){
        Node* temp =head;
        temp->next->prv=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prv = NULL ;
        int cnt =1 ;

        while(cnt<ps){
        prv=curr;
        curr=curr->next;
        cnt++;
        }
        curr->prv=NULL;
        prv->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}



int main(){
    Node* node1= new Node(10);
    Node* head=node1;
    Node* tail= node1;
    print(head);
    cout << "length is "<<getLen(head)<<endl;
    insertAtHead(head,5);
    print(head);
    cout << "length is "<<getLen(head)<<endl;
    insertAtTail(tail,19);
    print(head);
    cout << "length is "<<getLen(head)<<endl;

    insertAtPosition(head,tail,4,9);
    print(head);
    insertAtPosition(head,tail,1,72);
    print(head);
    insertAtPosition(head,tail,3,62);
    print(head);

    deletenode(head,1);
    print(head);
    return 0;
}