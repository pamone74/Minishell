# Minishell
This is the implementation of shell. 42 Abu Dhabi projects
⭐ Implement a shell..
## Things to learn for this project

🏹 System Programming

🏹 Command Line and how they are used:

The command line is an interface where users can type and execute commands to interact with the computer.
Users can run programs, navigate file systems, manage processes, and perform various tasks using the command line.
Commands are entered in a terminal or console, and they can have options and arguments.

🏹 Environment variables and local variables:

Environment variables are global variables that are accessible by all processes running on a system.
Local variables are specific to a particular shell session or script.
Examples of environment variables include PATH, HOME, and USER.

🏹 Pipe:

The pipe (|) is used to combine the output of one command as the input to another.
It allows for the creation of command pipelines, where the output of one command becomes the input for the next.

🏹 File permissions:

File permissions control access to files and directories in Unix-like operating systems.
Permissions include read (r), write (w), and execute (x) for the owner, group, and others.
chmod command is used to change file permissions.

🏹 Signals:

Signals are software interrupts that are sent to a process to notify it to perform some action.
Examples include SIGINT (interrupt), SIGTERM (terminate), and SIGKILL (forceful termination).
kill command is often used to send signals to processes.

🏹 Builtins:

        ✍️ echo -n: Prints text to the console without adding a newline at the end.

        ✍️ cd: Changes the current working directory.

        ✍️ pwd: Prints the current working directory.

        ✍️ export: Sets an environment variable.

        ✍️ unset: Unsets an environment variable.

        ✍️ env: Displays the environment variables.

        ✍️ exit: Exits the shell or script.


🏹 File descriptors:

File descriptors are integer values associated with open files in a Unix-like operating system.
Standard file descriptors are 0 (stdin), 1 (stdout), and 2 (stderr).
Input/output redirection and pipes manipulate file descriptors.

🏹 Synchronization between processes:

Synchronization mechanisms, such as semaphores, mutexes, and condition variables, are used to coordinate and control the execution of multiple processes.
These mechanisms prevent race conditions and ensure proper communication between processes.

💥 First thing to do is to understand the projects goals and requirements, learn and practice the allowed functions and in the process you will 
develop ideas that will later on help you to develop a algorithm that will work for you. 

I have give explantions for the give functions thanks to the man page and AI..


    Functions:
💥 readline(prompt): 
    readline will read a line from the terminal and return it, using
    prompt as a prompt.  If prompt is NULL or the empty string, no
    prompt is issued.  The line returned is allocated with malloc(3);
    the caller must free it when finished.  The line returned has the
    final newline removed, so only the text of the line remains
  
  char *readline(const char *promt)

💥 rl_clear_history(): The rl_clear_history function is part of the GNU
      Readline library and is used to clear the entire command history maintained by Readline. When you call rl_clear_history, it removes all the entries from the history list.
    Be cautious when using rl_clear_history because it removes all history entries. This function is typically used when you want to reset the command history, for example, when restarting a new session or when a specific condition is met in your program
    
    void rl_clear_history(void)
💥 rl_on_new_line():
    rl_on_new_line is a function in the GNU Readline library used to inform Readline that the cursor has moved to a new line. This function is part of the Readline library, which provides a set of functions for handling command-line input, editing, and history.

    void rl_on_new_line(void);

