#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;
class String
{
	unsigned size = 0;
	char* str = nullptr;
public:

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
	void insert_simbol(const char* simbol,int position) {
		char*s = str;
		size += 1;
		for (int i = 0; i <= size; ++i) {
			if (position== i) {
				s[i + 1] = s[i];
				s[position] =*simbol;
			}
		}

	}
	const char* get_str() {
		return str;
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
	const int strlen_str() {
		return strlen(str);
	}
};


int main() {

	String st("ds");
	cout << st.get_str() << endl;
	st.assign("mornefo");
	cout << st.get_str() << endl;
	st.concat("hfkdsdjk");
	cout << st.get_str() << endl;
	st.insert("*", 1);
	cout << st.get_str() << endl;
	st.ASC2();
    st.insert_simbol("5", 3);
	cout << st.get_str() << endl;
	cout << st.caps_lock() << endl;
	cout << st.NOT_caps_lock() << endl;
	cout << st.strlen_str() << endl;
	return 0;
}
