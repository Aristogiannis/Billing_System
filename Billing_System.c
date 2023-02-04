#include <ctype.h>
#include<stdio.h>
#include<time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 90

FILE *file;
/*================================================*/
void delete(){

}
/*================================================*/
int numberOflines(){
    char c;
    int lines = 0;
      file = fopen("D:\\C\\accounts.txt","r");    
    do{

        c =fgetc(file);
        if(c =='\n'){lines++;}

    }while (c != EOF);
    fclose(file);
    return lines;
}



/*===============================================*/

int option_search(){
    char type[9 ];
    char sname[100];
    int id;
    int store;
    char line[MAX_LINE_LENGTH] = {0};
    unsigned int line_num = 0;
    bool not_found = false;
    char *pos;
    file = fopen("D:\\C\\accounts.txt","r");  

    printf("name / id: ");
    scanf("%s", &type);
    
    if(strcmp(type,"name") == 0){ //Start of search by name
        printf("type name: ");
        scanf("%s", &sname);
        
        while(fgets(line, MAX_LINE_LENGTH, file)){
            pos = strstr(line, sname);
            if (pos != NULL){
                printf("%s", line);
                break;
            }
            line_num++;
        }

        fclose(file);

    } // End of Name search

    else if(strcmp(type, "id") == 0){ //Start search by id
        printf("type id: ");
        scanf("%d", &id);

        while (fgets(line, MAX_LINE_LENGTH, file))
    {
        if (id == 0){
            printf("%s", line);
            break;
        }
        else if (id == line_num){
            printf("%s", line);
            break;
        }
        line_num++;
        
        /* Adds a trailing newline to lines that don't already have one */
        if (line[strlen(line) - 1] != '\n')
            printf("\n");
    }
    if (fclose(file)){return EXIT_FAILURE;}
}//End search by id

    return store;
}

/*===============================================*/
void option_add(){ 
 char fullname[100];
 int due_date;
 float balance;
 int num = numberOflines();

 printf("Name, Surname (format = Name-Surname): ");
 scanf("%s",&fullname);
 printf("Due date (format = XXXXXX): ");
 scanf("%d",&due_date);
 printf("Balance: ");
 scanf("%f",&balance);
 
 file = fopen("D:\\C\\accounts.txt","a");
 fprintf(file,"id: %d, Full Name: %s, Due Date: %d, Balance: %f\n",num, fullname, due_date, balance);
 fclose(file);
}

/*===============================================*/
int homepage(){
    char title[] = "\n\nBilling System";
    int answer;
    time_t t;  
    time(&t);

    printf("%s %s %s \n\n", title,"\t\t\t",ctime(&t));
    printf("1: Add account\n2: Clear Screan\n3: Search account\n4: Exit\n");
    printf("  (Type from 1 to 4)\n");
    scanf("%d",&answer);
    return answer;
}

/*===============================================*/

int main(){
 //int a[numberOflines()];
 bool exitcode = false;
 
 do{ 
 switch (homepage()){

    case 1:
    option_add();
    system("cls");
    break;

    case 2:
    system("cls");
    break;
    
    case 3:
    option_search();
    //system("cls");
    break;
    
    case 4:
    exitcode = true;
    break;
    default:
    system("cls");
    printf("ERROR: Non existing option");

 }
 }while (!exitcode);

 return 0;
}
/*===============================================*/
