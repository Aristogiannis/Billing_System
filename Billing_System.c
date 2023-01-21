#include<stdio.h>
#include<time.h>
#include <stdbool.h>
#include <stdlib.h>


void option_add(){
 FILE *file;
 file = fopen("D:\\C\\accounts.txt","a");
 fprintf(file,"YO\n");
 fclose(file);

}

void homepage(){
    char title[] = "\n\n\t\tBilling System";
    
    
    time_t t;  
    time(&t);

    
    printf("%s %s %s \n\n", title,"\t\t\t",ctime(&t));
    printf("1: Add account\n2: Delete account\n3: Search account\n4: Exit\n");
    printf("  (Type from 1 to 4)\n");
}


int main(){
 bool exitcode;
 exitcode = false;
 int answer;
 char stop; 
 char no[] ="nN";

 do{
 homepage();
 scanf("%d",&answer);
 
 switch (answer){
    case 1:
    option_add();
    break;
    
    case 2:
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

