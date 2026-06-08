#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

void listFiles() {
    for (const auto& entry : fs::directory_iterator("/data")) {
        std::cout << entry.path().filename() << std::endl;
    }
}

void createFile() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    std::ofstream file("/data/" + filename);
    file.close();

    std::cout << "File created.\n";
}

void deleteFile() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> filename;

    if (fs::remove("/data/" + filename))
        std::cout << "File deleted.\n";
    else
        std::cout << "File not found.\n";
}

int main() {
    int choice;

    while (true) {
        std::cout << "\n=== File Manager ===\n";
        std::cout << "1. List Files\n";
        std::cout << "2. Create File\n";
        std::cout << "3. Delete File\n";
        std::cout << "4. Exit\n";
        std::cout << "Choice: ";

        std::cin >> choice;

        switch (choice) {
            case 1: listFiles(); break;
            case 2: createFile(); break;
            case 3: deleteFile(); break;
            case 4: return 0;
            default: std::cout << "Invalid choice\n";
        }
    }
}