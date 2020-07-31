#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *HEAD = nullptr;

// Function to dynamically allocate the memory for requested data
Node *makeNode(int data) {
    Node *ptr = new Node();
    ptr->data = data;
    ptr->next = nullptr;
    return ptr;
}

// Function to add Node at the end of Linked List
void addNodeToList() {
    int data;
    cout << endl << "Enter DATA : ";
    cin >> data;
    if (HEAD == nullptr) {
        HEAD = makeNode(data);
    } else {
        Node *temp;
        for (temp = HEAD; temp->next != nullptr; temp = temp->next);
        temp->next = makeNode(data);
    }
}

// Function to Display Linked List
void displayLL() {
    cout << endl;
    if(HEAD == nullptr) {
        cout << "List is Empty." << endl;
    }
    for (Node *temp = HEAD; temp != nullptr; temp = temp->next) {
        cout << temp->data << endl;
    }
    cout << endl;
}

int main() {
    int choice;
    while(true) {
        cout << endl << "Select Operation : " << endl;
        cout << "1. Add Node to Linked List." << endl;
        cout << "2. Display Linked List." << endl;
        cout << "3. Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch(choice) {
            case 1: addNodeToList();
                    break;
            case 2: displayLL();
                    break;
            case 3: return 0;
                    break;
            default: cout << "Invalid Entry. Try Again.";
        }
    }
    return 0;
}
