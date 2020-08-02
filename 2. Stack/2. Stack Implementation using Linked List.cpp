#include <iostream>
using namespace std;

// NOTE : Here I'm not considering size of the stack, as Linked List will use Dynamic Memory Allocation.

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node *top = nullptr;

// Dynamically Allocation Memory for Requested Element.
Node *makeElement(int data) {
    Node *ptr = new Node();
    ptr->data = data;
    ptr->next = nullptr;
    ptr->prev = nullptr;
    return ptr;
}

// Function to Push Element to STACK.
void pushToStack() {
    int data;
    cout << endl << "Enter Element : " << endl;
    cin >> data;
    if(top == nullptr) {
        top = makeElement(data);
    } else {
        Node *ptr = makeElement(data);
        ptr->prev = top;
        top->next = ptr;
        top = ptr;
    }
    cout << endl << "Element Pushed Successfully to STACK." << endl;
}

// Function to Pop Element from STACK;
void popFromStack() {
    if(top == nullptr) {
        cout << endl << "STACK is Empty." << endl;
    }

    if(top->next == nullptr && top->prev == nullptr) {
        Node *ptr = top;
        top = nullptr;
        delete ptr;
    } else {
        Node *ptr = top;
        top = top->prev;
        top->next = nullptr;
        delete ptr;
    }
    cout << endl << "Element Popped Successfully From STACK." << endl;
}

// Function to Check the Topmost Element of STACk.
void stackTop() {
    if(top == nullptr) {
        cout << endl << "STACK is Empty." << endl;
    }
    cout << endl << "Topmost Element Of Stack is : " << top->data << endl;
}

// Function to Check whether STACK is Empty or not.
void isStackEmpty() {
    if(top == nullptr) {
        cout << endl << "STACK is Empty." << endl;
    } else {
        cout << endl << "STACK is not Empty." << endl;
    }
}

// Function to view Stack Top to Bottom.
void viewStack() {
    if(top == nullptr) {
        cout << endl << "STACK is Empty." << endl;
        return;
    }
    cout << endl << "STACK Top to Bottom : " << endl;
    for(Node *ptr = top; ptr != nullptr; ptr = ptr->prev) {
        cout << ptr->data << endl;
    }
}

// Main Function
int main() {
    int choice;
    while(true) {
        cout << endl << "Please Select Operation : " << endl;
        cout << "1. Push Element To Stack." << endl;
        cout << "2. Pop Element From Stack." << endl;
        cout << "3. Top Element To Stack." << endl;
        cout << "4. Check whether Stack is Empty or Not." << endl;
        cout << "5. View Stack Top to Bottom." << endl;
        cout << "6. Exit." << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch(choice) {
            case 1: pushToStack();
                    break;
            case 2: popFromStack();
                    break;
            case 3: stackTop();
                    break;
            case 4: isStackEmpty();
                    break;
            case 5: viewStack();
                    break;
            case 6: return 0;
                    break;
            default: cout << endl << "Invalid Choice. Try Again!" << endl;
        }
    }
    return 0;
}

