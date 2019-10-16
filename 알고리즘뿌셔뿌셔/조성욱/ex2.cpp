#include <iostream>
#include <vector>
using namespace std;
class InterestingParty
{
public:
	int bestInvitation(vector<string> first, vector<string> second)
	{
		int result = 0;
		int f = 0;
		int s = 0;
		for (int i = 0; i < first.size(); ++i)
		{
			f = 0;
			s = 0;
			for (int j = 0; j < first.size(); ++j)
			{

				if (first[i] == first[j]) ++f;
				if (second[i] == second[j]) ++s;
				if(first[j]!=second[j])  // data중복이면 스킵
				{
					if (first[i] == second[j]) ++f;
					if (second[i] == first[j]) ++s;
				}
				int tmp = (f > s) ? f : s;
				result = (result > tmp)? result : tmp;
			}
		}

		return result;
	}
};
void inputData(int n, vector<string>* data);
void printData(int n, vector<string> data);

int main()
{
	InterestingParty ip;
	vector<string> first;
	vector<string> second;
	int n;
	int invitation;

	cout << "친구 수 : ";
	cin >> n;
	cout << "first : ";
	inputData(n, &first);
	cout << "second : ";
	inputData(n, &second);

	invitation = ip.bestInvitation(first, second);

	cout << "초대할 친구 수 : " << invitation << endl;



	return 0;
}
void inputData(int n, vector<string>* data)
{
	string interest;
	for (int i = 0; i < n; ++i)
	{

		cin >> interest;
		data->push_back(interest);
	}
}

void printData(int n, vector<string> data)
{
	for (int i = 0; i < n; ++i)
		cout << data[i] <<" ";
	cout << endl;
}