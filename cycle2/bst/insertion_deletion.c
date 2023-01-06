void insert(node** root, int data) {
    if (*root == NULL) {
        node* newleaf = (node*)malloc(sizeof(node));
        newleaf->data = data;
        newleaf->left = NULL;
        newleaf->right = NULL;
        *root = newleaf;
    }
    else {
        if (data < (*root)->data)
            return insert(&(*root)->left, data);
        else
            return insert(&(*root)->right, data);
    }
}

static node* search(node* root, int data) {
    if (root->data == data)
        return root;
    
    if (root->left != NULL)
        return search(root->left, data);
    if (root->right != NULL)
        return search(root->right, data);

    return NULL;
}
