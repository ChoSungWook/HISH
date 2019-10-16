#include <iostream>
#include <vector>
using namespace std;

class Cryptography
{
public:
	long encrypt(vector <int> numbers)
	{
		long result = 0;
		long temp;
		for (int i = 0; i < numbers.size(); ++i)
		{
			temp = numbers[i]+1;
			for (int j = 0; j < numbers.size(); ++j)
			{
				if(i != j)
					temp *= numbers[j];
			}
			result = (result > temp) ? result : temp;

		}
		return result;
	}
};
void inputData(int n, vector<int>* inputlist);
void printData(int n, vector<int> list);
int main()
{
	Cryptography crypt;
	vector<int> inputlist;
	long result = 0;
	int n;
	
	cout << "List »çÀÌÁî : ";
	cin >> n;
	cout << "numbers : ";
	inputData(n, &inputlist);

	result = crypt.encrypt(inputlist);
	cout << "Returns : " << result << endl;

	return 0;
}

void inputData(int n, vector<int>* inputlist)
{
	int data;
	for (int i = 0; i < n; ++i)
	{
		cin >> data;
		inputlist->push_back(data);
	}
}

void printData(int n, vector<int> list)
{
	for (int i = 0; i < n; ++i)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}