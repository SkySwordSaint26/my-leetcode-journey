/*
* Iterative approach 
* Time Complexity: O(log n)
* Space Complexity: O(1)
* 
* This function calculates the integer square root of a non-negative integer x.
* It uses binary search to find the largest integer whose square is less than or equal to x.
* 
*/
int mysqurt(int x) {
    if(x < 2) return x;

    int low = 1 , high = x / 2, ans = 0;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(mid <= x / mid) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

/*
* Newton Raphson method
* Time Complexity: O(log n)
* Space Complexity: O(1) 
* Slightly more efficient than binary search for large numbers.
* Uses more space for the guess variable.
*/

int mysqrt(int x) {
    if (x == 0 || x == 1) return x;

    long long guess = x;
    while(guess * guess > x) {
        guess = (guess + x / guess) / 2;
    }
    return static_cast<int>(guess);
}