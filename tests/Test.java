package tests;

import solutions.Solution;
import solutions.Solution.TreeNode;

public class Test {

    public static TreeNode insert(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        if (val < root.val) root.left = insert(root.left, val);
        else root.right = insert(root.right, val);
        return root;
    }

    public static void inorder(TreeNode root) {
        if (root == null) return;
        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    public static void runTestCase(String label, int[] values, int keyToDelete) {
        Solution sol = new Solution();
        TreeNode root = null;
        for (int v : values) {
            root = insert(root, v);
        }

        System.out.println("\n" + label);
        System.out.print("Original BST (inorder): ");
        inorder(root);

        root = sol.deleteNode(root, keyToDelete);

        System.out.print("\nBST after deleting " + keyToDelete + " (inorder): ");
        inorder(root);
        System.out.println();
    }

    public static void main(String[] args) {
        runTestCase("Basic Case", new int[]{5, 3, 6, 2, 4, 7}, 3);
        runTestCase("Moderate Case - Delete Root", new int[]{10, 5, 15, 3, 7, 12, 17}, 10);
        runTestCase("Hard Case - Delete node with two children", new int[]{50, 30, 70, 20, 40, 60, 80, 65, 75}, 70);
        runTestCase("Edge Case - Delete Non-existing Node", new int[]{8, 3, 10, 1, 6, 14, 4, 7, 13}, 100);
        runTestCase("Edge Case - Delete Leaf Node", new int[]{10, 5, 20}, 5);
        runTestCase("Edge Case - Empty Tree", new int[]{}, 5);
    }
}
