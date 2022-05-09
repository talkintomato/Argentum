#include <stdio.h>
#include <stdlib.h>
// A struct that represents the node of the Singly Linked list
struct node
{
    // the value variable points to address of its String
    char *value;
    // the next variable is of struct node* type and will be used to store the address of the next node of the Singly Linked list
    struct node *next;
};

void insert();
void display();
void remove();

typedef struct node DATA_NODE;
DATA_NODE *head_node = NULL;
DATA_NODE *first_node = NULL;
DATA_NODE *temp_node = NULL;
DATA_NODE *prev_node;
DATA_NODE next_node;
// a variable named data of integer type is created to store the value associated with that particular node of the Singly Linked list
char data[20];
char *ptr = data;

// Adds a new node to the list
void insert()
{
    // Data to be associate with that particular node of the Singly Linked list is taken as input from the user
    printf("\nEnter Element for Insert Linked list : \n");
    // the data enetred by the user is stored in the data variable
    scanf(" %s", ptr);
    // a temporary node is created with the added new data by the user, and this new temporary node is allocated memory by using the malloc function
    temp_node = (DATA_NODE *)malloc(sizeof(DATA_NODE));
    // now the data added by the user is associated with this particular new temproray node
    temp_node->value = ptr;

    if (first_node == NULL)
    {
        // if value of first_node varible is zero then it will become the head of the Singly Linked list
        first_node = temp_node;
    }
    else
    {
        // if the value is not zero, then the address of this new node will be added to the pointer of the already last existing node in the Singly Linked list
        head_node->next = temp_node;
    }
    // and the address that is stored in the newly added node is NULL representing it to be the last node of the Singly Linked list
    temp_node->next = NULL;
    head_node = temp_node;
    // Increments pointer for char arrays
    ptr += sizeof(DATA_NODE);
    fflush(stdin);
}

// Counts the total number of nodes in the list
int count()
{
    // Counts the number of nodes in the list
    int count = 0;
    // the temp_node variable is initialized with the first_node variable, which is the first node of the Singly Linked list
    temp_node = first_node;
    // The list is traversed until the last element of the Singly Linked list is encountered
    while (temp_node != NULL)
    {
        // the count varible is incremented after traversing each node of the Singly Linked list
        count++;
        temp_node = temp_node->next;
    }
    // after traversing each node of the Singly Linked list, the total count of the number of nodes in the Singly Linked list is printed
    return count;
}

// A function named remove was written to remove a node from the Singly Linked list
void remove()
{
    int countvalue = 0;
    int pos = 0;
    int i = 0;
    countvalue = count();
    temp_node = first_node;
    printf("\nDisplay Linked list : \n");
    printf("\nEnter Position for Delete Element : \n");
    scanf("%d", &pos);

    // checks if user input index is valid
    if (pos <= 0 && pos > countvalue)
    {
        printf("\nInvalid Position \n\n");
        return;
    }

    // checks if user wants to delete the head node of the list
    if (pos == 1)
    {
        temp_node = temp_node->next;
        first_node = temp_node;
        printf("\nDeleted Successfully \n\n");
        return;
    }

    // Traverse to that position and then delete that node from the Singly Linked list
    while (temp_node != 0)
    {
        if (i == (pos - 1))
        {
            prev_node->next = temp_node->next;
            if (i == (countvalue - 1))
            {
                head_node = prev_node;
            }
            // Once the node is deleted a message is displayed to the user
            printf("\nDeleted Successfully \n\n");
            break;
        }
        else
        {
            i++;
            prev_node = temp_node;
            temp_node = temp_node->next;
        }
    }

    // if the position that is entered by the user is out of the range of the length of the  Singly Linked list then an error message saying Invalid position is displayed
}

// A function named display is written to print the data in the nodes of the Singly Linked list
void display_all()
{
    // keeps the total count of the number of nodes in the list
    int count = 0;
    // the temp_node variable is initialized with the first_node variable, which is the first node of the Singly Linked list
    temp_node = first_node;
    printf("\nDisplay Linked list : \n");
    // The Singly Linked list is traversed untill the last element of the Singly Linked list is encountered
    while (temp_node != NULL)
    {
        // while traversing the Singly Linked list the data present in the each node of the Singly Linked list is printed
        printf("%s, ", temp_node->value);
        // the count variable is incremented after traversing each node of the Singly Linked list
        count++;
        temp_node = temp_node->next;
    }
    // after traversing each node of the Singly Linked list, the total count of the number of nodes in the Singly Linked list is printed
    printf("\nNo Of Items In Linked list : %d\n", count);
}

void display()
{
    int countvalue = 0;
    int pos = 0;
    temp_node = first_node;
    printf("\nEnter Position of String : \n");
    scanf("%d", &pos);
    // Checks if user input is valid
    if (pos > count() || pos < -1)
    {
        printf("\nInvalid Index \n");
        return;
    }
    // The Singly Linked list is traversed until the requested index
    while (countvalue < pos)
    {
        countvalue++;
        temp_node = temp_node->next;
    }

    printf("%s ", temp_node->value);
}

int main()
{
    // Display messages
    printf("Please Choose one of the Operations::\n");
    printf("1. To insert data into the list.\n");
    printf("2. To delete data from the list.\n");
    printf("3. To display all data present in the list.\n");
    printf("4. To display data present in the list by index.\n");
    printf("5. Exit programme.\n");
    while (1)
    {
        printf("Enter command: \n");
        printf("\n");
        int choice;
        scanf("%d", &choice);
        // Switch case
        switch (choice)
        {
        case 1:
            insert();
            printf("Data Added Sucessfully.\n");
            break;
        case 2:
            remove();
            break;
        case 3:
            display();
            break;
        case 4:
            display_all();
            break;
        case 5:
            goto out;
            break;
        default:
            printf("Please enter a valid option from the menu to proceed further.\n \n");
            break;
        }
    };
out:
    return 0;
}