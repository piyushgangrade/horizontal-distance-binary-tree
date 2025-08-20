"""Compute horizontal distance between two nodes at the same level in a binary tree.

The distance counts the gaps where a node could have existed if the tree were
complete.  For example, in the following tree the distance between the nodes
``7`` and ``1`` is ``2`` because there would be a missing sibling between them::

        5
       / \
      2   3
     /   /
    7   1

The implementation performs a level‑order traversal while assigning a virtual
position to every node as if the tree were a complete binary tree.  The
distance between two nodes at the same level is the absolute difference of
their positions.
"""

from __future__ import annotations

from collections import deque
from dataclasses import dataclass
from typing import Optional


@dataclass
class TreeNode:
    """Simple binary tree node used for tests and examples."""

    val: int
    left: Optional["TreeNode"] = None
    right: Optional["TreeNode"] = None


def find_horizontal_distance(
    root: Optional[TreeNode], node1: int, node2: int
) -> int:
    """Return the horizontal distance between ``node1`` and ``node2``.

    Parameters
    ----------
    root:
        The root of the binary tree.
    node1, node2:
        The values of the nodes whose distance is required.

    Returns
    -------
    int
        The horizontal distance if both nodes are present on the same level;
        ``-1`` otherwise.

    Notes
    -----
    The function assumes that node values are unique.  It short‑circuits once
    the level containing the target nodes has been processed which makes it
    more efficient than traversing the entire tree.
    """

    if not root:
        return -1

    queue = deque([(root, 0)])  # (node, position)

    while queue:
        level_size = len(queue)
        pos1 = pos2 = None

        for _ in range(level_size):
            node, pos = queue.popleft()

            if node.val == node1:
                pos1 = pos
            if node.val == node2:
                pos2 = pos

            # enqueue children with their virtual positions
            if node.left:
                queue.append((node.left, pos * 2))
            if node.right:
                queue.append((node.right, pos * 2 + 1))

        # Both nodes found on the same level
        if pos1 is not None and pos2 is not None:
            return abs(pos1 - pos2)

        # If exactly one node is found at this level, they are on different levels
        if (pos1 is not None) ^ (pos2 is not None):
            return -1

    return -1


if __name__ == "__main__":  # pragma: no cover - example usage
    root = TreeNode(5)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(7)
    root.right.left = TreeNode(1)
    root.right.left.left = TreeNode(4)
    root.right.left.right = TreeNode(6)
    root.left.left.left = TreeNode(9)

    print(
        "For the nodes 9 and 4, the horizontal distance is:",
        find_horizontal_distance(root, 9, 4),
    )
    print(
        "For the nodes 7 and 1, the horizontal distance is:",
        find_horizontal_distance(root, 7, 1),
    )
    print(
        "For the nodes 9 and 6, the horizontal distance is:",
        find_horizontal_distance(root, 9, 6),
    )

