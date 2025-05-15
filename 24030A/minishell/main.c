/*PRANAV TR
Date:16/02/2024
*/
#include "main.h"

char *builtins[] = {"echo", "printf", "read", "cd", "pwd", "pushd", "popd", "dirs", "let", "eval", "set", "unset", "export", "declare", "typeset", "readonly", "getopts", "source", "exit", "exec", "shopt", "caller", "true", "type", "hash", "bind", "help", NULL};

char *external[200];
pid_t pid;
int status;

int main()
{
    char input_string[100];
    char prompt[100] = "minishell$";
    system("clear");
    scan_input(prompt, input_string);
    return 0;
}

void scan_input(char *prompt, char *input_string)
{
    extract_external_commands(external);
    signal(SIGINT, signal_handler);

    while (1)
    {
//	printf(ANSI_COLOR_GREEN "%s$ " ANSI_COLOR_RESET, prompt);
	printf("%s$",prompt);
	scanf("%[^\n]", input_string);
	getchar();

	if (strstr(input_string, "PS1") != NULL)
	{
	    if (input_string[3] == '=' && input_string[4] != ' ')
	    {
		strcpy(prompt, input_string + 4);
	    }
	    else
	    {
		printf("%s: command not found\n", input_string);
	    }
	}

	char *word = get_command(input_string);
	int ret = check_command_type(word);

	if (ret == BUILTIN)
	{
	    execute_internal_commands(input_string);
	}
	else if (ret == EXTERNAL)
	{
	    pid = fork();
	    if (pid == 0)
	    {
		execute_external_commands(input_string);
		exit(0);
	    }
	    else
	    {
		pid = wait(&status);
		if (WIFEXITED(status))
		{
		    printf("Child process %d terminated normally\n", pid);
		}
		else if (WIFSIGNALED(status))
		{
		    printf("Child process %d terminated by a signal\n", pid);
		}
	    }
	}
	else if (ret == NO_COMMAND)
	{
	    if (word[0] != 0)
		printf("%s: command not found\n", input_string);
	}

	memset(input_string, 0, 100);
	__fpurge(stdin);
    }
}

void signal_handler(int sig_num)
{
    if (pid != 0 && sig_num == SIGINT)
    {
	kill(pid, SIGKILL);
    }
}
/*
void extract_external_commands(char **external_commands)
{
    int fd = open("command.txt", O_RDONLY);
    if (fd < 0)
    {
	perror("Error opening command file");
	exit(1);
    }

    char word[100], ch;
    int i = 0, j = 0;
    while (read(fd, &ch, 1))
    {
	if (ch != '\n')
	{
	    word[i++] = ch;
	}
	else
	{
	    word[i] = '\0';
	    external_commands[j] = malloc(strlen(word) + 1);
	    strcpy(external_commands[j], word);
	    i = 0;
	    j++;
	}
    }
    external_commands[j] = NULL;
    close(fd);
}
*/


void extract_external_commands(char **external_commands)
{
    FILE *fp = fopen("command.txt", "r");
    if (!fp)
    {
	perror("Failed to open command.txt");
	exit(1);
    }

    char word[100];
    int index = 0;

    while (fscanf(fp, "%s", word) != EOF)
    {
	external_commands[index] = strdup(word);
	index++;
    }
    external_commands[index] = NULL; 

    fclose(fp);
}



char *get_command(char *input_string)
{
    char *cmd = malloc(20);
    int i;
    for (i = 0; input_string[i] && input_string[i] != ' '; i++)
    {
	cmd[i] = input_string[i];
    }
    cmd[i] = '\0';
    return cmd;
}



int check_command_type(char *command)
{
    for (int i = 0; builtins[i]; i++)
    {
	if (strcmp(builtins[i], command) == 0)
	{
	    return BUILTIN;
	}
    }

    for (int i = 0; external[i]; i++)
    {
	if (strcmp(external[i], command) == 0)
	{
	    return EXTERNAL;
	}
    }
    return NO_COMMAND;
}


void execute_internal_commands(char *input_string)
{
    if (strncmp(input_string, "exit", 4) == 0)
    {
	printf("Exiting shell...\n");
	exit(0);
    }
    else if (strncmp(input_string, "cd", 2) == 0)
    {
	char *ptr = strchr(input_string, '/');
	if (ptr)
	    chdir(ptr);
    }
    else if (strcmp(input_string, "pwd") == 0)
    {
	char buf[200];
	printf("%s\n", getcwd(buf, 200));
    }
    else if (strncmp(input_string, "echo", 4) == 0)
    {
	echo(input_string, status);
    }
}

void echo(char *input_string, int status)
{
    if(!strcmp(input_string,"echo $?"))
    {
	printf("%d\n",status);
    }
    else if(!strcmp(input_string,"echo $$"))
    {
	printf("%d\n",getpid());
    }
    else if(!strcmp(input_string,"echo $SHELL"))
    {
	printf("%s\n",getenv("SHELL"));
    }
}


void execute_external_commands(char *input_string)
{
    char *argv[20] = {NULL};
    char *cmds[10] = {NULL};  
    int num_cmds = 0;

    // Tokenize input based on '|'
    char *token = strtok(input_string, "|");
    while (token != NULL)
    {
	cmds[num_cmds++] = strdup(token);
	token = strtok(NULL, "|");
    }

    int pipes[num_cmds - 1][2];
    pid_t pids[num_cmds];

    for (int i = 0; i < num_cmds; i++)
    {
	if (i < num_cmds - 1) 
	{
	    if (pipe(pipes[i]) == -1)
	    {
		perror("pipe");
		exit(1);
	    }
	}

	pids[i] = fork();
	if (pids[i] == 0)
	{
	    if (i > 0)
	    {
		dup2(pipes[i - 1][0], STDIN_FILENO);
	    }
	    if (i < num_cmds - 1)
	    {
		dup2(pipes[i][1], STDOUT_FILENO);
	    }

	    for (int j = 0; j < num_cmds - 1; j++)
	    {
		close(pipes[j][0]);
		close(pipes[j][1]);
	    }

	    int arg_idx = 0;
	    char *arg = strtok(cmds[i], " ");
	    while (arg != NULL)
	    {
		argv[arg_idx++] = arg;
		arg = strtok(NULL, " ");
	    }
	    argv[arg_idx] = NULL;

	    execvp(argv[0], argv);
	    perror("execvp");
	    exit(1);
	}
    }

    for (int i = 0; i < num_cmds - 1; i++)
    {
	close(pipes[i][0]);
	close(pipes[i][1]);
    }

    for (int i = 0; i < num_cmds; i++)
    {
	waitpid(pids[i], NULL, 0);
    }
}