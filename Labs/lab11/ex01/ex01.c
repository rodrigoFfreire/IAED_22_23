#include <stdio.h>
#include <stdlib.h>


typedef struct stru_node
{
    struct stru_node *next;
    int v;
} node;


node* pop(node* head) {
    node* temp = head;
    if (temp == NULL)
        return NULL;

    head = temp->next;
    free(temp);
    return head;
}

node* push(node* head, int e) {
    node* new = (node*) malloc(sizeof(node));
    new->v = e;
    new->next = head;

    return new;
}

node* destroy(node *head) {
    node* temp1 = head;
    node* temp2;

    while (temp1 != NULL) {
        temp2 = temp1->next;
        free(temp1);
        temp1 = temp2;
    }
    return NULL;
}

void print(node* head) {
    node* curr = head;
    while (curr != NULL) {
        printf("%d\n", curr->v);
        curr = curr->next;
    }
    return;
}

int main()
{
    int d = 1;
    node* link = NULL;
    node* curr;
    
    while (d != 0) {
        scanf("%d", &d);
        if (d != 0)
            link = push(link, d);
    }

    curr = link;
    while (curr != NULL) {
        printf("%d\n", curr->v);
        curr = curr->next;
    }

    return 0;
}