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
    } else {
        Node *temp;
        for (temp = HEAD; temp->next != HEAD; temp = temp->next);
        temp->next = makeNode(data);
        temp->next->next = HEAD;
    }

    cout << endl << "Node Added Successfully." << endl;
}

// Function to add Node in the Beginning of Linked List
void addNodeInBeginning() {
    int data;
    cout << endl << "Enter DATA : ";
    cin >> data;

    Node *ptr = makeNode(data);
    Node *temp;
    for (temp = HEAD; temp->next != HEAD; temp = temp->next);

    ptr->next = HEAD;
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
    Node *temp = HEAD;
    for(int i = 1; i < pos; temp = temp->next, i++) {
        Node *ptr = makeNode(data);
        ptr->next = temp->next;
        temp->next = ptr;
    }

    cout << endl << "Node Added Successfully." << endl;
}

// Function to Delete a Node From Last of Linked List
void deleteNodeFromLast() {
    if(HEAD == nullptr) {
        cout << endl << "List is Empty" << endl;
        return;
    }
    Node *ptr;
    if(HEAD->next == HEAD) {
        ptr = HEAD;
        HEAD = nullptr;
        delete ptr;
    } else {
        for(ptr = HEAD; ptr->next->next != HEAD; ptr = ptr->next);
        Node *temp = ptr->next;
        ptr->next = HEAD;
        delete temp;
    }
    cout << endl << "Node Deleted Successfully" << endl;    
}

// Function to delete Node from Beginning of Linked List
void deleteNodeFromStart() {
    if(HEAD == nullptr) {
        cout << endl << "List is Empty" << endl;
        return;
    }
    Node *ptr;
    if(HEAD->next == HEAD) {
        ptr = HEAD;
        HEAD = nullptr;
        delete ptr;
    } else {
        Node *temp = HEAD;
        for(ptr = HEAD; ptr->next != HEAD; ptr = ptr->next);
        ptr->next = HEAD->next;
        HEAD = HEAD->next;
        delete temp;
    }
    cout << endl << "Node Deleted Successfully" << endl; 
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
    for(int i=1; i < pos - 1; i++, ptr = ptr->next);
    Node *temp = ptr->next;
    ptr->next = temp->next;
    delete temp;

    cout << endl << "Node Deleted Successfully" << endl;    
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
        cout << "4. Delete Node From Last Of Linked List." << endl;
        cout << "5. Delete Node From Beginning Of Linked List." << endl;
        cout << "6. Delete Node from a position of Linked List." << endl;
        cout << "7. Display Linked List." << endl;
        cout << "8.  Exit" << endl;
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
            case 7: displayLL();
                    break;
            case 8: return 0;
                    break;
            default: cout << "Invalid Entry. Try Again.";
        }
    }
    return 0;
}