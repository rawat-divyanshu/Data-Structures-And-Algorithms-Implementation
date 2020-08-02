#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node *HEAD = nullptr;

// Function to dynamically allocate the memory for requested data
Node *makeNode(int data) {
    Node *ptr = new Node();
    ptr->data = data;
    ptr->next = nullptr;
    ptr->prev = nullptr;
    return ptr;
}

// Function to count number of nodes in Linked List.
int countNodes() {
    int count = 0;
    if(HEAD == nullptr) {
      return count;
    }
    Node *ptr = HEAD;
    do {
      count++;
      ptr = ptr->next;
    } while(ptr != HEAD);
    return count;
}

// Function to add Node at the end of Linked List
void addNodeToList() {
    int data;
    cout << endl << "Enter DATA : ";
    cin >> data;
    if (HEAD == nullptr) {
        HEAD = makeNode(data);
        HEAD->next = HEAD;
        HEAD->prev = HEAD;
    } else {
        Node *temp;
        for (temp = HEAD; temp->next != HEAD; temp = temp->next);
        Node *ptr = makeNode(data);
        ptr->next = HEAD;
        ptr->prev = temp;
        HEAD->prev = ptr;
        temp->next = ptr;
    }

    cout << endl << "Node Added Successfully." << endl;
}

// Function to add Node at the beginning of Linked List.
void addNodeInBeginning() {
    int data;
    cout << endl << "Enter DATA : ";
    cin >> data;

    Node *ptr = makeNode(data);
    Node *temp;
    for (temp = HEAD; temp->next != HEAD; temp = temp->next);

    ptr->next = HEAD;
    ptr->prev = temp;
    HEAD->prev = ptr;
    temp->next = ptr;
    HEAD = ptr;

    cout << endl << "Node Added Successfully." << endl;
}

// Function to add Node at a certain position of Linked List (Except Beginning and End so, position != 1 && position != countNodes())
void addNodeAtAPosition() {
    int pos;
    cout << endl << "Enter POSITION : ";
    cin >> pos;
    if(pos <= 1 || pos > countNodes()) {
        cout << endl << "Invalid Position to add Node" << endl;
        return;
    }
    int data;
    cout << endl << "Enter DATA : ";
    cin >> data;
    
    Node *ptr = makeNode(data);
    Node *temp = HEAD;
    for(int i = 1;i < pos - 1;i++, temp = temp->next);
    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next->prev = ptr;
    temp->next = ptr;

    cout << endl << "Node added Successfully." << endl;
}

// Function to Display Linked List
void displayLL() {
    cout << endl;
    if(HEAD == nullptr) {
        cout << "List is Empty." << endl;
    }
    Node *temp = HEAD;
    do {
        cout << temp->data << endl;
        temp = temp->next;
    } while(temp != HEAD);
    cout << endl;
}

// Main Function
int main() {
    int choice;
    while(true) {
        cout << endl << "Select Operation : " << endl;
        cout << "1. Add Node to End OF Linked List." << endl;
        cout << "2. Add Node to Beginning Linked List." << endl;
        cout << "3. Add Node at a position of Linked List." << endl;
        cout << "4. Display Linked List." << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch(choice) {
            case 1: addNodeToList();
                    break;
            case 2: addNodeInBeginning();
                    break;
            case 3: addNodeAtAPosition();
                    break;
            case 4: displayLL();
                    break;
            case 5: return 0;
                    break;
            default: cout << "Invalid Entry. Try Again.";
        }
    }
    return 0;
}