// test.cpp

#include <iostream>
#include <vector>
#include "../solutions/solution.cpp"

using namespace std;

// Insert node into BST
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

// Inorder traversal to print the BST
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void runTestCase(string label, vector<int> values, int keyToDelete) {
    Solution sol;
    TreeNode* root = nullptr;

    // Build the BST
    for (int val : values) {
        root = insert(root, val);
    }

    cout << "\n" << label << "\n";
    cout << "Original BST (inorder): ";
    inorder(root);

    root = sol.deleteNode(root, keyToDelete);

    cout << "\nBST after deleting " << keyToDelete << " (inorder): ";
    inorder(root);
    cout << "\n";
}

int main() {
    // Basic Case
    runTestCase("Basic Case", {5, 3, 6, 2, 4, 7}, 3);

    // Moderate Case - Delete root
    runTestCase("Moderate Case - Delete Root", {10, 5, 15, 3, 7, 12, 17}, 10);

    // Hard Case - Delete node with two children
    runTestCase("Hard Case - Delete node with two children", {50, 30, 70, 20, 40, 60, 80, 65, 75}, 70);

    // Edge Case - Delete non-existing node
    runTestCase("Edge Case - Delete Non-existing Node", {8, 3, 10, 1, 6, 14, 4, 7, 13}, 100);

    // Edge Case - Delete leaf node
    runTestCase("Edge Case - Delete Leaf Node", {10, 5, 20}, 5);

    // Edge Case - Delete from empty tree
    runTestCase("Edge Case - Empty Tree", {}, 5);

    return 0;
}
