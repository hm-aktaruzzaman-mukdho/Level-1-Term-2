#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <map>
#include <set>
#include <sstream>

using namespace std;
int nodecount = 52;
// map<int, vector<int>> adjlist;
// map<int, vector<int>> transadj;
vector<vector<int>> adjlist(nodecount);
vector<vector<int>> transadj(nodecount);

vector<bool> isvisited;
vector<int> component;
vector<bool> varassignment; // Assigns values to variables

set<char> varset; // Stores the variables used.

stack<int> orderoftraversal;

void dfs_first(int vertex)
{
    isvisited[vertex] = true;

    for (int i : adjlist[vertex])
    {
        if (!isvisited[i])
        {
            dfs_first(i);
        }
    }
    orderoftraversal.push(vertex);
}

void dfs_second(int vertex, int color)
{
    component[vertex] = color;
    for (int i : transadj[vertex])
    {
        if (component[i] == -1)
        {
            dfs_second(i, color);
        }
    }
}

bool Evaluator()
{
    isvisited.assign(nodecount, false);
    component.assign(nodecount, -1);
    varassignment.assign(nodecount, true);

    // cout << "DFS 1 call start.\n";

    for (int i = 0; i < nodecount; i++)
    {
        if (!isvisited[i])
        {
            dfs_first(i);
        }
    }
    // cout << "DFS 1 call ends\n";

    // cout << "Printing orderoftraversals\n";
    //  for (int i = 0; i < nodecount; i++)
    //  {
    //      cout << i << " " << orderoftraversal[i] << "\n";
    //  }

    // cout << " DFS 2 starts\n";

    for (int i = 0, color = 0; i < nodecount; i++)
    {
        int vertex = orderoftraversal.top();
        orderoftraversal.pop();
        if (component[vertex] == -1)
        {
            dfs_second(vertex, color);
            color++;
        }
    }

    // cout << "DFS 2 call ends\n";

    // cout << "Printing components\n";
    // for (int i = 0; i < nodecount; i++)
    // {
    //     cout << "Component " << i << " " << component[i] << endl;
    // }
    // cout << "Value assignment starts\n";

    for (int i = 0; i < nodecount; i += 2)
    {

        {
            if (component[i] == component[i + 1])
            {
                return false;
            }
            varassignment[i / 2] = (component[i] > component[i + 1]);
        }
    }
    // cout<<"Value assignment ends.\n";
    return true;
}

void addexpression(int x1, bool state1, int x2, bool state2)
// Takes in as (a or b) ,(~a or b) format.so just scan and input.
// x1 x2 denotes the variables in the expression.state1 , state 2 denotes if they are present as negated in the expression.
{
    // ASCII value of lowercase alphabet is passed.So first 97 needs to be subtracted.
    x1 = x1 - 97;
    x2 = x2 - 97;

    x1 = 2 * x1 ^ state1;
    x2 = 2 * x2 ^ state2;
    //cout << x1 << " " << x2 << endl;
    int neg_x1 = x1 ^ 1;
    int neg_x2 = x2 ^ 1;
    adjlist[neg_x1].push_back(x2);
    adjlist[neg_x2].push_back(x1);
    transadj[x2].push_back(neg_x1);
    transadj[x1].push_back(neg_x2);
}

int main()
{
    string str;
    FILE *fp1 = freopen("in.txt", "r", stdin);
    FILE *fp2 = freopen("out.txt", "w", stdout);

    int n; // number of input lines
    cin >> n;
    getline(cin, str); // Gets the empty line after the integer.

    for (int i = 0; i < n; i++)
    {
        // cout<<"Expression adding "<<i<<endl;
        getline(cin, str);

        stringstream ss(str);
        string s1, s2;
        if (str.length() <= 2)
        {
            ss >> s1;
            //cout << s1 << endl;
            if (s1.at(0) == '~')
            {
                addexpression((int)s1[1], true, (int)s1[1], true);
                varset.insert(s1[1]);
            }
            else
            {
                addexpression((int)s1[0], false, (int)s1[0], false);
                varset.insert(s1[0]);
            }
        }
        else
        {
            ss >> s1 >> s2;
            //cout << s1 << " " << s2 << endl;
            if ((s1.at(0) != '~') && (s2.at(0) != '~'))
            {
                addexpression((int)s1[0], false, (int)s2[0], false);
                varset.insert(s1[0]);
                varset.insert(s2[0]);
            }
            else if ((s1.at(0)) != '~' && (s2.at(0) == '~'))
            {
                addexpression((int)s1[0], false, (int)s2[1], true);
                varset.insert(s1[0]);
                varset.insert(s2[1]);
            }
            else if ((s1.at(0)) == '~' && (s2.at(0) != '~'))
            {
                addexpression((int)s1[1], true, (int)s2[0], false);
                varset.insert(s1[1]);
                varset.insert(s2[0]);
            }
            else if ((s1.at(0)) == '~' && (s2.at(0) == '~'))
            {
                addexpression((int)s1[1], true, (int)s2[1], true);
                varset.insert(s1[1]);
                varset.insert(s2[1]);
            }
        }
        // cout << "Expression added " << i << endl;
    }

    if (Evaluator())
    {
        for (char ch : varset)
        {
            cout << ch << " ";
            if (varassignment[(int)ch - 97])
            {
                cout << "true\n";
            }
            else
            {
                cout << "false\n";
            }
        }
    }
    else
    {
        cout << "No valid assignment possible.";
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}