#include "binary_trees.h"

/**
 * find_min - This finds the minimum value node in a tree
 *
 * @node: Pointer to the root node
 * Return: Pointer to the minimum node
 */
bst_t *find_min(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - This removes a node from a Binary Search Tree
 *
 * @root: Pointer to the root node of the tree
 * @value: Value to be removed
 * Return: Pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp, *parent;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			temp = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(temp);
		}
		else if (root->right == NULL)
		{
			temp = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(temp);
		}
		else
		{
			temp = find_min(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}

	return (root);
}
