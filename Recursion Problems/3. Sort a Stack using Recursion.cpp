#include <iostream>
#include <stack>
using namespace std;

void insertVal(stack<int> *s, int insVal) {
    if(s->empty() || s->top() <= insVal) {
        s->push(insVal);
        return;
    }
    
    int topVal = s->top();
    s->pop();
    insertVal(s, insVal);
    s->push(topVal);    
}


void sortStack(stack<int> *s) {
    if(s->empty()) {
        return;
    }
    int topValue = s->top();
    s->pop();
    sortStack(s);
    insertVal(s, topValue);
}

void printStack(stack <int> s) { 
    while (!s.empty()) { 
        cout << s.top() << '\t'; 
        s.pop(); 
    }
} 

int main() {
    int stackVal[] = {2,5,3,6,9,0,-1};
    stack<int> s;
    for(auto num: stackVal) {
        s.push(num);
    }

    cout << "Stack Before Sorting (Top to Bottom) :" << endl;
    printStack(s);

    sortStack(&s);

    cout << endl << "Stack After Sorting (Top to Bottom) :" << endl;
    printStack(s);

    return 0;

}