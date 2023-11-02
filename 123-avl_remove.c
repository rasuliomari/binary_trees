#include "binary_trees.h"

/**
 * balance_avl - The balance an AVL tree if necessary.
 *
 * @tree: Pointer to the root node of the AVL tree
 */
void balance_avl(avl_t **tree)
{
	int balance_factor;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	balance_avl(&(*tree)->left);
	balance_avl(&(*tree)->right);

	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);

	if (balance_factor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * find_successor - The find the minimum value in the right subtree.
 *
 * @node: Pointer to the tree node to check
 * Return: The minimum value in the subtree
 */
int find_successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = find_successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}

/**
 * remove_node_type - The remove a node based on its children.
 *
 * @node: Pointer to the node to remove
 * Return: 0 if it has no children, or the new value if it has
 */
int remove_node_type(bst_t *node)
{
	int new_value = 0;

	if (!node->left && !node->right)
	{
		if (node->parent->right == node)
			node->parent->right = NULL;
		else
			node->parent->left = NULL;
		free(node);
		return (0);
	}
	else if ((!node->left && node->right) || (!node->right && node->left))
	{
		if (!node->left)
		{
			if (node->parent->right == node)
				node->parent->right = node->right;
			else
				node->parent->left = node->right;
			node->right->parent = node->parent;
		}
		if (!node->right)
		{
			if (node->parent->right == node)
				node->parent->right = node->left;
			else
				node->parent->left = node->left;
			node->left->parent = node->parent;
		}
		free(node);
		return (0);
	}
	else
	{
		new_value = find_successor(node->right);
		node->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - The remove a node from a BST tree.
 *
 * @root: Pointer to the root of the tree
 * @value: Value of the node to remove
 * Return: Pointer to the new root after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_node_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);

	return (root);
}

/**
 * avl_remove - This remove a node from an AVL tree.
 *
 * @root: Pointer to the root of the AVL tree
 * @value: Value of the node to remove
 * Return: Pointer to the new root after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *new_root = (avl_t *) bst_remove((bst_t *) root, value);

	if (new_root == NULL)
		return (NULL);

	balance_avl(&new_root);
	return (new_root);
}
