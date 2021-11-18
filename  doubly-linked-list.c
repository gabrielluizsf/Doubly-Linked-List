#include <stdio.h>
#include <stdlib.h>


 struct node{
   int value;
   struct node* next;
 };
  typedef struct node node_t;
   
   void printList(node_t *head){
       node_t *temporary = head;


       while(temporary != NULL){
           printf("%d -", temporary->value);
           temporary = temporary->next;
       }
       printf("\n");
   }
void remove_node(node_t **head, node_t *node_to_remove){
if(*head==node_to_remove){
    *head=node_to_remove->next;
    return;
}else{
    node_t *temp = *head;
    while(temp != NULL && temp->next != node_to_remove){
     temp = temp->next;  
    }
    if(temp == NULL)return;
    temp->next = node_to_remove->next;
    node_to_remove->next = NULL;

}
return;
}
 node_t *create_new_node(int value){
   node_t*result = malloc(sizeof(node_t));
   result->value = value;
   result->next = NULL;
   return result;
}
 node_t *insert_at_head(node_t **head,node_t *node_to_insert){
   node_to_insert->next = *head;
   *head = node_to_insert;
    return node_to_insert;
 }
 void insert_after_node(node_t *node_to_insert_after,node_t *newnode){
       
     newnode->next = node_to_insert_after->next;
     node_to_insert_after->next = newnode;
 }
 node_t *find_node(node_t *head,int value){
     node_t *tmp = head;
     while(tmp != NULL){
         if(tmp->value == value)return tmp;
         tmp = tmp->next;

     }
     return NULL;
 }
      int main(){
        

        node_t *head = NULL;
        node_t  *tmp;
        int c;
        for(c=0 ;c<25 ; c++){
         tmp = create_new_node(c);
         insert_at_head(&head, tmp);
        }
        
        tmp = find_node(head, 13);
        printf("Found Node With Value %d\n", tmp->value);
        
        insert_after_node(tmp,create_new_node(75));
       printList(head);

          return 0;
      }