#include <stdio.h>
#include <stdlib.h>

struct Node{
    int cell;
    struct Node *nextNode;
};
void insert_node(struct Node *first, int i);
void print_list(struct Node *first);
void delete_node(struct Node *first);
int main()
{
    struct Node *list = (struct Node *) malloc(sizeof(struct Node));
    insert_node(list, 1);
    insert_node(list, 2);
    insert_node(list, 3);
    insert_node(list, 4);
    print_list(list);
    delete_node(list);
    printf("\n");
    print_list(list);
    return 0;
}
void insert_node(struct Node *first, int i){
    if (first->cell == NULL){
        first->cell = i;
        return;
    }
    struct Node *current;
    for(current = first; current->nextNode != NULL; current=current->nextNode);
    struct Node *next = (struct Node *) malloc(sizeof(struct Node));
    next->nextNode = NULL;
    next->cell = i;
    current->nextNode = next;
}
void print_list(struct Node *first){
    for(struct Node *current = first; current->nextNode != NULL; current=current->nextNode){
        printf("%d\t", current->cell);
        if(current->nextNode->nextNode == NULL){printf("%d\t", current->nextNode->cell);} //Знакомьтесь, костыль
    }
}
void delete_node(struct Node *first){
    if (first->cell == NULL){
        printf("List is empty");
        return;
    }else if(first->nextNode = NULL){
        first->cell = NULL;
        return;
    }
    struct Node *current;
    for(current = first; current->nextNode->nextNode != NULL; current=current->nextNode);
    free(current->nextNode);
    current->nextNode = NULL;

}

