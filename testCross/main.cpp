#include <cstdlib>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "area.h"

using namespace std;


void *NextFunction(void *areaStruct)
{
    //Casting the parameter to struct area
    area *ptrArea = (area*)areaStruct;
    int totalArea;
    
    while(1)
    {
        ptrArea->height= ptrArea->height+1;
        ptrArea->width = ptrArea->width+1;        
        totalArea = ptrArea->height*(ptrArea->width);        
        printf("---------------------Total Area of the square is: ");
        printf("%d",totalArea);
        printf("\n");        
        sleep (2);
    }
}

void *function (void * Name)
{
    int *i=(int*)Name;        
    while(1)
    {
        *i=*i+1;        
        if(*i == 850)
        {
            *i=0;
        }
        sleep(1);        
        printf("Value of i: ");        
        printf("%d",*i);
        printf(" \n ");
        printf("Address of i: ");        
        printf("%p",i);
        printf(" \n ");        
    }    
}

int main(int argc, char** argv) { 
    
    printf("Hello world from cross compiling\n");
    
    int counter = 1;
    area vAr={.height=45,.width=23};    
    pthread_t phNumChanger;
    pthread_t phAreaCalculator;    
    
    pthread_create (&phNumChanger,NULL,&function,&counter);
    pthread_create (&phAreaCalculator, NULL, &NextFunction,&vAr);
        
    
    while(1)
    {        
        scanf("%d",&counter);
        vAr.height = counter;        
        vAr.width = counter; 
        printf("\n New Value");
        printf("%d",counter);
        printf("\n");
        sleep(1);
    }
    return 0;
}

