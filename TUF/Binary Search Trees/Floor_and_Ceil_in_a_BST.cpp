#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class Solution{
private:
    int floor = -1;
    int ceil  = -1;

    void floorOfBST(TreeNode* root, int key){
        TreeNode* curr = root;

        while(curr){
            if(curr->data == key){
                floor = curr->data;
                return;
            }

            else if(curr->data < key){
                floor = curr->data;
                curr = curr->right;
            }
            else curr = curr->left;
        }
    }

    void ceilOfBST(TreeNode* root, int key){
        TreeNode* curr = root;

        while(curr){
            if(curr->data == key){
                ceil = curr->data;
                return;
            }

            else if(curr->data > key){
                ceil = curr->data;
                curr = curr->left;
            }
            else curr = curr->right;
        }
    }

public:
    vector<int> floorCeilOfBST(TreeNode* root, int key){
        floorOfBST(root, key);
        ceilOfBST(root, key);

        return {floor, ceil};
    }
};

// Technique:
// Binary Search Tree (BST)
// Iterative Traversal

// Approach:
// Traverse the BST to find the floor
// by moving right whenever the current
// node is smaller than the key.
//
// Traverse the BST to find the ceil
// by moving left whenever the current
// node is greater than the key.
//
// Return both the floor and ceil
// values.

// TC: O(H)
// H => Height of the Tree

// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}