#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//GLOBAL DEFINITION SECTION

void mainMenu();
int authentication();

// functions to manage projects
void projectMenu();
void addNewProject();
void saveProjectInfo();
void viewAllProjects();
void updateProjectInfo();
void deleteProjectInfo();

// functions to manage expenses
void expenseMenu();
void addNewExpense();
void saveExpenseInfo();
void viewAllExpenses();
void updateExpenseInfo();
void deleteExpenseInfo();

// functions to manage feeding history

// functions to manage employee

// functions to manage sells

// functions to generate reports

// functions for price estimation


//Project structure
struct Project{
    int id; 
    float estimatedBudget;
    char projectName[50], projectShortDes[100], projectType[30], startDate[15], endDate[15];
};

//Expense structure
struct Expense{
    int projectId;
    float amount;
    char date[30], productOrService[20], supplierInfo[25];
};

//FeedingHistory structure
struct FeedingHistory{
    int projectId;
    float quantity;
    char date[10], time[10], foodCategory[10];
};

//Employee structure
struct Employee{
    int id, phone_number;
    float salary;
    char name[50], address[50], email[25];
};

//SellingInfo structure
struct SellingInfo{
    int projectId;
    float amount;
    char projectName[20], date[10];
};


// declaring file pointer for the file read write operation
FILE *fileToOperate;
// declaring a variable to hold data of our custom data structure
struct Project projectInfo;
struct Expense expenseInfo;

//main function of the program
int main(){
    system("cls");
    int choice;
    printf("\n***Mazumdar's Agro & Frisharies***\n\n");
    printf("Please Login First!!!\n   1. Enter Password\n   2. Exit\nPlease enter your choice (1/2) : ");
    login: scanf("%d", &choice);
    if(choice==1){
        //calling the login function to check whether password is correct or not
        reauthenticate: if(authentication()==0){
            mainMenu();
        }else {
            printf("Your password is incorrect. Please Try again.\n");
            goto reauthenticate; // taking reinput for the valid password
        }
    }else if(choice==2){
        exit(0);
    }else{
        printf("\nInvalid Choice. You should enter \"1\" for Login or \"2\" for Exit.\n\nPlease enter your choice again (1/2) : ");
        goto login;
    }
    return 0;

}

// main menu of the project
void mainMenu(){
    system("cls");
    printf("\n\n***** Mazumdar's Agro & Frisharies Admin Panel. *****\n\n1. Manage Projects.\n");
    printf("2. Manage Expenses.\n3. Manage Feeding History.\n4. Manage Employee\n");
    printf("5. Manage Sells.\n6. Generate Report\n7. Price Estimation\n8. Exit\n");
    printf("\nChose the option what you want to do (1/2/3/4/5/6/7/8) : ");

    int userChoice;
    backToMainMenu: scanf("%d", &userChoice);
    
    if (userChoice==1){
        projectMenu();
    }else if(userChoice==2){
        expenseMenu();
    }else if(userChoice==3){

    }else if(userChoice==4){

    }else if(userChoice==5){

    }else if(userChoice==6){

    }else if(userChoice==7){

    }else if(userChoice==8){

    }else{
        printf("\nInvalid input. Please enter a valid input : ");
        goto backToMainMenu;
    }

}

// necessary codes for password protected login
int authentication(){
    char fixPassword[15]="12345";
    char userPassword[15];
    printf("\nEnter Password :");
    fflush(stdin);
    gets(userPassword);
    return strcmp(userPassword,fixPassword);
}

// Functions of project management starts here
// project sub menu
void projectMenu(){
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n");
    printf("A. Create New Project Info\n");
    printf("B. View all project info\n");
    printf("C. Update existing project info\n");
    printf("D. Delete a project info\n");
    printf("E. Back to Main Menu\n");
    
    returnToProjectMenu: printf("Choose the Option(A/B/C/D/E):");

    //Choose User Input
    fflush(stdin);
    char menuChoice;
    scanf("%c", &menuChoice);
    menuChoice = toupper(menuChoice);
    
    switch (menuChoice)
    {
    case 'A':
        addNewProject();
        break;
    case 'B':
        viewAllProjects();
        break;
    case 'C':
        updateProjectInfo();
        break;
    case 'D':
        deleteProjectInfo();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        mainMenu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto returnToProjectMenu;
    }
}

