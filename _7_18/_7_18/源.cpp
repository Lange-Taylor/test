//完全数
#if 0
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int M;
	cin >> M;
	//vector<int> ret;
	int count = 0;
	
	for (int i = M; i >= 2; --i)
	{
		int sum = 1;
		for (int j = i/2; j >= 2; --j)
		{
			if (i % j == 0)
			{
				//ret.push_back(i);
				sum += j;
			}
		}
		if (i == sum)
		{
			count++;
		}
	}

	cout << count << endl;
	return 0;
}

#endif


#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

unordered_map<char, int> helper{ {'3',1},{'4',2},{ '5',3 },{ '6',4 },{ '7',5 },{ '8',6 },
{ '9',7 },{ '1',8 },{ 'J',9 },{ 'Q',10 },{ 'K',11 },{ 'A',12 },{'2',13} };

string del_0(string str) {
	while (str.find('0') != string::npos)
		str.erase(str.find('0'), 1);
	return str;
}
int main() {
	string str, s1, s2, s1_, s2_;
	while (getline(cin, str)) {
		s1_ = str.substr(0, str.find('-'));
		s1 = del_0(s1_);//获取输入数据并将其分割,删去空格
		s2_ = str.substr(str.find('-') + 1);
		s2 = del_0(s2_);
		if (s1 == "joker JOKER" || s2 == "joker JOKER") 
			cout << "joker JOKER" << endl;
		else 
			if (s1.size() == 7 || s2.size() == 7) {//有炸弹
				if (s1.size() == 7 && s2.size() == 7)//炸弹比较
					if (helper[s1[0]] > helper[s2[0]])
						cout << s1_ << endl;
					else 
						cout << s2_ << endl;
				else
					if (s1.size() == 7) 
						cout << s1_ << endl;
				else 
						cout << s2_ << endl;
			}
		else 
			if (s1.size() == s2.size())//其余只能同等长度比较
				if (helper[s1[0]] > helper[s2[0]])
					cout << s1_ << endl;
				else 
					cout << s2_ << endl;
		else 
				cout << "ERROR" << endl;
	}
}
