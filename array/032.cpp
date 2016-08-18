/*
	GCD of two numbers when one of them can be very large
	URL: http://bit.ly/2bfVIBL
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long basicGCD(long long a, long long b) {
	if(a == 0)
		return b;
	else
		return basicGCD(b%a,a);
}

long long reduceB(long long a, string b) {
	long long ans = 0;
	for(int i=0;i<b.size();++i) {
		ans = (ans*10 + b[i]-'0') % a;
	}
	return ans;
}

long long specialGCD(long long a, string b) {
	long long num = reduceB(a,b);
	return basicGCD(a,num);
}

int main (int argc, char const* argv[])
{
	long long a = 1221;
	string b("1234567891011121314151617181920212223242526272829");
	cout << specialGCD(a,b) << "\n";
	return 0;
}
