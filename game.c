#include "excelsior.h"

void parse_into_tokens(char input_command[], char *tokens[], int *ntok){
  int i = 0;
  char *tok = strtok(input_command," \n");
  while(tok!=NULL && i<ARG_MAX){
    tokens[i] = tok;            // assign tokens to found string
    i++;
    tok = strtok(NULL," \n");
  }
  tokens[i] = NULL;             // null terminate tokens to ease argv[] work
  *ntok = i;
  return;
}

int main(int argc, char *argv[]) {

  printf(WELCOME_MSG);

  // Variables
  int run = 1;
  char **tokens;						// Arguments to pass to parse_into_tokens
  int *ntok;

  // Initialize tokens and ntok
  tokens = (char **) malloc(sizeof(char) * ARG_MAX);
  ntok = (int *) malloc(sizeof(int));

  // Main Loop
  while(run){
    char buf[INPUT_BUF_SIZE];
    printf(PROMPT);
    if (fgets(buf, sizeof buf, stdin) != NULL) {
      //printf("%s", buf);
      // read into buffer



      parse_into_tokens(buf, tokens, ntok);


      // User input entered
      if (tokens[0] != NULL) {

        // "help" command
        if (strcmp(tokens[0],"help") == 0){
          printf("EXCELSIOR COMMANDS\n");
  			  printf("help               : show this message\n");
          printf("exit               : exit the program\n");
  		  }
        // "exit" command
		      else if (strcmp(tokens[0],"exit") == 0) {
			         run = 0;
			            break;
		              }
                }

              }
              else {
                printf("\nEnd of input\n");
                run = 0;
                break;
              }

            } // end while loop
            free(tokens);
            free(ntok);
            printf(WELCOME_MSG);


            return 0;
          }
