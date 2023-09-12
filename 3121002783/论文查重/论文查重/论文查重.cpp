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

unordered_map<string, int> GetWordFrequency(string text) {
	unordered_map<string, int> wordTable;
	for (int i = 0; size_t(i) + 1 < text.size(); i++) {
		string word = text.substr(i, 3); //bigram分词
		wordTable[word]++;
	}
	return wordTable;
}

double GetSimilarity(vector<int>& vec1, vector<int>& vec2) {
	const size_t n = vec1.size();
	double a = 0, b = 0, c = 0;
	for (int i = 0; i < n; i++) {
		a += 1LL * vec1[i] * vec2[i];
		b += 1LL * vec1[i] * vec1[i];
		c += 1LL * vec2[i] * vec2[i];
	}

	if (b == 0 || c == 0) return 0;

	double similarity = a / (sqrt(b) * sqrt(c));
	return similarity;
}

int main(int argc, char* argv[]) {

	string text1 = ReadTXT(argv[1]);
	string text2 = ReadTXT(argv[2]);
	
	unordered_map<string, int> wordTable1 = GetWordFrequency(text1);
	unordered_map<string, int> wordTable2 = GetWordFrequency(text2);
	
	unordered_set<string> totalWords;
	for (auto temp : wordTable1) {
		totalWords.insert(temp.first);
	}

	vector<int> vec1, vec2;
	for (auto word : totalWords) {
		vec1.push_back(wordTable1[word]);
		vec2.push_back(wordTable2[word]);
	}

	double similarity = GetSimilarity(vec1, vec2);
	cout << similarity << endl;

	return 0;
}