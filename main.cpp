#include <thread>
#include <filesystem>

#include "daemon.h"
#include "extra.h"

int main(int argc, char *argv[]) {
    // Check if link exists at /etc/init.d and daemonize program
    execute_on_startup();
    daemon();

    // Daemon body
    while (true) {
        // If daemon was started with -b key, stop the program immediately
        if (argv[1] == "-b") {
            syslog(LOG_NOTICE, "Stopping the daemon...");
            closelog();
            exit(EXIT_SUCCESS);
        }

        syslog(LOG_NOTICE, "Clearing the bin...");

        // Clear trash bin, if there is an error, ignore this part
        if (delete_directory_content(
                std::filesystem::path("/home/").concat(getenv("USER")).concat("/.local/share/Trash/files/"))
            && delete_directory_content(
                std::filesystem::path("/home/").concat(getenv("USER")).concat("/.local/share/Trash/info/")))
            syslog(LOG_NOTICE, "The bin was cleared successfully!");

        // Wait for n minutes
        std::this_thread::sleep_for(std::chrono::minutes(atoi(argv[1] + 1)));

        // If daemon was started with -ss key, stop the program after first iteration
        if (argv[2] == "-ss") {
            syslog(LOG_NOTICE, "Stopping the daemon...");
            closelog();
            exit(EXIT_SUCCESS);
        }
    }
}
