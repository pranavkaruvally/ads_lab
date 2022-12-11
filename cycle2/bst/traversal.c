void inorder_traversal(node* root) {
    if (root != NULL) {
		inorder_traversal(root->left);
	    printf("%d ", root->data);
		inorder_traversal(root->right);
    }
}

void preorder_traversal(node* root) {
    if (root != NULL) {
	    printf("%d ", root->data);
		preorder_traversal(root->left);
		preorder_traversal(root->right);
    }
}

void postorder_traversal(node* root) {
    if (root != NULL) {
		postorder_traversal(root->left);
		postorder_traversal(root->right);
	    printf("%d ", root->data);
    }
}
