#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"
#include <ctype.h>

void sort_by_name( Contact *str ,AddressBook *addressBook)
{
    int c=addressBook->contactCount;
    Contact temp;
    int i,j;
    for(i=0;i<c-1;i++)
    {
        for(j=0;j<c-i-1;j++)
        {
            if(strcasecmp(str[j].name,str[j+1].name)>0)
            {
                temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }
}
void sort_by_phone( Contact *str ,AddressBook *addressBook)
{
    int c=addressBook->contactCount;
    Contact temp;
    int i,j;
    for(i=0;i<c-1;i++)
    {
        for(j=0;j<c-i-1;j++)
        {
            if(strcasecmp(str[j].phone,str[j+1].phone)>0)
            {
                temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }
}
void sort_by_email( Contact *str ,AddressBook *addressBook)
{
    int c=addressBook->contactCount;
    Contact temp;
    int i,j;
    for(i=0;i<c-1;i++)
    {
        for(j=0;j<c-i-1;j++)
        {
            if(strcasecmp(str[j].email,str[j+1].email)>0)
            {
                temp=str[j];
                str[j]=str[j+1];
                str[j+1]=temp;
            }
        }
    }
}
void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    if (addressBook->contactCount == 0) {
        printf("Address book is empty.\n");
        return;
    }

    
    switch (sortCriteria) 
    {
        case 1:
            sort_by_name(addressBook->contacts, addressBook);
            printf("\033[32mSorting by Name...\033[0m\n");
            break;

        case 2:
            sort_by_phone(addressBook->contacts, addressBook);
            printf("\033[32mSorting by Phone...\033[0m\n");
            break;

        case 3:
            sort_by_email(addressBook->contacts, addressBook);
            printf("\033[32mSorting by Email...\033[0m\n");
            break;

        default:
            printf("\033[31mInvalid sort criteria. Listing as is.\033[0m\n");
    }

    
    printf("\033[36m+-----+--------------------------------+-----------------+--------------------------------+\033[0m\n");
    printf("\033[36m| Sl/No | \033[31m%-30s\033[36m | \033[32m%-15s\033[36m | \033[34m%-30s\033[36m |\033[0m\n", 
           "Name", "Phone", "Email");
    printf("\033[36m+-----+--------------------------------+-----------------+--------------------------------+\033[0m\n");

    
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        printf("\033[36m| %5d | \033[31m%-30s\033[36m | \033[32m%-15s\033[36m | \033[34m%-30s\033[36m |\033[0m\n",
               i + 1,
               addressBook->contacts[i].name,
               addressBook->contacts[i].phone,
               addressBook->contacts[i].email);
    }

    
    printf("\033[36m+-----+--------------------------------+-----------------+--------------------------------+\033[0m\n");
}




void initialize(AddressBook *addressBook) 
{
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}
int validateName(char *name)
{

    for(int i=0;name[i] != '\0';i++)
    {
        if(!(isalpha(name[i]) || name[i] == ' '))
        {
            return 0;
        }
    }
    return 1;
}




int validatePhoneNumber(char *phone)
{
    int i=0;
    int len = strlen(phone);
    if (len != 10)
    {
        return 0;
    }
    while(phone[i] != '\0')
    {
        if(! isdigit(phone[i]))
        {
            return 0;
        }
        i++;
    }
    return 1;
}


int validateEmail(char *email)
{

    if (email[0] == '@')
    {
        return 0;
    }

    char *p;
    
    p = strstr(email, ".com");
    if (p == NULL)
    {
        return 0;
    }

    
    p = strstr(email, "@");
    if (p == NULL)
    {
        return 0;
    }

    return 1; 
}
void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    if (addressBook->contactCount >= MAX_CONTACTS) {
        printf("Address book is full. Cannot add more contacts.\n");
        return;
    }

    char name[50], phone[20], email[50];
    int isValid;

    
    do 
    {
        printf("Enter the name: ");
        scanf(" %[^\n]", name);
        isValid = validateName(name);
        if (!isValid) 
        {
            printf("Invalid name. Please use only letters and spaces.\n");
        }
    } while (!isValid);

    
    do 
    {
        printf("Enter the phone number: ");
        scanf(" %[^\n]", phone);
        isValid = validatePhoneNumber(phone);
        if (!isValid) 
        {
            printf("Invalid number. Please enter digits only (7-15 characters).\n");
        }
    } while (!isValid);


    do 
    {
        printf("Enter the email: ");
        scanf(" %[^\n]", email);
        isValid = validateEmail(email);
        if (!isValid) 
        {
            printf("Invalid email. Please enter a valid email address.\n");
        }
    } while (!isValid);


    Contact *newContact = &addressBook->contacts[addressBook->contactCount];
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    strcpy(newContact->email, email);
    addressBook->contactCount++;

    printf("Contact added successfully.\n");
}
void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    
    int choice;
    char searchKey[50];
    int found = 0;

    printf("Search Contacts by:\n");
    printf("1. Name\n");
    printf("2. Phone Number\n");
    printf("3. Email\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) 
    {
        case 1:
            printf("Enter the name to search: ");
            scanf(" %[^\n]", searchKey);
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcasecmp(addressBook->contacts[i].name, searchKey) == 0)
                {
                    printf("Contact Found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Email: %s\n", addressBook->contacts[i].email);
                    printf("Phone: %s\n", addressBook->contacts[i].phone);
                    found = 1;
                    break;
                }
            }
            break;


        case 2:
            printf("Enter the phone number to search: ");
            scanf(" %[^\n]", searchKey);
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcmp(addressBook->contacts[i].phone, searchKey) == 0)
                {
                    printf("Contact Found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Email: %s\n", addressBook->contacts[i].email);
                    printf("Phone: %s\n", addressBook->contacts[i].phone);
                    found = 1;
                    break;
                }
            }
            break;

        case 3:
            printf("Enter the email to search: ");
            scanf(" %[^\n]", searchKey);
            for (int i = 0; i < addressBook->contactCount; i++)
            {
                if (strcasecmp(addressBook->contacts[i].email, searchKey) == 0)
                {
                    printf("Contact Found:\n");
                    printf("Name: %s\n", addressBook->contacts[i].name);
                    printf("Email: %s\n", addressBook->contacts[i].email);
                    printf("Phone: %s\n", addressBook->contacts[i].phone);
                    found = 1;
                    break;
                }
            }
            break;

        default:
            printf("Invalid choice. Please select a valid option (1-3).\n");
            return;
    }

    if (!found)
    {
        printf("No contact found matching the search criteria.\n");
    }
}    


