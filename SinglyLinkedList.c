#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct node {
  int val;
  struct node *next;
} node;

struct node *head = NULL;
struct node *current = NULL;

struct node* createList(int num){
	printf("\n Creating list with headnode as [%d]\n",num);
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

struct node* addNode(int num){
	/* Ensures that a list exists */
	if(NULL == head)
    {
        return (createList(num));
    }

	printf("\n Adding to list node with value [%d]\n",num);
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(NULL == ptr)
    {
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->val = num;
    ptr->next = NULL;
    current->next = ptr;
    current = ptr;
    return ptr;
}

struct node* searchInList(int val, struct node **prev)
{
    struct node *ptr = head;
    struct node *tmp = NULL;
    bool found = false;

    printf("\n Searching the list for value [%d] \n",val);

    while(ptr != NULL)
    {
        if(ptr->val == val)
        {
            found = true;
            break;
        }
        else
        {
            tmp = ptr;
            ptr = ptr->next;
        }
    }

    if(true == found)
    {
        // if(prev)
        //     *prev = tmp;
        return ptr;
    }
    else
    {
        return NULL;
    }
}

int deleteFromList(int val)
{
    struct node *prev = NULL;
    struct node *del = NULL;

    printf("\n Deleting value [%d] from list\n",val);

    del = searchInList(val, &prev);
    if(del == NULL)
    {
        return -1;
    }
    else
    {
        if(prev != NULL)
            prev->next = del->next;

        if(del == current)
        {
            current = prev;
        }
        else if(del == head)
        {
            head = del->next;
        }
    }

    free(del);
    del = NULL;

    return 0;
}



void printList(void)
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
    addNode(8);
    addNode(9);
    addNode(10);
    addNode(11);
    printList();
    deleteFromList(10);
    printList();
}
