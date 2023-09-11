#include "common.h"

using namespace std;

string ReadTXT(char* addr) {
	ifstream infile;
	infile.open(addr);
	//assert(infile.is_open());
	if (!infile.is_open()) {
		cout << "文件打开失败。" << endl;
		exit(0);
	}

	string s, t;
	while (infile >> t) {
		s += t;
	}

	infile.close();
	return s;
}

int main(int argc, char* argv[]) {

	string orig = ReadTXT(argv[1]);
	string orig_add = ReadTXT(argv[2]);

	cout << orig << endl;
	cout << orig_add << endl;

	return 0;
}