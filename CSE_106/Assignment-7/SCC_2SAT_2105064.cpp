#include<bits/stdc++.h>
using namespace std;

int nodecount = 52;
map<int, vector<int>> adjlist,transadj;

vector<bool> isvisited,varassignment;
vector<int> component; // Assigns values to variables
set<char> varset; // Stores the variables used.
stack<int> orderoftraversal;//Stores the order at which the dfs_first travarsed the graph.

void dfs_first(int vertex)
{
    isvisited[vertex] = true;
    for (int i : adjlist[vertex])
        if (!isvisited[i])
            dfs_first(i);
    orderoftraversal.push(vertex);
}

void dfs_second(int vertex, int color)
{
    component[vertex] = color;//Marks the SCC component of every graph.
    for (int i : transadj[vertex])
        if (component[i] == -1)
            dfs_second(i, color);
}

bool Evaluator()
{
    isvisited.assign(nodecount, false);
    component.assign(nodecount, -1);
    varassignment.assign(nodecount, true);
    //First DFS of kosaraju
    for (int i = 0; i < nodecount; i++)
        if (!isvisited[i])
            dfs_first(i);
    //Second DFS of kosaraju.It marks the scc component count to every node.
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
    //Check if x and ~x in same scc.if not assign value;
    for (int i = 0; i < nodecount; i += 2)
    {
            if (component[i] == component[i + 1])
                return false;
            varassignment[i / 2] = (component[i] > component[i + 1]);
    }
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
        getline(cin, str);

        stringstream ss(str);
        string s1, s2;

        if (str.length() <= 2)
        {
            ss >> s1;
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
    }
    if (Evaluator())
    {
        for (char ch : varset)
        {
            cout << ch << " ";
            if (varassignment[(int)ch - 97])
                cout << "true\n";
            else
                cout << "false\n";
        }
    }
    else
        cout << "No valid assignment possible.";
    fclose(fp1);
    fclose(fp2);
    return 0;
}