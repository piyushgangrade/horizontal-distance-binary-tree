# Horizontal-Distance-Binary-Tree

In a binary tree, find the horizontal distance between 2 nodes at the same level while also counting the position where a sibling node is not present.

![Binary Tree Example Image](/binary_tree_example_image.png)


For example in the given tree, the distance betweem node 7 and 1 which are at same level is 2 (considering right child of node 2 and left child of node 3)


**Input Data:**

Node *root = newNode(5); 
root->left = newNode(2); 
root->right = newNode(3); 
root->left->left = newNode(7); 
root->left->left->left = newNode(9);
// root->left->left->right = newNode(11);
root->right->right = newNode(1); 
root->right->right->left = newNode(4);
root->right->right->right = newNode(6);


*Test Case 1:* Checking for nodes 7 and 11, if a node doesn’t exist in the binary tree

![Test Case 1 Image](/images/testcase1.png)

*Test Case 2:* Checking for nodes 9 and 1, if both nodes are not at same level

![Test Case 2 Image](/images/testcase2.png)

*Test Case 3:* Checking for nodes 7 and 1

![Test Case 3 Image](/images/testcase3.png)

*Test Case 4:* Checking for nodes 9 and 6

![Test Case 4 Image](/images/testcase4.png)

*Test Case 5:* Checking for nodes 2 and 3 (nodes are childs of root)

![Test Case 5 Image](/images/testcase5.png)

*Test Case 6:* Checking for nodes 4 and 6 (where LCA is parent node)

![Test Case 6 Image](/images/testcase6.png)

The statements of counting nodes where a sibling is missing is repeating because it's being executed for both node 4 and node 6 as we have to traverse right to get there. *I don't know how I can solve it without seperating traversing condiitons. Please suggest if you any idea on how to make it better.*

*Test Case 7:* Checking for nodes 9 and 4

![Test Case 7 Image](/images/testcase7.png)

This case is **not working** as the node 9 is left child of node 7 and node 4 is the left child of of node 1, there is 3 nodes (sibling of 7, sibling of 2 and sibling of 3) missing in between. So when calculating horizontal distance, it should give 3 as output but instead it's resulting 4
