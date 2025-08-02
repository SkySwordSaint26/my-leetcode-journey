#include <iostream>
#include <string>
using namespace std;
int strStr(std::string haystack, std::string needle) {
    int n = haystack.size();
    int m = needle.size();

    if(m > n) return -1;
    if(m == 0) return 0;

    int i = 0, j = 0;
    while(i < n) {
        if(haystack[i] == needle[i]) {
            i++;
            j++;
            if(j == m) return i - m; // Found the needle, return the starting index
        } else {
            i = i - j + 1; // Reset i to the next character after the last matched character
            j = 0; // Reset j to 0 to start matching needle again
        }
    }
    return -1;
}