#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};
 

class Solution{
public:
    vector<vector<int>> treeTraversal(TreeNode* root){
        vector<int> preOrder, postOrder, inOrder;

        if(!root){
            return {inOrder, preOrder, postOrder};
        }

        stack<pair<TreeNode*, int>> st;

        st.push({root, 1});

        while (!st.empty()) {
            auto [node, state] = st.top();
            st.pop();

            if (state == 1){
                preOrder.push_back(node->data);
                st.push({node, 2});

                if(node->left){
                    st.push({node->left, 1});
                }
            } else if (state == 2){
                inOrder.push_back(node->data);
                st.push({node, 3});

                if(node->right){
                    st.push({node->right, 1});
                }
            } else{
                postOrder.push_back(node->data);
            }
        }

        return {inOrder, preOrder, postOrder};
    }
};

// Technique:
// Iterative Traversal (Stack with State Simulation)

// Approach:
// Use a stack storing {node, state} to simulate recursion.
// State 1 → Preorder (process node, go left)
// State 2 → Inorder (process node, go right)
// State 3 → Postorder (process node)
// This allows generating preorder, inorder, and postorder
// traversals in a single pass without recursion.

// TC: O(N)
// N => Number of nodes in the tree
// SC: O(N)
// N => Stack storage in worst case

// Verdict: Optimal

int main()
{
    // Main Function placeholder for testing
    return 0;
}