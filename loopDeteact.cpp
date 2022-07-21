#include <iostream>
#include <map>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};

void insertion(Node *&tail, int ele, int d)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = tail;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != ele)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);

        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "Link list null " << endl;
        return;
    }
    else
    {
        Node *temp = tail;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail);
        cout << endl;
    }
}

bool detect(Node *head)
{
    if (head == NULL)
    {
        return false;
    }
    Node *temp = head;
    map<Node *, bool> visited; // Key and string sotre thai ama

    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node* floyedDetection(Node* head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    
    while(slow!=NULL && fast!=NULL){
        fast = fast->next;
        if(fast->next!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        if(slow==fast){
            return slow;
        }
        return NULL;
    }



}

Node* getStartingloopele(Node* head){
    if (head == NULL){
        return NULL;
    }
    Node* inter = floyedDetection(head);
    Node* slow = head;
    while(slow != inter){
        slow= slow->next;
        inter = inter->next;
    }
    return slow ;
}

void removeLoop(Node* head){
    if(head==NULL){
        return ;
    }
    Node* startNode = getStartingloopele(head);
    Node* temp = startNode;
    while(temp->next!= startNode){
        temp = temp->next;
    }
    temp->next=NULL;
}


int main() {
    Node *tail = NULL;
    insertion(tail, 1, 10);
    insertion(tail, 1, 5);
    print(tail);
    return 0;
}