💥 rl_replace_line():
    rl_replace_line is a function in the GNU Readline library used to replace the entire current input line (the line the user is currently typing) with a new string. This function is part of the Readline library, which provides a set of functions for handling command-line input, editing, and history.

    int rl_replace_line(const char *text, int clear_undo;
    parameters:
        text: The new string that will replace the current input line.
        clear_undo: If non-zero, clears the undo information.
    Return Value:
        Returns 0 on success and -1 on failure.
    Description:
        The rl_replace_line function replaces the entire contents of the current input line with the specified text.
    
💥 rl_redisplay():
        The rl_redisplay function forces an immediate redisplay of the current input line. This is useful when you've made changes to the line using functions like rl_replace_line, and you want to ensure that the changes are immediately visible on the terminal
    
    void    rl_redisplay(void);

    add_history(const char *string):
        The add_history function adds the specified string to the command history, making it available for retrieval and recall through the command history features provided by Readline.
    
    void add_history(const char *string);
    To retrieve the history, you need to get the history list and print it:
    
    HIST_ENTRY is the struct type and the history list retuns pointer to the commands.
    HIST_ENTRY** list = history_list();

💥 access():
        The access function in C is part of the <unistd.h> header and is used to check whether the calling process can access a file or directory.
    
    int access(const char *path, int amode);
    parameters:
        path: 
            The path to the file or directory whose accessibility is to be checked.
        amode: 
            The mode of access to be checked, specified using a combination of    symbolic constants. Common constants include:
                F_OK:   Checks for the existence of the file or directory.
                R_OK:   Checks if the file or directory is readable.
                W_OK:   Checks if the file or directory is writable.
                X_OK:   Checks if the file or directory is executable.
    The function returns 0 if the access is allowed according to the specified mode,and -1 if there is an error or if access is denied.

💥 open():
        The open function in C is part of the <fcntl.h> (File Control) header and is used to open a file or create it if it doesn't exist. It returns a file descriptor, an integer that represents the file in subsequent operations.
    
    #include <fcntl.h>

    int open(const char *pathname, int flags, ... mode_t mode );

    Parameters:
        pathname: The path to the file.
        flags: 
            A combination of flags that specify the mode of opening. Common flags include:
                O_RDONLY: Open for reading only.
                O_WRONLY: Open for writing only.
                O_RDWR: Open for reading and writing.
                O_CREAT: Create the file if it does not exist.
                O_TRUNC: Truncate the file to zero length.
        mode: 
            An optional parameter that specifies the file permissions when creating a file (used only when O_CREAT is set). You can specify the permissions using symbolic constants like S_IRUSR (read permission for the owner) or S_IWGRP (write permission for the group).

    
    .
    The function returns a file descriptor on success or -1 on failure. The file descriptor can be used in subsequent read or write operations.

💥 read():
        The read function in C is part of the <unistd.h> header and is used to read data from a file descriptor. It returns the number of bytes read, or -1 if there was an error.
    
        ssize_t read(int fd, void *buf, size_t count);
        Parameters:
            fd: The file descriptor to read from.
            buf: The buffer to store the data read.
            count: The maximum number of bytes to read.
        The function returns the number of bytes read, or -1 if there was an error.

💥 close():
        The close function in C is part of the <unistd.h> header and is used to close a file descriptor. It returns 0 on success and -1 on failure.
    
        int close(int fd);
        Parameters:
            fd: The file descriptor to close.
        The function returns 0 on success and -1 on failure.

💥 fork():

The fork function in C is part of the <unistd.h> header and is used to create a new process, called a child process, which runs concurrently with the process that makes the fork() call (parent process). The child process is an exact copy of the parent process except for the following:

            The child process has a unique process ID.
            The child process has a different parent process ID (the process ID of the parent process).
            The child process has its own copy of the parent's file descriptors. These file descriptors refer to the same open file descriptions as the corresponding file descriptors in the parent.
            The child process has its own copy of the parent's environment variables.
            The child process has its own copy of the parent's working directory.
            The child process does not inherit the parent's memory locks.
            The child process does not inherit timers set by the parent.
            The child process does not inherit record locks set by the parent.
            The child process does not inherit process-associated resource limits from the parent.
            The child process does not inherit process-associated signal masks from the parent.
            The child process does not inherit process-associated pending signals from the parent.
            The child process does not inherit process-associated semaphores from the parent.
            The child process does not inherit process-associated alternate signal stacks from the parent.
            The child process does not inherit process-associated timers from the parent.
            The child process does not inherit process-associated asynchronous I/O operations from the parent.
            The child process does not inherit process-associated CPU-time clocks from the parent.
            The child process does not inherit process-associated I/O completion notifications from the parent.
            The child process does not inherit process-associated I/O completion queues from the parent.
            The child process does not inherit process-associated CPU affinity from the parent.
            The child process does not inherit process-associated thread-specific data from the parent.
            The child process does not inherit process-associated thread cancellation states from the parent.
            The child process does not inherit process-associated thread cancellation types from the parent.
            The child process does not inherit process-associated thread cancellation asynchronous safe cleanup handlers from the parent.
            The child process does not inherit process-associated thread cancellation deferred handlers from the parent.
            The child process does not inherit process-associated thread cancellation set IDs from the parent.
            The child process does not inherit process-associated thread cancellation enabled states from the parent.
            The child process does not inherit process-associated thread cancellation pending states from
        pid_t fork(void);
        
        The function returns the process ID of the child process to the parent process, and 0 to the child process. If there is an error, the function returns -1.

💥 wait():
        The wait function in C is part of the <sys/wait.h> header and is used to wait for the child process to terminate. It returns the process ID of the terminated child process, or -1 if there was an error.

        pid_t wait(int *status);

        Parameters:
            status: A pointer to an integer where the exit status of the child process will be stored.
        The wait() system call returns the process ID of the terminated child process. If there are no child processes, wait() returns -1 and sets errno to ECHILD.

        The status argument is used to store information about the terminated child process. By convention, the macro WIFEXITED(status) can be used to check whether the child terminated normally. If true, WEXITSTATUS(status) can be used to obtain the exit status of the child process.

💥 waitpid():
        The waitpid function in C is part of the <sys/wait.h> header and is used to wait for a specific child process to terminate. It returns the process ID of the terminated child process, or -1 if there was an error.

        pid_t waitpid(pid_t pid, int *status, int options);

        Parameters:
            pid: 
                The process ID of the child process to wait for. If pid is -1, waitpid() waits for any child process to terminate.
                if the pid is 0, waitpid() waits for any child process in the same process group as the calling process to terminate.
                if the pid is > 0, waitpid() waits for the child process with the specified process ID to terminate.
            status: 
                A pointer to an integer where the exit status of the child process will be stored.
            options: 
                A combination of flags that specify the behavior of waitpid(). Common flags include:
                WNOHANG: Return immediately if no child process has terminated.
                WUNTRACED: Also return if a child has stopped (but not traced via ptrace(2)). Status for traced children which have stopped is provided even if this option is not specified.
        The waitpid() system call returns the process ID of the terminated child process. If there are no child processes, waitpid() returns -1 and sets errno to ECHILD.

💥 wait3():
        This is the same as waitpid() with the options set to 0.
    wait4():
        The wait4 function is another system call for waiting on child processes in Unix-like operating systems. It is similar to waitpid but provides additional options for gathering information about child processes, such as resource usage statistics. Like waitpid, wait4 is considered more feature-rich compared to the basic wait system call.

        pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);
        parameters:
            pid: 
                The process ID of the child process to wait for. If pid is -1, wait4() waits for any child process to terminate.
                if the pid is 0, wait4() waits for any child process in the same process group as the calling process to terminate.
                if the pid is > 0, wait4() waits for the child process with the specified process ID to terminate.
            status: 
                A pointer to an integer where the exit status of the child process will be stored.
            options: 
                A combination of flags that specify the behavior of wait4(). Common flags include:
                WNOHANG: Return immediately if no child process has terminated.
                WUNTRACED: Also return if a child has stopped (but not traced via ptrace(2)). Status for traced children which have stopped is provided even if this option is not specified.
            rusage: 
                A pointer to a struct rusage where resource usage statistics for the child process will be stored.
