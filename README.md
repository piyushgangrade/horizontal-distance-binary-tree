# Binary Tree Horizontal Distance Calculator

## Problem Description
The task is to calculate the horizontal distance between two nodes situated at the same level in a binary tree. The distance calculation includes positions where a sibling node may be absent. 

In a binary tree, find the horizontal distance between 2 nodes at the same level while also counting the position where a sibling node is not present.

![Binary Tree Example Image](/binary_tree_example_image.png)

For example in the given tree, the distance between node 7 and 1 which are at same level is 2 (considering right child of node 2 and left child of node 3)

## Solution

### Overview
The solution involves a level-order traversal to determine each node's level and its horizontal distance from the root. We define horizontal distance as the number of edges traversed from the root to the node. The algorithm assigns an incremented distance for each level of the tree, even for missing sibling nodes.

### Steps

1. **TreeNode Structure**: Define a tree node structure with variables for value, left child, and right child.

2. **Level Order Traversal**: Implement a level-order traversal using a queue that stores each node along with its level and horizontal distance.

3. **Distance Map**: Create a map to associate each node's value with its level and horizontal distance.

4. **Child Node Placement**: For each node at level `L` and horizontal distance `D`, assign the left child a horizontal distance `D*2` and the right child `D*2 + 1`, assuming a complete binary tree.

5. **Distance Calculation**: Once all nodes' levels and distances are mapped, calculate the horizontal distance between the two specified nodes by subtracting their distances, provided they are at the same level.

### Implementation
Two separate implementations are provided: one in Python and another in C++. Both follow the algorithm outlined above to ensure accurate horizontal distance calculation between any two nodes on the same level in a binary tree.


**Input Data for Python:**

root = TreeNode(5)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(7)
root.right.left = TreeNode(1)
root.right.left.left = TreeNode(4)
root.right.left.right = TreeNode(6)
root.left.left.left = TreeNode(9)

**Input Data for C++:**

TreeNode* root = new TreeNode(5);
root->left = new TreeNode(2);
root->right = new TreeNode(3);
root->left->left = new TreeNode(7);
root->right->left = new TreeNode(1);
root->right->left->left = new TreeNode(4);
root->right->left->right = new TreeNode(6);
root->left->left->left = new TreeNode(9);

*Test Case:* Checking for nodes (9, 60)

![Test Case C++ Image](/images/testcase4.png)
![Test Case Python Image](/images/py_code_run.png)