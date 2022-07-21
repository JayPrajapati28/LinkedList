#include <iostream>
#include<map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Consturctor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int value= this->data;
        if(this->next != NULL){
            delete next;
            this->next= NULL;
        }
        cout <<"memory free thai gai che "<<endl;
    }
};
void insertAtHead(Node *&head, int d)
{
    // new node creation
    Node *temp = new Node(d);
    temp->next = head;
    temp->data = d;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);

    tail->next = temp;
    tail = temp;
}
void insertAtPosition(Node *&head, int position, int d)
{

    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(head, d);
        return;
    }

    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deletion(int postion , Node* &head){
    if(postion ==1){
        //deleting frist node 
        Node* temp = head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        //deleting any node and last node 
        Node* curr =head;
        Node* pre = NULL;
        int cnt =1;
        while(cnt < postion){
            pre=curr;
            curr = curr->next;
            cnt++;
        } 
        pre->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        /* code */
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* del(Node* &head){
    
        if(head==NULL||head->next==NULL){
            return NULL;
        }    
        Node* curr = head;
        Node* prev = NULL;
        map<Node*,bool> visi;
        while(curr!=NULL){
            if(visi[curr]==true){
            //     Node* next = curr->next;
            //     Node* nodeTodel = curr;
            //     delete(nodeTodel);
            //    curr= next;
            //    prev->next= next;
            
            }
            else{
            visi[curr]=true;
            prev = curr;
            curr=curr->next;
            }
        }
    return head;
}
int main()
{
    Node *node1 = new Node(10);
    // cout << node1->data << endl;
    // cout << node1->next <<endl;
    Node *head = node1; // head of the node                  head  tail
    Node *tail = node1; // tail of the node                 [      |       ]

    insertAtHead(head, 17);
    insertAtHead(head, 18);
    insertAtHead(head,15);
    insertAtHead(head,17);
    insertAtHead(head,18);

    print(head);
    del(head);
    print(head);
    // insertAtPosition(head, 2, 22);
    // print(head);

    // deletion(1,head);
    print(head);
    return 0;
}