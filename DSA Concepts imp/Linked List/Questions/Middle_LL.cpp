#include<iostream>
using namespace std;

    class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

int getLength(Node *head) {
    int length = 0;
    Node *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node *&head, Node *&tail, int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data) {
    Node *newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}
void insertAtAnyPosition(Node *&head, Node *&tail, int data, int position)
{
    int length = getLength(head);

    if (position <= 1)
    {
        insertAtHead(head, tail, data);
    }    
    else if (position > length)
    {
        insertAtTail(head, tail, data);
    }
    else
    {
        // insert at middle of LL

        // step1: create a new node
        Node *newNode = new Node(data);
        // step2: traverse prev // curr to position
        Node *prev = NULL;
        Node *curr = head;
        //intially prev null pr hai current head pr hai
        //while loop leke prev aur curr dono ko aage bhadenge
        while (position != 1)
        {
            prev = curr;
            curr = curr->next;
            position--;
        }
        // step3: attach prev to new Node
        prev->next = newNode;
        // step4: attack newNode to curr
        newNode->next = curr;
    }
}

// Node *findMiddle(Node * head){
//     int len = getLength(head);
//     int ans = (len/2);

//     Node* temp = head;
//     int count = 0;
//     while(count < ans){
//         temp = temp ->next;
//         count++;
//     }
    
//     return temp;
// }

//FAST AND SLOW METHOD WHERE SLOW IS ON HEAD & FAST IN ON HEAD->NEXT INITIALLY
//SLOW MOVES ONE STEP WHILE FAST MOVES TWO STEPS
//SO WHEN FAST REACEHS TO NULL SLOW HAVE REACHED TO MIDDLE
Node *findMiddle(Node * head){
    if(head == NULL || head->next ==NULL){
        return head;
    }
    //2nodes
    if(head ->next->next == NULL){
        return head -> next;
    }

    Node* slow = head;
    Node* fast = head -> next;

    while(fast->next != NULL){
        fast = fast->next;
        if(fast !=NULL){
            fast = fast -> next;
        }
        slow = slow->next;
    }
    return slow;
    
}


void print(Node *head)
{
    // jab bhi LL ko head mein paas krenge toh uske liye hmesha new pointer banaenge
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtAnyPosition(head ,tail,1,1);
    insertAtAnyPosition(head ,tail,2,2);
    insertAtAnyPosition(head ,tail,3,3);
    insertAtAnyPosition(head ,tail,4,4);
    insertAtAnyPosition(head ,tail,5,5);
    insertAtAnyPosition(head ,tail,6,6);
    insertAtAnyPosition(head ,tail,7,7);
    insertAtAnyPosition(head ,tail,8,8);
    print(head);

   Node* middleNode = findMiddle(head);
    cout << "Middle Element: " << middleNode->data << endl;


    print(head);

}