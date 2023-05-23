#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "commands.h"


Command* create_command() {
    Command* cmd = (Command*)malloc(sizeof(Command));
    if (cmd == NULL) {
        printf("Failed to allocate memory for command.\n");
        exit(1);
    }
    strcpy(cmd->name, "");
    cmd->int_size = 0;
    cmd->str_size = 0;
    return cmd;
}

void add_str_param(Command* cmd, char* p) {
    cmd->str_params[cmd->str_size] = strdup(p);
    cmd->str_size++;
}

void add_int_param(Command* cmd, int p) {
    cmd->int_params[cmd->int_size] = p;
    cmd->int_size++;
}

void free_cmd(Command* cmd) {
    for (int i = 0; i < cmd->str_size; i++) {
        free(cmd->str_params[i]);
    }
    free(cmd);
}

int read_exec_command(Command* cmd) {
    // Your code to execute the command goes here
    printf("Executing command: %s\n", cmd->name);
    for (int i = 0; i < cmd->int_size; i++) {
        printf("Int Param: %d\n", cmd->int_params[i]);
    }
    for (int i = 0; i < cmd->str_size; i++) {
        printf("Str Param: %s\n", cmd->str_params[i]);
    }
    return 0;
}

void read_from_stdin(Command* cmd) {
    char line[100];
    printf("Enter a command: ");
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0'; // Remove the newline character
    char* token = strtok(line, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            int param = atoi(token);
            add_int_param(cmd, param);
        } else {
            add_str_param(cmd, token);
        }
        token = strtok(NULL, " ");
    }
}