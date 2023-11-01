#include "binary_trees.h"

/**
 * binary_tree_sibling - This finds the sibling of a node in a binary tree.
 *
 * @node: A pointer to the node to find the sibling of.
 * Return: A pointer to the sibling node, or NULL if not found.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);

	return (node->parent->left);
}
