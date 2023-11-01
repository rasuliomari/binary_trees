#include "binary_trees.h"

/**
 * binary_tree_height_aux - This calculate the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree.
 * Return: Height of the tree.
 */
size_t binary_tree_height_aux(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree->left)
		left_height = 1 + binary_tree_height_aux(tree->left);
	if (tree->right)
		right_height = 1 + binary_tree_height_aux(tree->right);

	return (left_height > right_height ? left_height : right_height);
}

/**
 * print_level - This print nodes at a specific level of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 * @level: Level of the tree to print.
 * @func: Pointer to a function for each node.
 */
void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - This perform level-order
 * traversal of a binary tree.
 *
 * @tree: Pointer to the root node of the tree.
 * @func: Pointer to a function for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int tree_height = 0;
	int current_level = 1;

	if (!tree || !func)
		return;

	tree_height = binary_tree_height_aux(tree) + 1;

	while (current_level <= tree_height)
	{
		print_level(tree, current_level, func);
		current_level++;
	}
}