void addNewProject(){
    system("cls");
    //struct Project pr;
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n");

    printf("\nProvide all necessary information about the project\n\n");
    printf("Please Enter Project Type (Fish/Poultry): ");
    fflush(stdin);
    gets(projectInfo.projectType);
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &projectInfo.id);
    printf("Please Enter Project Name/Title: ");
    fflush(stdin);
    gets(projectInfo.projectName);
    printf("Please Provide Short Details About Projcet: ");
    fflush(stdin);
    gets(projectInfo.projectShortDes);
    printf("Please Enter Project Start Date: ");
    fflush(stdin);
    gets(projectInfo.startDate);
    printf("Please Enter Project End Date: ");
    fflush(stdin);
    gets(projectInfo.endDate);
    printf("Please Enter the Estimated Budget: ");
    fflush(stdin);
    scanf("%f", &projectInfo.estimatedBudget);

    saveProjectInfo();

    add_record: printf("\n\t\t\t1.Do You Want To Add Another new Project info?\n\t\t\t2.Project Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        addNewProject();
    }else if (choice==2){
        projectMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record;
    }
}

void saveProjectInfo()
{
    fileToOperate = fopen("projectData.txt", "a");
    fwrite(&projectInfo, sizeof(struct Project), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

// codes to show the stored projects info from file
void viewAllProjects()
{
    system("cls");
    fileToOperate = fopen("projectData.txt", "r");
    printf("\n*#$All Project Information$#*\n");
    printf(" **Project ID** \t**Project Title** \t**Start Date** \t**End Date**");
    while (fread(&projectInfo, sizeof(struct Project), 1, fileToOperate))
    {
        printf("\n%d\t\t%s\t\t%s\t\t%s\n",projectInfo.id,projectInfo.projectName, projectInfo.startDate,projectInfo.endDate);
    }
    fclose(fileToOperate);

    add_record1: printf("\n\t\t\t1.Project Menu\n\t\t\t2.Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");
    
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        projectMenu();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        exit(0);
    }
    else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record1;
    }
}

//codes to update the information of a specific project in a file
void updateProjectInfo(){
    system("cls");
    printf("\nA.Update Project Information Information\n");

    printf("Please enter project id you want to modify: ");
    int pId;
    fflush(stdin);
    scanf("%d", &pId);
    fileToOperate = fopen("projectData.txt", "r+");
    int found = 0;
    while (fread(&projectInfo, sizeof(struct Project), 1, fileToOperate))
    {
        if (projectInfo.id == pId)
        {
            found = 1;
            printf("\nProvide all necessary information about the project\n\n");
            printf("Please Enter Project Type (Fish/Poultry): ");
            fflush(stdin);
            gets(projectInfo.projectType);
            printf("Please Enter Project ID: ");
            fflush(stdin);
            scanf("%d", &projectInfo.id);
            printf("Please Enter Project Name/Title: ");
            fflush(stdin);
            gets(projectInfo.projectName);
            printf("Please Provide Short Details About Project: ");
            fflush(stdin);
            gets(projectInfo.projectShortDes);
            printf("Please Enter Project Start Date: ");
            fflush(stdin);
            gets(projectInfo.startDate);
            printf("Please Enter Project End Date: ");
            fflush(stdin);
            gets(projectInfo.endDate);
            printf("Please Enter the Estimated Budget: ");
            fflush(stdin);
            scanf("%f", &projectInfo.estimatedBudget);
            fseek(fileToOperate, -sizeof(projectInfo), SEEK_CUR);
            fwrite(&projectInfo, sizeof(struct Project), 1, fileToOperate);
            break;
        }
    }
    
    fclose(fileToOperate);
    if (found == 1)
    {
        printf("\nProject information updated\n");
    }
    else
    {
        printf("\nProject with the given IID  not found in file\n");
    }

    
    updateProject: printf("\n\t\t\t1.Do You Want To Modify Another  Project info?\n\t\t\t2.Project Menu\n\t\t\t3.Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        updateProjectInfo();
    }else if (choice==2){
        projectMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto updateProject;
    }
}

