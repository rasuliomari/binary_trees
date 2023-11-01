#include "binary_trees.h"

/**
 * binary_tree_nodes - This counts the nodes with
 * at least one child in a binary tree.
 *
 * @tree: A pointer to the root node of the tree to count nodes.
 * Return: The number of nodes with at least one child in the binary tree,
 * or 0 if the tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t count = 0;

	if (tree)
	{
		if (tree->left || tree->right)
			count++;

		count += binary_tree_nodes(tree->left);
		count += binary_tree_nodes(tree->right);
	}

	return (count);
}
