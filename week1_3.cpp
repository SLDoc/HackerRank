/*

Given a time in 12-hour AM/PM format, convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

Example

s="12:01:00PM"
Return '12:01:00'.

s="12:01:00AM"
Return '00:01:00'.

*/
#include <bits/stdc++.h>
using namespace std;

/*
 *Complete the 'timeConversion' function below.
 *
 *The function is expected to return a STRING.
 *The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
	stringstream to_int;
	string check, output, MM, SS;
	check += s.substr(s.size() - 2, s.size() - 1);
	int HH;

	for (int i = 0; i < s.size(); i++)
	{
		if (i == 3 || i == 4)
		{
			MM += s[i];
		}
		else if (i == 6 || i == 7)
		{
			SS += s[i];
		}
	}

	to_int << s[0];
	to_int << s[1];
	to_int >> HH;

	if (check == "PM")
	{
		if (HH == 12)
		{
			return to_string(HH) + ":" + MM + ":" + SS;
		}

		return to_string(HH + 12) + ":" + MM + ":" + SS;
	}
	else
	{
		if (HH == 12)
		{
			return "00:" + MM + ":" + SS;
		}

		if (HH < 10)
		{
			return "0" + to_string(HH) + ":" + MM + ":" + SS;
		}
		else
		{
			return to_string(HH) + ":" + MM + ":" + SS;
		}
	}
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string s;
	getline(cin, s);

	string result = timeConversion(s);

	fout << result << "\n";

	fout.close();

	return 0;
}