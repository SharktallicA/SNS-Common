#pragma once

/*
	C++ general utility functions library
    kali 2016-2022
*/

#include <iostream>
#include <sstream>
#include <random>

#ifdef _WIN32
#include <conio.h>
#endif

using namespace std;

/*
	Class of static methods that provide utility functions for C++
	console applications.
*/
class Utility
{
private:
	Utility() {}; //prevents class from being constructed

public:
	/*
		Requests yes (true) or no (false) boolean input from the
		user.
		Returns: true if yes, false if no
	*/
	static bool get_yes_no(void)
	{
		string input = "";
		bool boolIsYes = true;

		cin >> input;
		while (input != "Y" && input != "Yes" && input != "YES" && input != "yes" && input != "N" && input != "No" && input != "NO" && input != "no" && input != "y" && input != "n")
		{
			cout << "ERROR: you can only enter 'Yes', 'No' or a similar variation.\nTry again: ";
			cin >> input;
		}

		if (input == "Y" || input == "Yes" || input == "YES" || input == "yes" || input == "y")
			boolIsYes = true;
		else if (input == "N" || input == "No" || input == "NO" || input == "no" || input == "n")
			boolIsYes = false;
		return boolIsYes;
	}

	/*
		Safely requests any string input from the user.
		Returns: inputted string
	*/
	static string get_str(void)
	{
		string input = "";
		getline(cin, input);
		return input;
	}

	/*
		Safely requests an integer input from the user.
		Returns: inputted integer
	*/
	static int get_int(void)
	{
		string input = "";
		int as_int = -1024;

		cin >> input;
		cin.ignore();
		stringstream sstream(input);
		sstream >> as_int;
		return as_int;
	}

	/*
		Safely requests an integer input from the user within
		desired bounds.
		Parametres:
			min - minimum bound
			max - maximum bound
		Returns: inputted integer
	*/
	static int get_int(int min, int max)
	{
		string input = "";
		int as_int = -1024;

		cin >> input;
		cin.ignore();
		stringstream sstream(input);
		sstream >> as_int;
		while (as_int < min || as_int > max)
		{
			cout << "ERROR: you can only enter a whole number between " << min << " and " << max << ".\nTry again: ";
			cin >> input;
			cin.ignore();
			stringstream sstream(input);
			sstream >> as_int;
		}
		return as_int;
	}

	/*
		Generates a random integer using 32-Bit Mersenne Twister 19937.
		Parametres:
			min - minimum bound
			max - maximum bound
		Returns: pseudorandomly-generated integer
	*/
	static int rand_32(int min, int max)
	{
		int result;
		random_device randGenerator;
		mt19937 mersenne(randGenerator());
		uniform_int_distribution<int> distInt(min, max);
		result = distInt(mersenne);
		return result;
	}

	/*
		Generates a random float using 32-Bit Mersenne Twister 19937.
		Parametres:
			min - minimum bound
			max - maximum bound
		Returns: pseudorandomly-generated float
	*/
	static float rand_32(float min, float max)
	{
		float result;
		random_device randGenerator;
		mt19937 mersenne(randGenerator());
		uniform_real_distribution<float> distInt(min, max);
		result = distInt(mersenne);
		return result;
	}

	/*
		Generates a random integer using 64-Bit Mersenne Twister 19937.
		Parametres:
			min - minimum bound
			max - maximum bound
		Returns: pseudorandomly-generated integer
	*/
	static int rand_64(int min, int max)
	{
		int result;
		random_device randGenerator;
		mt19937_64 mersenne(randGenerator());
		uniform_int_distribution<int> distInt(min, max);
		result = distInt(mersenne);
		return result;
	}

	/*
		Generates a random float using 64-Bit Mersenne Twister 19937.
		Parametres:
			min - minimum bound
			max - maximum bound
		Returns: pseudorandomly-generated float
	*/
	static float rand_64(float min, float max)
	{
		float result;
		random_device randGenerator;
		mt19937_64 mersenne(randGenerator());
		uniform_real_distribution<float> distInt(min, max);
		result = distInt(mersenne);
		return result;
	}

	/*
		Checks if a given string is an integer.
		Parametres:
			str - string to check
		Returns: true if is int, false if is not int
	*/
	static bool is_int(string str)
	{
		string::const_iterator it = str.begin();
		while (it != str.end() && isdigit(*it)) ++it;
		return !str.empty() && it == str.end();
	}

	/*
		Converts a string into an integer.
		Parametres:
			str - string to convert
		Returns: integer after conversion
	*/
	static int to_int(string str)
	{
		return stoi(str);
	}

	/*
		Works out the percentage difference between two values.
		Parametres:
			a - first value
			b - second value
		Returns: percentage as integer
	*/
	static int percent_int(double a, double b)
	{
		double rslt = 0;
		rslt = ((b - a) * 100) / a;
		return (int)round(rslt);
	}

	/*
		Clears the terminal screen.
	*/
	static void clr_scn(void)
	{
		// TODO: switch to a non "system()" method of doing this

		#ifdef _WIN32
		system("cls");
		#endif
		#ifdef __linux__
		system("clear");
		#endif
	}

	/*
		Waits for user input - replacement for system("pause").
		Parametres:
			msg - message to print
		Returns: character inputted
	*/
	static char pause(string msg = "Press any key to continue...")
	{
		cout << msg;
		char in;

		#ifdef _WIN32
		in = _getch();
		#endif
		#ifdef __linux__
		in = getchar();
		#endif

		cout << endl;
		return in;
	}
};