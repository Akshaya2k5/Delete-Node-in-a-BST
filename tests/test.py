import sys
sys.path.append('solutions')

from solution import TreeNode, Solution

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

def build_bst(values):
    root = None
    for v in values:
        root = insert(root, v)
    return root

def run_test(label, values, key_to_delete, expected):
    sol = Solution()
    root = build_bst(values)
    root = sol.deleteNode(root, key_to_delete)
    result = inorder(root)
    if result == expected:
        print(f"✅ {label} passed")
    else:
        print(f"❌ {label} failed: expected {expected}, got {result}")

if __name__ == "__main__":
    test_cases = [
        ("Basic Case", [5, 3, 6, 2, 4, 7], 3, [2, 4, 5, 6, 7]),
        ("Delete Root", [10, 5, 15, 3, 7, 12, 17], 10, [3, 5, 7, 12, 15, 17]),
        ("Delete Node with Two Children", [50, 30, 70, 20, 40, 60, 80, 65, 75], 70, [20, 30, 40, 50, 60, 65, 75, 80]),
        ("Delete Non-Existing Node", [8, 3, 10, 1, 6, 14, 4, 7, 13], 100, [1, 3, 4, 6, 7, 8, 10, 13, 14]),
        ("Delete Leaf Node", [10, 5, 20], 5, [10, 20])
    ]

    for label, values, key_to_delete, expected in test_cases:
        run_test(label, values, key_to_delete, expected)
