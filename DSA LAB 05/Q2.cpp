#include <iostream>
using namespace std;

void generateParenthesis(int open, int close, int n, string current) {
    if (open == n && close == n) {
        cout << current << " ";
        return;
    }

    if (open < n) {
        generateParenthesis(open + 1, close, n, current + "(");
    }

    if (close < open) {
        generateParenthesis(open, close + 1, n, current + ")");
    }
}

int main() {
    int n = 3;
    generateParenthesis(0, 0, n, "");
    return 0;
}

