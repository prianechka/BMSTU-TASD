#include "manage_avl.h"

avl_node_t *avl_make_new_node(int value)
{
    avl_node_t* tmp = (avl_node_t*) malloc(sizeof(avl_node_t));
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data = value;
    tmp->heigth = 0;
    return tmp;
}


int count_height(avl_node_t *node)
{
    int result;
    if (node != NULL)
        result = node->heigth;
    else
        result = -1;
    return result;
}

int count_balance(avl_node_t *avl_node)
{
    int result;
    result = count_height(avl_node->right)- count_height(avl_node->left);
    return result;
}

void change_height(avl_node_t *node)
{
    int hl = count_height(node->left);
    int hr = count_height(node->right);
    if (hl > hr)
        node->heigth = hl + 1;
    else
        node->heigth = hr + 1;
}

avl_node_t* right_rotate(avl_node_t *node)
{
    avl_node_t *tmp = node->left;
    node->left = tmp->right;
    tmp->right = node;
    change_height(node);
    change_height(tmp);
    return tmp;
}

avl_node_t* left_rotate(avl_node_t *node)
{
    avl_node_t *tmp = node->right;
    node->right = tmp->left;
    tmp->left = node;
    change_height(node);
    change_height(tmp);
    return tmp;
}

avl_node_t *avl_balance(avl_node_t *node)
{
    change_height(node);
    if (count_balance(node) == 2)
    {
        if (count_balance(node->right) < 0)
            node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    if (count_balance(node) == -2)
    {
        if (count_balance(node->left) > 0 )
            node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    return node;
}

avl_node_t *avl_insert(avl_node_t *avl_tree, int value, int* count, int flag) // вставка ключа k в дерево с корнем p
{
    if (avl_tree == NULL)
        return avl_make_new_node(value);
    if (value < avl_tree->data)
    {
        (*count)++;
        avl_tree->left = avl_insert(avl_tree->left, value, count, flag);
        avl_tree = avl_balance(avl_tree);
    }
    else if (value > avl_tree->data)
    {
        (*count)++;
        avl_tree->right = avl_insert(avl_tree->right, value, count, flag);
        avl_tree = avl_balance(avl_tree);
    }
    return avl_balance(avl_tree);
}

avl_node_t *avl_find_min(avl_node_t *tree)
{
    if (tree->left == NULL)
        return tree;
    else
        return avl_find_min(tree->left);
}

avl_node_t *avl_remove_min(avl_node_t *tree)
{
    if (tree->left == NULL)
        return tree->right;
    tree->left = avl_remove_min(tree->left);
    return avl_balance(tree);
}

void check_balance_in_del(avl_node_t *tree)
{
    change_height(tree);
    tree = avl_balance(tree);
}

avl_node_t *avl_remove(avl_node_t *tree, int del_value)
{
    if (tree == NULL)
        return NULL;
    if (del_value < tree->data)
        tree->left = avl_remove(tree->left, del_value);
    else if (del_value > tree->data)
        tree->right = avl_remove(tree->right, del_value);
    else
    {
        avl_node_t *tmp_l = tree->left;
        avl_node_t *tmp_r = tree->right;
        tree->left = NULL;
        tree->right = NULL;
        if (tmp_r == NULL)
            return tmp_l;
        avl_node_t* min = avl_find_min(tmp_r);
        min->right = avl_remove_min(tmp_r);
        min->left = tmp_l;
        return avl_balance(min);
    }
    return avl_balance(tree);
}

avl_node_t *avl_find_node(avl_node_t *tree, int value)
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

void free_avl_tree(avl_node_t *tree)
{
    if (tree != NULL)
    {
        free_avl_tree(tree->left);
        free_avl_tree(tree->right);
    }
    free(tree);
}

void print_avl_tree(avl_node_t *tree, const char *dir, int level)
{
    if (tree)
    {
        printf("lvl %d %s = %d\n", level, dir, tree->data);
        print_avl_tree(tree->left, "left", level+1);
        print_avl_tree(tree->right, "right", level+1);
    }
}

void avl_apply(avl_node_t *tree, void (*f)(avl_node_t*, void*), void *arg)
{
    if (tree == NULL)
        return;
    avl_apply(tree->left, f, arg);
    f(tree, arg);
    avl_apply(tree->right, f, arg);
}

void avl_to_dot(avl_node_t *tree, void *param)
{
    FILE *f = param;

    if (tree->left)
        fprintf(f, "%d -> %d;\n", tree->data, tree->left->data);

    if (tree->right)
        fprintf(f, "%d -> %d;\n", tree->data, tree->right->data);
}

void avl_export_to_dot(FILE *f, avl_node_t *tree)
{
    fprintf(f, "digraph %s {\n", "avl");

    avl_apply(tree, avl_to_dot, f);

    fprintf(f, "}\n");
}


//Поиск элемента для удаления
avl_node_t *avl_tree_find_del_node(avl_node_t *tree, avl_node_t **parent, int find_elem)
{
    while (tree)
    {
        if (tree->data > find_elem)
        {
            *parent = tree;
            tree = tree->left;
        }
        else if (tree->data < find_elem)
        {
            *parent = tree;
            tree = tree->right;
        }
        else
            break;
    }
    return tree;
}

//Удаление элемента из дерева
void avl_tree_delete(avl_node_t *del_node, avl_node_t **parent)
{

    //Если у узла нет наследников
    if (del_node->left == NULL && del_node->right == NULL)
    {
        if ((*parent)->left == del_node)
            (*parent)->left = NULL;
        else
            (*parent)->right = NULL;
        free(del_node);
    }

    //Если у узла один правый наследник
    else if (del_node->left == NULL && del_node->right != NULL)
    {
        del_node->data = del_node->right->data;
        free(del_node->right);
        del_node->right = NULL;
    }

    //Если у узла один левый наследник
    else if (del_node->left != NULL && del_node->right == NULL)
    {
        del_node->data = del_node->left->data;
        free(del_node->left);
        del_node->left = NULL;
    }

    //Если у узла два наследника
    else
    {
        avl_node_t *min_left_elem =  del_node->left;
        del_node->data = min_left_elem->data;
        avl_tree_delete(min_left_elem, &del_node);
    }
}


