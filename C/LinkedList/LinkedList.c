#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;                //data stored in the node
    struct node *next;       //pointer to the next node
};

struct LinkedList
{
    struct node *head;
};

struct node* add(struct node *list, int n)
{
    struct node* new_node = NULL;

    new_node = (struct node*)malloc(sizeof(struct node));

    if(NULL == new_node)
    {
        printf("Error: malloc failed.");
        exit(EXIT_FAILURE);
    }

    new_node->val = n;
    new_node->next = list;

    return new_node;
}

struct node* search(struct node *list, int n)
{
    struct node *p;

    for(p=list; p!=NULL; p=p->next)
    {
        if(p->val == n)
            return p;
    }

    return (struct node*)NULL;
}

int main(void)
{
    struct LinkedList list;
    list.head = NULL;

    //add new node
    int i=0;
    //while(i<1000000000000000)
    //{
    //    list.head = add(list.head, i++);
    //}

    //struct node *pn = list.head;
    //while(pn)
    //{
    //   printf("%d ", pn->val);
    //    pn = pn->next;
    //}

    printf("\n");


    printf("Hello World.\n");

 
    int *restrict p1 = NULL;
    int *restrict q1 = NULL;

    p1 = (int*)malloc(4);
    *p1 = 123;

    printf("p1: %d\n", *p1);
    q1 = p1;
    *q1 = 0;

    printf("p1: %d\n", *p1);

    return 0;
} 