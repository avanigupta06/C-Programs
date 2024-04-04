#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node *insert(struct Node *root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node *search(struct Node *root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

int main() {
    struct Node *root = NULL;
    int choice, key;

    do {
        printf("\nMenu:\n");
        printf("1. Create a BST\n");
        printf("2. Traverse in Inorder\n");
        printf("3. Traverse in Preorder\n");
        printf("4. Traverse in Postorder\n");
        printf("5. Search for an element\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                
                root = insert(root, 6);
                root = insert(root, 9);
                root = insert(root, 5);
                root = insert(root, 2);
                root = insert(root, 8);
                root = insert(root, 15);
                root = insert(root, 24);
                root = insert(root, 14);
                root = insert(root, 7);
                root = insert(root, 8);
                root = insert(root, 5);
                root = insert(root, 2);
                break;
            case 2:
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                struct Node *result = search(root, key);
                if (result != NULL)
                    printf("%d found in the BST.\n");
                else
                    printf("%d not found in the BST.\n");
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}