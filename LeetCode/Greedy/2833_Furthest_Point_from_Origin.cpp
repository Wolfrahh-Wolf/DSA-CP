#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// <=== OPTIMAL SOL ===>
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dis = 0;
        int blank = 0;
        for(char c : moves){
            if(c == 'L') dis--;
            else if(c == 'R') dis++;
            else blank++;
        }

        return abs(dis) + blank;        
    }
};

// Technique:
// Greedy

// Approach:
// Compute the Net Displacement from "L" & "R" and also calculate the blanks.
// Return abs(displacement) + blank.
// This will add blank directly to the required side.

// TC: O(N)
// SC: O(1)

// Verdict: Optimal



// <=== BETTER SOL===>

class Solution {
private:
    int findDistance(string moves, int side){
        int dis = 0;
        for(char c : moves){
            if(c == 'L') dis--;
            else if(c == 'R') dis++;
            else dis += side;
        }

        return dis;
    }

public:
    int furthestDistanceFromOrigin(string moves) {
        int dis1 = abs(findDistance(moves, +1));
        int dis2 = abs(findDistance(moves, -1));

        return max(dis1, dis2);
    }
};

// Better Sol 
// Technique:
// Greedy => Simulation with Dual Possibilities)

// Approach:
// Treat '_' as flexibility to act as both L -> "-1" or R -> "+1" as we prefer.
// So, run two iterations to get fidn the absolute distance in each assumbtion.
// 1) Assume all '_' contribute +1
// 2) Assume all '_' contribute -1
// Return the maximum absolute distance from both cases.

// TC: O(N)
// SC: O(1)

// Verdict: Better

int main()
{
    // Main Function placeholder for testing
    return 0;
}