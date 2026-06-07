#include "matching_brackets.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// returns the corresponding closing bracket for c
static char get_closing_bracket(char bracket)
{
    switch (bracket)
    {
    case '(':
        return ')';
    case '[':
        return ']';
    case '{':
        return '}';
    default:
        return bracket;
    }
}

/**
 * @concept just like a stack data structure where the last to come in leaves first, a proper set of brackets also follow this same idea.
 * Brackets that open last need to close first, this solution uses that idea to model a simple stack an track if the brackets have been 
 * closed in proper order and not just whether a bracket has been closed. 
 */

bool is_paired(const char *input)
{
    if(!input) return false;
    // return true for an empty string
    if(!(*input)) return true;

    // maintains the sequence in which the brackets should close.
    char *stack = calloc(1, strlen(input) + 1);
    if(!stack){
        perror("error: allocation failure");
        exit(EXIT_FAILURE);
    } 

    // points at the first bracket that needs to be closed in pair, which is the last character in pair.
    int top = 0;
    while (*input) 
    {
        if (*input == '[' || *input == '{' || *input == '(')
        {
            // keep pos at 0 if it's the first character
            if(strlen(stack) > 0 || top < 0) ++top;
            stack[top] = get_closing_bracket(*input);
        }else if(*input == ']' || *input == '}' || *input == ')'){
            // if the brackets aren't closed in proper order.
            if(*input != stack[top]){
                free(stack);
                return false;
            } 
            stack[top--]= '\0';
        }
        ++input;
    }
    free(stack);
    return top < 0;
}
