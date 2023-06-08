#pragma once
#include <iostream>

using namespace std;

class clsScreen
{
protected:
	static void _DrawHeder(string Title, string subTitle = "")
	{
		cout << "===================================\n";
		cout << "\t " << Title << endl;

		if (subTitle != "")		
			cout << "\t\t\t" << subTitle << endl;
		
		cout << "===================================\n";
	}
};

