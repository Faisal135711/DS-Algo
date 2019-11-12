#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root;

struct node* create_node(int data)
{
    node* new_node = new node();
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert(int data)
{
    node* new_node = create_node(data);

    if(root == NULL){
        root = new_node;
    }
    else{
        node* temp = root;
        while(1){
            if(new_node->data <= temp->data){
                if(temp->left == NULL){
                    temp->left = new_node;
                    break;
                }
                else{
                    temp = temp->left;
                }
            }
            else{
                if(temp->right == NULL){
                    temp->right = new_node;
                    break;
                }
                else{
                    temp = temp->right;
                }
            }
        }
    }
}

void preorder_recursive(node* temp)
{
	if(temp != NULL){
		printf("%d ", temp->data);
		preorder_recursive(temp->left);
		preorder_recursive(temp->right);
	}
}
void postorder_recursive(node* temp)
{
	if(temp != NULL){
		postorder_recursive(temp->left);
		postorder_recursive(temp->right);
		printf("%d ", temp->data);
	}
}
void levelorder(node* temp)
{
	if(temp == NULL) return;
	queue <struct node*> myqueue;
	myqueue.push(temp);

	while(!myqueue.empty()){
		struct node* temp2 = myqueue.front();
		myqueue.pop();
		if(temp2 != NULL){
			printf("%d ", temp2->data);
			myqueue.push(temp2->left);
			myqueue.push(temp2->right);
		}
	}
}

void inorder_recursive(node* temp)
{
    if(temp == NULL) return;
    inorder_recursive(temp -> left);
    printf("%d ", temp -> data);
    inorder_recursive(temp -> right);
}

int main()
{
    int num, i;
    int ch;

    printf("Enter the number of data: ");
    scanf("%d", &num);
    printf("Enter data: \n");
    for(i = 1; i <= num; i++){
        scanf("%d", &ch);
        insert(ch);
    }

    printf("\n\nThe tree traversed in preorder: \n");
    preorder_recursive(root);

    printf("\n\nThe tree traversed in inorder: \n");
    inorder_recursive(root);

    printf("\n\nThe tree traversed in postorder: \n");
    postorder_recursive(root);

    printf("\n\nThe tree traversed in levelorder: \n");
    levelorder(root);

    printf("\n");

    return 0;
}
/*
7
100 20 10 30 200 150 300

*/

