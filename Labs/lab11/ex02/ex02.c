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

node* rev(node* head) {
    node* new_list = NULL;
    node* curr = head;

    while (curr != NULL) {
        new_list = push(new_list, curr->v);
        curr = curr->next;
    }
    free(head);
    return new_list;
}

void print(node* head) {
    node* curr = head;
    while (curr != NULL) {
        printf("%d\n", curr->v);
        curr = curr->next;
    }
    return;
}

int is_eq(node* h1, node* h2) {
    node* curr1 = h1;
    node* curr2 = h2;

    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->v != curr2->v)
            return 0;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return 1;
}

int main()
{
    char c;
    node *link = NULL, *link_rev = NULL;

    while ((c = getchar()) && c != EOF && c != '\n') {
        link = push(link, c);
        link_rev = push(link_rev, c);
    }
    if (link != NULL && link_rev != NULL) {
        link_rev = rev(link_rev);
        if (is_eq(link, link_rev)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}