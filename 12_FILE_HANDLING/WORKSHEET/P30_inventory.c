/*30.Log Session a grocery store inventory where you can add, update, or remove items using a file.
Input: Add item: Milk, 2 litres, Rs.40
Output: Inventory file now includes the new item*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "inventory.txt"
#define TEMP_FILE "temp.txt"

void addItem() 
{
    char name[50], quantity[30];
    float price;

    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf(" %[^\n]", quantity);
    printf("Enter price (Rs.): ");
    scanf("%f", &price);

    FILE *fp = fopen(FILE_NAME, "a");
    if (!fp) 
    {
        printf("Could not open inventory file.\n");
        return;
    }

    fprintf(fp, "%s, %s, Rs.%.2f\n", name, quantity, price);
    fclose(fp);
    printf("Item added.\n");
}

void viewInventory() 
{
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) 
    {
        printf("Could not open inventory file.\n");
        return;
    }

    char line[128];
    printf("\nInventory:\n");
    while (fgets(line, sizeof(line), fp)) 
    {
        printf("%s", line);
    }
    fclose(fp);
}

void updateItem() 
{
    char target[50];
    char name[50], quantity[30], line[128];
    float price;
    int found = 0;

    printf("Enter item name to update: ");
    scanf("%s", target);

    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen(TEMP_FILE, "w");
    if (!fp || !temp) 
    {
        printf("File error.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp)) 
    {
        sscanf(line, "%[^,],", name);
        if (strcmp(name, target) == 0) 
        {
            found = 1;
            printf("Enter new quantity: ");
            scanf(" %[^\n]", quantity);
            printf("Enter new price: ");
            scanf("%f", &price);
            fprintf(temp, "%s, %s, Rs.%.2f\n", name, quantity, price);
        } else {
            fputs(line, temp);
        }
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename(TEMP_FILE, FILE_NAME);

    if (found)
        printf("Item updated.\n");
    else
        printf("Item not found.\n");
}

void removeItem() 
{
    char target[50], name[50], line[128];
    int found = 0;

    printf("Enter item name to remove: ");
    scanf("%s", target);

    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen(TEMP_FILE, "w");
    if (!fp || !temp) 
    {
        printf("File error.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp)) 
    {
        sscanf(line, "%[^,],", name);
        if (strcmp(name, target) == 0) {
            found = 1;
            continue; 
        }
        fputs(line, temp);
    }

    fclose(fp);
    fclose(temp);
    remove(FILE_NAME);
    rename(TEMP_FILE, FILE_NAME);

    if (found)
        printf("Item removed.\n");
    else
        printf("Item not found.\n");
}

int main() 
{
    int choice;

    do {
        printf("\n--- Grocery Inventory Menu ---\n");
        printf("1. Add Item\n");
        printf("2. View Inventory\n");
        printf("3. Update Item\n");
        printf("4. Remove Item\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: viewInventory(); break;
            case 3: updateItem(); break;
            case 4: removeItem(); break;
            case 5: printf("Exiting...\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

