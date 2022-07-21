#include <iostream>
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

void inset(Node *&tail, int ele, int d)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
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
bool iscircular(Node* head){
    if(head == NULL){
        return false;
    }
    Node* temp = head->next;
    while(temp!=head){
        temp = temp->next;
    }
    if(temp == head){
        return true ;
    }




}
void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }

    Node *temp = tail;
    do
    {
        cout << tail->data << "  ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

int main()
{
    Node *tail = NULL;
    inset(tail, 1, 10);
    inset(tail, 10, 15);
    print(tail);
    if(iscircular(tail)){
        cout << "circular he " << endl;
    }
    else{
        cout << "Not circular " << endl;
    }
    return 0;
}