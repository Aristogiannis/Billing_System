#include <ctype.h>
#include<stdio.h>
#include<time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


FILE *file;


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

void option_search(){
    char type[12];
    char sname[100];
    int id;
    int count = 0;
    bool found = false;

    printf("name / id: ");
    scanf("%s", &type);
    if(strcmp(type,"name") == 0){
        printf("type name: ");
        scanf("%s", &sname);
    }
    else if(strcmp(type, "id") == 0){
        printf("type id: ");
        scanf("%d", &id);
    }

     char c;
     char store;
     file = fopen("D:\\C\\accounts.txt","r");    
     
     do{
        c = fgetc(file);
        if( isdigit(c) ){
            store = c;
        }
        if(c == sname[count]){
            count++;
        }
        else{count = 0;}

        if (count == strlen(sname)){
        found = true;}
    }while (!found || c == EOF);
    fclose(file);
    file = fopen("D:\\C\\accounts.txt","r");   
    
    found = false;
    
    while(!found){
     c = getc(file);
     if (c == store){
        do{
        printf("%c", c);
        c = getc(file);
        }while(c != '\n');
        found = true;
     }
    }
    fclose(file);
}

/*===============================================*/
void option_add(){ 
 char fullname[100];
 int due_date;
 float balance;
 int num = numberOflines();

 printf("Name, Surname: ");
 scanf("%s",&fullname);
 printf("Due date (format = XXXXXX): ");
 scanf("%d",&due_date);
 printf("Balance: ");
 scanf("%f",&balance);
 
 file = fopen("D:\\C\\accounts.txt","a");
 fprintf(file,"%d,%s,%d,%f\n",num, fullname, due_date, balance);
 fclose(file);
}

/*===============================================*/
int homepage(){
    char title[] = "\n\nBilling System";
    int answer;
    time_t t;  
    time(&t);

    printf("%s %s %s \n\n", title,"\t\t\t",ctime(&t));
    printf("1: Add account\n2: Delete account\n3: Search account\n4: Exit\n");
    printf("  (Type from 1 to 4)\n");
    scanf("%d",&answer);
    return answer;
}

/*===============================================*/

int main(){
 int a[numberOflines()];
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
