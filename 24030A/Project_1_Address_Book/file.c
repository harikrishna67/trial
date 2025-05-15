#include <stdio.h>
#include "file.h"
#include<string.h>
#include "contact.h"

void saveContactsToFile(AddressBook *addressBook) 

{
    FILE *file = fopen("contact.csv", "w");
    if (!file) 
    {
        printf("Error: Could not open file for saving contacts.\n");
        return;
    }


    fprintf(file, "#%d\n", addressBook->contactCount);

    
    for (int i = 0; i < addressBook->contactCount; i++) 
    {
        fprintf(file, "%s,%s,%s\n", 
                addressBook->contacts[i].name, 
                addressBook->contacts[i].phone, 
                addressBook->contacts[i].email);
    }

    fclose(file);
    printf("Contacts saved successfully.\n");

}


void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE *file = fopen("contact.csv", "r");
    if (!file) 
    {
        printf("Error: Could not open file for loading contacts. Starting with an empty address book.\n");
        addressBook->contactCount = 0;
        return;
    }


    fscanf(file, "#%d\n", &addressBook->contactCount);

    
    for (int i = 0; i < addressBook->contactCount; i++) 
    {

        fscanf(file, "%[^,],%[^,],%[^\n]\n", addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
        // fgets(addressBook->contact[i].name, sizeof(addressBook->contact[i].name), file);
        // addressBook->contact[i].name[strcspn(addressBook->contact[i].name, "\n")] = '\0'; 

        // fgets(addressBook->contact[i].phone, sizeof(addressBook->contact[i].phone), file);
        // addressBook->contact[i].phone[strcspn(addressBook->contact[i].phone, "\n")] = '\0';

        // fgets(addressBook->contact[i].email, sizeof(addressBook->contact[i].email), file);
        // addressBook->contact[i].email[strcspn(addressBook->contact[i].email, "\n")] = '\0';
    }

    fclose(file);
    printf("Contacts loaded successfully."); 
}
