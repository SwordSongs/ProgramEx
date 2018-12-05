#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<bitset>
#include<set>
#include<afx.h>
#include<Winbase.h>

#include"mapTest.h"

using namespace std;

#define ui32 unsigned int 
#define ui64 unsigned __int64 
#define sizeMax 80    //校验部分最大长度

const ui32 SHUFFLE[] =
{
	8,  5,  79,  30,  46,  58,  19,  28,
	66, 35,   6,  25,  14,  68,  47,  43,
	0, 56,  59,  61,  64,  15,   3,  63,
	13, 21,  24,   7,  73,  49,  23,  55,
	44, 31,  11,  74,  70,  77,  51,  42,
	18, 65,  67,  39,  72,   4,  10,  12,
	2, 48,  22,  71,  62,  38,  45,  20,
	16, 60,  53,  69,  40,  75,  54,  57,
	17, 29,  33,   1,  34,  37,  50,  36,
	9, 32,  41,  76,  26,  52,  27,  78
};

//const ui32 INVERSE_SHUFFLE[] =
//{
//	 9,  19,  24,  31,  32,  36,  45,  54,
//	72,   0,  13,  18,  47,  48,  50,  55,
//	56,  64,  20,   3,  21,  25,  39,  60,
//	62,  11,  12,  71,   7,  14,   6,  10,
//	35,  44,  65,  16,  75,   4,  34,  43,
//	70,  74,  76,  15,  17,  26,  51,  66,
//	29,  41,  30,  38,  77,  22,  27,  40,
//	33,  46,   1,  53,  57,  67,  52,  23,
//	58,  49,   8,  42,  59,  63,   5,  69,
//	68,  28,  73,  61,  78,  37,  79,   2
//};



void elimDups(vector<string>& words) {
	sort(words.begin(),words.end());                //字典序
	auto p = unique(words.begin(),words.end());    //去除重复
	words.erase(p,words.end());                    //删除多余
}

void bigges(vector<string>& words, vector<string>::size_type sz) {
	elimDups(words);
	sort(words.begin(), words.end(), [](string &a, string &b)-> bool { return a.size() < b.size(); });
	auto p = find_if(words.begin(), words.end(), [sz](string& a)-> bool { return a.size() > sz; });
	for_each(p, words.end(), [](string& a)-> void {cout <<a<<"  "; });
	cout << endl;
}

void testCS(CString s) {
	cout << s << endl;
}

void testSTR(string s) {
	cout << s << endl;;
}

//struct A{
//	int a;
//	unsigned char c;
//};

ui64 move_left64(ui64 a, int len)
{
	ui32 *p = (ui32*)&a;

	if (len <32)
	{
		*(p + 1) <<= len;
		ui32 tmp = (*p) >> (32 - len);
		*(p + 1) |= tmp;
		*p <<= len;
	}
	else
	{
		*(p + 1) = *p;
		*p = 0x00000000;
		*(p + 1) <<= (len - 32);
	}
	return a;
}

ui64 move_right64(ui64 a, int len)
{
	ui32 *p = (ui32*)&a;
	if (len<32)
	{
		*p >>= len;
		ui32 tmp = *(p + 1) << (32 - len);
		*p |= tmp;
		*(p + 1) >>= len;
	}
	else
	{
		*p = *(p + 1);
		*(p + 1) = 0x00000000;
		*p >>= (len - 32);
	}
	return a;
}


ui64 stringToull(string& key) {
	ui64 result = 0;

	char cL[32] = { 0 };
	char cR[32] = { 0 };
	ui32 i = 0;

	for (i = 0; i < 8; ++i)
		cL[i] = key[i];

	for (i = 0; i < 8; ++i)
		cR[i] = key[i+8];

	ui32 L = strtoul(cL,NULL,16);
	ui32 R = strtoul(cR,NULL,16);

	result |= L;
	result <<= 32;
	result |= R;

	return result;
}



void keyGenRand(ui32 seed, vector<int>& v) {
	int temp = 0;
	set<int> position;

	srand(static_cast<ui32>(time(NULL)));  //如果放到while里，每次判定一个seed，使得重复次数上升，耗时严重

	while (1) {
		//srand(static_cast<ui32>(time(NULL)));   
		temp = rand() % seed;        //range..[0,79]
		vector<int>::iterator it = find(v.begin(), v.end(), temp);
		if (v.end() == it) {
			v.push_back(temp);
		}

		if (seed == v.size())    break;
	}

	//clock_t end = clock();
	//cout << "rand time:" << end - start << "ms" << endl;
	int count = 0;
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it,++count) {
		cout << *it << "   ";
		if ((0 == count % 8) && (0 != count)) {
			cout << endl;
		}
	}

}

string shuffle(string& text, vector<char>& v, bool shuffleFlag) {
	string result;

	if (shuffleFlag) {
		//	按照SHUFFLE序列
		for (ui32 i = 0; i < sizeMax;++i) {
			result += v[SHUFFLE[i]];
		}
	}
	else {
		for (vector<char>::iterator it = v.begin(); it != v.end(); ++it) {
			result += *it;
		}
	}

	return result;
}

void initialize(map<string,int>& mapTest) {
	mapTest.insert(make_pair("abc",1));
	mapTest.insert(make_pair("def",2));
}
string p;
void f() {
	for (map<string, int>::iterator iter = mapTest.begin(); iter != mapTest.end(); iter++)
		cout << iter->first << ' ' << iter->second << endl;
	p = "a";
}


int main() {
//	string s1 = "abcd\
//ef";
//	string s2 = "abcd\
//		ef";
//	string s3 = "abce"
//"ef";
//	string s4 = "abce"
//		"ef";
//	string s5 = s4
//		+ "ef";
//
//	cout << "s1: "<<s1 << endl;
//	cout << "s2: "<<s2 << endl;
//	cout << "s3: "<<s3 << endl;
//	cout << "s4: "<<s4<< endl;

	//char isql[1024];
	//sprintf_s(isql,1024,"%08X%08d",110,16);
	//cout << isql << endl;
	string s = "test";
	cout << s << endl;

	system("pause");
	return 0;
}