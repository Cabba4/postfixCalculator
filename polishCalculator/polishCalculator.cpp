// polishCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
typedef double Stack_entry;
#include "stack.h"

using namespace std;

void introduction()
{
    cout << "This is a postfix calculator which takes in elements and calculates them by using stacks" << endl;
    cout << "Standard input looks like 1 2 3 + and the output would be 5 " << endl;
}

void instructions()
{
    cout << "The valid commands are:" << endl
        << "[?]push to stack   [=]print top" << endl
        << "[+] [-] [*] [/]   are arithmetic operations" << endl
        << "[x] to switch top 2 entries      [s] to add all elements in the stack" << endl
        << "[a] average of the sum      [%] to calculate remainder "<<endl
        << "[^] Raise to power      [v] Square root     [Q]uit." << endl;
}

char get_command()
{
    char command;
    bool waiting = true;
    cout << "Select command and press <Enter>:";

    while (waiting) {
        cin >> command;
        command = tolower(command);
        if (command == '?' || command == '=' || command == '+' ||
            command == '-' || command == '*' || command == '/' ||
            command == 'q' || command == 'x' || command == 's' ||
            command == 'a' || command == '%' || command == '^' ||
            command == 'v') waiting = false;


        else {
            cout << "Please enter a valid command:" << endl
                << "[?]push to stack   [=]print top" << endl
                << "[+] [-] [*] [/]   are arithmetic operations" << endl
                << "[x] to switch top 2 entries      [s] to add all elements in the stack" << endl
                << "[a] average of the sum      [%] to calculate remainder " << endl
                << "[^] Raise to power      [v] Square root     [Q]uit." << endl;
        }
    }
    return command;
}


bool do_command(char command, Extended_stack& numbers)
/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
      has been applied to the Stack of numbers given by the second parameter.
      A result of true is returned unless command == 'q'.
Uses: The class Stack.
*/

{
    double p, q, temp = 0;
    int size = 0;
    switch (command) {
    case '?':
        cout << "Enter a real number: " << flush;
        cin >> p;
        if (numbers.push(p) == overflow)
            cout << "Warning: Stack full, lost number" << endl;
        break;

    case '=':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else
            cout << p << endl;
        break;

    case '+':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q + p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case '-':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q - p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case '*':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q * p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case '/':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                if (numbers.push(q / p) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case 'x':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            //cout << "Here is p" << p << endl;
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }
        //
            else {
                numbers.push(p);
                numbers.top(p);
                numbers.pop();
                if (numbers.top(q) == underflow)
                {
                    cout << "Stack should have more than one number" << endl;
                }
                else
                {
                    numbers.top(q);
                    numbers.pop();
                    numbers.push(p);
                    numbers.push(q);
                }
            }
        }
        break;
        //   Add options for further user commands.

    case 's':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }
            else {
                numbers.push(p);
                while (!numbers.empty())
                {
                    numbers.top(p);
                    temp += p;
                    numbers.pop();
                }
                numbers.push(temp);
            }

        }
        break;

    case 'a':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }
            else {
                numbers.push(p);
                size = numbers.size();
                while (!numbers.empty())
                {
                    numbers.top(p);
                    temp += p;
                    numbers.pop();
                }
                numbers.push(temp/size);
            }

        }
        break;


    case '%':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                temp = fmod(q, p);
                if (numbers.push(temp) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case '^':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
                cout << "Stack has just one entry" << endl;
                numbers.push(p);
            }

            else {
                numbers.pop();
                temp = pow(q, p);
                if (numbers.push(temp) == overflow)
                    cout << "Warning: Stack full, lost result" << endl;
            }
        }
        break;

    case 'v':
        if (numbers.top(p) == underflow)
            cout << "Stack empty" << endl;
        else {
            numbers.top(p);
            temp = sqrt(p);
            if (numbers.push(temp) == overflow)
                cout << "Warning: Stack full, lost result" << endl;
            }
        break;

    case 'q':
        cout << "Calculation finished.\n";
        return false;
    }
    return true;
}

int main()
/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/

{
    Extended_stack stored_numbers;
    introduction();
    instructions();
    while (do_command(get_command(), stored_numbers));
}





