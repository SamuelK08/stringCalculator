#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> decode(string userInput) {
    vector<string> result;
    string partialString = "";
    for(int i = 0; i < userInput.size(); i++) {
        if(userInput[i] == ' ') {
            result.push_back(partialString);
            partialString = "";
        } else if(i == userInput.size() - 1) {
            partialString += userInput[i];
            result.push_back(partialString);
        } else {
            partialString += userInput[i];
        }
    }

    return result;
}

bool isNumber(char inputChar) {
    return '0' <= inputChar && inputChar <= '9';
}

bool isValid(vector<string> vectorInput) {
    if(vectorInput.size() % 2 == 0) {
        return false;
    }

    int balanced = 0;
    for(int i = 0; i < vectorInput.size(); i++) {
        if((i % 2 == 0) && isNumber(vectorInput[i][0])) {
            balanced++;
        } else if((i % 2 != 0) && !isNumber(vectorInput[i][0])) {
            balanced--;
        } else {
            return false;
        }
    }

    return 0 <= balanced && balanced <= 1;
}

void applyOperatorTo(double& result, double inputDouble, char c) {
    if(c == '+') {
        result += inputDouble;
    } else if(c == '-') {
        result -= inputDouble;
    } else if(c == '*') {
        result *= inputDouble;
    } else if(c == '/') {
        result /= inputDouble;
    }
}

double calculate(vector<string> vectorInput) {
    double result = stod(vectorInput[0]);

    for(int i = 1; i < vectorInput.size(); i++) {
        if(i % 2 == 0) {
             applyOperatorTo(result, stod(vectorInput[i]), vectorInput[i - 1][0]);
        }
    }

    return result;
}

int main() {
    string userInput = "";
    string partialString = "";

    cout << "Type line: ";
    getline(cin, userInput);
    vector<string> vectorInput = decode(userInput);
    cout << endl;

    if(isValid(vectorInput)) {
        cout << "Result: " << calculate(vectorInput) << endl;
    } else {
        cout << "Result: ERROR" << endl;
    }

    return 0;
}
