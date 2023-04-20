#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100

struct contact
{
    char name[30];
    char phone[15];
};

int num_contacts = 0;
struct contact contacts[MAX_CONTACTS];

void add_contact()
{
    if (num_contacts >= MAX_CONTACTS)
    {
        printf("Error: Contact list is full.\n");
        return;
    }

    struct contact new_contact;
    printf("Enter name: ");
    fgets(new_contact.name, 30, stdin);
    printf("Enter phone number: ");
    fgets(new_contact.phone, 15, stdin);

    contacts[num_contacts++] = new_contact;
    printf("Contact added successfully.\n");
}

void search_contact()
{
    char name[30];
    printf("Enter name to search: ");
    fgets(name, 30, stdin);

    int found = 0;
    for (int i = 0; i < num_contacts; i++)
    {
        if (strcmp(name, contacts[i].name) == 0)
        {
            printf("Phone number: %s\n", contacts[i].phone);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Contact not found.\n");
    }
}

void display_contacts()
{
    if (num_contacts == 0)
    {
        printf("Contact list is empty.\n");
        return;
    }

    printf("Contacts:\n");
    for (int i = 0; i < num_contacts; i++)
    {
        printf("%d. Name: %sPhone: %s\n", i + 1, contacts[i].name, contacts[i].phone);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nPhone Book Management\n");
        printf("---------------------\n");
        printf("1. Add Contact\n");
        printf("2. Search Contact\n");
        printf("3. Display Contacts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            add_contact();
            break;
        case 2:
            search_contact();
            break;
        case 3:
            display_contacts();
            break;
        case 4:
            printf("Goodbye.\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
