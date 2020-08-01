#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
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

// Function to count number of nodes in a Linked List.
int countNodes() {
    int count = 0;
    for (Node *temp = HEAD; temp != nullptr; temp = temp->next, count++);
    return count;
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
        Node *ptr = makeNode(data);
        ptr->prev = temp;
        temp->next = ptr;
    }
    cout << endl << "Node added Successfully." << endl;
}

// Function to add Node at the beginning of Linked List
void addNodeInBeginning() {
    int data;
    cout << endl << "Enter DATA : ";
    cin >> data;
    if (HEAD == nullptr) {
        HEAD = makeNode(data);
        return;
    }
    Node *ptr = makeNode(data);
    ptr->next = HEAD;
    HEAD->prev = ptr;
    HEAD = ptr;

    cout << endl << "Node added Successfully." << endl;
}

// Function to add Node at a certain position of Linked List (Except Beginning and End so, position != 1 && position != countNodes())
void addNodeAtAPosition() {
    int pos;
    cout << endl << "Enter POSITION : ";
    cin >> pos;
    int data;
    cout << endl << "Enter DATA : ";
    cin >> data;
    if(pos <= 1 || pos >= countNodes()) {
        cout << endl << "Invalid Position to add Node" << endl;
        return;
    }
    Node *ptr = makeNode(data);
    Node *temp = HEAD;
    for(int i = 1;i < pos - 1;i++, temp = temp->next);
    ptr->next = temp->next;
    ptr->prev = temp;
    temp->next->prev = ptr;
    temp->next = ptr;

    cout << endl << "Node added Successfully." << endl;
}

// Function to delete Node from Beginning of a Linked List
void deleteNodeFromStart() {
    if(HEAD == nullptr) {
        cout << "List is Empty." << endl;
        return;
    }
    Node *ptr = HEAD;
    HEAD = ptr->next;
    HEAD->prev = nullptr;
    delete ptr;

    cout << endl << "Node Deleted Successfully." << endl;
}

// Function to delete Node from Last of Linked List
void deleteNodeFromLast() {
    if(HEAD == nullptr) {
        cout << "List is Empty." << endl;
        return;
    }
    if(HEAD->next == nullptr) {
        Node *ptr = HEAD;
        HEAD = nullptr;
        delete ptr;
        return;
    }
    Node *temp;
    for(temp = HEAD; temp->next != nullptr; temp = temp->next);
    Node *ptr = temp;
    temp->prev->next = nullptr;
    delete ptr;

    cout << endl << "Node Deleted Successfully." << endl;
}

// Delete a Node From a Position of Linked List (Excluding the case of Beginning an Last Node)
void deleteNodeFromAPos() {
    if(HEAD == nullptr) {
        cout << endl << "List is Empty" << endl;
        return;
    }

    int pos;
    cout << endl << "Enter POSITION : ";
    cin >> pos;

    if(pos <= 1 || pos >= countNodes()) {
        cout << endl << "Invalid Position" << endl;
        return;
    }

    Node *ptr = HEAD;
    for(int i = 1; i < pos; i++, ptr = ptr->next);
    ptr->next->prev = ptr->prev;
    ptr->prev->next = ptr->next;
    delete ptr;

    cout << endl << "Node Deleted Successfully." << endl;
}

// Function to reverse the Linked List
void reverseLL() {
    if(HEAD == nullptr) {
        cout << endl << "List is Empty." << endl;
    }
    if(HEAD->next != nullptr) {
        Node *ptr;
        for(ptr = HEAD; ptr != nullptr; ptr = ptr->prev) {
            Node *temp = ptr->next;
            ptr->next = ptr->prev;
            ptr->prev = temp;
            if(ptr->prev == nullptr) {
                HEAD = ptr;
            }
        }
    }

    cout << endl << "List Reversed Successfully." << endl;
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

// Main Function
int main() {
    int choice;
    while(true) {
        cout << endl << "Select Operation : " << endl;
        cout << "1. Add Node to End OF Linked List." << endl;
        cout << "2. Add Node to Beginning Linked List." << endl;
        cout << "3. Add Node at a position of Linked List." << endl;
        cout << "4. Delete Node From Last Of Linked List." << endl;
        cout << "5. Delete Node From Beginning Of Linked List." << endl;
        cout << "6. Delete Node from a position of Linked List." << endl;
        cout << "7. Rotate Linked List." << endl;
        cout << "8. Display Linked List." << endl;
        cout << "9. Count Number Of Nodes in Linked List." << endl;
        cout << "10. Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch(choice) {
            case 1: addNodeToList();
                    break;
            case 2: addNodeInBeginning();
                    break;
            case 3: addNodeAtAPosition();
                    break;
            case 4: deleteNodeFromLast();
                    break;
            case 5: deleteNodeFromStart();
                    break;
            case 6: deleteNodeFromAPos();
                    break;
            case 7: reverseLL();
                    break;
            case 8: displayLL();
                    break;
            case 9: cout << endl << "Number Of Nodes in Linked List : " << countNodes() << endl;
                    break;
            case 10: return 0;
                    break;
            default: cout << "Invalid Entry. Try Again.";
        }
    }
    return 0;
}