💥 signal():
        The signal function in C is part of the <signal.h> header and is used to register a signal handler for a specific signal. It returns the previous value of the signal handler, or SIG_ERR if there was an error.

        void (*signal(int sig, void (*handler)(int)))(int);

        Parameters:
            sig: The signal to register a handler for.
            handler: A pointer to the signal handler function.
        The signal() function returns the previous value of the signal handler, or SIG_ERR if there was an error.
    sigaction():
        The sigaction function in C is part of the <signal.h> header and is used to register a signal handler for a specific signal. It returns 0 on success and -1 on failure.

        int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);

        Parameters:
            sig: The signal to register a handler for.
            act: A pointer to a struct sigaction that specifies the action to be associated with the specified signal.
            oact: A pointer to a struct sigaction where the previous action associated with the specified signal will be stored.
        The sigaction() function returns 0 on success and -1 on failure.
    
💥 sigemptyset():
        The sigemptyset function in C is part of the <signal.h> header and is used to initialize a signal set to be empty. It returns 0 on success and -1 on failure.

        int sigemptyset(sigset_t *set);

        Parameters:
            set: A pointer to a sigset_t where the empty signal set will be stored.
        The sigemptyset() function returns 0 on success and -1 on failure.
    
💥 sigaddset():
        The sigaddset function in C is part of the <signal.h> header and is used to add a signal to a signal set. It returns 0 on success and -1 on failure.

        int sigaddset(sigset_t *set, int signum);

        Parameters:
            set: A pointer to a sigset_t where the signal will be added.
            signum: The signal to add to the signal set.
        The sigaddset() function returns 0 on success and -1 on failure.
    
💥 kill():
        The kill function in C is part of the <signal.h> header and is used to send a signal to a process or a group of processes. It returns 0 on success and -1 on failure.

        int kill(pid_t pid, int sig);

        Parameters:
            pid: The process ID of the process to send the signal to.
            sig: The signal to send.
        The kill() function returns 0 on success and -1 on failure.
    
💥 exit():
        The exit function in C is part of the <stdlib.h> header and is used to terminate the calling process. It does not return a value.

        void exit(int status);

        Parameters:
            status: The exit status of the process.
        The exit() function does not return a value.

💥 getcwd():
        The getcwd function in C is part of the <unistd.h> header and is used to get the current working directory. It returns a pointer to a string containing the current working directory, or NULL if there was an error.

        char *getcwd(char *buf, size_t size);

        Parameters:
            buf: A pointer to a buffer where the current working directory will be stored.
            size: The size of the buffer.
        The getcwd() function returns a pointer to a string containing the current working directory, or NULL if there was an error.

