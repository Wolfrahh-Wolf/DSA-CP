#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions){
        restrictions.push_back({1, 0});

        sort(restrictions.begin(), restrictions.end());

        int m = restrictions.size();

        for(int i = 1; i < m; i++){
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] +
                (restrictions[i][0] - restrictions[i - 1][0])
            );
        }

        for(int i = m - 2; i >= 0; i--){
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] +
                (restrictions[i + 1][0] - restrictions[i][0])
            );
        }

        int lastId = restrictions.back()[0];
        int lastH  = restrictions.back()[1];

        restrictions.push_back(
            {n, lastH + (n - lastId)}
        );

        long long ans = 0;

        for(int i = 1; i < restrictions.size(); i++){
            long long id1 = restrictions[i - 1][0];
            long long h1  = restrictions[i - 1][1];

            long long id2 = restrictions[i][0];
            long long h2  = restrictions[i][1];

            long long dist = id2 - id1;

            ans = max(
                ans,
                max(h1, h2) +
                (dist - abs(h1 - h2)) / 2
            );
        }

        return (int)ans;
    }
};

// Technique:
// Greedy + Constraint Propagation

// Intuition:
// Each restriction limits not only its own building
// but also nearby buildings because adjacent heights
// can differ by at most 1.
//
// Propagate restrictions from left-to-right and
// right-to-left to make all constraints consistent.
//
// Between two valid restriction points, the maximum
// height occurs at the highest possible peak formed
// while respecting the slope constraint.

// Approach:
// Add building 1 with height 0.
// Sort all restrictions.
//
// Propagate constraints:
// - Left -> Right
// - Right -> Left
//
// Add building n with its maximum valid height.
//
// For every adjacent restriction pair,
// compute the highest possible peak between them:
//
// max(h1, h2)
// + (distance - abs(h1 - h2)) / 2
//
// Return the maximum peak found.

// TC: O(M log M) + 3 * O(M) ~= O(M log M)
// M => No of restrictions
// O(M log M) => Sorting
// O(M) => Passes 
// Domination => O(M log M)

// SC: O(1)
// Ignoring sorting space

// Verdict: Optimal



// ===> Formula Derivation

// Intuition:
// Between two valid restriction points:
//
// (id1, h1) and (id2, h2)
//
// the tallest building will lie somewhere
// between them.
//
// First, some distance is consumed to bridge
// the height difference between h1 and h2.
//
// Any remaining distance can be used to form
// a mountain-like peak in the middle.
//
// Since the height can change by at most 1
// per building, increasing the peak by 1
// requires:
//
// +1 while climbing
// +1 while descending
//
// => 2 units of distance per extra height.

// Derivation:
//
// dist = id2 - id1
//
// Height difference that must be covered:
//
// diff = abs(h1 - h2)
//
// Minimum distance needed to match the
// shorter side with the taller side:
//
// diff
//
// Remaining distance available to build
// a peak:
//
// rem = dist - diff
//
// Every extra height requires 2 positions:
//
// Peak Increase = rem / 2
//
// The peak starts from the taller side:
//
// Peak Height
// = max(h1, h2) + rem / 2
//
// = max(h1, h2)
//   + (dist - abs(h1 - h2)) / 2

// Example:
//
// h1 = 1, h2 = 4
// dist = 6
//
// Need 3 positions to go:
//
// 1 -> 2 -> 3 -> 4
//
// Remaining:
//
// rem = 6 - 3 = 3
//
// Peak Increase:
//
// 3 / 2 = 1
//
// Peak:
//
// 4 + 1 = 5
//
// Heights:
//
// 1 2 3 4 5 4 3

int main(){
    // Main Function placeholder for testing
    return 0;
}