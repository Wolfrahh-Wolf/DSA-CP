#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{    
  public:    
    bool lemonadeChange(vector<int>& bills){
        int five = 0;
        int ten  = 0;

        for(int bill : bills){
            if(bill == 5) five++;

            else if(bill == 10){
                if(five){
                    ten++;
                    five--;
                }
                else return false;
                
            }
            else{
                if(five && ten){
                    five--;
                    ten--;
                }
                else if(five >= 3) five -= 3;
                else return false;
            }
        }

        return true;
    }
};

// Technique:
// Greedy

// Approach:
// Maintain the count of available
// ₹5 and ₹10 bills.
//
// For each customer:
// - If they pay with ₹5, store it.
// - If they pay with ₹10, give one
//   ₹5 as change.
// - If they pay with ₹20, always
//   prefer giving one ₹10 and one
//   ₹5 as change. Otherwise, give
//   three ₹5 bills.
//
// If exact change cannot be
// provided at any point, return
// false. Otherwise, return true.

// TC: O(N)

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}