💥 chdir():
        The chdir function in C is part of the <unistd.h> header and is used to change the current working directory. It returns 0 on success and -1 on failure.

        int chdir(const char *path);

        Parameters:
            path: The path to the directory to change to.
        The chdir() function returns 0 on success and -1 on failure.
    
💥 stat():
        The stat function in C is part of the <sys/stat.h> header and is used to get information about a file. It returns 0 on success and -1 on failure.

        int stat(const char *restrict path, struct stat *restrict buf);

        Parameters:
            path: The path to the file.
            buf: A pointer to a struct stat where the information about the file will be stored.
        The stat() function returns 0 on success and -1 on failure.

💥 lstat():
        The lstat function in C is part of the <sys/stat.h> header and is used to get information about a file. It returns 0 on success and -1 on failure.

        int lstat(const char *restrict path, struct stat *restrict buf);

        Parameters:
            path: The path to the file.
            buf: A pointer to a struct stat where the information about the file will be stored.
        The lstat() function returns 0 on success and -1 on failure.

        lstat is similar to stat but does not follow symbolic links. If pathname refers to a symbolic link, lstat returns information about the link itself, not the file it points to.
    
💥 fstat():
        The fstat function in C is part of the <sys/stat.h> header and is used to get information about a file. It returns 0 on success and -1 on failure.

        int fstat(int fd, struct stat *buf);

        Parameters:
            fd: The file descriptor of the file.
            buf: A pointer to a struct stat where the information about the file will be stored.
        The fstat() function returns 0 on success and -1 on failure.
    
    stat, lstat and fstat are system calls in Unix-like operating systems that provide information about a file, such as its size, permissions, timestamps, and more. These calls are part of the <sys/stat.h> header file in C.

💥 unlink():
        The unlink function in C is part of the <unistd.h> header and is used to delete a file. It returns 0 on success and -1 on failure.

        int unlink(const char *pathname);

        Parameters:
            pathname: The path to the file to delete.
        The unlink() function returns 0 on success and -1 on failure.
    
💥 execve():
        The execve function in C is part of the <unistd.h> header and is used to execute a program. It does not return a value.

        int execve(const char *pathname, char *const argv[], char *const envp[]);

        Parameters:
            pathname: 
                The path to the program to execute.
            argv: 
                An array of strings containing the arguments to the program.
            envp: 
                An array of strings containing the environment variables for the program.
        Return Value:

        On success,
            execve() does not return; the new program image is loaded into the current process.
        On failure, it returns -1, and errno is set to indicate the error.
💥 dup():
        The dup function in C is part of the <unistd.h> header and is used to duplicate a file descriptor. It returns a new file descriptor on success and -1 on failure.

        int dup(int oldfd);

        Parameters:
            oldfd: The file descriptor to duplicate.
        The dup() function returns a new file descriptor on success and -1 on failure.
    why do we need dup()?
        The dup() function is used to duplicate a file descriptor. It is useful when you want to redirect the output of a program to a file. For example, if you want to redirect the output of a program to a file, you can use dup() to duplicate the file descriptor of the file and then use dup2() to redirect the output of the program to the file.

💥 dup2():
        The dup2 function in C is part of the <unistd.h> header and is used to duplicate a file descriptor. It returns a new file descriptor on success and -1 on failure.

        int dup2(int oldfd, int newfd);

        Parameters:
            oldfd: The file descriptor to duplicate.
            newfd: The file descriptor to duplicate to.
        The dup2() function returns a new file descriptor on success and -1 on failure.
    uses of dup2():
        The dup2() function is used to duplicate a file descriptor. It is useful when you want to redirect the output of a program to a file. For example, if you want to redirect the output of a program to a file, you can use dup() to duplicate the file descriptor of the file and then use dup2() to redirect the output of the program to the file.
    
    examples of dup2():
        int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        dup2(fd, STDOUT_FILENO);
        close(fd);
        printf("Hello, World!\n");
        The above code opens a file called output.txt and redirects the output of the program to the file. The printf() function will write to the file instead of the standard output. The file descriptor of the file is duplicated using dup() and then redirected to the standard output using dup2().
    
