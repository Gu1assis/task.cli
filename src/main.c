#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  
  if(argc==1 || strcmp(argv[1],"--help")==0){
    printf("Welcome to task!\n");
    return 0;
  }

  if(strcmp(argv[1], "add")==0){
    printf("Input data to add new task!\n");
    return 0;
  }

  if(strcmp(argv[1], "ls")==0){
    printf("Here is your data!\n");
    return 0;
  }

  if(strcmp(argv[1], "complete")==0){
    printf("Input data to add complete task!\n");
    return 0;
  }

  if(strcmp(argv[1], "cancel")==0){
    printf("Input data to cancel task!\n");
    return 0;
  }

  if(strcmp(argv[1], "sync")==0){
    printf("Syncing data...\n");
    return 0;
  }

  printf("Command not found! Try using task --help");
  return 0;
}
