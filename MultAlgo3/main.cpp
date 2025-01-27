#include <iostream>
#include <vector>
using namespace std;

static vector<int> makeIterable(int number) {

    // Make integers iterable

    vector<int> result;
    
    while (number != 0) {
        result.push_back(number % 10);
        number /= 10;
    }

    return result;
}

static int rebuildNumber(vector<int> digits) {
    int number = 0;

    for (int i = 0; i < digits.size(); i++) {
        int place = 1;

        for (int j = 0; j < i; j++)
            place *= 10;

        number += digits[i] * place;
    }

    return number;
}

static int multA(int inMultiplicand, int inMultiplier) {

    // Long multiplication

    int result = 0;
    vector<int> multiplicand = makeIterable(inMultiplicand);
    vector<int> multiplier = makeIterable(inMultiplier);

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

static int multB(int inMultiplicand, int inMultiplier) {

    // Karatsuba multiplication

    vector<int> multiplicand = makeIterable(inMultiplicand);
    vector<int> multiplier = makeIterable(inMultiplier);

    if (multiplicand.size() < 4 and multiplier.size() < 4)
        return multA(inMultiplicand, inMultiplier); // More efficient when numbers are this small
    
    else {
        int m = multiplicand.size() / 2 + (multiplicand.size() % 2);
        int x0;
        int x1;
        int y0;
        int y1;

        if (multiplicand.size() % 2 == 0) {
            vector<int> x1Vector(multiplicand.begin(), multiplicand.end() - m);
            x0 = rebuildNumber(x1Vector);
        }
        else {
            vector<int> x1Vector(multiplicand.begin(), multiplicand.end() - (m - 1));
            x0 = rebuildNumber(x1Vector);
        }

        vector<int> x0Vector(multiplicand.begin() + m, multiplicand.end());
        x1 = rebuildNumber(x0Vector);

        if (multiplier.size() % 2 == 0) {
            vector<int> y1Vector(multiplier.begin(), multiplier.end() - m);
            y0 = rebuildNumber(y1Vector);
        }
        else {
            vector<int> y1Vector(multiplier.begin(), multiplier.end() - (m - 1));
            y0 = rebuildNumber(y1Vector);
        }

        vector<int> y0Vector(multiplier.begin() + m, multiplier.end());
        y1 = rebuildNumber(y0Vector);

        // Implementation of algorithm
        int z0 = x0 * y0;
        int z2 = x1 * y1;
        int z1 = (x1 + x0) * (y0 + y1) - z2 - z0;
        return z2 * pow(pow(10, m), 2) + z1 * pow(10, m) + z0;
    }
}

static int multC(int multiplicand, int multiplier) {

    // Repeated addition

    int result = 0;

    for (int i = 0; i < multiplier; i++)
        result += multiplicand;

    return result;
}

int main() {
    cout << "Eisig Liang - 26 Jan. 2025" << endl;
    cout << multA(281, 2145) << endl;
    cout << multB(281, 2145) << endl;
    cout << multC(281, 2145) << endl;
}