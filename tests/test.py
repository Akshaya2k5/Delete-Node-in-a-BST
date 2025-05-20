# tests/test.py

import sys
sys.path.append('..')  # To import from solutions folder

from solutions.solution import TreeNode, Solution

def insert(root, val):
    if root is None:
        return TreeNode(val)
    if val < root.val:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root

def inorder(root):
    return inorder(root.left) + [root.val] + inorder(root.right) if root else []

def run_test_case(label, values, key_to_delete):
    root = None
    for v in values:
        root = insert(root, v)

    print(f"\n{label}")
    print("Original BST (inorder):", inorder(root))

    sol = Solution()
    root = sol.deleteNode(root, key_to_delete)

    print(f"BST after deleting {key_to_delete} (inorder):", inorder(root))

if __name__ == "__main__":
    # Basic Case
    run_test_case("Basic Case", [5, 3, 6, 2, 4, 7], 3)

    # Moderate Case - Delete root
    run_test_case("Moderate Case - Delete Root", [10, 5, 15, 3, 7, 12, 17], 10)

    # Hard Case - Delete node with two children
    run_test_case("Hard Case - Delete node with two children", [50, 30, 70, 20, 40, 60, 80, 65, 75], 70)

    # Edge Case - Delete non-existing node
    run_test_case("Edge Case - Delete Non-existing Node", [8, 3, 10, 1, 6, 14, 4, 7, 13], 100)

    # Edge Case - Delete leaf node
    run_test_case("Edge Case - Delete Leaf Node", [10, 5, 20], 5)

    # Edge Case - Delete from empty tree
    run_test_case("Edge Case - Empty Tree", [], 5)
