#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;
class String
{
public:
	unsigned size = 0;
	char* str = nullptr;

	String(const char* s)
	{
		if (s && *s) {
			size = strlen(s) + 1;
			str = new char[size];
			strcpy_s(str, size, s);
		}
	}


	~String() {
		if (str) {
			delete[] str;
			str = nullptr;
		}
	}
	void assign(const char* s) {
		if (s && *s) {
			size = strlen(s) + 1;
			delete[] str;
			str = new char[size];
			strcpy_s(str, size, s);
		}

	}
	void concat(const char* s) {
		if (s && *s && str && *str) {
			size += strlen(s);
			char* new_str = new char[size];
			strcpy_s(new_str, (strlen(str) + 1), str);
			strcat_s(new_str, size, s);
			delete[] str;
			str = new_str;
		}
	}
	void insert(const char* simb, int position) {
		for (int i = 0; i < size; ++i) {
			if (position == i)
				str[i] = *simb;
		}
	}

	void ASC2() {
		for (int i = 0; i < strlen(str); ++i) {
			int ascii = str[i];
			cout << ascii << " ";
		}
		cout << endl;
	}
	char* caps_lock() {
		return _strupr(str);
	}
	char* NOT_caps_lock() {
		return _strlwr(str);
	}
};


int main() {

	String st("ds");
	cout << st.str << endl;
	st.assign("mornefo");
	cout << st.str << endl;
	st.concat("hfkdsdjk");
	cout << st.str << endl;
	cout << strlen(st.str) << endl;
	st.insert("*", 1);
	cout << st.str << endl;
	st.ASC2();
	cout << st.caps_lock() << endl;
	cout << st.NOT_caps_lock() << endl;
	return 0;
}
