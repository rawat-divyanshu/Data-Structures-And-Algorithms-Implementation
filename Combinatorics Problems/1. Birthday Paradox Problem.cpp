#include <iostream>
using namespace std;

int main() {

    float prob = 1.0;
    // prob denotes the probability of all people having different birthdays.

    float num = 365;
    float denom = 365;

    int noOfPeople = 0;

    float p;
    cout << "Enter probability : ";
    cin >> p;
    // Taking the input for probability of two people having same birthdays.
    
    if(p == 1.0) {
        cout << "For " << noOfPeople << " people, the probability of two people having same birthday is " << (1-prob) << endl;
        return;
    }

    while(prob > 1 - p) {
        prob = (prob * num)/denom;
        num--;
        noOfPeople++;

        cout << "For " << noOfPeople << " people, the probability of two people having same birthday is " << (1-prob) << endl;
    }
    return 0;
}