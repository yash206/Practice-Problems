#include<iostream>

using namespace std;



struct node{
    int data;
    struct node *next;
};

struct node *first;



struct node *lsearch(struct node *p8,int key){
    struct node *q=NULL;
while(p8!=NULL){//using move to head
    if(key==p8->data){
q->next=p8->next;//pointer q points to next element of p8 where key==p8->data
p8->next=first;//p8 points to first node so 1st element becomes key
first=p8;//first pointer pointing on key node
return p8;// since, return type is node pointer
    }
    else{
    q=p8;
    p8=p8->next;
  
   

}
}
}


struct node *recurLsearch(struct node *p9,int key){
    if(p9==NULL){
        return NULL;
    }
    if(key==p9->data){
    return p9;
    }
    else{
    return recurLsearch(p9->next,key);//for going on to next node by recursion
    }
}


void display2(struct node *p2){
    if(p2!=NULL){
   
   cout<<p2->data<<endl;
   display2(p2->next);

}
}


int main(){
    //CREATING LINKED LIST
    int arr[]={1,2,3,4,5,6};
   struct node *last,*temp;
   first=new node;
   first->data=arr[0];
   first->next=NULL;
   last=first;

for(int i=1;i<6;i++){
    temp=new node;
    temp->next=NULL;
    temp->data=arr[i];
    last->next=temp;
    last=temp;
   }
  
  
  cout<<recurLsearch(first,3)<<endl;
  display2(first);
  return 0;
}
