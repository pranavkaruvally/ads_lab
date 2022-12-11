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
