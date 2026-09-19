#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

/** 
CPU uses 4 byte words, so its preferrable that the struct has a size multiple of 4. 
*/
typedef struct {
  uint32_t id;
  uint8_t status; // 0: CREATED, 1: IN_PROGRESS, 2: COMPLETED, 3: CANCELED
  uint64_t timestamp;
  uint16_t title_len;
  uint16_t desc_len;
  uint8_t padding; //Making sure compiler does not add variable padding to optime cpu usage
} __attribute__((packed)) TaskHeader;

int append(const char *title, const char *desc, time_t epoch){
  uint16_t title_len = (uint16_t)strlen(title);
  uint16_t desc_len = (uint16_t)strlen(desc);
  printf("Title len: %d, desc len: %d in epoch: %ld\n", title_len, desc_len, epoch);
  
  // Definir buffer de dados
  // COmo fazer o id ser atualizado sem ter q ler o db?
  TaskHeader th = {5, 0, epoch, title_len, desc_len, 1};
  // Abrir arquivo do db
  FILE *fp = fopen("../data/db", "ab");
  if(!fp){
    printf("Error while Opening database.\n");
    return 1;
  }
  // gravar o header e gravar o title e desc em seguida
  size_t n = fwrite(&th,sizeof(TaskHeader),1,fp);
  printf("Structs written: %ld with %ld bytes\n", n, sizeof(TaskHeader));
  size_t n1 = fwrite(title,title_len,1,fp);
  printf("Title written: %ld with %u bytes\n", n1, title_len);
  size_t n2 = fwrite(desc,desc_len,1,fp);
  printf("Desc written: %ld with %u bytes\n", n2, desc_len);
  // fechar o arquivo e retornar sucesso
  fclose(fp);
  return 0;
}

int read(uint32_t id){
  FILE *fp = fopen("../data/db", "r");
  if(!fp){
    printf("Error while Opening database.\n");
    return 1;
  }
  TaskHeader th;
  size_t structs_read = fread(&th, sizeof(TaskHeader), 1, fp);

  printf("Struct found: %d, read %ld structs\n", th.id, structs_read);
  return 0;
}

int main() {

  const char *t = "Title eba";
  const char *desc = "desc man";
  time_t epoch = time(NULL);
  uint32_t id = 1;

  append(t, desc, epoch);
  read(id);
  return 0;
}
