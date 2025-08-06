#include <string>
#include <iostream>
using namespace std;
bool isPalindrome(const std::string& s) {
    string temp;
    for(char c: s){
        if(isalnum(c)) temp+= tolower(c);
    }

    int i = 0, j = temp.length() -1;
    while(i < j ){
        if(temp[i] != temp[j]) return false;
        i++;
        j--;
    }
    return true;
}