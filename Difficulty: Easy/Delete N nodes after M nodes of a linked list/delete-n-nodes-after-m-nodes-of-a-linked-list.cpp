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
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert(int n1)
{
    int n,value;
    n=n1;
    struct Node *temp;
    
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp=start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp=temp->next;
        }
    }
}

// } Driver Code Ends
/*
delete n nodes after m nodes
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
    //week 10
    void linkdelete(struct Node  *head, int M, int N)
    {
        //ok so we will make use of recurssion
        //we will 1st try to solve 1 case, rest recurssion will take care of 
        
        //base case
        //is there is no LL at all
                // Base case: if head is NULL, return
        if (head == NULL) return;

        Node* current = head;

        // Skip M nodes
        for (int i = 1; i < M && current != NULL; i++) {
            current = current->next;
        }

        // If we've reached the end of the list, return
        if (current == NULL || current->next == NULL) return;

        // Now current is at the Mth node, start deleting the next N nodes
        Node* temp = current->next;
        for (int i = 0; i < N && temp != NULL; i++) {
            Node* nodeToDelete = temp;
            temp = temp->next;
            delete nodeToDelete;
        }

        // Link the Mth node to the (M+N+1)th node
        current->next = temp;

        // Recur for the list starting from the node after the deleted nodes
        linkdelete(current->next, M, N);
    }
};



//{ Driver Code Starts.
int main()
{
    int t,n1;
    cin>>t;
    while (t--) {
        cin>>n1;
        int m,n;
        cin>>m;
        cin>>n;
        insert(n1);
        Solution ob;
        ob.linkdelete(start,m,n);
        printList(start);
    }
    
    return 0;
}

// } Driver Code Ends