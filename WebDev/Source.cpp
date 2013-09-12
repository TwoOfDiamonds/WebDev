#include <iostream>
#include <queue>
#include <string>

using namespace std;

int to_power_three (int i);
int multiply_by_five (int i);
int minus_ten (int i);
int add_two (int i);
int floor_of_div_by_seven (int i);

int main (int argc, char *argv[])
{
	int i; //numarul dat
	string strI; //pentru a merge mai usor cu getline
	queue<string> functions; //coada cu functiile ce vor fi apelate
	string strPureLine; //string ce va contine input-ul nefinisat
	string toAdd = ""; //string ce va fi adaugat in coada

	cout << "i: ";
	getline(cin, strI);
	i = stoi(strI); //specific C++11

	//cateva informatii
	cout << "Functions cand be \"add_two\", \"multiply_by_five\", \"floor_of_div_by_seven\", \n\"to_power_three\", \"minus_ten\".\n\n Please choose functions (e.g. \"add_two, minus_ten\": ";

	//se citeste input-ul
	getline(cin, strPureLine);

	//se imparte input-ul nefinisat in string-uri convenabile pentru coada
	for (int i = 0 ; i < strPureLine.length(); i++)
	{
		if (strPureLine[i] == '_' || isalnum(strPureLine[i]))
			toAdd = toAdd + strPureLine[i];

		else if (toAdd != "" && strPureLine[i] != '_' && !isalnum(strPureLine[i]))
		{
			functions.push(toAdd);
			toAdd = "";
		}
	}

	while (functions.empty() == false)
	{

		cout << functions.front() << ": ";

		if (functions.front() == "add_two")
		{
			cout << add_two(i) << endl;
		}

		else if (functions.front() == "multiply_by_five")
		{
			cout <<  multiply_by_five(i) << endl;
		}

		else if (functions.front() == "floor_of_div_by_seven")
		{
			cout << floor_of_div_by_seven(i) << endl;
		}

		else if (functions.front() == "to_power_three")
		{
			cout << to_power_three(i) << endl;
		}

		else if (functions.front() == "minus_ten")
		{
			cout << minus_ten(i) << endl;
		}

		else
		{
			cout << "function not defined" << endl;
		}

		functions.pop();
	}

	system("pause");

	return 0;
}

int add_two(int i)
{
	return i + 2;
}

int  multiply_by_five(int i)
{
	return i*5;
}

int floor_of_div_by_seven (int i)
{
	return i / 7;
}

int to_power_three (int i)
{
	return i * i * i;
}

int minus_ten(int i)
{
	return i - 10;
}