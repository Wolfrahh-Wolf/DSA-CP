#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node{
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val){
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    void insertNodeInBetween(Node* head){
        Node* temp = head;
        
        while(temp){
            Node* nextNode = temp->next;

            temp->next = new Node(temp->val);
            temp->next->next = nextNode;
            temp = nextNode;
        }
    }

    void connectRandomPointers(Node* head){
        Node* temp = head;

        while(temp){
            Node* nextNode = temp->next->next;

            if(temp->random){
                temp->next->random = temp->random->next;
            }
            else{
                temp->next->random = nullptr;
            }

            temp = nextNode;
        }
    }

    Node* extractClone(Node* head){
        Node dummy(-1);
        Node* temp = head;
        Node* clone = &dummy;

        while(temp != nullptr){
            Node* nextNode =  temp->next->next;

            clone->next = temp->next;
            clone = clone->next;
            temp->next = nextNode;
            temp = nextNode;
        }

        return dummy.next;
    }

public:
    Node* copyRandomList(Node* head){
        insertNodeInBetween(head);
        connectRandomPointers(head);

        return extractClone(head);
    }
};

// Technique:
// Interleave + Copy + Extract (O(1) Space Cloning)

// Approach:
// Phase 1 - Insert clones between originals: A→A'→B→B'→C→C'
// Phase 2 - Connect clone random pointers: A'.random = A.random'
// Phase 3 - Extract clones: A→B→C, A'→B'→C' (restore original)

// TC: O(N)
// SC: O(1)

// Verdict: Optimal

int main(){
    // Main Function placeholder for testing
    return 0;
}