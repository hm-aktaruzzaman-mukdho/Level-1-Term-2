#include <iostream>
#include <string>
#include <bits/stdc++.h>

#include "Stack.cpp"

using namespace std;

bool isoperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    else
        return false;
}

bool iszero(char c)
{
    if (c == '0')
        return true;
    else
        return false;
}

bool braket_balance(string infixexpression)
{
    Stack<char> braket;
    for (int i = 0; i < infixexpression.length(); i++)
    {
        if (infixexpression[i] == '(')
        {
            braket.push(infixexpression[i]);
        }
        if (infixexpression[i] == ')')
        {
            if (braket.isEmpty())
            {
                return false;
            }
            else
                braket.pop();
        }
    }
    if (!braket.isEmpty())
    {
        return false;
    }
    else
        return true;
}

bool noextraoperator(string infix)
{
    int exceptions = 18;
    string str[exceptions];
    str[0] = "++";
    str[1] = "+*";
    str[2] = "+/";
    str[3] = "-+";
    str[4] = "-*";
    str[5] = "-/";
    str[6] = "*+";
    str[7] = "**";
    str[8] = "*/";
    str[9] = "/+";
    str[10] = "/*";
    str[11] = "//";
    str[12] = "(+)";
    str[13] = "(-)";
    str[14] = "(*)";
    str[15] = "(/)";
    str[16] = "/0";
    str[17] = "()";
    bool state = true;
    for (int i = 0; i < exceptions; i++)
    {
        if (infix.find(str[i]) != string::npos)
        {
            state = false;
            break;
        }
    }

    // Any operator on the last position
    char c = infix[infix.length() - 1];
    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        state = false;
    }

    // Alphabet in expression is invalid
    for (int i = 0; i < infix.length(); i++)
    {
        if (isalpha(infix[i]))
        {
            state = false;
            break;
        }
    }

    //* or / on first position implies invalid
    if (infix[0] == '*' || infix[0] == '/')
    {
        state = false;
    }
    return state;
}

bool infixvalidity(string infixexpression)
{
    if (braket_balance(infixexpression) && noextraoperator(infixexpression))
    {
        cout << "       Syntactically Valid Expression :)" << endl;
        return true;
    }
    else
    {
        cout << "    !!!Syntactically Invalid Expression!!!  :')" << endl;
        return false;
    }
}

string convertinfix(string infix)
{

    // Removes spaces from expression
    int k = 0;
    while (k < infix.length())
    {

        if (isspace(infix[k]))
        {
            infix.erase(k, 1);
        }
        else
            k++;
    }

    // Removes extra zero.
    k = 0;
    while (k < infix.length() - 1)
    {
        if (isdigit(infix[k]) && (!iszero(infix[k])))
        {
            while (isdigit(infix[k]))
            {
                k++;
            }
        }
        else if ((infix[k] == '0') && isdigit(infix[k + 1]))
        {
            infix.erase(k, 1);
        }
        else
            k++;
    }


    //Removes extra - signs to simplify urinary - calculation
    k=0;
    while(k<infix.length()-1)
    {
        size_t pos;
        pos=infix.find("---");
        if(pos!=string::npos)
            infix.erase(pos,2);
        k++;
    }


    k = 0;
    while (k < infix.length() - 1)
    {
        // Convert digit(expression)=digit*(expression)
        if (isdigit(infix[k]) && (infix[k + 1] == '('))
        {
            infix.insert(k + 1, "*");
            k++;
        }
        // Convert (expression)digit=(expression)*digit
        else if ((infix[k] == ')') && isdigit(infix[k + 1]))
        {
            infix.insert(k + 1, "*");
            k++;
        }
        // Converts (expression)(expression)=(expression)*(expression)
        else if ((infix[k] == ')') && (infix[k + 1] == '('))
        {
            infix.insert(k + 1, "*");
            k++;
        }
        // Converts () into (1) ->Syntactically error.
        // else if ((infix[k] == '(') && (infix[k + 1] == ')'))
        // {
        //     infix.insert(k + 1, "1");
        // }
        // Converts (-expression)=(0-expression).
        else if ((infix[k] == '(') && (infix[k + 1] == '-'))
        {
            infix.insert(k + 1, "0");
            k++;
        }
        else if ((isoperator(infix[k])) && (infix[k + 1] == '-') && (isdigit(infix[k + 2])))
        {
            size_t pos1 = k + 1;
            size_t pos2 = pos1 + 1;
            while (isdigit(infix[pos2]))
                pos2++;
            infix.insert(pos2, ")");
            infix.insert(pos1, "(0");
            
            k++;
        }
        /*Convert -( expression ) to (0-(expression)) . This must be evaluated after (- is converted to (0-*/
        else if(isoperator(infix[k])&&(infix[k+1]=='-')&&(infix[k+2]=='('))
        {
            k++;
            infix.insert(k,"(0");
            int i=k+3;//i can never be k.Because there is an extra ( inserted at k.
                      //So if i is k the below braket balance point finding will fail.
            Stack<char> braket;
            while(1)
            {
                char temp = infix[i];
                if(temp=='(')
                {
                    braket.push(temp);
                    i++;
                }
                else if(temp==')')
                {
                    braket.pop();
                    i++;
                    if(braket.isEmpty())
                    {
                        break;
                    }
                }
                else
                {
                    i++;
                }

            }
            infix.insert(i,")");
            k=k+3;//This statement is very crucial.Otherwise infinite loop occars.
                  //New k should denote the position of (
            
        }
        else if ((isoperator(infix[k])) && (infix[k + 1] == '+') && (isdigit(infix[k + 2])))
        {
            size_t pos1 = k + 1;
            size_t pos2 = pos1 + 1;
            while (isdigit(infix[pos2]))
                pos2++;
            infix.insert(pos2, ")");
            infix.insert(pos1, "(0");
            
            k++;
        }
        /*Convert +( expression ) to (0+(expression)) . This must be evaluated after (+ is converted to (0+*/
        else if(isoperator(infix[k])&&(infix[k+1]=='+')&&(infix[k+2]=='('))
        {
            k++;
            infix.insert(k,"(0");
            int i=k+3;//i can never be k.Because there is an extra ( inserted at k.
                      //So if i is k the below braket balance point finding will fail.
            Stack<char> braket;
            while(1)
            {
                char temp = infix[i];
                if(temp=='(')
                {
                    braket.push(temp);
                    i++;
                }
                else if(temp==')')
                {
                    braket.pop();
                    i++;
                    if(braket.isEmpty())
                    {
                        break;
                    }
                }
                else
                {
                    i++;
                }

            }
            infix.insert(i,")");
            k=k+3;//This statement is very crucial.Otherwise infinite loop occars.
                  //New k should denote the position of (
            
        }
        else
        {
            k++;
        }
    }

    
    // if started with + - add 0 in front to calculate the result.
    char c = infix[0];
    if ((c == '+' || c == '-'))
    {
        infix.insert(0, "0");
    }

    return infix;
}

