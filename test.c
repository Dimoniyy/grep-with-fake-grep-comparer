#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#define MATCHING_FILES_ONLY 0x1        // -l
#define CASE_INSENSITIVE 0X2           // -i
#define INVERT_MATCH 0x4               // -v
#define OUTPUT_COUNT 0X8               // -c
#define NO_FILENAME_OUTPUT 0x10        // -h
#define PROCEED_LINE_NUM 0x20          // -n
#define SUPPRESS_FILENAME_ERRORS 0x40  // -s
#define ONLY_MATCHING_PARTS_LINE 0x80  // -o
#define COMBINATIONS_MAX_LENGHT 10   
#define BUFFER_MAX_LENGHT 1024 

int combinations(const char* letters, char* temp_res, unsigned long int from, unsigned long int until, unsigned long int iteration, unsigned long int target_lenght, char** out);
int fileCompare(char* file_1_path, char* file_2_path);

int main() {
  char letters[] = "livchnso";
  char buffer[BUFFER_MAX_LENGHT];
  char** out;
  int how_many = 0;
  int res = 0;
    /*for (int i = 0; i < how_many; i++){
      printf("%s\n", out[i]);
      free(out[i]);
    }*/
    
  for (int i = 1; i < 8; i++) {
    out = malloc(sizeof(char) * BUFFER_MAX_LENGHT * BUFFER_MAX_LENGHT);
    how_many = combinations(letters, buffer, 0, 3, 0, 3, out);
    for (int j = 0; j < how_many; j++) {
      snprintf(buffer, BUFFER_MAX_LENGHT, "grep -%s Nya text > $TMPDIR/tempfile_test_grep", out[j]);
      system(buffer);
      snprintf(buffer, BUFFER_MAX_LENGHT, "grep/s21_grep -%s Nya text > $TMPDIR/tempfile_test_s21grep", out[j]);
      system(buffer);
      res += fileCompare("$TMPDIR/tempfile_test_grep", "$TMPDIR/tempfile_test_s21grep");
    }
    for (int i = 0; i < how_many; i++){
      free(out[i]);
    }
    free(out);
  }
  printf("%d\n", res);
  system("rm $TMPDIR/tempfile_test_s21grep");
  
}

int fileCompare(char* file_1_path, char* file_2_path) {
  FILE* file1;
  FILE* file2;
  file1 = fopen(file_1_path, "r");
  file2 = fopen(file_2_path, "r");
  int file_1_out = 0;
  int file_2_out = 0;
  int res = 0;
  if (file1 != NULL && file2 != NULL) {
    do {
      file_1_out = getc(file1);
      file_2_out = getc(file2);
      res += !(file_1_out == file_2_out);
    } while (file_1_out != EOF || file_2_out != EOF);
  }
  fclose(file1);
  fclose(file2);
  return res;
}

int combinations(const char* letters, char* temp_res, unsigned long int from, unsigned long int until, unsigned long int iteration, unsigned long int target_lenght, char** out) {
  static int out_n = 0;
  if (iteration == target_lenght) {
    out[out_n] = strdup(temp_res);
    out_n++;
  }
  for (unsigned long int i = from; i < strlen(letters) && from + target_lenght - iteration <= strlen(letters) && iteration < target_lenght; i++) {
    temp_res[iteration] = letters[i];
    combinations(letters, temp_res, i + 1, until, iteration + 1, target_lenght, out);
  }
  return out_n;
}



/*

struct array_with_positon {
  unsigned int pos;
  unsigned int max;
  void* array;
};

struct matrix_with_positon {
  struct array_with_positon* matrix;
  unsigned int pos;
  unsigned int max;
};

void addNewArrayToMatrixWithPosition(struct matrix_with_positon* dest, struct array_with_positon* array_to_add);
struct array_with_positon* makeArrayWithPosition();
void addToArrayInMatrixWithPostion(struct matrix_with_positon* target, void* ptr_to_thing_to_add);

void addNewArrayToMatrixWithPosition(struct matrix_with_positon* dest, struct array_with_positon* array_to_add) {
  dest->matrix = realloc(dest->matrix, sizeof(dest->matrix) + sizeof(array_to_add));
  dest->max++; 
  (dest->matrix)[dest->max].array = array_with_positon_fresh(array_to_add);
}

void printoutMatrixWithPosition(struct matrix_with_positon* origin) {
  setPosMatrixWithPosition(origin, 0);
  for (int i = 0; i < origin->max; i++) {
    printf("%s", accessMatrixWithPosition(origin));
  }
}

void setPosMatrixWithPosition(struct matrix_with_positon* target, unsigned int position) {
  if (position <= target->max) {
    target->pos = position;
  }
}

struct array_with_positon* makeArrayWithPosition() {
  struct array_with_positon* array_with_positon_fresh = malloc(sizeof(struct array_with_positon));
  array_with_positon_fresh->max = 0;
  array_with_positon_fresh->pos = 0;
  return array_with_positon_fresh;
}

void addToArrayInMatrixWithPostion(struct matrix_with_positon* target, void* ptr_to_thing_to_add) {
  (target->matrix[target->pos].array[target->matrix[target->pos].pos]) = *ptr_to_thing_to_add;
  target->matrix[target->pos].pos++;
}

*/