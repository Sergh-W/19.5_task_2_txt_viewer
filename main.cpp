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

        while (!textFile.eof())
        {
            char buffer[20];
            textFile.read(buffer, sizeof(buffer));
            std::string str(buffer, textFile.gcount());
            std::cout << str << std::endl;
        }
    }

    textFile.close();
    return 0;
}

   

