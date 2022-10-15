#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class My_mas
{
public:
	My_mas() {

		cout << "The lowest index range->\n";
		cin >> range_low;

		cout << "The highest index range->\n";
		cin >> range_high;

		cout << "Your mass->\n";
		for (size_t i = 0; i < range_high - range_low; i++)
		{
			vec.push_back(10 + rand() % 10);
			cout << vec[i] << " ";
		}
		cout << endl;
	}
	int operator[](int index) {
		if (index < 0) {
			int res = range_high - (abs(index) %12);
			return vec[res];
		}

		if (index >= range_low && index <= range_high) {
			return vec.at(index - range_low);
		}
		throw exception("WRONG INDEX");
	}

private:
	int range_low, range_high;
	vector <int> vec;
};

int main()
{
	srand(time(NULL));
	My_mas mass;

	cout << "Which element do you want to know->\n";
	int a;
	cin >> a;
	try
	{
		cout << mass[a];
	}
	catch (const std::exception& ex)
	{
		cout << ex.what();
	}
}
