#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
}*temp,*newnode;
int getMax(int arr[], int n)
{
    int max = arr[0];
    int i;
    for ( i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void printArray(int arr[], int n)
{	int i;
    for ( i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}
int main()
{
      int n;
      printf("Enter number of elements:");
      scanf("%d",&n);
      int a[n];
      int b[n];
      printf("Enter array's element:\n");
      int i;
      for( i=0;i<n;i++)
      {
        scanf("%d",&a[i]);
      }
      printf("\nOriginal array: ");
      printArray(a, n);
      int max = getMax(a, n);
      int exp ;
       for ( exp = 1; max / exp > 0; exp *= 10)
    {
       struct node* count[10]={};
       int i;
       for( i=0;i<n;i++)
       {
        
         temp=count[(a[i]/exp)%10];
          if(temp==NULL)
          {
             
              newnode=(struct node*)malloc(sizeof(struct node)); 
              newnode->data=a[i];
              count[(a[i]/exp)%10]=newnode;
              newnode->next=NULL; 
          }
          else
          {
                
              while(temp->next!=NULL)
              {
                    temp=temp->next;
              }
               newnode=(struct node*)malloc(sizeof(struct node));
               newnode->data=a[i];
               temp->next=newnode;
               newnode->next=NULL;
          }
       }
       int c=0;
       for(i=0;i<10;i++)
       {
           temp=count[i];
          
           while(temp!=NULL)
           {
             b[c]=temp->data;
             temp=temp->next;
             c++;
           }
           
       }
       for(i=0;i<n;i++)
       {
        a[i]=b[i];
       }
    }
    printf("Sorted array: ");
    printArray(a, n);
} 
