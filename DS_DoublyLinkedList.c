#include<stdio.h>
#include<stdlib.h>

int node_number = 0;

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};
struct node* head;

void insert()
{
    int data, position, i;

    printf("\tEnter the data and position to insert: ");
    scanf("%d%d", &data, &position);

    if(position > node_number+1){
        printf("\tCan't insert in this position\n");
        return;
    }

    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data = data;

    struct node* temp, *temp2;
    temp = head;

    for(i = 1; i <= position; i++){
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = new_node;
    new_node->prev = temp2;
    new_node->next = temp;

    node_number++;
}
void delete()
{
    if(node_number <= 0){
        printf("\tLink List is empty\n");
        return;
    }
    int i, position;
    printf("\tEnter the position of the node to delete: ");
    scanf("%d", &position);

    if(position > node_number+1){
        printf("\tCan't delete in this position\n");
        return;
    }

    struct node* temp = head, *temp2, *temp3;

    for(i = 1; i <= position; i++){
        temp2 = temp;
        temp = temp->next;
        temp3 = temp->next;
    }
    temp2->next = temp->next;
    if(temp3 != NULL) temp3->prev = temp2;

    node_number--;

    free(temp);
}
void display()
{
    if(node_number <= 0){
        printf("\tNothing to show\n");
        return;
    }
    struct node* show = head->next;

    printf("\tShowing data: \n\t\t");
    while(show != NULL){
        printf("%d ", show->data);
        show = show->next;
    }
    printf("\n");
}
void menu()
{
    int choice;

    printf("\t\tPress 1 for insert()\n");
    printf("\t\tPress 2 for delete()\n");
    printf("\t\tPress 3 for display()\n");
    printf("\t\tPress 4 for exit\n\n");

    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\tInvalid choice\n");
        }
    }
}

int main()
{
    head = NULL;

    struct node* dummy_node = (struct node*) malloc(sizeof(struct node));

    head = dummy_node;
    dummy_node->prev = NULL;
    dummy_node->next = NULL;

    menu();

    return 0;
}
