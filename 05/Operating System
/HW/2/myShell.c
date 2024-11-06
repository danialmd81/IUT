#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

#define READ_END 0
#define WRITE_END 1
#define MAX_ARGS 100

// Function to parse commands separated by pipe
int parse_pipe(char *command, char **parsed_command) {
    for (int i = 0; i < 2; i++) {
        parsed_command[i] = strsep(&command, "|");
        if (parsed_command[i] == NULL) {
            break;
        }
    }
    return (parsed_command[1] != NULL) ? 1 : 0;
}

// Function to parse commands with redirection
int parse_redirect(char *command, char **parsed_command) {
    for (int i = 0; i < 2; i++) {
        parsed_command[i] = strsep(&command, ">");
        if (parsed_command[i] == NULL) {
            break;
        }
    }
    if (parsed_command[1] != NULL){
        // printf("%s, %s", parsed_command[0], parsed_command[1]);
        return 1;
    }
    
    return 0;
}

// Function to execute a single command
void exec_command(char *command) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        return;
    } else if (pid == 0) {
        // Remove trailing '&' if present
        if (command[strlen(command) - 1] == '&') {
            command[strlen(command) - 1] = '\0';
        }
        char *args[MAX_ARGS];
        int i = 0;
        char *token = strsep(&command, " ");
        while (token != NULL) {
            if (*token != '\0') {
                args[i++] = token;
            }
            token = strsep(&command, " ");
        }
        args[i] = NULL;
        
        if (execvp(args[0], args) < 0) {
            perror("Execution failed");
        }
        exit(0);
    } else {
        if (command[strlen(command) - 1] != '&') {
            wait(NULL);
        }
    }
}

// Function to execute piped commands
void exec_piped_commands(char *command1, char *command2) {
    int pipefd[2];
    pid_t pid1, pid2;
    
    if (pipe(pipefd) < 0) {
        perror("Pipe initialization failed");
        return;
    }
    
    pid1 = fork();
    if (pid1 < 0) {
        perror("Forking failed");
        return;
    }
    if (pid1 == 0) {
        close(pipefd[READ_END]);
        dup2(pipefd[WRITE_END], STDOUT_FILENO);
        close(pipefd[WRITE_END]);
        
        char *args1[MAX_ARGS];
        int i = 0;
        char *token = strsep(&command1, " ");
        while (token != NULL) {
            if (*token != '\0') {
                args1[i++] = token;
            }
            token = strsep(&command1, " ");
        }
        args1[i] = NULL;
        
        if (execvp(args1[0], args1) < 0) {
            perror("Execution failed for Command1");
        }
        exit(0);
    } else {
        pid2 = fork();
        if (pid2 < 0) {
            perror("Forking failed");
            return;
        }
        if (pid2 == 0) {
            close(pipefd[WRITE_END]);
            dup2(pipefd[READ_END], STDIN_FILENO);
            close(pipefd[READ_END]);
            
            char *args2[MAX_ARGS];
            int i = 0;
            char *token = strsep(&command2, " ");
            while (token != NULL) {
                if (*token != '\0') {
                    args2[i++] = token;
                }
                token = strsep(&command2, " ");
            }
            args2[i] = NULL;
            
            if (execvp(args2[0], args2) < 0) {
                perror("Execution failed for Command2");
            }
            exit(0);
        } else {
            close(pipefd[READ_END]);
            close(pipefd[WRITE_END]);
            wait(NULL);
            wait(NULL);
        }
    }
}

// Function to execute commands with output redirection
void exec_redirect_commands(char **command) {
    int fd = open(command[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Open failed");
        return;
    }
    
    char *args[MAX_ARGS];
    int i = 0;
    char *token = strsep(&command[0], " ");
    while (token != NULL) {
        if (*token != '\0') {
            args[i++] = token;
        }
        token = strsep(&command[0], " ");
    }
    args[i] = NULL;
    printf("%s, %s\n", args[0], command[1]);
  
    pid_t pid1 = fork();
    if (pid1 < 0) {
        perror("Forking failed");
        return;
    }
    if (pid1 == 0) {
        dup2(fd, STDOUT_FILENO);
        close(fd);
    
        if (execvp(args[0], args) < 0) {
            perror("Execution failed");
        }
        exit(0);
    } else {
        close(fd);
        wait(NULL);
    }
}

int main() {
    char command[256];
    char *parsed_command[2];

    while (1) {
        printf("myshell> ");
        if (!fgets(command, sizeof(command), stdin)) {
            break; // Handle EOF
        }
        command[strcspn(command, "\n")] = 0; // Remove newline

        if (parse_pipe(command, parsed_command) == 1) {
            exec_piped_commands(parsed_command[0], parsed_command[1]);
        } else if (parse_redirect(command, parsed_command) == 1) {
            exec_redirect_commands(parsed_command);
        } else {
            exec_command(command);
        }
    }
    return 0;
}
