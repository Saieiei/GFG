/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
public:
    int sumOfLongRootToLeafPath(Node* root) {
        int maxSum = INT_MIN, maxLength = INT_MIN;
        findLongestPath(root, 0, 0, maxSum, maxLength);
        return maxSum;
    }

private: 
    void findLongestPath(Node* node, int currentSum, int currentLength, int &maxSum, int &maxLength) {

        //base case
        if (!node) {
            if (currentLength > maxLength) {
                maxLength = currentLength;
                maxSum = currentSum;
            } else if (currentLength == maxLength) {
                maxSum = max(maxSum, currentSum);
            }
            return;
        }

        //recursion
        findLongestPath(node->left, currentSum + node->data, currentLength + 1, maxSum, maxLength);
        findLongestPath(node->right, currentSum + node->data, currentLength + 1, maxSum, maxLength);
    }
};