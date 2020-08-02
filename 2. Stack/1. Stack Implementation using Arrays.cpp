#include <iostream>
#define SIZE 100

using namespace std;

int stack[SIZE] = {0};
int top = -1;

// Function to Push Element to STACK.
void pushToStack() {
    if(top == SIZE - 1) {
        cout << endl << "STACK Full Can't Push Element." << endl;
        return;
    }
    cout << endl << "Enter Element : ";
    top++;
    cin >> stack[top];
}

// Function to Pop Element from STACK.
void popFromStack() {
    if(top == -1) {
        cout << endl << "STACK Empty Can't pop Element." << endl;
        return;
    }
    cout << endl << "Element Popped : " << stack[top] << endl;
    top--;
}

// Function to Check the Topmost Element of STACk.
void stackTop() {
    if(top == -1) {
        cout << endl << "STACK Empty." << endl;
        return;
    }
    cout << endl << "Topmost Element Of Stack is : " << stack[top] << endl;
}

// Function to Check whether STACK is Empty or not.
void isStackEmpty() {
    if(top == -1) {
        cout << endl << "STACK is Empty." << endl;
    } else {
        cout << endl << "STACK is not Empty." << endl;
    }
}

// Function to Check whether STACK is Empty or not.
void isStackFull() {
    if(top == SIZE - 1) {
        cout << endl << "STACK is Full." << endl;
    } else {
        cout << endl << "STACK is not Full." << endl;
    }
}

// Function to view Stack Top to Bottom.
void viewStack() {
    if(top == -1) {
        cout << endl << "STACK is Empty." << endl;
        return;
    }
    for(int i = top; i >= 0; i--) {
        cout << stack[i] << endl;
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
        cout << "5. Check whether Stack is Full or Not." << endl;
        cout << "6. View Stack Top to Bottom." << endl;
        cout << "7. Exit." << endl;
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
            case 5: isStackFull();
                    break;
            case 6: viewStack();
                    break;
            case 7: return 0;
                    break;
            default: cout << endl << "Invalid Choice. Try Again!" << endl;
        }
    }
    return 0;
}