int precedance(char c)
{
    if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(string infix)
{

    Stack<char> operatorstack;
    string result;

    for (int i = 0; i < infix.length();)
    {
        char c = infix[i];
        if (isdigit(c))
        {
            int pos = i, l;
            while (isdigit(infix[i]))
            {
                ++i;
            }
            l = i - pos;
            string temp = infix.substr(pos, l);
            // cout<<temp<<endl;
            result = result + "|" + temp + "|";
        }
        else if (c == '(')
        {
            operatorstack.push('(');
            i++;
        }
        else if (c == ')')
        {
            while (operatorstack.topValue() != '(')
            {
                result += operatorstack.topValue();
                operatorstack.pop();
            }
            operatorstack.pop();
            i++;
        }
        else
        {
            while (!operatorstack.isEmpty() && precedance(infix[i]) <= precedance(operatorstack.topValue()))
            {
                result += operatorstack.topValue();
                operatorstack.pop();
            }
            operatorstack.push(c);
            i++;
        }
    }
    while (!operatorstack.isEmpty())
    {
        result += operatorstack.topValue();
        operatorstack.pop();
    }
    return result;
}

string postdfix_evaluation(string postfix)
{
    string result;
    Stack<double> operand;
    int flag = 1;

    for (int i = 0; i < postfix.length(); /*Needs to be modified for multidigit number*/)
    {
        if (isdigit(postfix[i]))
        {
            int pos = i;
            while (postfix[i] != '|')
            {
                ++i;
            }
            string temp = postfix.substr(pos, i - pos);
            // cout<<temp<<endl;
            operand.push(stoi(temp));
        }
        if (isoperator(postfix[i]))
        {
            float p1 = operand.topValue();
            operand.pop();
            float p2 = operand.topValue();
            operand.pop();
            if (postfix[i] == '+')
                operand.push((p2 + p1));
            if (postfix[i] == '-')
                operand.push((p2 - p1));
            if (postfix[i] == '*')
                operand.push((p2 * p1));
            if (postfix[i] == '/')
            {
                if (p1 == 0)
                {
                    flag = 0;
                    break;
                }
                else
                    operand.push(p2 / p1);
            }
            i++;
        }
        else
            i++;
    }
    if (flag)
    {
        double temp=operand.topValue();
        result = to_string(temp);
    }
    else
        result = "   Mathematically invalid expression!";
    return result;
}
int main()
{
    while (1)
    {
        cout << "Enter mathematical expression : ";
        string infixexpression;
        getline(cin, infixexpression);

        if (infixexpression == "exit")
            exit(0);

        bool state = infixvalidity(infixexpression);
        infixexpression = convertinfix(infixexpression);
        cout <<"Converted formal infix    : "<< infixexpression << endl;
        if (state)
        {
            string postfix = infixToPostfix(infixexpression);
            cout << "Convrted to postfix       : " << postfix << endl;
            cout << "Result of that expression : " << postdfix_evaluation(postfix) << endl
                 << endl;
        }
    }
    return 0;
}