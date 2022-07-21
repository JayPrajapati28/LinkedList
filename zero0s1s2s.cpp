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

void insert(Node* &tail,Node* curr){   // store karva mate nu function
    tail->next = curr;
    tail=curr;

}

Node* sortList(Node* &head){
    Node* zeroHead = new Node(-1);  // list ma zero mate ni node banavi
    Node* zeroTail = zeroHead;

    Node* oneHead = new Node(-1);   // list ma one mate ni node banavi
    Node* oneTail = oneHead;

    Node* twoHead = new Node(-1);   // list ma two mate ni node banavi
    Node* twoTail = twoHead;
       
    

    Node* curr = head;
    while(curr!=NULL){
        int val = curr->data;
        if(val==0){
            insert(zeroTail,curr);  // Jo value zero hase to te ne zero vali node ma store kaese
        }
        else if (val==1){
            insert(oneTail,curr);  // Jo value one hase to te ne zero vali node ma store kaese
            cout << "one ni vlue add thai 6" <<endl; 
        }
        else if (val==2){
            insert(twoTail,curr);    // Jo value two hase to te ne zero vali node ma store kaese
        }
        curr = curr->next;
    }
    // have je aa tane node bani ene merge karva mate
    if(oneHead->next!= NULL){
        zeroTail->next = oneHead->next;
        cout << "condition chek thai 6 " << endl; 
    }
    else{
        // one vali list empty che to 
        zeroTail->next=twoHead->next;
    }

    oneTail->next=twoHead->next;
    twoTail->next=NULL;


    // setup head 

    head= zeroHead->next;

    //delete dummy node;
    // delete zeroHead;
    // delete oneHead;
    // delete twoHead;
    return head;
}



int main()
{
    Node *node1 = new Node(1);
    Node *head = node1; 
    Node *tail = node1; 

    insertAtHead(head, 0);
    insertAtHead(head, 1);
    insertAtHead(head,0);
    insertAtHead(head,2);
    insertAtHead(head,2);
    print(head);
    sortList(head);
    print(head);

   
    return 0;
}