💥 pipe():
        The pipe function in C is part of the <unistd.h> header and is used to create a pipe, a unidirectional communication channel between two processes. It returns 0 on success and -1 on failure.

        int pipe(int pipefd[2]);

        Parameters:
            pipefd: 
                An array of two integers where the file descriptors for the pipe will be stored.
        The pipe() function returns 0 on success and -1 on failure.

        uses of pipe():
            The pipe() function is used to create a pipe, a unidirectional communication channel between two processes. It is useful when you want to create a communication channel between two processes, such as a parent process and a child process. For example, you can use a pipe to redirect the output of a program to another program, or to send data from one program to another.

        example of pipe():
            int pipefd[2];
            if (pipe(pipefd) == -1) {
                perror("pipe");
                return EXIT_FAILURE;
            }
            The above code creates a pipe and stores the file descriptors for the pipe in the pipefd array. The pipefd[0] file descriptor is used for reading from the pipe, and the pipefd[1] file descriptor is used for writing to the pipe.

💥 opendir():
            The opendir function in C is part of the <dirent.h> header and is used to open a directory stream. It returns a pointer to a DIR structure on success and NULL on failure.

            DIR *opendir(const char *name);

            Parameters:
                name: The path to the directory to open.
            The opendir() function returns a pointer to a DIR structure on success and NULL on failure.

        uses of opendir():
            The opendir() function is used to open a directory stream. It is useful when you want to read the contents of a directory, such as the files and subdirectories it contains. For example, you can use opendir() to open a directory and then use readdir() to read the contents of the directory.

        example of opendir():
            DIR *dir = opendir(".");
            if (dir == NULL) {
                perror("opendir");
                return EXIT_FAILURE;
            }
            The above code opens the current directory and stores the directory stream in the dir pointer. The opendir() function returns a pointer to a DIR structure on success, or NULL on failure.
    
💥 readdir():
            The readdir function in C is part of the <dirent.h> header and is used to read the next entry from a directory stream. It returns a pointer to a dirent structure on success and NULL on failure.

        struct dirent *readdir(DIR *dirp);

        Parameters:
            dirp: 
            A pointer to a DIR structure representing the directory stream.
        The readdir() function returns a pointer to a dirent structure on success and NULL on failure.

        example:
            DIR *dir = opendir(".");
            if (dir == NULL) {
                perror("opendir");
                return EXIT_FAILURE;
            }
            struct dirent *entry;
            while ((entry = readdir(dir)) != NULL) {
                printf("%s\n", entry->d_name);
            }
            The above code reads the next entry from the directory stream and prints the name of the entry. It continues reading entries until there are no more entries in the directory stream.   

💥 closedir():
        The closedir function in C is part of the <dirent.h> header and is used to close a directory stream. It returns 0 on success and -1 on failure.

        int closedir(DIR *dirp);

        Parameters:
            dirp: A pointer to a DIR structure representing the directory stream.
        The closedir() function returns 0 on success and -1 on failure.
        uses of closedir():
            The closedir() function is used to close a directory stream. It is useful when you are finished reading the contents of a directory and want to close the directory stream. For example, you can use closedir() to close the directory stream after using opendir() and readdir() to read the contents of a directory.

        example of closedir():
            DIR *dir = opendir(".");
            if (dir == NULL) {
                perror("opendir");
                return EXIT_FAILURE;
            }
            struct dirent *entry;
            while ((entry = readdir(dir)) != NULL) {
                printf("%s\n", entry->d_name);
            }
            closedir(dir);
            The above code opens the current directory, reads the contents of the directory, and then closes the directory stream. The closedir() function returns 0 on success, or -1 on failure.
    
💥 strerror():
        The strerror function in C is part of the <string.h> header and is used to get a string describing an error code. It returns a pointer to a string containing the error message.

        char *strerror(int errnum);

        Parameters:
            errnum: The error code to get the error message for.
        The strerror() function returns a pointer to a string containing the error message.

        uses of strerror():
            The strerror() function is used to get a string describing an error code. It is useful when you want to get a human-readable description of an error code, such as the error code returned by the errno variable. For example, you can use strerror() to print an error message when a system call fails.

        example of strerror():
            if (access("file.txt", F_OK) == -1) {
                perror(strerror(errno));
                return EXIT_FAILURE;
            }
            The above code checks if the file file.txt exists, and if it doesn't, it prints an error message using strerror() and returns EXIT_FAILURE. The strerror() function returns a pointer to a string containing the error message.
    
💥 perror():
        The perror function in C is part of the <stdio.h> header and is used to print an error message to the standard error stream. It prints the string pointed to by s, followed by a colon and a space, followed by the error message for the current value of errno, and a newline.

        void perror(const char *s);

        Parameters:
            s: A pointer to a string to print before the error message.
        The perror() function does not return a value.

        uses of perror():
            The perror() function is used to print an error message to the standard error stream. It is useful when you want to print an error message when a system call fails, such as when a file cannot be opened or a directory cannot be read. For example, you can use perror() to print an error message when the access() system call fails.

        example of perror():
            if (access("file.txt", F_OK) == -1) {
                perror("access");
                return EXIT_FAILURE;
            }
            The above code checks if the file file.txt exists, and if it doesn't, it prints an error message using perror() and returns EXIT_FAILURE. The perror() function prints the string "access" followed by a colon and a space, followed by the error message for the current value of errno, and a newline.

