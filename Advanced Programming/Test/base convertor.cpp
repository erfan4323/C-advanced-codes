#include <bits/stdc++.h>

using namespace std;

class BaseConverter {
private:
    int baseFrom;
    int baseTo;
    string number;

    int charToDigit(char ch) {
        if (ch >= '0' && ch <= '9') {
            return ch - '0';
        }
        else if (ch >= 'A' && ch <= 'Z') {
            return ch - 'A' + 10;
        }
        else if (ch >= 'a' && ch <= 'z') {
            return ch - 'a' + 10;
        }
        else {
            return -1;
        }
    }

    char digitToChar(int digit) {
        if (digit >= 0 && digit <= 9) {
            return '0' + digit;
        }
        else {
            return 'A' + digit - 10;
        }
    }

public:
    BaseConverter(const string& num, int from, int to) {
        number = num;
        baseFrom = from;
        baseTo = to;
    }

    string convert() {
        int decimalNumber = 0;
        string result = "";

        // Convert the given number to decimal
        int power = number.size() - 1;
        for (char ch : number) {
            int digit = charToDigit(ch);
            if (digit == -1 || digit >= baseFrom) {
                cout << "Invalid number for the given base!" << endl;
                return "";
            }

            decimalNumber += digit * pow(baseFrom, power);
            power--;
        }

        // Convert the decimal number to the desired base
        while (decimalNumber != 0) {
            int remainder = decimalNumber % baseTo;
            char ch = digitToChar(remainder);
            result = ch + result;
            decimalNumber /= baseTo;
        }

        return result;
    }
};

int main() {
    int from, to;
    cout << "Enter the base to convert from (2-32): ";
    cin >> from;
    cout << "Enter the base to convert to (2-32): ";
    cin >> to;

    if (from < 2 || from > 32 || to < 2 || to > 32) {
        cout << "Unsupported base!" << endl;
        return 0;
    }

    if (from == to) {
        cout << "Error: The bases are the same!" << endl;
        return 0;
    }

    string num;
    cout << "Enter the number: ";
    cin >> num;

    BaseConverter converter(num, from, to);
    string convertedNumber = converter.convert();

    if (!convertedNumber.empty()) {
        cout << "Converted number: " << convertedNumber << endl;
    }

    return 0;
}
