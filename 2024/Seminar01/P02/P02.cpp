#include <iostream>

enum ExitCode
{
    OK,
    Overflow,
    NullPtr,
    InvalidString
};

struct ResultPair
{
    int64_t number;
    ExitCode exitCode;
};

bool isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

int strLen(const char* str)
{
    if (!str)
        return 0;

    int count = 0;
    while (*str)
    {
        count++;
        str++;
    }

    return count;
}

ResultPair strToNumber(const char* str)
{
    if (!str)
        return { 0, ExitCode::NullPtr };

    int numLen = strLen(str);
    int counter = 1;
    int64_t resultNum = 0;
    int64_t temp = 0;

    while (*str)
    {
        if (!isDigit(*str))
            return { resultNum, ExitCode::InvalidString };

        resultNum *= 10;
        resultNum += (*(str++) - '0');
        if (temp > resultNum)
            return { resultNum, ExitCode::Overflow };

        temp = resultNum;
    }

    return { resultNum, ExitCode::OK };
}

int main()
{
    ResultPair result = strToNumber("12345");

    switch (result.exitCode)
    {
    case ExitCode::InvalidString: 
        std::cout << "Invalid string!"; 
        break;
    case ExitCode::NullPtr: 
        std::cout << "NullPtr!"; 
        break;
    case ExitCode::Overflow: 
        std::cout << "Number caused overflow!"; 
        break;
    case ExitCode::OK: 
        std::cout << "The number is: " << result.number; 
        break;
    }
}

