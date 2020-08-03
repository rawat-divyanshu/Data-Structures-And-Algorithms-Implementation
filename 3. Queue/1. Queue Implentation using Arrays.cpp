#include <iostream>
#define SIZE 100

using namespace std;

int queue[SIZE];

int FRONT = -1;
int BACK = -1;

// Function for rearranging Queue
void rearrangeQueue() {
    int i,j;
    for(i = FRONT, j = 0; i <= BACK; i++, j++) {
        queue[j] = queue[i];
    }
    FRONT = 0;
    BACK = j - 1;
}

// Function to add element to Queue
void addToQueue() {
    if(FRONT == 0 && BACK == 99) {
        cout << endl << "Queue is Full." << endl;
        return;
    }
    if(FRONT > 0 && BACK == 99) {
        rearrangeQueue();
    }
    if(FRONT == -1 && BACK == -1) {
        FRONT++;
    }
    BACK++;
    cout << endl << "Enter Data : ";
    cin >> queue[BACK];
}

// Function to remove element from Queue
void removeFromQueue() {
    if(FRONT == -1 && BACK == -1) {
        cout << endl << "Queue is Empty." << endl;
    }
    FRONT++;
    if(FRONT > BACK) {
        FRONT = -1;
        BACK = -1;
    }
    cout << endl << "Element removed successfully." << endl;
}

// Function to view First Element in Queue
void queueFirst() {
    if(FRONT == -1 && BACK == -1) {
        cout << endl << "Queue is Empty." << endl;
    }
    cout << endl << "First Element in Queue is : " << queue[FRONT] << endl;
}

// Function to view Last Element in Queue
void queueLast() {
    if(FRONT == -1 && BACK == -1) {
        cout << endl << "Queue is Empty." << endl;
    }
    cout << endl << "Last Element in Queue is : " << queue[BACK] << endl;
}

// Function to check whether Queue is empty or not.
void isQueueEmpty() {
    if(FRONT == -1 && BACK == -1) {
        cout << endl << "Queue is Empty." << endl;
    } else {
        cout << endl << "Queue is not Empty." << endl;
    }
}

// Function to check whether Queue is full or not.
void isQueueFull() {
    if(FRONT == 0 && BACK == 99) {
        cout << endl << "Queue is Full." << endl;
    } else {
        cout << endl << "Queue is not Full." << endl;
    }
}

// Function to View/Print Queue.
void viewQueue() {
    if(FRONT == -1 && BACK == -1) {
        cout << endl << "Queue is Empty." << endl;
        return;
    }
    cout << endl << "Queue from Front to Back : " << endl;
    for(int i = FRONT; i <= BACK; i++) {
        cout << queue[i] << "\t";
    }
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
        cout << "6. Is Queue Full ?" << endl;
        cout << "7. View Queue Front to Back." << endl;
        cout << "8. Exit" << endl;
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
        case 6: isQueueFull();
                break;
        case 7: viewQueue();
                break;
        case 8: return 0;
        }
    }
}