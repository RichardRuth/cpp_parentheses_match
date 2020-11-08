// Richard Ruth
// COP2535.CM1
// Project 4
// Program reads in a string from text file and uses a single stack to evaluate characters in string to determine
// whether any parentheses in the string are balanced mean each left parentheses is matched with a right parentheses.
// If parenthese are balanced, program displays balanced message. If not, program displays an unbalanced message.

#include <iostream>
#include <fstream>
#include <string>
#include <stack>            // Uses STL stack template implementation for stack
using namespace std;

// Function prototypes

bool ParenthesesCheck(string stringCharacter);
bool ParenthesesMatch(char checkOne, char checkTwo);


int main()
{
    string inputString;     //holds content of input file string
    fstream inputFile;      //input file stream object
    
    // Open the data file for string input
    
    inputFile.open("inputString.txt", ios::in);
    
    if (!inputFile)
    {
        
        // input file not found
        
        cout << "Error opening data file\n";
        return 0;
    }
    else
    {
        // Read the characters from the file into string variable
        
        getline(inputFile, inputString);
        
        // Close the input file
        
        inputFile.close();
    }
    
    // call program functions for each sort or search purpose and assign values to variables
    
    if (ParenthesesCheck(inputString))
    {
        cout << "\nParentheses are balanced.\n";        // balanced if function returns true value
    }
    else
    {
        cout << "\nParentheses are not balanced.\n";    // unbalanced if function returns false value
    }

    return 0;
}

/****************************************************************************
 *                                                                          *
 *                          Parentheses Check                               *
 * This function uses a a single stack to evaluate and compare              *
 * characters in a string for matching left and right parentheses.          *
 * If parentheses balanced, true value is returned. If not, a false         *
 * value is returned by function.                                           *
 *                                                                          *
 ***************************************************************************/

bool ParenthesesCheck(string stringCharacter)
{
    stack<char> textStack;                      // create stack
    int index=0;                                // index used to traverse through string
    
    while(stringCharacter[index])               // traverse string
    {
        if(stringCharacter[index]=='(')
        {
            
            // push left parentheses character to top of stack if found in string
            
            textStack.push(stringCharacter[index]);
        }
        else if(stringCharacter[index]==')')
        {
            if(textStack.empty() || !ParenthesesMatch(textStack.top(),stringCharacter[index]))
            {
                
                // if string contains right parentheses, unbalanced if stack is empty with no left parentheses
                // also unbalanced if function ParenthesesMatch is not a true value
                // return false value if unbalanced
                
                return false;
            }
            else
            {
                
                //  if parentheses matched, pop left parentheses off top of stack
                
                textStack.pop();
            }
        }
        index++;
    }
    
    // if stack empty after traversing string, all parentheses have been paired and expression balanced
    
    return textStack.empty();
}


/****************************************************************************
 *                                                                          *
 *                          ParenthesesMatch                                *
 * This function receives two characters. First character is from top of    *
 * stack and contains a left parentheses. Second character is a right       *
 * parentheses. If matching pair, function returns true. If not, a false    *
 * value is returned.                                                       *
 *                                                                          *
 ***************************************************************************/

bool ParenthesesMatch(char testOne, char testTwo)
{
    if(testOne=='(' && testTwo==')')
        return true;
    else
        return false;
}
