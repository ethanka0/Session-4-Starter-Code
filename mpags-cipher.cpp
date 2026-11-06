#include <cctype>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char* argv[])
{
    // Create vector of arguments
    const std::vector<std::string> cmdLineArgs { argv, argv + argc };

    // Check for help option
    if (std::find(cmdLineArgs.begin(), cmdLineArgs.end(), "-h") != cmdLineArgs.end() ||
        std::find(cmdLineArgs.begin(), cmdLineArgs.end(), "--help") != cmdLineArgs.end()) {
        std::cout << "HELPPPPPP" << std::endl;
        return 0;
    }

    std::string inputFileName;
    std::string outputFileName;
    // Print command-line arguments
    for (std::size_t i{0}; i < cmdLineArgs.size(); ++i) {
        std::cout << "Argument " << i << " : " << cmdLineArgs.at(i) << std::endl;
        if (cmdLineArgs.at(i) == "--version") {
            std::cout << "Version 0.0.1" << std::endl;
        }
        if (cmdLineArgs.at(i) == "-i") {
            inputFileName = cmdLineArgs.at(i+1);
        }
        if (cmdLineArgs.at(i) == "-o") {
            outputFileName = cmdLineArgs.at(i+1);
        }
    }

    std::cout << "Input file name: " << inputFileName << std::endl;
    std::cout << "Output file name: " << outputFileName << std::endl;

    // Read input one line at a time
    std::string inputLine;

    while (std::getline(std::cin, inputLine)) {

        // Store the transliterated text
        std::string inputText;

        // Loop over each character in the input line
        for (char inputChar : inputLine) {

            // Uppercase alphabetic characters
            if (std::isalpha(static_cast<unsigned char>(inputChar))) {
                inputText += static_cast<char>(
                    std::toupper(static_cast<unsigned char>(inputChar))
                );
                continue;
            }

            // Transliterate digits to English words
            switch (inputChar) {
                case '0':
                    inputText += "ZERO";
                    break;
                case '1':
                    inputText += "ONE";
                    break;
                case '2':
                    inputText += "TWO";
                    break;
                case '3':
                    inputText += "THREE";
                    break;
                case '4':
                    inputText += "FOUR";
                    break;
                case '5':
                    inputText += "FIVE";
                    break;
                case '6':
                    inputText += "SIX";
                    break;
                case '7':
                    inputText += "SEVEN";
                    break;
                case '8':
                    inputText += "EIGHT";
                    break;
                case '9':
                    inputText += "NINE";
                    break;
            }

            // If the character isn't alphabetic or numeric, don't add it
        }

        // Print out the transliterated text
        std::cout << inputText << std::endl;
    }

    return 0;
}