#include <iostream>
using namespace std;

// NOTE : Here I'm not considering size of the stack, as Linked List will use Dynamic Memory Allocation.

struct Node {
    int data;
    Node *next;
};

Node *FRONT = nullptr;
Node *BACK = nullptr;

// Function to allocate memory dynamically to requested node
Node *makeNode(int data) {
    Node *ptr = new Node();
    ptr->data = data;
    ptr->next = nullptr;
    return ptr;
}

// Function to add element in Queue.
void addToQueue() {
    int data;
    cout << endl << "Enter Data : ";
    cin >> data;
    Node *ptr = makeNode(data);
    if(FRONT == nullptr && BACK == nullptr) {
        FRONT = ptr;
        BACK = ptr;
        return;
    }
    BACK->next = ptr;
    BACK = ptr;
}

// Function to remove element from Queue.
void removeFromQueue() {
    if(FRONT == nullptr && BACK == nullptr) {
        cout << endl << "Queue is Empty." << endl;
    }
    Node *ptr = FRONT;
    if(FRONT == BACK) {
        FRONT = nullptr;
        BACK = nullptr;
    } else {
        FRONT = FRONT->next;
    }  
    delete ptr;
    cout << endl << "Element removed successfully." << endl;
}

// Function to view First Element in Queue
void queueFirst() {
    if(FRONT == nullptr && BACK == nullptr) {
        cout << endl << "Queue is Empty." << endl;
    }
    cout << endl << "First Element in Queue is : " << FRONT->data << endl;
}

// Function to view Last Element in Queue
void queueLast() {
    if(FRONT == nullptr && BACK == nullptr) {
        cout << endl << "Queue is Empty." << endl;
    }
    cout << endl << "Last Element in Queue is : " << BACK->data << endl;
}

// Function to check whether Queue is empty or not.
void isQueueEmpty() {
    if(FRONT == nullptr && BACK == nullptr) {
        cout << endl << "Queue is Empty." << endl;
    } else {
        cout << endl << "Queue is not Empty." << endl;
    }
}

// Function to View/Print Queue.
void viewQueue() {
    if(FRONT == nullptr && BACK == nullptr) {
        cout << endl << "Queue is Empty." << endl;
    }
    cout << endl << "Queue from Front to Back : " << endl;
    for(Node *ptr = FRONT; ptr != nullptr; ptr = ptr->next) {
        cout << ptr->data << "\t";
    }
    cout << endl;
}


// Main Function
int main() {
    int choice;
    while(true) {
        cout << endl << "Select Operation : " << endl;
        cout << "1. Add Element to Queue." << endl;
        cout << "2. Remove Element from Queue." << endl;
        cout << "3. First Element in Queue." << endl;
        cout << "4. Last Element in Queue." << endl;
        cout << "5. Is Queue Empty ?" << endl;
        cout << "6. View Queue Front to Back." << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        default: cout << endl << "Invalid Choice. Try Again !" << endl;
                break;
        case 1: addToQueue();
                break;
        case 2: removeFromQueue();
                break;
        case 3: queueFirst();
                break;
        case 4: queueLast();
                break;
        case 5: isQueueEmpty();
                break;
        case 6: viewQueue();
                break;
        case 7: return 0;
        }
    }
}