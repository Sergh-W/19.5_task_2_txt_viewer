#include <iostream>
#include <fstream>

int main()
{
    std::ifstream textFile;
    textFile.open("..\\Gagarin.txt", std::ios::binary);

    if (!textFile.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
    }
    else
    {
        std::cout << "File opened." << std::endl;
        std::cout << std::endl;
        int size = 24;
        char buffer[size];

        while (!textFile.eof())
        {
            textFile.read(buffer, size);
            buffer[textFile.gcount()] = '\0';
            std::cout << buffer;
        }

    }

    textFile.close();
    return 0;
}

   

