#include <stdio.h>
#include <stdlib.h>

struct node {
    int coe;
    int expo;
    struct node* link;
};

struct node* insert(struct node* head, int coe, int expo) {
    struct node* temp;
    struct node* newp = malloc(sizeof(struct node));
    newp->coe = coe;
    newp->expo = expo;
    newp->link = NULL;

    if (head == NULL || head->expo < expo) {
        newp->link = head;
        head = newp;
    } else {
        temp = head;
        while (temp->link != NULL && temp->link->expo > expo) {
            temp = temp->link;
        }
        newp->link = temp->link;
        temp->link = newp;
    }
    return head;
}

struct node* create(struct node* head) {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    int i;
    int coef, ex;
    for (i = 0; i < n; i++) {
        printf("Enter the Coefficient of term %d: ", i + 1);
        scanf("%d", &coef);
        printf("Enter the Exponent of term %d: ", i + 1);
        scanf("%d", &ex);
        head = insert(head, coef, ex);
    }
    return head;
}

void print(struct node* head) {
    if (head == NULL) {
        printf("NO Polynomial !!");
    } else {
        struct node* temp = head;
        while (temp != NULL) {
            printf("%dx^%d", temp->coe, temp->expo);
            temp = temp->link;
            if (temp != NULL) {
                printf(" + ");
            } else {
                printf("\n");
            }
        }
    }
}

void MultiPoly(struct node* head1, struct node* head2) {
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;

    if (head1 == NULL || head2 == NULL) {
        printf("No Polynomial!");
        return;
    }

    while (ptr1 != NULL) {
        while (ptr2 != NULL) {
            head3 = insert(head3, ptr1->coe * ptr2->coe, ptr1->expo + ptr2->expo);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
        ptr2 = head2;
    }
    struct node* ptr3 = head3;
    struct node* temp = NULL;

    while (ptr3->link != NULL) {
        if (ptr3->expo == ptr3->link->expo) {
            ptr3->coe = ptr3->coe + ptr3->link->coe;
            temp = ptr3->link;
            ptr3->link = ptr3->link->link;
            free(temp);
            temp = NULL;
        } else {
            ptr3 = ptr3->link;
        }
    }
    print(head3);
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    printf("Enter 1st Polynomial:\n");
    head1 = create(head1);
    printf("Enter 2nd Polynomial:\n");
    head2 = create(head2);
    MultiPoly(head1, head2);
    return 0;
}

