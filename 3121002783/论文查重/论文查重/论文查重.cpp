﻿#include "common.h"

using namespace std;

string ReadTXT(char* addr) { //从文件输入文本数据
	ifstream infile;
	infile.open(addr);
	//assert(infile.is_open());
	if (!infile.is_open()) {
		cout << "读取时文件打开失败。" << endl;
		exit(0);
	}

	string s, t;
	while (infile >> t) {
		s += t;
	}

	infile.close();
	return s;
}

void PrintTXT(char* addr, const double& val) { //往文件输出答案
	ofstream outfile;
	outfile.open(addr);
	if (!outfile.is_open()) {
		cout << "写入时文件打开失败。" << endl;
		exit(0);
	}

	outfile << fixed << setprecision(2) << val << endl; //精确到小数点后两位
	outfile.close();
}

map<string, int> GetWordFrequency(const string& text) { //传入text文本，用n-gram算法分词，然后计算词频，返回一个map
	map<string, int> wordTable;
	for (int i = 0; size_t(i) + 5 < text.size(); i++) {
		string word = text.substr(i, 6); //n-gram分词
		wordTable[word]++;
	}
	return wordTable;
}

double GetSimilarity(const vector<int>& vec1, const vector<int>& vec2) {  //传入两个词向量vec，用余弦公式计算余弦相似度并返回结果
	const size_t n = vec1.size();
	double a = 0, b = 0, c = 0;
	for (int i = 0; i < n; i++) {
		a += 1LL * vec1[i] * vec2[i];
		b += 1LL * vec1[i] * vec1[i];
		c += 1LL * vec2[i] * vec2[i];
	}

	if (b == 0 || c == 0) return 0;  //注意不能除0

	double similarity = a / (sqrt(b) * sqrt(c));
	return similarity;
}

int main(int argc, char* argv[]) {

	string text1 = ReadTXT(argv[1]); //输入文本内容
	string text2 = ReadTXT(argv[2]);

	map<string, int> wordTable1 = GetWordFrequency(text1);
	map<string, int> wordTable2 = GetWordFrequency(text2);

	set<string> totalWords;  //总词库
	for (auto temp : wordTable1) {
		totalWords.insert(temp.first);
	}
	for (auto temp : wordTable2) {
		totalWords.insert(temp.first);
	}

	vector<int> vec1, vec2;  //获取两个文本的词频向量
	for (auto word : totalWords) {
		vec1.push_back(wordTable1[word]);
		vec2.push_back(wordTable2[word]);
	}

	double similarity = GetSimilarity(vec1, vec2); //获取结果
	PrintTXT(argv[3], similarity);
	cout << "答案已输出至文件。" << endl;

	return 0;
}