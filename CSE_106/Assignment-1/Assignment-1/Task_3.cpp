#include <iostream>
#include <cstring>
#include "Linked_list_double.cpp"
// #include "arr.cpp"

using namespace std;

int main()
{
	int X, Y, Z;
	char operation[10];
	cin >> X >> Y >> Z;
	// X=Total number of cars
	// Y=number of cars.
	// Z=number of parking spot in a garage.
	//  cout << X << endl;
	//  cout << Y << endl;
	//  cout << Z << endl;
	linkedlist<int> garage[Y];

	for (int i = 0; i < Y; i++)
	{
		garage[i].init(Z);
	}
	for (int i = 0; i < Y; i++)
	{
		garage[i].printlist();
	}
	for (int m = 0; m < Y;)
	{
		int g, inlen;
		cin >> g >> inlen;
		g--;
		if (g < Y)
		{
			if (inlen <= Z)
			{
				for (int i = 0; i < inlen; i++)
				{
					int temp, lastval;
					cin >> temp;
					if (temp <= X)
					{
						garage[g].moveToEnd();
						garage[g].insert(temp);
						garage[g].moveToEnd();
						lastval = garage[g].remove();
						garage[g].insert(lastval);
						garage[g].moveToPos(0);
					}
					else
						cout<<"Invalid car label."<<endl;
				}
				m++;
			}
			else
				cout << "Garage capacity exceeded.";
		}
		else
		{
			cout << "Garage number does not exist.\nEnter with valid garage number." << endl;
		}
	}
	// code for printing cars in garages
	for (int i = 0; i < Y; i++)
	{
		garage[i].printlist();
	}

	while (1)
	{
		cin >> operation;
		// cout << operation;
		if (strcmp(operation, "end") == 0)
		{
			break;
		}
		else if (strcmp(operation, "req") == 0)
		{
			int curgar, leastlabel;

			// printing cars in garage
			//  for (int i = 0; i < Y; i++)
			//  {
			//  	cout<<"garage length"<<garage[i].length()<<endl;
			//  }

			int flag = 0;
			int carpos = 0;
			// selecting garage
			for (int i = 0; i < Y; i++)
			{
				if ((garage[i].length() > 0))
				{

					curgar = i;
					flag = 1;
					break;
				}
			}
			// cout <<"Current garage"<< curgar << endl;
			// cout<<"flag"<<flag<<endl;
			if (flag == 1)
			{

				garage[curgar].moveToStart();
				leastlabel = garage[curgar].getValue();
				int l = garage[curgar].length();
				for (int i = 0; i < l; i++)
				{
					if (leastlabel >= garage[curgar].getValue())
					{
						leastlabel = garage[curgar].getValue();
						carpos = garage[curgar].currPos();
						// cout<<"Current pos 1"<<garage[curgar].currPos()<<endl;
					}
					garage[curgar].next();
				}
				cout << "Current pos" << carpos << endl;
				garage[curgar].moveToPos(carpos);
				int reqcar = garage[curgar].remove();
				for (int i = 0; i < Y; i++)
				{
					garage[i].printlist();
				}
				cout << "Response to your request->Car:" << reqcar << endl;
			}
			else
			{
				cout << "All garage is empty" << endl;
			}
		}
		else if (strcmp(operation, "ret") == 0)
		{
			// cout<<"return";
			int carnum;
			cin >> carnum;
			int curgar = Y - 1;
			int flag = 0;

			for (int i = Y - 1; i >= 0; i--)
			{
				int l = garage[i].length();
				if (l < Z)
				{
					curgar = i;
					flag = 1;
					break;
				}
			}

			if (flag == 1)
			{
				int carpos = 0;
				garage[curgar].moveToStart();
				int maxlabel = garage[curgar].getValue();
				int l = garage[curgar].length();
				for (int i = 0; i < l; i++)
				{
					if (maxlabel <= garage[curgar].getValue())
					{
						maxlabel = garage[curgar].getValue();
						carpos = i;
					}
					garage[curgar].next();
				}
				garage[curgar].moveToPos(carpos);
				garage[curgar].insert(carnum);
				garage[curgar].next();
				int temp = garage[curgar].remove();
				garage[curgar].moveToPos(carpos);
				garage[curgar].insert(temp);
				for (int i = 0; i < Y; i++)
				{
					garage[i].printlist();
				}
			}
			else
			{
				cout << "All garage is full";
			}
		}
	}

	return 0;
}