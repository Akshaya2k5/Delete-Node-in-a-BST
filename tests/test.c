// test.c

#include <stdio.h>
#include "../solutions/solution.c" // Include the solution file

// Inorder traversal to print BST
void inorder(struct TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Insert into BST (helper for test case building)
struct TreeNode* insert(struct TreeNode* root, int val) {
    if (root == NULL) return newNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void test_case(const char* label, int values[], int n, int key_to_delete) {
    struct TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    printf("\n%s\nOriginal BST (Inorder): ", label);
    inorder(root);
    printf("\nDeleting key: %d\n", key_to_delete);
    root = deleteNode(root, key_to_delete);
    printf("BST After Deletion (Inorder): ");
    inorder(root);
    printf("\n");
}

int main() {
    // Basic case
    int case1[] = {5, 3, 6, 2, 4, 7};
    test_case("Basic Case", case1, 6, 3);

    // Moderate case: Delete root node
    int case2[] = {10, 5, 15, 3, 7, 12, 17};
    test_case("Moderate Case - Delete Root", case2, 7, 10);

    // Hard case: Delete a node with two children and deep subtree
    int case3[] = {50, 30, 70, 20, 40, 60, 80, 65, 75};
    test_case("Hard Case", case3, 9, 70);

    // Edge case: Delete non-existing key
    int case4[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
    test_case("Edge Case - Delete Non-existing", case4, 9, 100);

    // Edge case: Delete leaf node
    int case5[] = {10, 5, 20};
    test_case("Edge Case - Delete Leaf", case5, 3, 5);

    return 0;
}
