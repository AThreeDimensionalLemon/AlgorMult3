#include <iostream>
#include <vector>
using namespace std;

int multA(int inMultiplicand, int inMultiplier) {

    // Long multiplication

    int result = 0;

    // Make integer arguements iterable
    vector<int> multiplicand;
    vector<int> multiplier;

    while (inMultiplicand != 0) {
        multiplicand.push_back(inMultiplicand % 10);
        inMultiplicand /= 10;
    }

    while (inMultiplier != 0) {
        multiplier.push_back(inMultiplier % 10);
        inMultiplier /= 10;
    }

    // Implementation of algorithm
    for (int i = 0; i < multiplicand.size(); i++) {
        int temp = 0;
        int place1 = 1;

        for (int j = 0; j < multiplier.size(); j++) {
            int place2 = 1;
            
            for (int k = 0; k < j; k++)
                place2 *= 10;

            temp += multiplicand[i] * multiplier[j] * place2;
        }

        for (int j = 0; j < i; j++)
            place1 *= 10;

        result += temp * place1;
    }

    return result;
}

int multB(int inMultiplicand, int inMultiplier) {

    // Karatsuba multiplication

    int result = 0;

    return result;
}

int multC(int inMultiplicand, int inMultiplier) {

    // Schönhage–Strassen algorithm

    int result = 0;

    return result;
}

int main() {
    cout << "Eisig Liang - 26 Jan. 2025" << endl;
    cout << multA(281, 2145) << endl;
    /*cout << multB(281, 2145) << endl;
    cout << multC(281, 2145) << endl;*/
}
