#include <stdio.h>

struct linkedlist
{
    char data;
    struct linkedlist *next;
};
typedef struct linkedlist node;

void displayMenu()
{
    printf("\t____________HERE IS THE MENU____________\n");
    printf("\t1. Insert at the start\n");
    printf("\t2. Insert at index\n");
    printf("\t3. Insert at the end\n");
    printf("\t4. Delete at the start\n");
    printf("\t5. Delete with value\n");
    printf("\t6. Delete from end\n");
    printf("\t7. Display\n");
    printf("\t0. Exit\n");
}

void display(node *head)
{
    node *temp = head;
    printf("\n");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

node *insertAtStart(node *head, int nodeToInsert)
{
    node *temp1;

    if(head == NULL)
    {
        head = new node;
        head->next = NULL;
        head->data = nodeToInsert;
        return head;
    }
    temp1 = new node;
    temp1 -> next = head;
    temp1 -> data = nodeToInsert;
    head = temp1;

    return head;
}

node *insertAtIndex(node *head, int insertItem, int index)
{

    node *previousNode, *newNode;
    int i;

    previousNode = head;
    for(i = 0; i < index-1; i++)
    {
        previousNode = previousNode -> next;
    }
    newNode = new node;
    newNode -> next = previousNode -> next;
    newNode -> data = insertItem;
    previousNode -> next = newNode;

    return head;

}


node *insertAtEnd(node *head, int insertItem)
{
    node *temp, *newNode;

    newNode = new node;
    newNode -> data = insertItem;
    newNode -> next = NULL;

    if(head == NULL)
    {
        return newNode;
    }

    temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }
    temp -> next = newNode;

    return head;
}

node *deleteFromStart(node *head)
{
    node *nodeToDelete;

    if(head == NULL)
    {
        printf("\n  The list is empty.  ");
        return head;
    }

    nodeToDelete = head;
    head = head -> next;
    delete (nodeToDelete);

    printf(" \nAfter deleting the first node of the list:\n");
    return head;
}

node *deleteWithValue(node *head, int itemToDelete)
{
    node *previousNode = head;
    node *nodeToDelete = head;

    if(head -> data == itemToDelete)
    {
        head = head -> next;
        delete (nodeToDelete);
        return head;
    }

    while(nodeToDelete != NULL && nodeToDelete -> data != itemToDelete)
    {
        previousNode = nodeToDelete;
        nodeToDelete = nodeToDelete -> next;
    }

    if( nodeToDelete == NULL )
    {
        printf("\nNothing to delete.");
        return head;
    }

    previousNode -> next = nodeToDelete -> next;
    delete (nodeToDelete);
    return head;
}

node *deleteFromEnd(node *head)
{
    node *temp;
    if(head == NULL)
    {
        printf("\n  The list is empty.  ");
    }
    if(head -> next == NULL)
    {
        delete (head);
        head = NULL;
    }
    temp = head;
    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }
    delete (temp -> next);
    temp -> next = NULL;

    printf(" \nAfter deleting the last node of the list:\n");

    return head;
}

int main()
{
    node *head;
    int choice, item;
    head = NULL;

    do
    {
        display(head);
        displayMenu();
        printf("Enter your choice here:  ");
        fflush(stdin);
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("\nEnter data to insert at the beginning: ");
            scanf("%d", &item);
            head = insertAtStart(head, item);
        }
        else if(choice == 2)
        {
            int index;
            printf("\nEnter data to insert at the given index: ");
            scanf("%d", &item);
            printf("\nEnter the index where you want to insert the data: ");
            scanf("%d", &index);

            head = insertAtIndex(head, item, index);

        }
        else if(choice == 3)
        {
            printf("\nEnter data to insert at the last: ");
            scanf("%d", &item);
            head = insertAtEnd(head, item);
        }
        else if(choice == 4)
        {
            head = deleteFromStart(head);
        }
        else if(choice == 5)
        {
            printf("\nEnter the value to delete: ");
            scanf("%d", &item);

            head = deleteWithValue(head, item);
        }
        else if(choice == 6)
        {
            head = deleteFromEnd(head);
        }
        else if(choice == 7)
        {
            display(head);
        }
        else if(choice == 0)
        {
            break;
        }
        else
        {
            printf("\nInvalid Choice!\n");
        }
    }
    while(choice != 0);

    return 0;
}
