#include "Utils.h"
#include <iostream>
#include <limits>

using namespace std;

void utils::clear_console() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int utils::get_input() {
    cin.clear();
    string input;
    cin >> input;
    return stoi(input);
}

void utils::press_key_to_continue() {
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << endl << "Press enter to continue...";
    cin.get();
}

