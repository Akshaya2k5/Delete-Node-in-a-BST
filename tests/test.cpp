// test.cpp

#include <iostream>
#include <vector>
#include <cassert>
#include "../solutions/solution.cpp"

using namespace std;

// Insert node into BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Inorder traversal to return the BST as a vector
vector<int> inorder(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    vector<int> left = inorder(root->left);
    vector<int> right = inorder(root->right);
    res.insert(res.end(), left.begin(), left.end());
    res.push_back(root->val);
    res.insert(res.end(), right.begin(), right.end());
    return res;
}

// Compare actual vs expected and assert
void assertEqual(const vector<int>& actual, const vector<int>& expected, const string& label) {
    assert(actual == expected && "❌ Test case failed");
    cout << "✅ " << label << " passed.\n";
}

void runTestCase(string label, vector<int> values, int keyToDelete, const vector<int>& expected) {
    Solution sol;
    TreeNode* root = nullptr;

    // Build the BST
    for (int val : values) {
        root = insert(root, val);
    }

    root = sol.deleteNode(root, keyToDelete);

    vector<int> result = inorder(root);
    assertEqual(result, expected, label);
}

int main() {
    runTestCase("Basic Case", {5, 3, 6, 2, 4, 7}, 3, {2, 4, 5, 6, 7});

    runTestCase("Moderate Case - Delete Root", {10, 5, 15, 3, 7, 12, 17}, 10, {3, 5, 7, 12, 15, 17});

    runTestCase("Hard Case - Delete node with two children", {50, 30, 70, 20, 40, 60, 80, 65, 75}, 70, {20, 30, 40, 50, 60, 65, 75, 80});

    runTestCase("Edge Case - Delete Non-existing Node", {8, 3, 10, 1, 6, 14, 4, 7, 13}, 100, {1, 3, 4, 6, 7, 8, 10, 13, 14});

    runTestCase("Edge Case - Delete Leaf Node", {10, 5, 20}, 5, {10, 20});

    runTestCase("Edge Case - Empty Tree", {}, 5, {});
}
