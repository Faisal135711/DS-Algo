#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
struct node* head;

struct node* create_node()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    return temp;
}
void reverse()
{
    struct node* current = head;
    struct node* next = NULL, *prev = NULL;

    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
void push()
{
    int data;
    printf("Enter data: ");
    scanf("%d", &data);

    struct node* new_node = create_node();
    struct node* temp = head, *temp2;

    new_node->data = data;

    if(head == NULL){
        head = new_node;
        new_node->next = NULL;
        return;
    }
    else if(data < temp->data){
        new_node->next = head;
        head = new_node;
        return;
    }
    else{
        while(data > temp->data){
            temp2 = temp;
            temp = temp->next;
            if(temp == NULL) break;
        }
        new_node->next = temp;
        temp2->next = new_node;
    }
}
void display()
{
    struct node* temp = head;

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    head = NULL;
    int choice;

    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                reverse();
                break;
            case 3:
                display();
                break;
            default:
                exit(0);
        }
    }

    return 0;
}
