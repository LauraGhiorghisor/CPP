
//
//  BalancedDelimiterCheck.cpp
//  SE2
//
//  Created by Laura Ghiorghisor on 22/04/2020.
//  Copyright © 2020 Laura Ghiorghisor. All rights reserved.
//
/*
 Part of the solution was inspired by :
 https://www.slader.com/discussion/question/a-string-may-use-more-than-one-type-of-delimiter-to-bracket-information-into-blocks-aab70259/
 */
#include "StringStack.hpp"
#include <iostream>
#include<stack>
using namespace std;

// The match method returns true if the parameters are in the format () or [] or {}, false otherwise.
bool match (char a, char b)
{
    if ((a=='(' && b== ')') ||
        (a=='[' && b== ']') ||
        (a=='{' && b== '}'))
    {
        cout<<endl<<"Match between "<<a<<" and "<<b<<"."<<endl;
        return true;
        
    }
    return false;
}


int main()
{
    StringStack stack(100);
//     stack<int> mystack;
    string string;
//  This boolean returns true if the expression is balanced. False if it isn't.
    bool correct=true;
//  User enters string
    cout<<"Please enter a string to be checked:";
    getline(cin, string);

/*
 In order to check for (), {} and [], the following algorithm will be applied:
 - traverse the input string
 - pop every open paranthesis on the stack
 - if any closing paranthesis is found, compare it to the last open one
 - if they match, remove the open one from the stack
 - if they don't match, the string isn't balanced.
 In order to incorporate the checks for "" the logic has been divided in two section, for when the stack is empty and not empty, respectively, as ignoring characters after " presupposes an exisiting top of the stack. Similar logic as for the parantheses applies.
 */

    for (int i=0; i<string.length(); i++)
    {
        char top;

        if (!stack.isEmpty())
        {
            // Checks for ""
            // Read the top of the stack.
            stack.pop(top);  stack.push(top);
            // If the top element is " but the char being read is not ", skip this iteration of the for loop, i.e., ignore any character after the " until a new " is found.
            if (top == '\"' && string[i]!='\"') { continue;}
            // If the top of the stack is not " but the current char is, " is pushed to the stack and the for loop jumps to its next iteration.
            else if (top != '\"' && string[i]=='\"') { stack.push(string[i]); continue;}
            // If the top and the current char are both ", there is a match and the char is popped from the stack. The loop jumps to its next iteration.
            else if (top == '\"' && string[i]=='\"') { cout<<endl<<"Match between \" and \"."<<endl; stack.pop(top); continue;}
            
            // Add open parantheses to stack.
            if (string[i]=='(' || string[i]=='[' || string[i]=='{') stack.push(string[i]);
            else
                // Check for a match for closing parantheses.
                if (string[i]==')' || string[i]==']' || string[i]=='}' )
                {
                    if (match(top, string[i])) stack.pop(top);
                            else
                            {
                                correct=false;
                                break;
                            }
                }
        }
        else
            if (stack.isEmpty())
            {
                // Check for open paranthesses.
                if (string[i]=='(' || string[i]=='[' || string[i]=='{' || string[i]=='\"') stack.push(string[i]);
                    else
                        // Check for closing parantheses. If any are found, and the stack is empty, then the string is not balanced.
                        if (string[i]==')' || string[i]==']' || string[i]=='}')
                          {
                              correct=false;
                              break;
                          }
        }
    }
   

    
/* In order for the string to be balanced, we  need to check for the stack to be empty, as it may contain open parantheses. The algorithm just adds them to the stack. If they have not found their match (haven't been popped), they remain on the stack when the for loop ends. If that is the case, the string is not balanced.
 */
    //  Output result.
    if (correct && stack.isEmpty()) cout<<endl<<endl<<"The string is balanced;"<<endl<<endl;
    else cout<<endl<<endl<<"The string is not balanced"<<endl;

    return 0;
}

