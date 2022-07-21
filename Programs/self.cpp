#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
// constroctor
    Node(int d){
    this->data=d;
    this->next=NULL;
    }
};
void insertAthead(Node* &head,int d){
    Node* temp = new Node(d) ;
    temp->next=head;
    head=temp;
}
void insertAtTail(Node* &tail,int d){
    Node* temp = new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertAtpo(Node* &head,Node* &tail,int postion,int d){
    if(postion==1){
        insertAthead(head,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    while(cnt < postion-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }
  
    Node* nodtoins= new Node(d);
    nodtoins->next=temp->next;
    temp->next=nodtoins;
   
}
void deletion(int potion , Node* &head){
    if(potion == 1){
        Node* temp = head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* curr=head;
        Node* prv =NULL;
        int cnt =1;

        while(cnt<potion){
        prv=curr;
        curr=curr->next;
        cnt++;
        }
        prv->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
} 



void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data << " " ;
        temp=temp->next;
    }
    cout << endl;
}
int main(){
    Node* node1= new Node(5);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAthead(head,10);
    print(head);
    insertAtTail(tail,19);
    print(head);
    insertAtTail(tail,29);
    print(head);
    insertAtpo(head,tail,5,72);
    print(head);
    deletion(1,head);
    print(head);
    deletion(4,head);
    print(head);
    return 0;
}