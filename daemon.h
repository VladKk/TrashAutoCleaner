#ifndef TRASHAUTOCLEANER_DAEMON_H
#define TRASHAUTOCLEANER_DAEMON_H

#include <csignal>
#include <cstdlib>

#include <unistd.h>
#include <syslog.h>

#include <sys/stat.h>

static void daemon() {
    pid_t pid;

    // Fork off the parent process
    pid = fork();

    // An error occurred
    if (pid < 0)
        exit(EXIT_FAILURE);

    // Ok, let the parent terminate
    if (pid > 0)
        exit(EXIT_SUCCESS);

    // The child process becomes session leader
    if (setsid() < 0)
        exit(EXIT_FAILURE);

    // Ignore signals
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);

    // Fork off the second time
    pid = fork();

    // An error occurred
    if (pid < 0)
        exit(EXIT_FAILURE);

    // Ok, let the parent terminate
    if (pid > 0)
        exit(EXIT_SUCCESS);

    // Set new file permissions
    umask(0);

    // Change the working directory on the root directory
    chdir("/");

    // Close all open file descriptors
    int x;
    for (x = sysconf(_SC_OPEN_MAX); x >= 0; x--)
        close(x);

    // Open the log file
    openlog("trash_auto_cleaner", LOG_PID, LOG_DAEMON);
}

#endif //TRASHAUTOCLEANER_DAEMON_H
