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


int len (Node* head){
    Node* temp = head;
    int cnt =0 ;
    while(temp!=NULL){
        cnt ++;
        temp=temp->next;
    }
    return cnt ;
}
int main(){
    Node* node1=new Node(10);
    Node* head=node1;
    insert(head,15);
    insert(head,16);
    insert(head,12);
    insert(head,1);
//  insert(head,72);
    print(head);
    cout << "head at " <<head->data<<endl;
    cout << "len of linklist is :"<<len(head)<<endl;
    int cnt= 0 ;
    int a =len(head);
    cout << " a is " << a<< endl;
    int mid = a/2;
    cout << "mid is " << mid << endl;
    Node* temp = head;
    while(cnt < mid ){
        temp=temp->next;
        cnt++;
    }
    cout << "mid is " << temp->data;

}