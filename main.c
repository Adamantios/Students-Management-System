#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SMTHNG
#define SMTHNG

#include "errors.h"
#include "commonVariables.h"
#include "listFunctions.h"
#include "studentFunctions.h"
#include "fileFunctions.h"
#include "instructions.h"

#endif

int main(int argc, char *argv[]) {
    int run = 1;
    int command;
    char choice[10];

    welcome();
    Load();
    while (run == 1) {
        instructions();
        scanf("%s", choice);
        if (strlen(choice) != 1)
            printf("\nBad command. Please try again\n\n");
        else {
            command = strcspn(digits, choice);

            switch (command) {
                case insert:
                    Insert();
                    break;
                case del:
                    Del();
                    break;
                case refresh:
                    Refresh();
                    break;
                case list:
                    List();
                    break;
                case save:
                    Save();
                    break;
                case Exit:
                    Save();
                    run = 0;
                    break;
                default:
                    printf("%s", NOT_EXISTING_COMMAND);
                    break;
            }
        }
    }
    printf("\nBye!\n\n");
    system("PAUSE");
    return 0;
}
