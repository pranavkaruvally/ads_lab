node* highest(node* root) {
    if (root == NULL)
        return NULL;

    node* temp = root;
    while (temp->right != NULL)
        temp = temp->right;

    return temp;
}

node* lowest(node* root) {
    if (root == NULL)
        return NULL;

    node* temp = root;
    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}
