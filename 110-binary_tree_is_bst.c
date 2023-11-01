#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst_recursive - This check if a binary tree is a valid BST recursively.
 *
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum valid value for this subtree.
 * @max: Maximum valid value for this subtree.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int is_bst_recursive(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_recursive(tree->left, min, tree->n) &&
			is_bst_recursive(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - THIS Check if a binary tree
 * is a valid Binary Search Tree (BST).
 *
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst_recursive(tree, INT_MIN, INT_MAX));
}
