#include "manage_tree.h"

node_t* make_new_node(int value, node_t *parent)
{
    node_t* tmp = (node_t*) malloc(sizeof(node_t));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

void insert(node_t **tree, int value, int *count)
{
    if (*tree == NULL)
    {
        *tree = make_new_node(value, NULL);
        return;
    }

    node_t *tmp = NULL;
    tmp = *tree;
    while (tmp)
    {
        if (value > tmp->data)
        {
            (*count)++;
            if (tmp->right)
                tmp = tmp->right;
            else
            {
                tmp->right = make_new_node(value, tmp);
                return;
            }
        }
        else if (value < tmp->data)
        {
            (*count)++;
            if (tmp->left)
                tmp = tmp->left;
            else
            {
                tmp->left = make_new_node(value, tmp);
                return;
            }
        }
        else
            return;
    }
}


node_t *find_node(node_t *tree, int value)
{
    while (tree)
    {
        if (tree->data > value)
            tree = tree->left;
        else if (tree->data < value)
            tree = tree->right;
        else
            return tree;
    }
    return NULL;
}


node_t *find_min_node(node_t *tree)
{
    while (tree->left)
        tree = tree->left;
    return tree;
}

node_t *find_max_node(node_t *tree)
{
    while (tree->right)
        tree = tree->right;
    return tree;
}


void delete_node(node_t *del_node)
{
    if (del_node->left && del_node->right)
    {
        node_t *max = find_max_node(del_node->left);
        del_node->data = max->data;
        delete_node(max);
        return;
    }
    else if (del_node->left && del_node->right == NULL)
    {
        if (del_node == del_node->parent->left)
            del_node->parent->left = del_node->left;
        else
            del_node->parent->right = del_node->left;
    }
    else if (del_node->left == NULL && del_node->right)
    {
        if (del_node == del_node->parent->right)
            del_node->parent->right = del_node->right;
        else
            del_node->parent->left = del_node->right;
    }
    else
    {
        if (del_node == del_node->parent->left)
            del_node->parent->left = NULL;
        else
            del_node->parent->right = NULL;
    }
    free(del_node);
}


void delete_value(node_t *tree, int value)
{
    node_t *del_node = find_node(tree, value);
    delete_node(del_node);
}

void print_tree(node_t *tree, const char *dir, int level)
{
    if (tree)
    {
        printf("lvl %d %s = %d\n", level, dir, tree->data);
        print_tree(tree->left, "left", level+1);
        print_tree(tree->right, "right", level+1);
    }
}

void apply(node_t *tree, void (*f)(node_t*, void*), void *arg)
{
    if (tree == NULL)
        return;
    apply(tree->left, f, arg);
    f(tree, arg);
    apply(tree->right, f, arg);
}


void to_dot(node_t *tree, void *param)
{
    FILE *f = param;

    if (tree->left)
        fprintf(f, "%d -> %d;\n", tree->data, tree->left->data);

    if (tree->right)
        fprintf(f, "%d -> %d;\n", tree->data, tree->right->data);
}

void export_to_dot(FILE *f, node_t *tree)
{
    fprintf(f, "digraph %s {\n", "usual");

    apply(tree, to_dot, f);

    fprintf(f, "}\n");
}




void free_tree(node_t *tree)
{
    if (tree != NULL)
    {
        free_tree(tree->left);
        free_tree(tree->right);
    }
    free(tree);
}

void in_order_search(node_t *tree)
{
    if (tree != NULL)
    {
        in_order_search(tree->left);
        printf("%d ", tree->data);
        in_order_search(tree->right);
    }
}

void pre_order_search(node_t *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->data);
        pre_order_search(tree->left);
        pre_order_search(tree->right);
    }
}

void post_order_search(node_t *tree)
{
    if (tree != NULL)
    {
        post_order_search(tree->left);
        post_order_search(tree->right);
        printf("%d ", tree->data);
    }
}
