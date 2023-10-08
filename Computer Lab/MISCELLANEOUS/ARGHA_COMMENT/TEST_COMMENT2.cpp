#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("TECH2.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    char ch;

    // Read characters one by one and print them along with their positions
    while (inputFile.get(ch)) {
        // Get the current position of the file pointer
        std::streampos position = inputFile.tellg();

        // Print the character along with its position
        std::cout << "Character at position " << position - 1 << ": " << ch << std::endl;
    }

    // Close the file
    inputFile.close();

    return 0;
}
