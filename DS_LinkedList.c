#include<stdio.h>
#include<stdlib.h>

int node_number = 0;

struct node
{
    int data;
    struct node* link;
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

    struct node* pred = NULL;
    struct node* p = NULL;

    p = head;

    for(i = 1; i <= position; i++){
        pred = p;
        p = p->link;
    }
    pred->link = new_node;
    new_node->link = p;

    node_number++;
}

void insert2()
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));

    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    struct node* temp = head, *temp2;

    while(temp->data < data){
        temp2 = temp;
        temp = temp->link;
    }
 //   new_node->link = temp;
    if(head->link == NULL){
        head = new_node;
        new_node->link = NULL;
        return;
    }
    temp2->link = new_node;
    new_node->link = temp;
}
void delete()
{
    if(node_number <= 0){
        printf("\tLink List is empty\n");
        return;
    }
    struct node* temp, *next, *prev;
    int i, position;

    printf("\tEnter the position of the node to delete: ");
    scanf("%d", &position);

    if(position > node_number+1){
        printf("\tCan't delete in this position\n");
        return;
    }

    temp = head;

    for(i = 1; i <= position; i++){
        prev = temp;
        temp = temp->link;
        next = temp->link;
    }
    prev->link = next;

    node_number--;

    free(temp);

}
void display()
{
    struct node* show = NULL;
  //  printf("aj\n");
    show = head->link;

  //  printf("j2j\n");
    printf("\tShowing data:\n\t\t");
    while(show != NULL){
        printf("%d ", show->data);
        show = show->link;
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
                insert2();
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
    dummy_node->data = -10000;
    dummy_node->link = NULL;

    menu();

    return 0;
}
