#include<iostream>
#include "stack.h"

using namespace std;

//////////////////////////

/*
    Pre: None.
    Post: The stack is initialized to be empty.
*/
Extended_stack::Extended_stack() {
    count = 0;
}


/*
    Pre: None.
    Post: If the Stack is empty,true is returned. Otherwise, false is returned.
*/
bool Extended_stack::empty() const {
    bool outcome = true;
    if (count > 0) outcome = false;
    return outcome;
}


/*
    Pre: None.
    Post: If the Stack is not empty, the top of the Stack is removed. If the Stack is empty,an Error_code of underflow is returned.
*/
Error_code Extended_stack::pop() {
    Error_code outcome = success;
    if (count == 0)
        outcome = underflow;
    else --count;
    return outcome;
}


/*
    Pre: None.
    Post: If the Stack is not empty,the top of the Stack is returned in item. If the Stack is empty an Error code of underflow is returned.
*/
Error_code Extended_stack::top(Stack_entry& item) const {
    Error_code outcome = success;
    if (count == 0) outcome = underflow;
    else item = entry[count - 1];
    return outcome;
}


/*
    Pre: None.
    Post: If the Stack is not full, item is added to the top of the Stack. If the Stack is full, an Error code of overflow is returned and the Stack is left unchanged.
*/
Error_code Extended_stack::push(Stack_entry item) {
    Error_code outcome = success;
    if (count >= maxstack) outcome = overflow;
    else entry[count++] = item;
    return outcome;
}






Error_code copy_stack(Extended_stack& dest, Extended_stack& source)
{
    Error_code outcome = success;
    if (source.size() > 0)
    {
        dest = source;
    }
    else
        outcome = error;
    return outcome;
}


//Sets count to zero 

void Extended_stack::clear()
{
    count = 0;
}


// Checks for maxsize

bool Extended_stack::full() const {

    if (count == maxstack)
    {
        return true;
    }
    else
        return false;
}

int Extended_stack::size() const {
    return count;
}