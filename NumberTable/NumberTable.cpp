#include <iostream>

int main()
{ 
    std::string input;
    std::cin >> input;
    int max = std::stoi(input.substr(1));
    input = input.substr(0, 1);
    
    int tens = max - 9;
    int digits = (tens > 0 ? 9 : max);
    std::cout << (tens > 0 ? "+--+" : "+-+");
    for (int i = 0; i <= digits; i++)
    {
        std::cout << "--+";
    }
    for (int i = 0; i < tens; i++)
    {
        std::cout << "---+";
    }
    std::cout << std::endl << "|" << input << (tens > 0 ? " |" : "|");
    for (int i = 0; i <= max; i++)
    {
        std::cout << i << " |";
    }
    std::cout << std::endl << (tens > 0 ? "+--+" : "+-+");
    for (int i = 0; i <= digits; i++)
    {
        std::cout << "--+";
    }
    for (int i = 0; i < tens; i++)
    {
        std::cout << "---+";
    }
    std::cout << std::endl;
    for (int i = 0; i <= max; i++)
    {
        std::cout << "|" << i << (i < 10 and tens > 0 ? " |" : "|");
        for (int e = 0; e <= max; e++)
        {
            if (input == "+")
            {
                std::string result = std::to_string(i + e);
                result.resize(e < 10 ? 2 : 3, ' ');
                std::cout << result << "|";
            }
        }
        std::cout << std::endl << (tens > 0 ? "+--+" : "+-+");
        for (int i = 0; i <= digits; i++)
        {
            std::cout << "--+";
        }
        for (int i = 0; i < tens; i++)
        {
            std::cout << "---+";
        }
        std::cout << std::endl;
    }
}
