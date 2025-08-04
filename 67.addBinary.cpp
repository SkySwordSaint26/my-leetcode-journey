/*
    Initialize:
        Two pointers i and j at the end of strings a and b.
        A carry = 0.
        A stack to hold the result bits.
    While either string still has digits left OR there is a carry:
        Take digit from a[i] if i >= 0, else 0.
        Take digit from b[j] if j >= 0, else 0.
        Compute: sum = bitA + bitB + carry.
        Push sum % 2 onto the stack (this is the result bit).
        Update carry = sum / 2.
        Decrement i and j.
    After loop ends, pop everything from stack to get the final string.
*/

#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
    string result;
    stack<char> stk;
    
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int bitA = (i >= 0) ? a[i--] - '0' : 0;
        int bitB = (j >= 0) ? b[j--] - '0' : 0;

        int sum = bitA + bitB + carry;
        carry = sum / 2;
        stk.push((sum % 2) + '0');
    }

    while (!stk.empty()) {
        result += stk.top();
        stk.pop();
    }
    return result;
}