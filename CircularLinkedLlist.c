#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};
struct node* last;

struct node* add_at_empty(struct node* last, int data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    last = new_node;
    new_node->link = new_node;
    return last;
}
struct node* add_at_beg(struct node* last, int data)
{
    if(last == NULL) return add_at_empty(last, data);
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = last->link;
    last->link = new_node;
    return last;
}
struct node* add_at_end(struct node* last, int data)
{
    if(last == NULL) return add_at_empty(last, data);
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = last->link;
    last->link = new_node;
    last = new_node;
    return last;
}
struct node* add_after(struct node* last, int data, int item)
{
    if(last == NULL) return add_at_empty(last, data);
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    struct node* temp = last->link;
    do{
        if(temp->data == item){
            new_node->link = temp->link;
            temp->link = new_node;
            if(temp == last){
                last = new_node;
            }
            return last;
        }
        temp = temp->link;
    }while(temp != last->link);
    return last;
}
void display()
{
    if(last == NULL) return;
    struct node* temp = last->link;
    do{
        printf("%d\n", temp->data);
        temp = temp->link;
    }while(temp != last->link);
}
void delete(int data)
{
    if(last == NULL) return;
    struct node* temp = last->link;
    struct node* temp2 = NULL;

    while(temp2 != last){
        if(temp->data == data){
            if(temp->link == temp){
                last = NULL;
            }
            else if(temp == last->link){
                last->link = temp->link;
            }
            else if(last == temp){
                temp2->link = last->link;
                last = temp2;
            }
            else{
                temp2->link = temp->link;
            }
            free(temp);
            return;
        }
        temp2 = temp;
        temp = temp->link;
    }
}
struct node* insert_at_sorted_order(struct node* last, int data)
{
    if(last == NULL) return add_at_empty(last, data);
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = NULL;
    struct node* temp = last->link;
    struct node* temp2 = NULL;
    while(temp != last && temp->data < data){
        temp2 = temp;
        temp = temp->link;
    }
    if(temp == last && temp2 != NULL){
        new_node->link = last->link;
        last->link = new_node;
        last = new_node;
        return last;
    }
    else if(temp2 == NULL){
        new_node->link = last->link;
        last->link = new_node;
        return last;
    }
    else{
        new_node->link = temp2->link;
        temp2->link = new_node;
        return last;
    }
}
int main()
{
    last = NULL;

  //  last = add_at_empty(last, 20);
 /*   last = add_at_end(last, 80);
    last = add_at_end(last, 100);
    last = add_at_end(last, 22);
    last = add_at_end(last, 40);*/

 /*   display();
    printf("\n");
    delete(20);
    display();*/
    last = insert_at_sorted_order(last, 4);
    last = insert_at_sorted_order(last, 2);
    last = insert_at_sorted_order(last, 8);
    last = insert_at_sorted_order(last, 0);
    last = insert_at_sorted_order(last, 20);
    last = insert_at_sorted_order(last, 6);

    display();

    return 0;
}
