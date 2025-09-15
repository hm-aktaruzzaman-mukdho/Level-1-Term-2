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
    return true;
}

bool noextraoperator(string infix)
{
    int exceptions = 13;
    string str[exceptions];
    str[0] = "++";
    str[1] = "/0";
    str[2] = "**";
    str[3] = "//";
    str[4] = "-+";
    str[5] = "/0";
    str[6] = "*/";
    str[7] = "/*";
    str[8] = "+/";
    str[9] = "-/";
    str[10] = "+*";
    str[11] = "-*";
    str[12] = "/0";
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
    c = infix[0];
    if (c == '*' || c == '/')
    {
        state = false;
    }
    return state;
}

bool infixvalidity(string infixexpression)
{
    if (braket_balance(infixexpression) && noextraoperator(infixexpression))
    {
        cout << "       Syntactically Valid Expression" << endl;
        return true;
    }
    else
    {
        cout << "   Syntactically Invalid Expression" << endl;
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

    // Removes extra zero.function needs to be edited
    k = 0;
    while (k < infix.length() - 1)
    {
        if(isdigit(infix[k])&&(!iszero(infix[k])))
        {
            while(isdigit(infix[k]))
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

    k = 0;
    while (k < infix.length() - 1)
    {
        // Convert digit(expression)=digit*(expression)
        if (isdigit(infix[k]) && (infix[k + 1] == '('))
        {
            infix.insert(k + 1, "*");
        }
        // Convert (expression)digit=(expression)*digit
        else if ((infix[k] == ')') && isdigit(infix[k + 1]))
        {
            infix.insert(k + 1, "*");
        }
        // Converts (expression)(expression)=(expression)*(expression)
        else if ((infix[k] == ')') && (infix[k + 1] == '('))
        {
            infix.insert(k + 1, "*");
        }
        // Converts (-expression)=(0-expression).
        else if ((infix[k] == '(') && (infix[k + 1] == '-'))
        {
            infix.insert(k + 1, "0");
        }
        // Converts () into (1)
        else if ((infix[k] == '(') && (infix[k + 1] == ')'))
        {
            infix.insert(k + 1, "1");
        }
        else if((infix[k]=='-')&&(isdigit(infix[k+1])))
        {
            size_t pos1=k;
            size_t pos2=pos1+1;
            while(isdigit(infix[pos2]))
                pos2++;
            pos2+=2;
            infix.insert(pos1,"(0");
            infix.insert(pos2,")");
            k=pos2;
        }
        // else if (((infix[k] == '+') || (infix[k] == '-')) && ((infix[k + 1] == '+') || (infix[k + 1] == '-')))
        // {
        //     infix.insert(k + 1, "*");//code for validating ++ +- -- -+
        // }
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

    string str[4];
    str[0] = "/-";
    str[1] = "*-";
    str[2] = "/+";
    str[3] = "*+";

    for (int i = 0; i < 4; i++)
    {
        size_t pos1 = 0;
        size_t pos2;
        while (pos1 < infix.length())
        {
            pos1++;
            pos1 = infix.find(str[i], pos1);
            if (pos1 != string::npos)
            {
                pos2 = pos1 + 2;
                while (isdigit(infix[pos2]))
                {
                    pos2++;
                }
                infix.insert(pos1 + 1, "(0");
                infix.insert(pos2 + 2, ")");
            }
        }
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
    Stack<float> operand;
    int flag=1;

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

            // cout<<p2<<" "<<p1<<endl;
            if (postfix[i] == '+')
                operand.push((p1 + p2));
            if (postfix[i] == '-')
                operand.push((p2 - p1));
            if (postfix[i] == '*')
                operand.push((p2 * p1));
            if (postfix[i] == '/')
            {
                if (p1 == 0)
                {
                    //cout << "Mathematically invalid expression" << endl;
                    flag=0;
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
    if(flag)
        result = to_string(operand.pop());
    else
        result = "   Mathematically invalid expression!";
    return result;
}
int main()
{
    while (1)
    {
        cout << "Enter your mathematical expression:";
        string infixexpression;
        getline(cin, infixexpression);
        infixexpression = convertinfix(infixexpression);
        cout << infixexpression << endl;
        bool state=infixvalidity(infixexpression);
        if(state)
        {
            string postfix = infixToPostfix(infixexpression);
            //cout << postfix << endl;
            cout <<"Result of that expression:"<< postdfix_evaluation(postfix) << endl<<endl;
        }
    }
    return 0;
}