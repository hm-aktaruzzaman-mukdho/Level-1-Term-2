#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int main()
{
    char str[100];
    scanf("%s", str);
    int character[26];
    for (int i = 0; i < 26; i++)
    {
        character[i] = 0;
    }
    int i = 0;
    while (str[i])
    {
        character[str[i] - 97]++;
        i++;
    }
    int flag = 1;
    for (int j = 0; j < 26; j++)
    {
        if (character[j] % 2 != 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
    // printf("%c", 97);
    /*for(int j=0;j<26;j++)
    {
        cout<<character[j]<<endl;
    }*/
    for (int k = 0; k < 2; k++)
    {
        for (int j = 0; j < 26; j++)
        {
            if(character[j]!=0)
                printf("%c", j + 97);
        }
        cout << endl;
    }

    return 0;
}
