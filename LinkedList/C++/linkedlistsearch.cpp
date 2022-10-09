/*PROBLEM------
CREATE A LINKED LIST AND 
WRITE FUNCTIONS TO SEARCH FOR AN ELEMENT,
BOTH RECURSIVELY AND ITERATIVELY AND COMPARE IT
*/


#include<iostream>

using namespace std;
int key;



// CREATING STRUCTURE OF THE LINKED LIST

struct node{
    int data;
    struct node *next;
};

struct node *first;    //POINTER TO FIRST NODE OF LINKED LIST



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

//FUNCTION TO DISPLAY LINKED LIST RECURSIVELY
void display2(struct node *p2){
    if(p2!=NULL){

   cout<<p2->data<<endl;
   display2(p2->next);

}
}


int main(){
    //CREATING LINKED LIST BY HELP OF ARRAY
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
   
   
   
  cout<<"linked list is "<<endl;
  display2(first);
  cout<<"ENTER THE VALUE FOR FINDING IN LINKED LIST "<<endl;
  cin>>key;
  cout<<"----------------------------------"<<endl;
  cout<<"The address of " <<key<<" by RECURSIVE search is ";
  cout<<recurLsearch(first,key)<<endl;
  cout<<"The address of " <<key<<" by ITERATIVE search is ";
  cout<<lsearch(first,key)<<endl;
  cout<<"----------------------------------"<<endl;

  return 0;
}



/* OUTPUT------------
linked list is 
1
2
3
4
5
6
ENTER THE VALUE FOR FINDING IN LINKED LIST
4
-------------------------------
The address of 4 by RECURSIVE search is 0x1051aa0
The address of 4 by ITERATIVE search is 0x1051aa0
----------------------------------
*/
