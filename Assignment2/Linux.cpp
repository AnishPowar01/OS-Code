#include <stdio.h>
#include <dirent.h>


int main(void) {
    
    struct dirent *dEntry;
    DIR *dr = opendir(".");
    
    if(dr==NULL){
        printf("Directory is Empty");
        return 0;
    }
    
    while((dEntry=readdir(dr))!= NULL){
        printf("%s \n",dEntry -> d_name);
    }
    
    closedir(dr);
    return 0;
}