#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

int
main(int argc, char* argv[]){
 assert(argv[argc] == NULL);
 assert(argc > 0);
 assert(argv[0] != NULL);
 // ERROR CHECK no args
 if(argc == 1){
  fprintf(\
    stderr,\
    "NO ARGUMENT PROVIDED.\n"\
    "Usage: %s DIGITS...\n"\
    "e.g. %s 19 77\n",\
    argv[0], argv[0]
    );
  return -1;
 }
 // ERROR CHECK not enough args
 assert(argv[1] != NULL);
 if(argc == 2){
  int counter = 0;
  while(argv[1][counter] != '\0'){
   if(isdigit( (int) argv[1][counter] )){
    counter++;
    continue;
   }else{
    argv[1] = "19";
    break;
   }
   assert(0);
  }
  fprintf(\
    stderr,\
    "NO ADDITIONAL DIGIT PROVIDED.\n"\
    "Usage: %s DIGITS...\n"\
    "e.g. %s %s 77\n",\
    argv[0], argv[0], argv[1]\
    );
  return -1;
 }
 // ASCII TO DIGIT
 assert(argc >= 3);
 int digits[argc];
 digits[0] = 0;
 for(int x = 1, t = argc; x < t; ++x){
  int y = 0;
  assert(argv[x][y] != 0);
  do{
   if(isdigit((int)argv[x][y])){
    digits[x] = atoi(argv[x]);
    continue;
   }else{
    fprintf(stderr, "Argument \'%s\' number %d is not digit.\n", argv[x], x);
    argc = -1;
    continue;
   }
   assert(0);
  }while(argv[x][++y] != 0);
  continue;
 }
 if(argc == -1) return -1;
 int index = argc;
 // SORT DIGITS
 while(--index > 1){
  assert(index != argc);
  assert(digits[index] != digits[index-1]);
  if(digits[index] > digits[index-1]){
   int t = digits[index];
   digits[index] = digits[index-1];
   digits[index-1] = t;
   if(index < argc-1) index += 2;
   continue;
  }else continue;
  assert(0);
 }
 assert(digits[0] == 0);
 // CALCULATE GCD
 int pointer = 0;
 int n = 0;
 int m = 0;
 while(++pointer < (argc-1)){
  assert(pointer != 0);
  n = digits[pointer];
  m = digits[pointer+1];
  assert(n > m);
  for(int k = m; k > 0; --k){
   if( ((m%k) == 0) && ((n%k) == 0) ){
    digits[0] = k;
    break;
   }else continue;
  }
  continue;
 }
 fprintf(stdout, "GCD: %d\n", digits[0]);
 return 0;
}
