/* ---------------------------------------------
    Program 1: Gladiolus
        Prompt for the number of sections and display
        an ASCII gladiolus flower, with the sections centered
        above each other.

    Course: CS 141, Fall 2021. Program 1 due Saturday midnight
    System: Windows using CLion
    Author: Nikos Kotsopulos

    ASCII Graphic:
------------------------------------------------------------------------------------------------
     *___       ___*  .__.    ^__^   ___~       _"------"   --.-------~$          /`\      /'\
     /   \    /   /   /__/    /  /   /  /    //          \    $   ______|        /'/.|    (|-')/
    /     \  /   /    _%_    /  /~~/  /     /  "---/     |   |   /____.        //`//`)   (/''//'
   /   /\  _/   /    /  /   /   __   \     |   /___`   //    `-___     "     |*///~/ )\(//' | |/
  //   /  \     /    /  /   /   /  \   \    \         //     ____|    /     (////~`~ )_( ^//'~//|
 /*___*    \___*    /__/   (___/    \___\     -------     __/._______$     (___.______\_._______)
------------------------------------------------------------------------------------------------

---------------------------------------------
*/
#include <iostream>   // for cin and cout
#include <iomanip>    // for setw. The number in setw(...) is the total of blank spaces including the printed item.

using namespace std;  // so that we don't need to preface every cin and cout with std::

// Entire program is given inside of main(), which is acceptable since this is the first program.
int main() {

    // Display the menu and get the user choice
    int menuOption = 0;
    cout << "Program 1: Gladiolus            \n"
         << "Choose from among the following options:  \n"
         << "   1. Display original graphic  \n"
         << "   2. Display Gladiolus         \n"
         << "   3. Exit the program          \n"
         << "Your choice -> ";
    cin >> menuOption;

    // Handle menu option of 3 to exit
    if (menuOption == 3) {
        exit(0);
    }
        // Handle menu option of 1 to display custom ASCII graphics
    else if (menuOption == 1) {
        cout << setw(8) << " ";
        // Display a line across the top
        for (int i = 0; i < 95; i++) {
            cout << "-";
        }
        cout << endl;
        // Display ASCII graphics for "CS 141".  Yours must be different!
        cout << setw(8) << " "
             << "     *___       ___*  .__.    ^__^   ___~       _\"------\"   --.-------~$          /`\\      /'\\\n"
             << setw(8) << " "
             << "    /   \\    /   /   /__/    /  /   /  /    //          \\    $   ______|        /'/.|    (|-')/\n"
             << setw(8) << " "
             << "   /     \\  /   /    _%_    /  /~~/  /     /  \"---/     |   |   /____.        //`//`)   (/''//'\n"
             << setw(8) << " "
             << "  /   /\\  _/   /    /  /   /   __   \\     |   /___`   //    `-___     \"     |*///~/ )\\(//' | |/\n"
             << setw(8) << " "
             << " /   /  \\     /    /  /   /   /  \\   \\    \\         //     ____|    /     (////~`~ )_( ^//'~//|\n"
             << setw(8) << " "
             << "*___*    \\___*    /__/   (___/    \\___\\     -------     __/._______$     (___.______\\_._______)\n"
             << endl;
        cout << setw(8) << " ";
        // Display a line across the bottom
        for (int i = 0; i < 95; i++) {
            cout << "-";
        }
        cout << endl;
    } //end if( menuOption == 1)  // menu option to display custom graphic

    else if (menuOption == 2) {
        // Prompt for and get the number of flower sections.
        int numberOfSections;
        cout << "Number of sections -> ";
        cin >> numberOfSections;
        int innerSpaces = 0; //Tracking the number of spaces between the first and last parentheses of each row.
        int section = 1; //Tracking the section the outer loop is currently running through
        for (int i = 1; i <= numberOfSections; i++) { //loop to go through the number of sections
            cout << setw(numberOfSections) << "" << "---" << endl;
            innerSpaces = 0;// setting innerSpaces to 0 every time the outer loop iterates since we start in a new section
            for (int r = 1; r <=
                            i; r++) {//loop that outputs parentheses from the start of each section up to and including the middle
                if (r == i) {// if r loop is at middle section it will output an @ symbol in the middle
                    cout << setw(numberOfSections - r) << "" << "(" << setw(i) << "" << "@" << setw(i + 1) << ")"
                         << endl;
                    innerSpaces += 2;
                } else {
                    cout << setw(numberOfSections - r) << "" << "(" << setw(3 + innerSpaces) << "" << ")" << endl;
                    innerSpaces += 2;
                }
            }
            if (i >= section) { // when to start printing bottom part
                for (int r = i - 1; r > 0; r--) { //loop that handles the bottom part of each section
                    cout << setw(numberOfSections - r) << "" << "(" << setw(innerSpaces - 1) << "" << ")" << endl;
                    innerSpaces -= 2;
                }
            }
            section++;
        } //end if( menuOption == 2) // menu option to display building
        cout << setw(numberOfSections) << " ";
        cout << "---" << endl;
        for (int j = 0; j < numberOfSections; j++) { //stem of gladiolus
            if (j % 2 == 0) {// if even print |/
                cout << setw(numberOfSections + 1) << "" << "|/" << endl;
            } else if (j % 2 == 1) { // if odd print \|
                cout << setw(numberOfSections) << "" << "\\|" << endl;
            }
            cout << setw(numberOfSections + 1) << "" << "|" << endl;
        }
        cout << "Exiting" << endl;
        return 0;
    }// end main()
}