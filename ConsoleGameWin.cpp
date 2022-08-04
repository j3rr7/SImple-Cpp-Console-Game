// ConsoleGameWin.cpp : Simple Implementation for c++ game for beginner
// ABSOLUTELY NOT FOOL PROOF AND MESSY CODE PLEASE REFACTOR
//

#include <iostream>

// disable unused import
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN 
#include <Windows.h>

#include <thread>
#include <time.h>
#include <random>

// getting keyboard input
#include <conio.h>

// wrapper for clear screen in c++
void cls()
{
    // Get the Win32 handle representing standard output.
    // This generally only has to be done once, so we make it static.
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD topLeft = { 0, 0 };

    // std::cout uses a buffer to batch writes to the underlying console.
    // We need to flush that to the console because we're circumventing
    // std::cout entirely; after we clear the console, we don't want
    // stale buffered text to randomly be written out.
    std::cout.flush();

    // Figure out the current width and height of the console window
    if (!GetConsoleScreenBufferInfo(hOut, &csbi)) {
        // TODO: Handle failure!
        abort();
    }
    DWORD length = csbi.dwSize.X * csbi.dwSize.Y;

    DWORD written;

    // Flood-fill the console with spaces to clear it
    FillConsoleOutputCharacter(hOut, TEXT(' '), length, topLeft, &written);

    // Reset the attributes of every character to the default.
    // This clears all background colour formatting, if any.
    FillConsoleOutputAttribute(hOut, csbi.wAttributes, length, topLeft, &written);

    // Move the cursor back to the top left for the next sequence of writes
    SetConsoleCursorPosition(hOut, topLeft);
}

int main()
{
    // random seed
    srand(time(NULL));

    int width, height;
    int food = 0;
    int coords[2];
    int fcoords[2];

    try
    {
        std::cout << "input width: ";
        std::cin >> width;
        std::cout << "\n";

        std::cout << "input height: ";
        std::cin >> height;
        std::cout << "\n";
    }
    catch (const std::exception&)
    {
        std::cout << "Wrong Input";
        return 1;
    }

    // Get random coords with width and height as boundary
    // Hard Coded value
    // +1 for number 1 till height/width
    coords[0] = rand() % height + 1;
    coords[1] = rand() % width + 1;

    fcoords[0] = rand() % height + 1;
    fcoords[1] = rand() % width + 1;

    while (1)
    {
        if (_kbhit()) {
            char in = _getch();
            switch (in) {
                case 'W':
                case 'w':
                    coords[0] -= 1;
                    break;
                case 'S':
                case 's':
                    coords[0] += 1;
                    break;
                case 'A':
                case 'a':
                    coords[1] -= 1;
                    break;
                case 'D':
                case 'd':
                    coords[1] += 1;
                    break;
            }
        }

        //check if coords == fcoords 
        if (coords[0] == fcoords[0] && coords[1] == fcoords[1])
        {
            // do randomise and increment food
            fcoords[0] = rand() % height + 1;
            fcoords[1] = rand() % width + 1;

            food += 1;
        }

        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                // Generate map Game Playing
                if (i == 0 || j == 0 || i == height - 1 || j == width - 1) // boundary
                    std::cout << "#";
                else if (i == coords[0] && j == coords[1]) // print player
                    std::cout << "P";
                else if (i == fcoords[0] && j == fcoords[1]) // print food
                    std::cout << "*";
                else
                    std::cout << " "; // print empty space
            }
            std::cout << "\n";
        }
        std::cout << "Food: " << food << "\n";
        std::cout << "W,A,S,D to move" << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        cls();
    };
}

// IMPORTANT : 
// - No Checking for collision
// - Randomization still not good
// But the basic was there 
// Thanks - Refactored for 4yrs old code