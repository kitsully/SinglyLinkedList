#include <stdlib.h>
#include <stdio.h>

struct node {
  int val;
  struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

struct node* createList(int num){
	printf("\n creating list with headnode as [%d]\n",num);
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->val = num;
    ptr->next = NULL;

    head = current = ptr;
    return ptr;
}

void print_list(void)
{
    struct node *ptr = head;

    printf("\n -------Printing list Start------- \n");
    while(ptr != NULL)
    {
        printf("\n [%d] \n",ptr->val);
        ptr = ptr->next;
    }
    printf("\n -------Printing list End------- \n");

    return;
}

int main(void)
{
    struct node *ptr = NULL;
    createList(7);

    print_list();
}
