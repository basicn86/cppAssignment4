// cppAssignment4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Nedim Basic
//14th of November, 2021
//CPP Assignment 3

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const int rowWidth = 45;
const char fillChar = '.';

int main(int argc, char* argv[])
{
    //Display the welcoming message
    cout << "Welcome to my letter counting program!" << endl << endl;


    //initialize the counter variables
    int countA = 0;
    int countE = 0;
    int countI = 0;
    int countO = 0;
    int countU = 0;
    int countTotal = 0;

    //this is the code from the example
    //if there is less than two arguments, then quit the program
    if (argc < 2) {
        cout << "Error with input" << endl;
        return 0;
    }
    
    //open the file
    cout << "Analyzing the file: \"" << argv[1] << "\"" << endl << endl;
    ifstream myFile;
    myFile.open(argv[1]);
    //if the file cannot be opened or does not exist, exit the program
    if (!myFile) {
        cout << "Error with file name" << endl;
        return 0;
    }
    
    //count each character in the file
    //myFile.get() will return true as long as there is content remaining in the file
    //When myFile.get() is called, the current character that is read is being stored in the currentChar variable
    char currentChar = ' ';
    while (myFile.get(currentChar)) {
        switch (currentChar) {
        case 'a':
        case 'A':
            countA++;
            break;
        case 'e':
        case 'E':
            countE++;
            break;
        case 'i':
        case 'I':
            countI++;
            break;
        case 'o':
        case 'O':
            countO++;
            break;
        case 'u':
        case 'U':
            countU++;
            break;
        default:
            break;
        }
    }
    countTotal = countA + countE + countI + countO + countU; //add all the counts to the total count


    //display each count in the 
    cout << setw(rowWidth);
    cout << setfill(fillChar);
    cout << left << "The count of A's:" << countA << endl;
    cout << setw(rowWidth);
    cout << left << "The count of E's:" << countE << endl;
    cout << setw(rowWidth);
    cout << left << "The count of I's:" << countI << endl;
    cout << setw(rowWidth);
    cout << left << "The count of O's:" << countO << endl;
    cout << setw(rowWidth);
    cout << left << "The count of U's:" << countU << endl;
    cout << setw(rowWidth);
    cout << left << "The total count of vowels is:" << countTotal << endl;

    //close the file
    myFile.close();

    return 0; //end the program
}
