//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */


struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}


// } Driver Code Ends
/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
    
   };

*/
class Solution
{
    public:
   Node * reverse(Node* head){
        Node * curr = head ;
        Node * prev = NULL ;
        Node * forw = NULL ;
        
        while(curr!=NULL){
            forw = curr->next ;
            curr->next = prev ;
            prev = curr ;
            curr = forw ;
        }
        
        return prev ;   
    }
    void rearrange(struct Node *head)
    {
        //add code here
         if(head==NULL || head->next==NULL){
            head = head ;
            return ;
        }
        
        Node * temp = head ;
        // Storing the pointer for reversing 
        Node* curr = head->next ;
        Node * forw = head -> next ;
        
        while(forw->next!=NULL && forw->next->next!=NULL){
            // logic
            temp->next = forw ->next ;
            forw->next = forw->next->next ;
            // pointers move ahead 
            temp = temp->next ;
            forw = forw->next ;
        }
        
        
        Node * star = reverse(curr);
        
        temp->next = star ;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        Solution ob;
        ob.rearrange(start);
        printList(start);
    }
    return 0;
}

// } Driver Code Ends