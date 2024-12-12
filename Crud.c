#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int id;
    char name[50];
    int age;
    char gender;
} User;

void create()
{
    FILE *file = fopen("user.txt","a");
    if(file==NULL)
    {
        printf("We are currently not able to create the file.\n");
        return;
    }
    User user;
    printf("Enter the details of the user!\n");
    printf("id of the user.\n");
    scanf("%d",&user.id);
    getchar();
    printf("Name of the user?");
    fgets(user.name,sizeof(user.name),stdin);
    user.name[strcspn(user.name, "\n")] = 0; 
    printf("Enter the age ");
    scanf("%d", &user.age);
    getchar();
    printf("Enter the gender: ");
    scanf(" %c", &user.gender);
    getchar();
    fprintf(file, "%d %s %d %c\n", user.id, user.name, user.age,user.gender);
    fclose(file);
    printf("user has been succesfully added to the file\n");
}
void read()
{
    FILE *file=fopen("user.txt","r");
    if(file==NULL)
    {
        printf("We are currently unable to read the file");
        return;
    }
    User user;
    printf("Details of the user are as follows.\n");
    while(fscanf(file,"%d %s %d %c",&user.id,user.name,&user.age,&user.gender)!=EOF)
    {
        printf("ID: %d, Name: %s, Age: %d , Gender: %c\n", user.id, user.name, user.age,user.gender);
    }
    fclose(file);
}
    void update()
    {
        FILE *file =fopen("user.txt","r");
        FILE *temp =fopen("temp.txt","w");
        if(file==NULL || temp==NULL)
        {
            printf("Due to some error the file can not be updated rtn.");
            return;
        }
        int target, update=0;
        User user;
        printf("Enter the user id to be updated");
        scanf("%d",&target);
        getchar();
        
        while(fscanf(file,"%d %s %d %c",&user.id, user.name,&user.age,&user.gender)!=EOF)
        {
            if(user.id==target)
            {
                printf("Enter the updated name");
                fgets(user.name,sizeof(user.name),stdin);
                user.name[strcspn(user.name, "\n")] = 0;
                printf("Enter the updated age");
                scanf("%d",&user.age);
                getchar();
                printf("Enter the updated gender");
                scanf(" %c",&user.gender);
                getchar();
                update=1;
            }
            fprintf(temp,"%d %s %d %c\n",user.id,user.name,user.age,user.gender);
        }
        fclose(file);
        fclose(temp);
        remove("user.txt");
        rename("temp.txt","user.txt");
        if (update)
        printf("File has been succesfully updated");
        else
        printf("No user found\n",target);
}
void delete()
{
    FILE *file=fopen("user.txt","r");
    FILE *temp=fopen("temp.txt","w");
    if(file==NULL || temp==NULL)
    {
        printf("User can not be deleted rtn");
        return;
    }
    int target,deleted=0;
    User user;
    printf("Enter the id to be deleted \n");
    scanf("%d", &target);
    while(fscanf(file,"%d %s %d %c",&user.id,user.name,&user.name,&user.gender)!=EOF)
    {
        if (user.id != target) {
            fprintf(temp, "%d %s %d %c\n", user.id, user.name, user.age,user.gender);
        } else {
            deleted = 1;
        }
    }
    fclose(file);
    fclose(temp);

    remove("user.txt");
    rename("temp.txt", "user.txt");
    if(deleted)
    {
        printf("User succesfully deleted!\n");
    }
    else{
        printf("no user found with user id:  %d.\n",target);
    }
}
int main() {
    while(1){
    int input;
    printf("\nWELCOME TO CRUD MANAGER\n");
    printf( "SELECT THE CRUD OPERATION YOU WANT TO PERFORM\n"
            "1. Add User (Create)\n"
            "2. Display Users (Read)\n"
            "3. Update User (Update)\n"
            "4. Delete User (Delete)\n"
            "5. Exit\n");
            
    scanf("%d", &input);

    switch (input) {
            case 1:
                create();
                break;
            case 2:
                read();
                break;
            case 3:
                update();
                break;
            case 4:
                delete();
                break;
            case 5:
                printf("Thanks for using crud manager \n");
                exit(0);
            default:
                printf("Invalid input try again\n");
        }
    }
    
    return 0;
}