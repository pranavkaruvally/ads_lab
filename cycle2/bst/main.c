#include <stdio.h>
#include <stdlib.h>
#include "bst.c"
#include "insertion_deletion.c"
#include "traversal.c"

int main() {
    node* root = NULL;
    insert(&root, 15);
    insert(&root, 4);
    insert(&root, 32);
    insert(&root, 8);
    insert(&root, 20);
    insert(&root, 16);
    insert(&root, 2);

    inorder_traversal(root);
    printf("\n");
    preorder_traversal(root);
    printf("\n");
    postorder_traversal(root);
    printf("\n");

    return 0;
}