void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    printf("edit\n");


    char searchName[50];
    printf("Enter the name of the contact to edit: ");
    scanf(" %[^\n]", searchName);


    int found = -1;
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcmp(addressBook->contacts[i].name, searchName) == 0) 
        {
            found = i;
            break;
        }
    }

    if (found == -1) 
    {
        printf("Contact not found.\n");
        return;
    }


    int choice;
    printf("Which field do you want to edit?\n");
    printf("1. Name\n");
    printf("3. Phone\n");
    printf("2. Email\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    char newValue[50];
    int isValid;

    switch (choice) 
    {
        case 1:
        
            do 
            {
                printf("Enter the new name: ");
                scanf(" %[^\n]", newValue);
                isValid = validateName(newValue);
                if (!isValid) 
                {
                    printf("Invalid name. Please use only letters and spaces.\n");
                }
            } while (!isValid);
            strcpy(addressBook->contacts[found].name, newValue);
            break;


        case 2:
            
            do 
            {
                printf("Enter the new phone number: ");
                scanf(" %[^\n]", newValue);
                isValid = validatePhoneNumber(newValue);
                if (!isValid) 
                {
                    printf("Invalid phone number. Please enter digits only (7-15 characters).\n");
                }
            } while (!isValid);
            strcpy(addressBook->contacts[found].phone, newValue);
            break;

        case 3:
            
            do 
            {
                printf("Enter the new email: ");
                scanf(" %[^\n]", newValue);
                isValid = validateEmail(newValue);
                if (!isValid) 
                {
                    printf("Invalid email. Please enter a valid email address.\n");
                }
            } while (!isValid);
            strcpy(addressBook->contacts[found].email, newValue);
            break;

        default:
            printf("Invalid choice. No changes made.\n");
            return;
    }

    printf("Contact updated successfully.\n");

  
}  



void deleteContact(AddressBook *addressBook) 
{
    if (addressBook->contactCount == 0) 
    {
        printf("The address book is empty. No contacts to delete.\n");
        return;
    }

    char searchName[50];
    printf("Enter the name of the contact to delete: ");
    scanf(" %[^\n]", searchName);

    int found = -1;


    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        if (strcmp(addressBook->contacts[i].name, searchName) == 0) 
        {
            found = i;
            break;
        }
    }

    if (found == -1) 
    {
        printf("Contact not found.\n");
        return;
    }

    
    for (int i = found; i < addressBook->contactCount - 1; i++) 
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }

    addressBook->contactCount--;
    printf("Contact deleted successfully.\n");
}
int is_duplicate(AddressBook *addressBook, char *name, char *phone, char *email)
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].name, name) == 0)
        {
            printf("The name '%s' is already present. Please enter a new name.\n", name);
            return 1;
        }
        if (strcmp(addressBook->contacts[i].phone, phone) == 0)
        {
            printf("The phone number '%s' is already present. Please enter a new phone number.\n", phone);
            return 1;
        }
        if (strcmp(addressBook->contacts[i].email, email) == 0)
        {
            printf("The email '%s' is already present. Please enter a new email.\n", email);
            return 1;
        }
    }
    return 0;
}