💥 isatty():
        The isatty function in C is part of the <unistd.h> header and is used to check whether a file descriptor refers to a terminal. It returns 1 if the file descriptor refers to a terminal, and 0 if it does not.

        int isatty(int fd);

        Parameters:
            fd: The file descriptor to check.
        The isatty() function returns 1 if the file descriptor refers to a terminal, and 0 if it does not.

        uses of isatty():
            The isatty() function is used to check whether a file descriptor refers to a terminal. It is useful when you want to determine if a file descriptor is associated with a terminal, such as when you want to enable or disable terminal-specific features. For example, you can use isatty() to check if standard input is associated with a terminal before enabling line editing features.

        example of isatty():
            if (isatty(STDIN_FILENO)) {
                printf("Standard input is a terminal\n");
            } else {
                printf("Standard input is not a terminal\n");
            }
            The above code checks if standard input is associated with a terminal and prints a message accordingly. The isatty() function returns 1 if the file descriptor refers to a terminal, and 0 if it does not.

💥 ttyname():
        The ttyname function in C is part of the <unistd.h> header and is used to get the name of the terminal associated with a file descriptor. It returns a pointer to a string containing the name of the terminal, or NULL if the file descriptor is not associated with a terminal.

        char *ttyname(int fd);

        Parameters:
            fd: The file descriptor to get the terminal name for.
        The ttyname() function returns a pointer to a string containing the name of the terminal, or NULL if the file descriptor is not associated with a terminal.

        uses of ttyname():
            The ttyname() function is used to get the name of the terminal associated with a file descriptor. It is useful when you want to determine the name of the terminal associated with a file descriptor, such as when you want to display the name of the terminal to the user. For example, you can use ttyname() to get the name of the terminal associated with standard input and display it to the user.

        example of ttyname():
            char *name = ttyname(STDIN_FILENO);
            if (name != NULL) {
                printf("Terminal name: %s\n", name);
            } else {
                printf("Standard input is not associated with a terminal\n");
            }
            The above code gets the name of the terminal associated with standard input and displays it to the user. The ttyname() function returns a pointer to a string containing the name of the terminal, or NULL if the file descriptor is not associated with a terminal.

💥 ttyslot();
        The ttyslot function in C is part of the <unistd.h> header and is used to get the slot number of the current terminal in the utmp file. It returns the slot number of the current terminal, or 0 if the terminal is not found in the utmp file.

        int ttyslot(void);

        The ttyslot() function returns the slot number of the current terminal, or 0 if the terminal is not found in the utmp file.

        uses of ttyslot():
            The ttyslot() function is used to get the slot number of the current terminal in the utmp file. It is useful when you want to determine the slot number of the current terminal, such as when you want to display the slot number to the user. For example, you can use ttyslot() to get the slot number of the current terminal and display it to the user.

        example of ttyslot():
            int slot = ttyslot();
            if (slot != 0) {
                printf("Terminal slot: %d\n", slot);
            } else {
                printf("Terminal not found in utmp file\n");
            }
            The above code gets the slot number of the current terminal and displays it to the user. The ttyslot() function returns the slot number of the current terminal, or 0 if the terminal is not found in the utmp file.
    
💥 ioctl():
        The ioctl function in C is part of the <sys/ioctl.h> header and is used to perform I/O control operations on a file descriptor. It returns 0 on success and -1 on failure.

        int ioctl(int fd, unsigned long request, ...);

        Parameters:
            fd: The file descriptor to perform the I/O control operation on.
            request: The I/O control operation to perform.
        The ioctl() function returns 0 on success and -1 on failure.

        uses of ioctl():
            The ioctl() function is used to perform I/O control operations on a file descriptor. It is useful when you want to perform low-level I/O control operations, such as setting terminal attributes or controlling hardware devices. For example, you can use ioctl() to set the baud rate of a serial port or to control the behavior of a terminal.

        example of ioctl():
            struct winsize ws;
            if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
                perror("ioctl");
                return EXIT_FAILURE;
            }
            The above code gets the size of the terminal window and stores it in the ws structure. The ioctl() function returns 0 on success, or -1 on failure.

        example of ioctl():
            struct winsize ws;
            if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
                perror("ioctl");
                return EXIT_FAILURE;
            }
            The above code gets the size of the terminal window and stores it in the ws structure. The ioctl() function returns 0 on success, or -1 on failure.

