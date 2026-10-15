// Task-2-2-en.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <locale>

int main(int argc, char* argv[])
{
    unsigned int prev; // first height
    unsigned int curr; // second height
    unsigned int next_val; // third height
    unsigned int peaks_count = 0; // peak counter
    bool b_done = false; // loop termination flag
    // Setting the Russian locale for the Windows 11 terminal
    system("chcp 65001 >nul"); // Method 1: Execute an external command.
    setlocale(LC_ALL, "russian.65001"); // Method 2: Call a library function.
    std::locale rus_locale = std::locale("russian.65001"); // Method 3: Create a locale variable.
    std::cout.imbue(std::locale::global(rus_locale)); // Method 3: Select the terminal encoding (locale).
    // Data input
    // Display prompt on screen
    std::cout << "Enter radar station data (0 to end input).\r\n";
    // Read the first two elements
    std::cin >> prev; // input first height
    std::cin >> curr; // input second height
    while (!b_done)
    {
        std::cin >> next_val; // input third height
        // If 0 is encountered, input is finished
        b_done = (next_val == 0); // loop termination condition
        // Check the peak condition for the current element
        if (!b_done && (curr > prev) && (curr > next_val))
        {
            peaks_count += 1; // increment peak counter by 1
        }
        // Shift the three-element "window" forward
        prev = curr;
        curr = next_val;
    }
    std::cout << "Number of peaks: " << peaks_count << "\r\n"; // Output to screen
    // Delay screen output until the "Enter" key is pressed
    std::cin.ignore();
    std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
