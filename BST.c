#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* parent;
    struct node* left;
    struct node* right;
};
struct node* root;

void insert(int data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    struct node* temp = root;
    struct node* temp2 = NULL;

    while(temp != NULL){
        temp2 = temp;
        if(new_node->data <= temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    new_node->parent = temp2;
    if(temp2 == NULL){
        root = new_node;
    }
    else if(new_node->data <= temp2->data){
        temp2->left = new_node;
    }
    else{
        temp2->right = new_node;
    }
}
void preorder(struct node* temp)
{
    if(temp == NULL) return;
    printf("%d\n", temp->data);
    preorder(temp->left);
    preorder(temp->right);
}
bool search(int item)
{
    if(root == NULL) return;
    struct node* temp = root;
    while(1){
        if(temp == NULL){
            return false;
        }
        else if(item == temp->data){
            return true;
        }
        else if(item < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
}
struct node* Tree_Minimum(int node)
{
    if(root == NULL) return NULL;
    struct node* temp = root;
    while(1){
        if(temp == NULL){
            return temp;
        }
        else if(node == temp->data){
            break;
        }
        else if(node < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
 //   temp = temp->left;
 ///   printf("%d\n", temp->data);
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
struct node* Tree_Maximum(int node)
{
    if(root == NULL) return NULL;
    struct node* temp = root;
    while(1){
        if(temp == NULL) return NULL;
        else if(temp->data == node){
            break;
        }
        else if(node < temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}
struct node* successor(int node)
{
    if(root == NULL) return NULL;
    struct node* temp = root;
    while(1){
        if(temp == NULL){
            return NULL;
        }
        else if(temp->data == node){
            break;
        }
        else if(temp->data > node){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    if(temp->right != NULL){
        struct node* temp2 = temp->right;
        while(temp2->left != NULL){
            temp2 = temp2->right;
        }
        return temp2;
    }
    else{
        struct node* p = temp->parent;
        while(p != NULL && temp == p->right){
            temp = p;
            p = p->parent;
        }
        return p;
    }
}
int main()
{
    root = NULL;

    insert(100);
    insert(45);
    insert(33);
    insert(23);
    insert(78);
    insert(43);
    insert(22);
    insert(13);
    insert(21);

 //   preorder(root);
 /*   if(search(100)){
        printf("Found\n");
    }
    else{
        printf("Not found\n");
    }*/
    struct node* add = Tree_Minimum(13);
    if(add != NULL) printf("%d\n", add->data);

    struct node* max = Tree_Maximum(23);
    if(max != NULL) printf("%d\n", max->data);

    struct node* s = successor(21);
    if(s != NULL) printf("%d\n", s->data);

    return 0;
}
