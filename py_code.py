from collections import deque

class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def findHorizontalDistance(root, node1, node2):
    if not root:
        return -1

    # Queue for level order traversal, storing tuples of (node, level, horizontal distance)
    q = deque([(root, 0, 0)])
    node_distances = {}  # Dictionary to store the horizontal distance of each node

    while q:
        node, level, hd = q.popleft()
        if node:
            # Store the horizontal distance for the node
            node_distances[node.val] = (level, hd)
            # Enqueue the left and right children with updated level and horizontal distance
            q.append((node.left, level + 1, hd * 2))
            q.append((node.right, level + 1, hd * 2 + 1))

    # Get the levels and horizontal distances of the target nodes
    level1, hd1 = node_distances.get(node1, (-1, -1))
    level2, hd2 = node_distances.get(node2, (-1, -1))

    # If the nodes are at the same level, calculate the horizontal distance
    if level1 == level2:
        return abs(hd1 - hd2)
    else:
        return -1

# Example Usage:
root = TreeNode(5)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(7)
root.right.left = TreeNode(1)
root.right.left.left = TreeNode(4)
root.right.left.right = TreeNode(6)
root.left.left.left = TreeNode(9)

print("For the nodes 9 and 4, the horizontal distance is:", findHorizontalDistance(root, 9, 4))
print("For the nodes 7 and 1, the horizontal distance is:", findHorizontalDistance(root, 7, 1))
print("For the nodes 9 and 6, the horizontal distance is:", findHorizontalDistance(root, 9, 6))