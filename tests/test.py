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

def run_tests():
    sol = Solution()
    tests = [
        ("Basic Case", [5, 3, 6, 2, 4, 7], 3, [2, 4, 5, 6, 7]),
        ("Delete Root", [10, 5, 15, 3, 7, 12, 17], 10, [3, 5, 7, 12, 15, 17]),
        ("Delete Non-Existing", [1, 2, 3], 100, [1, 2, 3]),
        ("Delete from Empty", [], 1, [])
    ]

    for label, values, key, expected in tests:
        root = build_bst(values)
        root = sol.deleteNode(root, key)
        result = inorder(root)
        assert result == expected, f"❌ {label} failed: expected {expected}, got {result}"

    print("✅ All tests passed.")

if __name__ == "__main__":
    run_tests()
