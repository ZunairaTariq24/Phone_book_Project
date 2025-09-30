#include <stdio.h>
#include <string.h>
struct Person {
char name[30];
char phone[30];
char email[30];
char address[30];
};
void addressbook(){
printf("\n--- Contact Management System ---\n");
printf("1. Add Contact\n");
printf("2. View all Contacts\n");
printf("3. View a specific contact\n");
printf("4. Delete Contact\n");
printf("5.change a contact\n");
printf("6. delete all contacts \n");
printf("7. Search a contact\n");
printf("8. Exit ");
}
void addContact() {
FILE *file = fopen("C:\\files\\contacts.txt", "a");
if (file == NULL)
{
perror("Error opening file");
return;
}
struct Person newPerson;
printf("Enter name: ");
scanf("%s", &newPerson.name);
printf("Enter phone number: ");
scanf("%s",&newPerson.phone);

printf("Enter email: ");
scanf("%s", &newPerson.email);
printf("Enter address: ");
scanf("%s", &newPerson.address);
fprintf(file, "%s %s %s %s ", newPerson.name, newPerson.phone, newPerson.email,newPerson.address);
fclose(file);
printf("Contact added successfully.\n");
}
void viewContacts() {
FILE *file = fopen("C:\\files\\contacts.txt", "r");
if (file == NULL) {
perror("Error opening file");
return;
}

struct Person currentPerson;
printf("Contacts:\n");
while (fscanf(file, "%s %s %s %s", &currentPerson.name, &currentPerson.phone, &currentPerson.email,&currentPerson.address) != EOF) {
printf(" \n%s\n%s\n%s\n%s\n", currentPerson.name, currentPerson.phone, currentPerson.email,currentPerson.address);
}
fclose(file);
}
void deleteContact() {
char name[30];
printf("Enter name to delete: ");
scanf("%s", &name);
FILE *file = fopen("C:\\files\\contacts.txt", "r");
FILE *tempFile = fopen("C:\\files\\temp.txt", "w");
struct Person currentPerson;
int found = 0;
while (fscanf(file, "%s %s %s %s", &currentPerson.name, &currentPerson.phone, &currentPerson.email, &currentPerson.address) != EOF)
{
if (strcmp(currentPerson.name, name) != 0)

{
fprintf(tempFile, "%s %s %s %s\n", currentPerson.name, currentPerson.phone, currentPerson.email,currentPerson.address);
}
else {
found = 1;
}
}
fclose(file);
fclose(tempFile);
remove("C:\\files\\contacts.txt");
rename("C:\\files\\temp.txt", "C:\\files\\contacts.txt");
if (found)
{
printf("Contact '%s' deleted successfully.\n", name);
}
else {
printf("Contact '%s' not found.\n", name);
}
}
void deleteall() {
FILE *file = fopen("C:\\files\\contacts.txt", "r");
FILE *fprt = fopen("C:\\files\\temp.txt", "w");
fclose(file);
fclose(fprt);
remove("C:\\files\\contacts.txt");
rename("C:\\files\\temp.txt", "C:\\files\\contacts.txt");
printf("Contacts deleted successfully.\n");
}
void view(){
FILE *f = fopen("C:\\files\\contacts.txt", "r");
if (f == NULL)
{
perror("Error opening file");
return;

}
char nameToFind[30];
printf("Enter name to find: ");
scanf("%s", &nameToFind);
struct Person contact;
int found = 0;
while (fscanf(f, "%s %s ", &contact.name, &contact.phone)==2) {
if (strcmp(contact.name, nameToFind) == 0)
{
printf("Name: %s\nPhone: %s\n ", contact.name, contact.phone);
found = 1; }
}
if (found!=1)
{ printf("Contact not found\n");
}
fclose(f);
}
void editContact(){
struct Person contact;
FILE *f=fopen("C:\\files\\contacts.txt","r");
FILE *fprt=fopen("C:\\files\\tempFile.txt","w");
char name[30];
int found=0;
printf("enter the name to edit\n");
scanf("%s",&name);
while(fscanf(f, "%s %s %s %s",&contact.name,&contact.phone,&contact.email,&contact.address) == 4){
if(strcmp(contact.name,name)==0)
{
printf("enter new contact\n");
scanf("%s",&contact.name);
printf("enter new phone\n");
scanf("%s",&contact.phone);
printf("enter new email\n");
scanf("%s",&contact.email);
printf("enter new address\n");

scanf("%s",&contact.address);
found=1;
}
fprintf(fprt," %s %s %s %s ",contact.name,contact.email,contact.phone,contact.address);
}
fclose(f);
fclose(fprt);
remove("C:\\files\\contacts.txt");
rename("C:\\files\\tempFile.txt", "C:\\files\\contacts.txt");
}
void search(){
FILE*f=fopen("C:\\files\\contacts.txt","r");
struct Person contact;
char name[30];
printf("enter name to search");
scanf("%s",name);
while(fscanf(f, "%s %s %s %s",&contact.name,&contact.phone,&contact.email,&contact.address)==4){
if(strcmp(contact.name,name)==0
{ printf("%s %s %s %s",contact.name,contact.phone,contact.email,contact.address);
}
}
}
int main() {
int choice;
char name[30];
do {
addressbook();
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1: addContact();
break;
case 2: viewContacts();
break;
case 3: view();

break;
case 4: deleteContact();
break;
case 5: editContact();
break;
case 6: deleteall();
break;
case 7: search();
break;
case 8: printf("Exiting program. Goodbye!\n");
break;
default:
printf("Invalid choice. Please enter a valid option.\n");
}
} while (choice != 8);
return 0; }