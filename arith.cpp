#include "bits/stdc++.h"
#include "stdint.h"

using namespace std;

#define TEN3 1000
#define TEN4 10000
#define TEN5 100000
#define TEN6 1000000
#define TEN7 10000000
#define TEN8 100000000
#define TEN9 1000000000

#define MOD7 1000000007
#define MOD9 1000000009

#define pb push_back
#define mp make_pair

#define MM(a,x) memset(a, x, sizeof(a))
#define P(x) cout<<x<<endl;
#define P2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl;
#define PV(a,n) for(long i=0;i<n;i++) cout<<#a<<"[" << i <<"] = "<<a[i]<<endl;
#define TM(a,b) cout<<#a<<"->"<<#b<<": "<<1.*(b-a)/CLOCKS_PER_SEC<<"s\n";
#define all(X) (X).begin(), (X).end ()
//#define for_each(it, X) for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define as(i,be,en) assert(i>=be&&i<=en);
#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define sz(v) long((v).size())
#define X first
#define Y second

typedef long long li;
typedef long double ld;
typedef unsigned long long LL;
typedef string st;
typedef pair<long, long> pt;

template<typename T> T abs(T a) { return a < 0 ? -a : a; }
template<typename T> T sqr(T a) { return a*a; }

const long INF = (long)1e9;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;


// end of constants and definitions........................................................


string add(st st_1,st st_2,bool mul)
{
	st final="";
	int st_1_len = st_1.length(),st_2_len = st_2.length();
	int st_len = max(st_1_len,st_2_len);
	if(st_1_len == st_len)
	{
		st_2 = string(st_len - st_2_len,'0')+st_2;
	}
	else if(st_2_len == st_len)
	{
		st_1 = string(st_len - st_1_len,'0')+st_1;
	}
	for(int i=0;i<st_len;i++)
	{
		int sum = (int)st_1[i]-48+(int)st_2[i]-48;
		final.push_back((char)((sum%10)+48));
		int it = final.size()-1;
		while(it>=0 && sum >9)
		{
			if(it == 0 && sum > 9)
			{
				final = string(1,(char)(sum/10+48)) + final;
			}
			else
			{
				sum = (int)final[it-1]-48 + (sum/10);
				final[it-1] = (char)((sum%10)+48);
			}
			it--;
		}
	}
	st_1.erase(0,st_1.find_first_not_of('0'));
	st_2 = "+"+st_2.substr(st_len-st_2_len,st_len);
	st_2_len++;
	if (!mul)
	{
		int space= final.length();
		space = max(st_1_len,max(st_2_len,space));
		st_1 = string(space-st_1_len,' ')+st_1;
		st_2 = string(space-st_2_len,' ')+st_2;
		final = string(space-final.length(),' ')+final;
		st dash = st(space,'-');
		P(st_1)
		P(st_2)
		P(dash)
		P(final)

	}
	else
	{
		return final;
	}
	return "";
}

string sub(st st_1,st st_2)
{
	st final="";
	int st_1_len = st_1.length(),st_2_len = st_2.length();
	st_2 = string(st_1_len - st_2_len,'0')+st_2;
	final+=st_1.substr(0,st_1_len-st_2_len);
	for (int i = st_1_len - st_2_len; i < st_1_len ; ++i)
	{
		int diff = (int)st_1[i] - (int)st_2[i];
		if(diff < 0)
		{
			final.push_back((char)(diff+10)+48);
			int it = i-1;
			while(diff<0 && it>=0)
			{
				diff = (int)final[it]-48-1;
				if(diff>=0)
				{
					final[it] = ((char)diff+48);
				}
				else
				{
					final[it] = ((char)(diff+10)+48);
				}
				it--;
			}
		} 
		else
		{
			final.push_back((char)diff+48);
		}		
	}
	st_2 = "-"+st_2.substr(st_1_len-st_2_len,st_1_len);
	st_2_len++;
	final.erase(0,final.find_first_not_of('0'));
	if(final.length() == 0)
	{
		final = "0";
	}
	int space= final.length();
	space = max(st_1_len,max(st_2_len,space));
	int temp = final.length();
	temp = max(st_2_len,temp);
	st_1 = string(space-st_1_len,' ')+st_1;
	st_2 = string(space-st_2_len,' ')+st_2;
	final = string(space-final.length(),' ')+final;
	st dash = string(space-temp,' ')+string(temp,'-');
	P(st_1)
	P(st_2)
	P(dash)
	P(final)
	return "";
}

string mul(st st_1,st st_2)
{
	st final = "0";
	std::vector<st> multiplied;
	int st_1_len = st_1.length(),st_2_len = st_2.length();
	for(int i =st_2_len-1;i>=0;i--)
	{
		st current="";
		for(int j=0;j<st_1_len;j++)
		{
			int pro = ((int)st_1[j]-48)*((int)st_2[i]-48);
			current.push_back((char)(pro%10)+48);
			int sum = pro;
			int it = current.size()-1;
			while(it>=0 && sum >9)
			{
				if(it == 0 && sum > 9)
				{
					current = string(1,(char)(sum/10+48)) + current;
				}
				else
				{
					sum = (int)current[it-1]-48 + (sum/10);
					current[it-1] = (char)((sum%10)+48);
				}
				it--;
			}	
		}
		current.erase(0,current.find_first_not_of('0'));
		if(current.length() == 0)
		{
			current = "0";
		}
		multiplied.push_back(current);
		if(current[0] != '0')
		{
			current = current+string(st_2_len-1-i,'0');
		}
		final = add(final,current,true);
	}

	final.erase(0,final.find_first_not_of('0'));
	if(final.length() == 0)
	{
		final = "0";
	}

	st_2 = "*"+st_2;
	st_2_len++;
	int space= final.length();
	space = max(st_1_len,max(st_2_len,space));
	st_1 = string(space-st_1_len,' ')+st_1;
	st_2 = string(space-st_2_len,' ')+st_2;
	st dash_2 = string(space-final.length(),' ')+string(final.length(),'-');
	final = string(space-final.length(),' ')+final;

	int temp_len = multiplied[0].length();
	st dash_1 = string(max(temp_len,st_2_len),'-');

	if (st_2_len == 2)
	{
		P(st_1)
		P(st_2)
		P(dash_1)
		P(final)
	}
	else
	{
		
		P(st_1)
		P(st_2)
		dash_1 = string(space-dash_1.length(),' ')+dash_1;
		P(dash_1)
		forn(j,multiplied.size())
		{
			cout << string(space-multiplied[j].length()-j,' ');
			P(multiplied[j])
		}
		P(dash_2)
		P(final)
	}
	return "";
}

//main

int main(int argc, char const *argv[])
{
	int t;cin>>t;
	forn(i,t)
	{
		st input;cin>>input;
		int pos = -1;
		if(input.find("+") != -1)
		{
			pos = input.find("+");
		}
		else if(input.find("-") != -1)
		{
			pos = input.find("-");
		}
		else if(input.find("*") != -1)
		{
			pos = input.find("*");
		}

		st opr_1 = input.substr(0,pos);
		st opr_2 = input.substr(pos+1,input.length());
		if (input[pos] == '+')
		{
			add(opr_1,opr_2,false);
		}
		else if (input[pos] == '-')
		{
			sub(opr_1,opr_2);
		}
		else if (input[pos] == '*')
		{
			mul(opr_1,opr_2);
		}
		cout << endl;
	}
	return 0;
}
