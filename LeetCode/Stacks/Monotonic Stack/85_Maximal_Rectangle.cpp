#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    int largestRectangleArea(vector<int> &heights){
        int maxArea = 0;
        int area;
        int PSE;
        int NSE;

        int n = heights.size();

        stack<int> st;

        for(int i = 0 ; i < n; i++){
            int elem = heights[i];

            while(!st.empty() && heights[st.top()] >= elem){
                int idx = st.top(); st.pop();

                PSE = st.empty() ? -1 : st.top();
                NSE = i;

                area = heights[idx] * (NSE - PSE - 1);

                maxArea = max(maxArea, area);
            }

            st.push(i);

        }

        while(!st.empty()){
            int idx = st.top(); st.pop();

            PSE = st.empty() ? -1 : st.top();
            NSE = n;

            area = heights[idx] * (NSE - PSE - 1);

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix){
        int maxArea = INT_MIN;
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> row(cols, 0);

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                row[j]++;

                if(matrix[i][j] == '0') row[j] = 0;
            }

            int area = largestRectangleArea(row);

            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};

// Technique:
// Monotonic Stack + Histogram

// Approach:
// Treat each row as the base of a histogram.
// Maintain a height array where:
//
// row[j]
//
// stores the number of consecutive 1s
// ending at the current row for column j.
//
// For every row:
// - Increase height if the current cell is 1.
// - Reset height to 0 if the current cell is 0.
//
// The updated height array forms a histogram.
// Compute the largest rectangle area in this histogram
// using the Largest Rectangle in Histogram algorithm.
// Track the maximum area across all rows
// and return it.

// Approach: (Largest Rectangle in Histogram)
// Maintain a monotonic increasing stack
// storing indices of histogram bars.
// Whenever a smaller bar is encountered,
// the current index becomes the NSE
// for bars in the stack.
// Pop bars and compute their contribution:
//
// Area = Height × Width
//
// Width:
//
// NSE - PSE - 1
//
// After traversal, process the remaining bars
// by assuming NSE = n.
// Return the maximum area found.

// TC: O(R × C) + O(R × C) = O(2 × R × C) => O(R × C)
// TC: O(R × C)
// R => Number of rows
// C => Number of columns
// O(C) => Histogram update per row
// O(C) => Largest Rectangle computation per row

// SC: O(C)
// C => Histogram array + Stack storage

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}