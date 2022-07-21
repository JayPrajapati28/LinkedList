#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
    ~Node(){
        int value= this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};
void insertAtHead(Node* &tail,int ele,int d){
    //empty list
    if(tail==NULL){
        Node*  newNode= new Node(d);
        tail = newNode;
        newNode->next=newNode;
    }
    else{
        //Non empty List 
         //assuming that the element is present in the list
        Node* curr = tail;

        while(curr->data!=ele){
            curr= curr->next;
        }
        //element is found curr is Represnting the element node 
        Node* temp = new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }

}
void deletion(Node* &tail,int val){
    //empty list 
    if(tail==NULL){
        cout << "List is empty check again "<<endl;
        return;
    }
    else{
        // Non empty 
        //assuming the value in the list 
        Node* pre= tail;
        Node* curr = pre->next; 

        while(curr->data!=val){
            pre=curr ;
            curr=curr->next;
        }
        if(tail==pre){
            tail=NULL;
        }
        //Single node link
        else if  (tail==curr)
        {
            tail=pre; 
        }
        
        pre->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}


void print(Node* tail){
    if(tail==NULL){
        cout << "list is empty" <<endl;
        return ;
    }


    Node* temp = tail;
    do
    {
        cout << tail->data << "  ";
        tail=tail->next;
    } while (tail!=temp);
    cout << endl;
}


int len(Node* head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

bool  isCircular(Node* head){
    //empty list case 
    if(head==NULL){
        return true;
    }
    Node* temp = head->next;
    while(temp!= NULL && temp!=head){
        temp =temp ->next;

    }
    if(temp ==head){
        return true;
    }
}




void headtail(Node* head,Node* tail){
    cout <<"tail at point "<< tail->data<<endl;
    cout <<"head at point "<< head->data<<endl;
}

int main(){
    
    Node* tail=NULL;
    insertAtHead(tail,5,3);
    print(tail);
    insertAtHead(tail,3,15);
    print(tail);
    // insertAtHead(tail,3,1);
    // print(tail);
    // insertAtHead(tail,3,33);
    // print(tail);

    

     if(isCircular(tail)){
        cout << "Circuler he bhai " << endl;
    }
    else{
         cout << "Circuler  nai he bhai " << endl;
    }
    

    return 0;
}