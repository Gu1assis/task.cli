#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>
#include <time.h>

#define MAX_NAME_SZ 50
#define MAX_DESC_SZ 100

struct task {
  uuid_t id;
  char status[1];
  char name[1];
  char desc[1];
  char ts_created[1]; 
};

void replaceNewLineCharWithNull(char *s){
  if(strlen(s)>0 && s[strlen(s)-1] == '\n'){
    s[strlen(s)-1] = '\0';
  }
}

int addTask() {
  char *name = malloc(MAX_NAME_SZ);
  char *desc = malloc(MAX_DESC_SZ);

  if(name==NULL || desc==NULL){
    printf("Out of Memory!");
    return 1;
  }

  printf("Lets add a new Task!\n\nPlease type a Name to your task:\n");
  fgets(name, MAX_NAME_SZ, stdin);
  replaceNewLineCharWithNull(name);

  printf("Please type a Description to your task:\n");
  fgets(desc, MAX_DESC_SZ, stdin);
  replaceNewLineCharWithNull(desc);

  time_t t = time(NULL);
  struct tm date = *localtime(&t);

  printf("\nTask Created with\n\nName: %s\nDescription: %s\n", name, desc);
  printf("Creation date: %d-%02d-%02d at %02dh%02dm%02ds\n\n", date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, date.tm_hour, date.tm_min, date.tm_sec);
  free(name);
  free(desc);
}

int main(int argc, char *argv[]) {
  
  if(argc==1 || strcmp(argv[1],"--help")==0){
    printf("Welcome to task! A simple task manager\n");
    printf("Usage: \n\n  task ls -> list all tasks\n  task add -> add task to database\n\n");
    return 0;
  }

  if(strcmp(argv[1], "add")==0){
    if (addTask()==1) return 1;
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
