#include<stdio.h>
#include<time.h>
#include <stdbool.h>
#include <stdlib.h>


FILE *file;
const int length = 2000;

/*===============================================*/

void option_search(){
    char c;
    int lines = 0;
      file = fopen("D:\\C\\accounts.txt","r");    
    do{

        c =fgetc(file);
        if(c =='\n'){lines++;}

    }while (c != EOF);
 fclose(file);
 printf("%d", lines);
}

/*===============================================*/
void option_add(){ 
 
 char fullname[100];
 int due_date = 0;
 double balance = 0;
 
 printf("Name, Surname: ");
 scanf("%s",&fullname);
 printf("Due date (format = XXXXXX): ");
 scanf("%d",&due_date);
 printf("Balance: ");
 scanf("%f",&balance);
 
 file = fopen("D:\\C\\accounts.txt","a");
 fprintf(file,"%s,%d,%f \n", fullname, due_date, balance);
 fclose(file);
}

/*===============================================*/
int homepage(){
    char title[] = "\n\n\t\tBilling System";
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
 
 bool exitcode = false;

 do{ 
 switch (homepage()){
    case 1:
    option_add();
    break;
    
    case 2:
    option_search();
    break;
    
    case 3:
    break;
    
    case 4:
    exitcode = true;
    break;
    default:
    printf("Non existing option ");
 }
 }while (!exitcode);

 return 0;
}
/*===============================================*/
