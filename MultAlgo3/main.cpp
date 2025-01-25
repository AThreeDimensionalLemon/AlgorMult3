#include <iostream>
#include <stack>
using namespace std;

int multA(int inMultiplicand, int inMultiplier) {

    // Long multiplication

    stack<int> multiplicand;
    stack<int> multiplier;
    int result = 0;

    // Get factor digits
    while (inMultiplicand != 0) {
        multiplicand.push(inMultiplicand % 10);
        inMultiplicand /= 10;
    }

    while (inMultiplier != 0) {
        multiplier.push(inMultiplier % 10);
        inMultiplier /= 10;
    }

    

    return 0;
}

//int multB(int inMultiplicand, int inMultiplier) {
//
//}
//
//int multC(int inMultiplicand, int inMultiplier) {
//
//}

int main() {
    cout << "Eisig Liang - 26 Jan. 2025" << endl;
    multA(2, 4);
    /*cout << multA(281, 2145) << endl;
    cout << multB(281, 2145) << endl;
    cout << multC(281, 2145) << endl;*/
}
