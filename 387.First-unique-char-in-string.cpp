#include <unordered_map>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> freq;

    for(char c : s) {
        freq[c]++;
    }

    for(int i = 0; i < s.length(); i++) {
        if(freq[s[i]] == 1) {
            return i;
        }
    }
    return -1; // If no unique character found
}