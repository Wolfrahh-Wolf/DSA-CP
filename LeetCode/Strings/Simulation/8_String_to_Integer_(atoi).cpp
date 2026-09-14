#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string input) {
        int n = input.size();
        int i = 0;
        int result = 0;
        int sign = 1;

        while(i < n && isspace(input[i])) i++;

        if(input[i] == '-'){
            sign = -1;
            i++;
        }
        else if(input[i] == '+'){
            sign = 1;
            i++;
        }
        else sign = 1;

        while(i < n && input[i] - '0' >= 0 && input[i] - '0' <= 9){

            if (result > INT_MAX/10 || (result == INT_MAX/10 && input[i] - '0' > INT_MAX%10)){

            return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = (result * 10) + (input[i] - '0');
            i++;
        }

        return result * sign;
    }
};

// Technique:
// String Parsing (Simulation)

// Approach:
// Skip leading whitespaces and determine the sign of the number.
// Traverse the string digit by digit and construct the integer.
// Before adding a digit, check for overflow/underflow conditions.
// Stop parsing when a non-digit character is encountered.
// Return the final signed integer value.

// TC: O(N)
// N => Length of the string
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}