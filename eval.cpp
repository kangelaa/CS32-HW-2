//
//  eval.cpp
//  HW2
//
//  Created by Angela Kan on 2/1/21.
//

#include <iostream>
#include <string>
#include <stack>
#include <cassert>
#include <cctype>
using namespace std;

//HELPER FUNCTION DECLARATIONS
string removeBlanks(string infix);  //returns a string that is infix w/ all the blank characters removed
bool isSyntacticallyValid(string infix);    //checks for syntactically correct infix string


// Evaluates a boolean expression
//   If infix is a syntactically valid infix boolean expression,
//   then set postfix to the postfix form of that expression, set
//   result to the value of the expression (where in that expression,
//   each digit k represents element k of the values array), and
//   return zero.  If infix is not a syntactically valid expression,
//   return 1.  (In that case, postfix may or may not be changed, but
//   result must be unchanged.)
int evaluate(string infix, const bool values[], string& postfix, bool& result){
    infix = removeBlanks(infix);
    if (isSyntacticallyValid(infix)){
        postfix = "";   //initialize postfix to empty
        stack<char> operatorS;  //create empty operator stack
        
        //iterate through infix string and convert to postfix string
        for (int i=0; i<infix.size(); i++){
            switch(infix[i]){
                case '0': case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8': case '9':
                    postfix += infix[i];
                    break;
                case '(':
                case '!':
                    operatorS.push(infix[i]);
                    break;
                case ')':
                    while (operatorS.top() != '('){
                        postfix += operatorS.top();
                        operatorS.pop();
                    }
                    operatorS.pop();
                    break;
                case '|':
                    while (!operatorS.empty() && operatorS.top() != '('){
                        postfix += operatorS.top();
                        operatorS.pop();
                    }
                    operatorS.push(infix[i]);
                    break;
                case '&':
                    while (!operatorS.empty() && operatorS.top() != '(' && operatorS.top() != '|'){
                        postfix += operatorS.top();
                        operatorS.pop();
                    }
                    operatorS.push(infix[i]);
                    break;
            }
        }
        while (!operatorS.empty()){
            postfix += operatorS.top();
            operatorS.pop();
        }
        
        //evaluate postfix expression
        stack<bool> operandS; //create empty operand stack
        for (int i=0; i<postfix.size(); i++){
            if (isdigit(postfix[i])){
                operandS.push(values[postfix[i] - '0']);
            } else if (postfix[i] == '!'){
                bool operand = operandS.top();
                operandS.pop();
                operandS.push(!operand);
            } else {
                bool operand2 = operandS.top();
                operandS.pop();
                bool operand1 = operandS.top();
                operandS.pop();
                if (postfix[i] == '&'){
                    operandS.push(operand1 && operand2);
                } else {
                    operandS.push(operand1 || operand2);
                }
            }
        }
        result = operandS.top();
        
        return 0;
    }
    return 1;
}

//HELPER FUNCTION IMPLEMENTATIONS

string removeBlanks(string infix){
    string noBlanks = "";
    for (int i=0; i<infix.size(); i++){
        if (!isblank(infix[i])){
            noBlanks += infix[i];
        }
    }
    return noBlanks;
}

bool isSyntacticallyValid(string infix){
    if (infix == ""){
        return false;
    }
    if (infix[0] == ')' || infix[0] == '&' || infix[0] == '|'){
        return false;
    }
    if (infix[infix.size()-1] == '(' || infix[infix.size()-1] == '!' || infix[infix.size()-1] == '|' || infix[infix.size()-1] == '&'){
        return false;
    }
    int openParenCount = 0;
    int closeParenCount = 0;
    for (int i=0; i<infix.size(); i++){
        if (!isdigit(infix[i]) && infix[i] != '(' && infix[i] != ')' && infix[i] != '!' && infix[i] != '&' && infix[i] != '|'){
            return false;
        }
        if (infix[i] == '('){
            openParenCount++;
        }
        if (infix[i] == ')'){
            closeParenCount++;
        }
    }
    if (openParenCount - closeParenCount != 0){
        return false;
    }
    for (int i=1; i<infix.size(); i++){
        switch (infix[i]){
            case '(':
                if (isdigit(infix[i-1]) || infix[i-1] == ')'){
                    return false;
                } else {
                    break;
                }
            case ')':
                if (infix[i-1] == '('){
                    return false;
                } else {
                    break;
                }
            case '!':
                if (isdigit(infix[i-1]) || infix[i-1] == ')'){
                    return false;
                } else {
                    break;
                }
            case '&':
                if (infix[i-1] == '(' || infix[i-1] == '!' || infix[i-1] == '&' || infix[i-1] == '|'){
                    return false;
                } else {
                    break;
                }
            case '|':
                if (infix[i-1] == '(' || infix[i-1] == '!' || infix[i-1] == '&' || infix[i-1] == '|'){
                    return false;
                } else {
                    break;
                }
            default:    //this should be if infix[i] is a digit
                if (isdigit(infix[i-1]) || infix[i-1] == ')'){
                    return false;
                }
        }
    }
    return true;
}

//
//int main()
//{
//    bool ba[10] = {
//      //  0      1      2      3      4      5      6      7      8      9
//        true,  true,  true,  false, false, false, true,  false, true,  false
//    };
//    string pf;
//    bool answer;
//    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  answer);
//    assert(evaluate("8|", ba, pf, answer) == 1);
//    assert(evaluate(" &6", ba, pf, answer) == 1);
//    assert(evaluate("4 5", ba, pf, answer) == 1);
//    assert(evaluate("01", ba, pf, answer) == 1);
//    assert(evaluate("()", ba, pf, answer) == 1);
//    assert(evaluate("()4", ba, pf, answer) == 1);
//    assert(evaluate("2(9|8)", ba, pf, answer) == 1);
//    assert(evaluate("2(&8)", ba, pf, answer) == 1);
//    assert(evaluate("(6&(7|7)", ba, pf, answer) == 1);
//    assert(evaluate("x+5", ba, pf, answer) == 1);
//    assert(evaluate("", ba, pf, answer) == 1);
//    assert(evaluate("2|3|4", ba, pf, answer) == 0
//                           &&  pf == "23|4|"  &&  answer);
//    assert(evaluate("2|(3|4)", ba, pf, answer) == 0
//                           &&  pf == "234||"  &&  answer);
//    assert(evaluate("4  |  !3 & (0&3) ", ba, pf, answer) == 0
//                           &&  pf == "43!03&&|"  &&  !answer);
//    assert(evaluate(" 9  ", ba, pf, answer) == 0  &&  pf == "9"  &&  !answer);
//    ba[2] = false;
//    ba[9] = true;
//    assert(evaluate("((9))", ba, pf, answer) == 0  &&  pf == "9"  &&  answer);
//    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  !answer);
//    cout << "Passed all tests" << endl;
//}
