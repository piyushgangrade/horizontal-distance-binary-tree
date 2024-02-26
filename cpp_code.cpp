#include <iostream>
#include <queue>
#include <map>

using namespace std;

// Define the structure for the tree node
struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find horizontal distance between two nodes at the same level
int findHorizontalDistance(TreeNode* root, int node1, int node2) {
    if (!root) return -1;

    queue<pair<TreeNode*, pair<int, int>>> q; // Queue to perform level order traversal
    map<int, pair<int, int>> node_distances;  // Map to store level and horizontal distance

    q.push({root, {0, 0}});  // Initialize the queue with the root node

    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int level = q.front().second.first;
        int hd = q.front().second.second;
        q.pop();

        if (node) {
            // Store the horizontal distance for the node
            node_distances[node->val] = {level, hd};

            // Enqueue left and right children with updated level and horizontal distance
            q.push({node->left, {level + 1, hd * 2}});
            q.push({node->right, {level + 1, hd * 2 + 1}});
        }
    }

    // Check if both nodes are at the same level and calculate distance
    if (node_distances[node1].first == node_distances[node2].first) {
        return abs(node_distances[node1].second - node_distances[node2].second);
    }

    return -1; // Return -1 if nodes are not at the same level
}

int main() {
    // Construct the binary tree from the example
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(7);
    root->right->left = new TreeNode(1);
    root->right->left->left = new TreeNode(4);
    root->right->left->right = new TreeNode(6);
    root->left->left->left = new TreeNode(9);

    // Find the horizontal distance between node 7 and 1
    cout << "The horizontal distance between node 7 and 1 is: ";
    cout << findHorizontalDistance(root, 7, 1) << endl;

    return 0;
}
