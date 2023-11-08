#include<stdio.h>
#include<stdlib.h>
struct node
{
    int row;
    int col;
    int value;
    struct node* next;
}*newnode,*head,*temp,*tail;
int main()
{
    head=NULL;
    int r,c;
    int a;
     printf("Enter number of rows\t:");
     scanf("%d",&r);
     printf("Enter number of columns\t:");
     scanf("%d",&c);
     int i;
     for( i=0;i<r;i++)
     {	int j;
        for( j=0;j<c;j++)
        {
            printf("Enter element:");
            scanf("%d",&a);
            if(a!=0)
            {
               
                 newnode=(struct node*)malloc(sizeof(struct node));
                 newnode->next=NULL;
                 newnode->row=i;
                 newnode->col=j;
                 newnode->value=a;
                 if(head==NULL)
                 {
                    head=newnode;
                    temp=newnode;
                    tail=newnode;
                 }
                 else
                 {
                    temp->next=newnode;
                    temp=newnode;
                    tail=newnode;
                 }
            }
        }
     }
     temp=head;
     while(temp!=NULL)
     {
        printf("ROW: %d COLUMN: %d VALUE: %d\n",temp->row,temp->col,temp->value);
        temp=temp->next;
     }
     temp=head;
    printf("\nSPARSE MATRIX:\n");
     for( i=0;i<r;i++)
     {  int j;
        for( j=0;j<c;j++)
        {
             if(temp!=NULL&&temp->row==i&&temp->col==j)
             {
                printf("%d ",temp->value);
                temp=temp->next;
             }
             else
             {
                printf("0 ");
             }
             
        }
        printf("\n");
     }

}