// deleting a project info from the file
void deleteProjectInfo(){

    FILE  *removeFile;
    int pId;
    printf("Enter The project id :");
    fflush(stdin);
    scanf("%d", &pId);

    fileToOperate = fopen("projectData.txt", "r+");

    removeFile = fopen("temp.txt", "a+");
    if (fileToOperate == NULL)
    {
        fprintf(stderr, "can't open the file");
        exit(0);
    }

    while (fread(&projectInfo, sizeof(struct Project), 1, fileToOperate))
    {
        if (projectInfo.id != pId)
        {
            fwrite(&projectInfo, sizeof(struct Project), 1, removeFile);
        }
    }

    fclose(fileToOperate);
    fclose(removeFile);

    remove("projectData.txt");
    rename("temp.txt", "projectData.txt");

    printf("\nProject Info  Successfully Deleted\n");

    deleteRecord: printf("\n\t\t\t1.Do You Want To delete Another  Project info?\n\t\t\t2.Project Menu\n\t\t\t3.Main Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    
    int choice;
    scanf("%d",&choice);
    
    if(choice==1){
        deleteProjectInfo();
    }else if (choice==2){
        projectMenu();
    }else if(choice==3){
        mainMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto deleteRecord;
    }

}
// Functions of project management end here

// Functions of expense management starts here

void expenseMenu(){
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n");
    printf("A. Add an Expense\n");
    printf("B. View all Expenses\n");
    printf("C. Update existing expense info\n");
    printf("D. Delete a expense\n");
    printf("E. Back to Main Menu\n");
    
    returnToExpenseMenu: printf("Choose the Option(A/B/C/D/E):");

    //Choose User Input
    fflush(stdin);
    char menuChoice;
    scanf("%c", &menuChoice);
    menuChoice = toupper(menuChoice);
    
    switch (menuChoice)
    {
    case 'A':
        addNewExpense();
        break;
    case 'B':
        viewAllExpenses();
        break;
    case 'C':
        updateProjectInfo();
        break;
    case 'D':
        deleteProjectInfo();
        break;
    case 'E':
        printf("\nBack Successfully\n");
        mainMenu();
        break;
    default:
        printf("\nInvalid Input!\nTry again!!\n");
        goto returnToExpenseMenu;
    }
}

void addNewExpense(){
    system("cls");
    printf("\n\n\n*****Mazumdar's Agro & Frisharies Admin Panel.*****\n");

    printf("\nProvide all necessary information about the project\n\n");
    printf("Please Enter Project ID: ");
    fflush(stdin);
    scanf("%d", &expenseInfo.projectId);
    printf("Please Enter Product/Service Type: ");
    fflush(stdin);
    gets(expenseInfo.productOrService);
    printf("Please Enter Supplier Info: ");
    fflush(stdin);
    gets(expenseInfo.supplierInfo);
    printf("Please Enter Date: ");
    fflush(stdin);
    gets(expenseInfo.date);
    printf("Please Enter the Amount: ");
    fflush(stdin);
    scanf("%f", &expenseInfo.amount);

    saveExpenseInfo();

    add_record: printf("\n\t\t\t1.Do You Want To Add Another new Project info?\n\t\t\t2.Project Menu");
    printf("\n\t\t\tEnter Your Choose: ");
    int choice;
    fflush(stdin);
    scanf("%d",&choice);
    if(choice==1){
        addNewExpense();
    }else if (choice==2){
        expenseMenu();
    }else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record;
    }
}

void saveExpenseInfo()
{
    fileToOperate = fopen("expenseData.txt", "a");
    fwrite(&expenseInfo, sizeof(struct Expense), 1, fileToOperate);
    if (fwrite != 0)
    {
        printf("\nSuccessfully Saved\n");
    }
    else
    {
        printf("\nSomething went wrong\n");
    }
    fclose(fileToOperate);
}

void viewAllExpenses()
{
    system("cls");
    fileToOperate = fopen("expenseData.txt", "r");
    printf("\n*#$All Project Information$#*\n");
    printf(" **Project ID** \t**Project Title** \t**Start Date** \t**End Date**");
    while (fread(&expenseInfo, sizeof(struct Expense), 1, fileToOperate))
    {
        printf("\n%d\t\t%s\t\t%f\t\t%s\n",expenseInfo.projectId,expenseInfo.productOrService, expenseInfo.amount,expenseInfo.date);
    }
    fclose(fileToOperate);

    add_record2: printf("\n\t\t\t1.Expense Menu\n\t\t\t2.Main Menu\n\t\t\t3. Exit");
    printf("\n\t\t\tEnter Your Choose: ");
    
    int choice;
    scanf("%d",&choice);
    if(choice==1){
        expenseMenu();
    }else if (choice==2){
        mainMenu();
    }else if(choice==3){
        exit(0);
    }
    else{
        printf("\n\t\t\tInvalid Input! Please enter a valid choice");
        goto add_record2;
    }
}