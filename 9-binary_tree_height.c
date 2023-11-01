#include "binary_trees.h"

/**
 * binary_tree_height - This measures the height of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the height.
 * Return: The height of the binary tree, or 0 if the tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height = 0, right_height = 0;

		if (tree->left)
			left_height = 1 + binary_tree_height(tree->left);

		if (tree->right)
			right_height = 1 + binary_tree_height(tree->right);

		return ((left_height > right_height) ? left_height : right_height);
	}

	return (0);
}
