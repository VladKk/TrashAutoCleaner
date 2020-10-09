#ifndef TRASHAUTOCLEANER_EXTRA_H
#define TRASHAUTOCLEANER_EXTRA_H

#include <iostream>

static void execute_on_startup() {
    // Check if file exists and it is a symlink
    if (std::filesystem::exists(std::filesystem::path("/etc/init.d/trash_auto_cleaner"))
        && std::filesystem::is_symlink(std::filesystem::path("/etc/init.d/trash_auto_cleaner"))) {
        std::cout << "Good link!" << std::endl;
        return;
    }

    // If it is not a symlink, exit with failure
    if (!std::filesystem::is_symlink(std::filesystem::path("/etc/init.d/trash_auto_cleaner"))) {
        std::cerr << "Broken link!" << std::endl;
        exit(EXIT_FAILURE);
    }

    // If symlink does not exist, create it in /etc/init.d
    if (!std::filesystem::exists(std::filesystem::path("/etc/init.d/trash_auto_cleaner"))) {
        std::cout << "Creating symlink.." << std::endl;

        std::filesystem::create_symlink(
                std::filesystem::path(std::filesystem::current_path().concat("/TrashAutoCleaner")),
                std::filesystem::path("/etc/init.d/trash_auto_cleaner")
        );

        exit(EXIT_SUCCESS);
    }
}

static bool delete_directory_content(const std::string &dir_path) {
    // Remove all directory content without removing itself
    for (const auto &entry : std::filesystem::directory_iterator(dir_path)) {
        if (!std::filesystem::remove_all(entry.path()))
            return false;
    }

    return true;
}

#endif //TRASHAUTOCLEANER_EXTRA_H
