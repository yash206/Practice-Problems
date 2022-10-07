/*Problem Statementrite 
Write a C code to create a linked list where we need to get values for the linked list manually and then write a function to get the value from the user to delete 
the value from the linked list and then wirte a function to print the values in the list */


#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};
struct Node* head;


void addelement(){
    int number;
    printf("Enter number to add to the list:");
    scanf("%d", &number);
    if(head==NULL){
        struct Node* first=malloc(sizeof(struct Node));
        first->value=number;
        first->next=NULL;
        head=first;
        return;
    }
    else{
        struct Node* temp;
        struct Node* last;
        temp=head;
        while(temp!=NULL){
            last=temp;
            temp=temp->next;
        }
        struct Node* new=malloc(sizeof(struct Node));
        new->value=number;
        new->next=NULL;
        last->next=new;
    }
}
void deleteelement(){
    int number,flag;
    printf("Enter the number to delete:");
    scanf("%d", &number);
    struct Node* temp,*last;
    temp=head;
    if(head->value==number){
        head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL){
        if(temp->value==number){
            break;
        }
        last=temp;
        temp=temp->next;
    }
    last->next=temp->next;
    free(temp);
    return;
}
void viewlist(){
    printf("\nThe values in the list are:");
    struct Node*  temp;
    temp=head;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->next;
    }
    printf("\n\n");
    return;
}
int main(){
    int flag=1;
    while(flag){
        printf("1)Add element to list\n2)Delete element of our choice\n3)View list\nEnter your chocice:");
        int choice;
        scanf("%d", &choice);
    
        switch(choice){
            case 1:
                addelement();
                break;
            case 2:
                deleteelement();
                break;
            case 3:
                viewlist();
                break;
            default:
                flag=0;
                break;
        }
    }
}

/*Output
1)Add element to list
2)Delete element of our choice
3)View list
Enter your chocice:1
Enter number to add to the list:1
1)Add element to list
2)Delete element of our choice
3)View list
Enter your chocice:1
Enter number to add to the list:2
1)Add element to list
2)Delete element of our choice
3)View list
Enter your chocice:1
Enter number to add to the list:3
1)Add element to list
2)Delete element of our choice
3)View list
Enter your chocice:3

The values in the list are:1 2 3 

1)Add element to list
2)Delete element of our choice
3)View list
Enter your chocice:2
Enter the number to delete:2
1)Add element to list
2)Delete element of our choice
3)View list
Enter your chocice:3

The values in the list are:1 3

1)Add element to list
2)Delete element of our choice
3)View list
Enter your chocice:4 */