💥 getenv():
        The getenv function in C is part of the <stdlib.h> header and is used to get the value of an environment variable. It returns a pointer to a string containing the value of the environment variable, or NULL if the environment variable is not found.

        char *getenv(const char *name);

        Parameters:
            name: The name of the environment variable to get the value of.
        The getenv() function returns a pointer to a string containing the value of the environment variable, or NULL if the environment variable is not found.

        uses of getenv():
            The getenv() function is used to get the value of an environment variable. It is useful when you want to access environment variables, such as when you want to get the value of the PATH or HOME environment variables. For example, you can use getenv() to get the value of the SHELL environment variable and display it to the user.

        example of getenv():
            char *shell = getenv("SHELL");
            if (shell != NULL) {
                printf("Shell: %s\n", shell);
            } else {
                printf("SHELL environment variable not found\n");
            }
            The above code gets the value of the SHELL environment variable and displays it to the user. The getenv() function returns a pointer to a string containing the value of the environment variable, or NULL if the environment variable is not found.
   
💥 tcsetattr():
        The tcsetattr function in C is part of the <termios.h> header and is used to set the terminal attributes. It returns 0 on success and -1 on failure.

        int tcsetattr(int fd, int optional_actions, const struct termios *termios_p);

        Parameters:
            fd: The file descriptor of the terminal.
            optional_actions: The optional actions to perform.
            termios_p: A pointer to a struct termios containing the terminal attributes to set.
        The tcsetattr() function returns 0 on success and -1 on failure.

        uses of tcsetattr():
            The tcsetattr() function is used to set the terminal attributes. It is useful when you want to control the behavior of the terminal, such as setting the input and output modes or controlling the flow of data. For example, you can use tcsetattr() to set the terminal to non-canonical mode or to set the baud rate of a serial port.

        example of tcsetattr():
            struct termios newattr;
            tcgetattr(STDIN_FILENO, &newattr);
            newattr.c_lflag &= ~(ICANON | ECHO);
            tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
            The above code sets the terminal to non-canonical mode and disables echo. The tcsetattr() function returns 0 on success, or -1 on failure.
    
 💥 tcgetattr():
        The tcgetattr function in C is part of the <termios.h> header and is used to get the terminal attributes. It returns 0 on success and -1 on failure.

        int tcgetattr(int fd, struct termios *termios_p);

        Parameters:
            fd: The file descriptor of the terminal.
            termios_p: A pointer to a struct termios where the terminal attributes will be stored.
        The tcgetattr() function returns 0 on success and -1 on failure.

        uses of tcgetattr():
            The tcgetattr() function is used to get the terminal attributes. It is useful when you want to access the current settings of the terminal, such as the input and output modes or the baud rate. For example, you can use tcgetattr() to get the current settings of the terminal and display them to the user.

        example of tcgetattr():
            struct termios attr;
            tcgetattr(STDIN_FILENO, &attr);
            printf("Input baud rate: %d\n", cfgetispeed(&attr));
            printf("Output baud rate: %d\n", cfgetospeed(&attr));
            The above code gets the current settings of the terminal and displays the input and output baud rates to the user. The tcgetattr() function returns 0 on success, or -1 on failure. 

💥 tgetent():
        The tgetent function in C is part of the <curses.h> header and is used to get the terminal capabilities. It returns 1 on success and 0 on failure.

        int tgetent(char *bp, const char *name);

        Parameters:
            bp: A pointer to a buffer where the terminal capabilities will be stored.
            name: The name of the terminal type.
        The tgetent() function returns 1 on success and 0 on failure.

        uses of tgetent():
            The tgetent() function is used to get the terminal capabilities. It is useful when you want to access the capabilities of the terminal, such as the number of columns and rows or the control sequences for cursor movement. For example, you can use tgetent() to get the terminal capabilities and use them to control the behavior of the terminal.

        example of tgetent():
            char buf[1024];
            if (tgetent(buf, "xterm") != 1) {
                perror("tgetent");
                return EXIT_FAILURE;
            }
            The above code gets the terminal capabilities for the xterm terminal type and stores them in the buf buffer. The tgetent() function returns 1 on success, or 0 on failure.
    
💥 tgetflag():
        The tgetflag function in C is part of the <curses.h> header and is used to get the value of a terminal capability flag. It returns 1 if the flag is set, and 0 if it is not.

        int tgetflag(const char *id);

        Parameters:
            id: The name of the terminal capability flag.
        The tgetflag() function returns 1 if the flag is set, and 0 if it is not.

        uses of tgetflag():
            The tgetflag() function is used to get the value of a terminal capability flag. It is useful when you want to access the capabilities of the terminal, such as the number of columns and rows or the control sequences for cursor movement. For example, you can use tgetflag() to check if a specific terminal capability flag is set and use it to control the behavior of the terminal.

        example of tgetflag():
            if (tgetflag("am") == 1) {
                printf("Automatic margins are supported\n");
            } else {
                printf("Automatic margins are not supported\n");
            }
            The above code checks if the automatic margins terminal capability flag is set and prints a message accordingly. The tgetflag() function returns 1 if the flag is set, and 0 if it is not.
    
