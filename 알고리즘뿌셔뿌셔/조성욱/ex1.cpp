#include <iostream>
#include <vector>
using namespace std;

//문제 정의
class KiwiJuiceEasy
{
public:
	vector<int> thePouring(vector <int> capacities, vector<int> bottles, vector<int> fromId, vector<int> toId) {
		vector<int> err;
		if (capacities.size() < 2 || capacities.size() > 50)
		{
			cout << "[error] capacities range out" << endl;
			return err;
		}
		if (fromId.size() < 1 || fromId.size() > 50)
		{
			cout << "[error] fromId range out" << endl;
			return err;
		}
		if (fromId.size() != toId.size())
		{
			cout << "[error] fromId && toId  not equal range" << endl;
			return err;
		}
		for (int i = 0; i < capacities.size(); ++i)
		{
			if (capacities[i] < bottles[i])
			{
				cout << "[error] capacities[" << i << "] < bottles[" << i << "]" << endl;
				return err;
			}
		}
		for (int i = 0; i < fromId.size(); ++i)
		{
			if (fromId[i] > capacities.size())
			{
				cout << "[error] fromId[" << i << "] exceed idx" << endl;
				return err;
			}
			if (toId[i] > capacities.size())
			{
				cout << "[error] toId[" << i << "] exceed idx" << endl;
				return err;
			}
		}
		for (int i = 0; i < fromId.size(); ++i)
		{
			if (fromId[i] == toId[i])
				continue;
			while (bottles[fromId[i]] > 0  && bottles[toId[i]] < capacities[toId[i]])
			{
				--bottles[fromId[i]];
				++bottles[toId[i]];
			}
		}
		return bottles;
	}
	KiwiJuiceEasy() {}
};
//
void printData(int n, vector<int> v);
void inputData(int n, vector<int>* v);
int main()
{

	KiwiJuiceEasy kj;
	int n, m;
	vector<int> capacities;
	vector<int> bottles;
	vector<int> fromId;
	vector<int> toId;

	vector<int> returns;
	cout << "병의 개수 N : ";
	cin >> n;
	cout << "capacity : ";
	inputData(n, &capacities);
	cout << "bottles : ";
	inputData(n, &bottles);

	cout << "횟수 M : ";
	cin >> m;
	cout << "fromId : ";
	inputData(m, &fromId);
	cout << "toId : ";
	inputData(m, &toId);
	returns = kj.thePouring(capacities, bottles, fromId, toId);
	cout << "Return : ";
	printData(n, returns);

	return 0;
}
void inputData(int n, vector<int>* v)
{
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		v->push_back(data);
	}
}

void printData(int n, vector<int> v)
{
	for (int i = 0; i < n; ++i)
	{
		cout << v[i] << " ";
		
	}
	cout << endl;
}

