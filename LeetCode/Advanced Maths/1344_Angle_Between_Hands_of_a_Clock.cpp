#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    double angleClock(int hour, int minutes){
        double degPerMin = 6;
        double degPerHr  = 30;

        double hrHandDegPerMin = 0.5;

        double hrAngle  = (hour % 12) * degPerHr;
        double minAngle = minutes * degPerMin;

        hrAngle += minutes * hrHandDegPerMin;

        double angle = abs(minAngle - hrAngle);

        return min(angle, 360.00 - angle);
    }
};

// Technique:
// Math / Geometry

// Approach:
// Compute the angles made by the hour hand
// and minute hand independently.
// The minute hand moves 6 degrees per minute.
// The hour hand moves 30 degrees per hour
// and additionally 0.5 degrees per minute.
// Find the absolute difference between
// the two angles.
// Since the clock is circular, return the
// smaller angle between:
//
// angle and 360 - angle

// TC: O(1)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}