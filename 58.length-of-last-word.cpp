#include <iostream>
#include <string>
using namespace std;

int lengthOfLastWord(string s) {
    int count = 0;
    bool wordEncountered = false;
    for(int i= s.length() - 1; i >= 0; i--) {
        if(s[i] != ' ') {
            if(!wordEncountered) continue;
            else break;
        }
        wordEncountered = true;
        count++;
    }

    return count;
}