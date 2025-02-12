#include <iostream>
#include <string>
#include <fstream>


int main() {
    std::ifstream textFile;
    std::string filePath;

    std::cout << "Enter the path to the text file\n"
                 "you want to open (Example: C:\\...\\text.txt):\n";
    std::getline(std::cin, filePath);           // C:\\Text_files\\text.txt
    std::cout << std::endl;

    textFile.open(filePath, std::ios::binary);

    if (!textFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;

    }
    else
    {
        std::cout << "File opened." << std::endl;
        std::cout << std::endl;

        while (!textFile.eof())
        {
            char buffer[100];
            textFile.read(buffer, sizeof(buffer));
            buffer[textFile.gcount()] = '\0';
            std::cout << buffer;
            std::cout << std::endl;
            std::cout << std::endl << "********** Characters read: "
                      << textFile.gcount() << " **********"<< std::endl;
            std::cout << std::endl;
            std::cout <<"Do you want to continue? (Enter any character\n"
                        "to continue, 'q' - quit)" << std::endl;
            char choice;
            std::cin >> choice;
            if (choice == 'q') break;

            /*
            for (int i = 0; i < textFile.gcount(); ++i)
            {
                std::cout << buffer[i];
            }
            */

            /*
            std::string str(buffer, textFile.gcount());
            std::cout << str << std::endl;
            */
        }
    }

    textFile.close();
    return 0;
}
