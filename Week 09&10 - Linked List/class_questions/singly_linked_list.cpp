#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node() { //? default constructor
        cout << "I am inside default constructor" << endl;
        this->next = NULL;
    }

    Node(int data) { //? parameterized constructor function
        // cout << "I am inside parameterized constructor" << endl;
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        cout << "Destructor called for: " << this->data << endl;
    }
};

void printLL(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head) {
    Node* temp = head;
    int count = 0;

    while(temp != NULL) {
        count++;
        temp = temp->next;

    }
    return count;
}

void insertAtHead(Node* &head, Node* &tail, int data) {
    if (head == NULL) {
        //empty LL
        //steps 1: create new node
        Node* newNode = new Node(data);
        //step 2: update head
        head = newNode;
        tail = newNode;
    }
    else {
        //create a new node
        Node* newNode = new Node(data);
        //attach new node to head node
        newNode ->next = head;
        //update head
        head = newNode;
    }
}

void insertAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        //empty LL
        //step1: create the node
        Node* newNode = new Node(data);
        //Step2: single node h entire list mein
        head = newNode;
        tail = newNode;
    }
    else {
        //non-empty LL
        //step1: create a new node
        Node* newNode = new Node(data);
        //step2: tail node ko attach karo newNode se
        tail->next = newNode;
        //step3: update tail
        tail = newNode;
    }
}

void createTail(Node* &head, Node* &tail) {
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    //jab ye loop khatam hogaya hoga then aapka temp wala pointer khada hoga last node par, tail ko last node pr le aao
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position) {
    //! assumption: position ki value [1 to length+1 tak]
    if (position < 1) {
        cout << "Cannot insert, please enter a valid position" << endl;
        return;
    }
    int length = getLength(head);
    if(position > length) {
        cout << "Cannot insert, please enter a valid position" << endl;
        return;
    }
    if (position <= 1) {
        insertAtHead(head, tail, data);
    }
    else if(position > length) {
        insertAtTail(head, tail, data);
    }
    else {
        //insert at middle of linked list
        //step1: create a New Node
        Node* newNode = new Node(data);
        //step2: traverse prev to current position 
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1) {
            prev = curr;
            curr = curr->next;
            position--;
        } 
        //step3: attach prev to new node
        prev->next = newNode;
        //step4: attach newNode to curr
        newNode ->next = curr;
    }

}

void deleteNode(Node* &head, Node* &tail, int position) {
    //empty LL
    if(head == NULL) {
        cout << "Cannot delete, cause LL is empty" << endl;
        return;
    }

    if (head == tail) {
        //single element
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    int len = getLength(head);
    //delete from head
    if (position == 1) {
        //first node ko delete kardo
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

    } else if (position == len) {
        //last node ko delete kardo
        //find prev
        Node* prev = head;
        while(prev->next != tail) {
            prev = prev->next;
        }
        //prev node ka link null karo
        prev->next = NULL;
        //node delete karo
        delete tail;
        //update tail
        tail = prev;
    } else {
        //middle mein koi node ko delete karna hai
        //step1:
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1) {
            position--;
            prev = curr;
            curr = curr->next;
        }
        //step2 prev-> next mein curr ka next node add karo
        prev->next = curr->next;
        //step3 node isolate kardo
        curr->next = NULL;
        //step4 delete node
        delete curr;
    }
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 50);
    printLL(head);

    insertAtPosition(head, tail, 1000, 4);
    printLL(head);
    deleteNode(head, tail, 1);
    printLL(head);


    // //Node a; //static allocation
    // //creation of nodes
    // Node* first = new Node(10); //dynamic allocation
    // Node* second = new Node(20); //dynamic allocation
    // Node* third = new Node(30); //dynamic allocation
    // Node* fourth = new Node(40); //dynamic allocation
    // Node* fifth = new Node(50); //dynamic allocation

    // first->next = second;
    // second->next = third;
    // third->next = fourth;
    // fourth->next = fifth;
    // //linked list created

    // Node* head = first;
    // Node* tail = fifth;
    // cout << "Printing the entire LL: " << endl; 
    // printLL(head);
    // //insertAtHead(head, tail, 500);
    // insertAtTail(head, tail, 500);
    
    // printLL(head);

    // // cout << "Length of LL is: " << getLength(head) << endl;
    return 0;
}
