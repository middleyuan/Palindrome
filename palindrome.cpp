#include<iostream>
#include<string>
#include<cstring>
using namespace std;

bool palindrome(char str[], int n, int len, int c, int count)
{
	if (str[len - c + count] == str[c - 1])
	{
		if ((len - c + count) < (c - 1) && (len - c + 1 + count) != (c - 1))
			return palindrome(str, n, len, c - 1, count);
		else
			return true;
	}
	else if (str[len - c + count] != str[c - 1] && count < n)
			return palindrome(str, n, len, c, count + 1) || palindrome(str, n, len - 2, c - 1, count + 1);
	else
		return false;
};

int main(void)
{
	int n;
	int count = 0;
	cin >> n;
	char str[64];
	cin.clear();
	cin.ignore(64, '\n');
	
	while (cin.getline(str, 64))
	{
		int c;
		int len = c = strlen(str);
		if (palindrome(str, n, len, c, count))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	system("pause");
	return 0;
}
