"""Unit tests for the horizontal distance algorithm."""

import os
import sys


sys.path.insert(0, os.path.dirname(os.path.dirname(__file__)))

from py_code import TreeNode, find_horizontal_distance


def build_example_tree() -> TreeNode:
    root = TreeNode(5)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.left.left = TreeNode(7)
    root.right.left = TreeNode(1)
    root.right.left.left = TreeNode(4)
    root.right.left.right = TreeNode(6)
    root.left.left.left = TreeNode(9)
    return root


def test_example_distances():
    root = build_example_tree()
    assert find_horizontal_distance(root, 9, 4) == 4
    assert find_horizontal_distance(root, 7, 1) == 2
    assert find_horizontal_distance(root, 9, 6) == 5


def test_nodes_on_different_levels():
    root = build_example_tree()
    assert find_horizontal_distance(root, 9, 1) == -1


def test_missing_nodes():
    root = build_example_tree()
    # one node missing
    assert find_horizontal_distance(root, 100, 4) == -1
    # both nodes missing
    assert find_horizontal_distance(root, 100, 101) == -1


def test_empty_tree():
    assert find_horizontal_distance(None, 1, 2) == -1

