#include "binary_trees.h"
#include <limits.h>

/**
 * get_tree_height - This calculate the height of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 * Return: Height of the tree.
 */
int get_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = get_tree_height(tree->left);
	right_height = get_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * calc_balance_factor - This calculate the balance factor of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 * Return: Balance factor of the tree.
 */
int calc_balance_factor(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (get_tree_height(tree->left) - get_tree_height(tree->right));
}

/**
 * validate_avl_recursive - This recursive helper function
 * to validate if a binary
 *
 * tree is a proper AVL Tree.
 * @tree: Pointer to the root node of the tree.
 * @min: Minimum allowed value in the tree.
 * @max: Maximum allowed value in the tree.
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int validate_avl_recursive(const binary_tree_t *tree, int min, int max)
{
	int balance_left, balance_right, balance;

	if (tree == NULL)
		return (1);

	if (tree->n > max || tree->n < min)
		return (0);

	balance = calc_balance_factor(tree);

	if (balance < -1 || balance > 1)
		return (0);

	balance_left = validate_avl_recursive(tree->left, min, tree->n - 1);
	balance_right = validate_avl_recursive(tree->right, tree->n + 1, max);

	if (balance_left == 1 && balance_right == 1)
		return (1);

	return (0);
}

/**
 * binary_tree_is_avl - This check if a binary tree is a valid AVL Tree.
 *
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (validate_avl_recursive(tree, INT_MIN, INT_MAX));
}
