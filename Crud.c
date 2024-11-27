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
        printf("WE ARE CURRENTLY NOT ABLE TO CREATE THE FILE\n");
        return;
    }
    User user;
    printf("ENTER THE DETAILS OF THE USER!\n");
    printf("ENTER THE ID OF THE USER.\n");
    scanf("%d",&user.id);
    getchar();
    printf("ENTER THE NAME OF THE USER!");
    fgets(user.name,sizeof(user.name),stdin);
    user.name[strcspn(user.name, "\n")] = 0; 
    printf("ENTER AGE: ");
    scanf("%d", &user.age);
    getchar();
    printf("ENTER GENDER OF USER : ");
    scanf(" %c", &user.gender);
    getchar();
    fprintf(file, "%d %s %d %c\n", user.id, user.name, user.age,user.gender);
    fclose(file);
    printf("USER HAS BEEN  SUCCESSFULLY ADDED TO THE FILE.\n");
}
void read()
{
    FILE *file=fopen("user.txt","r");
    if(file==NULL)
    {
        printf("WE ARE CURRENTLY UNABLE TO READ THE FILE DUE TO SOME ERROR\n");
        return;
    }
    User user;
    printf("DETAILS OF THE USER ARE AS FOLLOWS!\n");
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
            printf("DUE TO ERROR THE FILE CAN NOT BE UPDATED!");
            return;
        }
        int target, update=0;
        User user;
        printf("ENTER THE USER ID TO BE UPDATE");
        scanf("%d",&target);
        getchar();
        
        while(fscanf(file,"%d %s %d %c",&user.id, user.name,&user.age,&user.gender)!=EOF)
        {
            if(user.id==target)
            {
                printf("ENTER THE UPDATED NAME");
                fgets(user.name,sizeof(user.name),stdin);
                user.name[strcspn(user.name, "\n")] = 0;
                printf("ENTER THE UPDATED AGE");
                scanf("%d",&user.age);
                getchar();
                printf("ENTER THE UPDATED GENDER");
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
        printf("FAILE HAS BEEN SUCCESSFULL UPDATED.\n");
        else
        printf("NO USER WAS FOUND WITH THE USER Id: %d.\n",target);
}
void delete()
{
    FILE *file=fopen("user.txt","r");
    FILE *temp=fopen("temp.txt","w");
    if(file==NULL || temp==NULL)
    {
        printf("THE DELETE OPERATION CAN NOT BE PERFORMED DUE TO ERROR");
        return;
    }
    int target,deleted=0;
    User user;
    printf("ENTER THE ID TO DELETE: \n");
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
        printf("USER HAS BEEN SUCCESSFULL FROM FILE\n");
    }
    else{
        printf("NO USER WAS FOUND WITH THE USER Id: %d.\n",target);
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
                printf("THANKS FOR USING CRUD MANAGER \n");
                exit(0);
            default:
                printf("INVALID INPUT, TRY AGAIN\n");
        }
    }
    
    return 0;
}