💥 tgetnum():
        The tgetnum function in C is part of the <curses.h> header and is used to get the value of a terminal capability number. It returns the value of the terminal capability, or -1 if the capability is not found.

        int tgetnum(const char *id);

        Parameters:
            id: The name of the terminal capability number.
        The tgetnum() function returns the value of the terminal capability, or -1 if the capability is not found.

        uses of tgetnum():
            The tgetnum() function is used to get the value of a terminal capability number. It is useful when you want to access the capabilities of the terminal, such as the number of columns and rows or the control sequences for cursor movement. For example, you can use tgetnum() to get the number of columns and rows of the terminal and use them to control the behavior of the terminal.

        example of tgetnum():
            int cols = tgetnum("co");
            int rows = tgetnum("li");
            printf("Number of columns: %d\n", cols);
            printf("Number of rows: %d\n", rows);
            The above code gets the number of columns and rows of the terminal and displays them to the user. The tgetnum() function returns the value of the terminal capability, or -1 if the capability is not found.

💥 tgetstr():
        The tgetstr function in C is part of the <curses.h> header and is used to get the value of a terminal capability string. It returns a pointer to a string containing the terminal capability, or NULL if the capability is not found.

        char *tgetstr(const char *id, char **area);

        Parameters:
            id: The name of the terminal capability string.
            area: A pointer to a buffer where the terminal capability string will be stored.
        The tgetstr() function returns a pointer to a string containing the terminal capability, or NULL if the capability is not found.

        uses of tgetstr():
            The tgetstr() function is used to get the value of a terminal capability string. It is useful when you want to access the capabilities of the terminal, such as the control sequences for cursor movement or text formatting. For example, you can use tgetstr() to get the terminal capability string for moving the cursor and use it to control the behavior of the terminal.

        example of tgetstr():
            char *cursor_up = tgetstr("up", NULL);
            if (cursor_up != NULL) {
                printf("Cursor up sequence: %s\n", cursor_up);
            } else {
                printf("Cursor up sequence not found\n");
            }
            The above code gets the terminal capability string for moving the cursor up and displays it to the user. The tgetstr() function returns a pointer to a string containing the terminal capability, or NULL if the capability is not found.
    
💥 tgoto():
        The tgoto function in C is part of the <curses.h> header and is used to expand a terminal capability string. It returns a pointer to a string containing the expanded capability.

        char *tgoto(const char *cap, int col, int row);

        Parameters:
            cap: The terminal capability string to expand.
            col: The column number.
            row: The row number.
        The tgoto() function returns a pointer to a string containing the expanded capability.

        uses of tgoto():
            The tgoto() function is used to expand a terminal capability string. It is useful when you want to access the capabilities of the terminal, such as the control sequences for cursor movement or text formatting. For example, you can use tgoto() to expand the terminal capability string for moving the cursor and use it to control the behavior of the terminal.

        example of tgoto():
            char *cursor_up = tgetstr("up", NULL);
            char *expanded = tgoto(cursor_up, 0, 0);
            printf("Expanded cursor up sequence: %s\n", expanded);
            The above code gets the terminal capability string for moving the cursor up, expands it with tgoto(), and displays the expanded capability to the user. The tgoto() function returns a pointer to a string containing the expanded capability.
  
💥 tputs():
        The tputs function in C is part of the <curses.h> header and is used to output a terminal capability string. It returns 0 on success and -1 on failure.

        int tputs(const char *str, int affcnt, int (*putc)(int));

        Parameters:
            str: The terminal capability string to output.
            affcnt: The number of lines affected by the operation.
            putc: A pointer to a function that outputs a character.
        The tputs() function returns 0 on success and -1 on failure.

        uses of tputs():
            The tputs() function is used to output a terminal capability string. It is useful when you want to access the capabilities of the terminal, such as the control sequences for cursor movement or text formatting. For example, you can use tputs() to output the terminal capability string for moving the cursor and use it to control the behavior of the terminal.

        example of tputs():
            char *cursor_up = tgetstr("up", NULL);
            if (tputs(cursor_up, 1, putchar) == -1) {
                perror("tputs");
                return EXIT_FAILURE;
            }
            The above code gets the terminal capability string for moving the cursor up and outputs it to the terminal using tputs(). The tputs() function returns 0 on success, or -1 on failure.

