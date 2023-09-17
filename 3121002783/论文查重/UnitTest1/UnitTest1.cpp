#include "pch.h"
#include "CppUnitTest.h"
#include "D:\\OneDrive - mail2.gdut.edu.cn\\StudyMaterials\\大三\\软件工程\\软件工程作业\\作业2\\SoftwareEngineerWork-check-the-weight-of-a-paper\\3121002783\\论文查重\\论文查重\\common.h"
#include "D:\\OneDrive - mail2.gdut.edu.cn\\StudyMaterials\\大三\\软件工程\\软件工程作业\\作业2\\SoftwareEngineerWork-check-the-weight-of-a-paper\\3121002783\\论文查重\\论文查重\\论文查重.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char addr1[] = "D:\\OneDrive - mail2.gdut.edu.cn\\StudyMaterials\\大三\\软件工程\\软件工程作业\\作业2\\SoftwareEngineerWork-check-the-weight-of-a-paper\\3121002783\\Test\\TestText\\orig.txt";
			char addr2[] = "D:\\OneDrive - mail2.gdut.edu.cn\\StudyMaterials\\大三\\软件工程\\软件工程作业\\作业2\\SoftwareEngineerWork-check-the-weight-of-a-paper\\3121002783\\Test\\TestText\\orig_0.8_add.txt";
			char addr3[] = "D:\\OneDrive - mail2.gdut.edu.cn\\StudyMaterials\\大三\\软件工程\\软件工程作业\\作业2\\SoftwareEngineerWork-check-the-weight-of-a-paper\\3121002783\\Test\\TestText\\answer.txt";
			char* argv[] = {"", addr1, addr2, addr3};
			
			//string text1 = ReadTXT(argv[1]); //输入文本内容
			//string text2 = ReadTXT(argv[2]);

			//map<string, int> wordTable1 = GetWordFrequency(text1);
			//map<string, int> wordTable2 = GetWordFrequency(text2);

			//set<string> totalWords;  //总词库
			//for (auto temp : wordTable1) {
			//	totalWords.insert(temp.first);
			//}
			//for (auto temp : wordTable2) {
			//	totalWords.insert(temp.first);
			//}

			//vector<int> vec1, vec2;  //获取两个文本的词频向量
			//for (auto word : totalWords) {
			//	vec1.push_back(wordTable1[word]);
			//	vec2.push_back(wordTable2[word]);
			//}

			//double similarity = GetSimilarity(vec1, vec2); //获取结果
			//PrintTXT(argv[3], similarity);

			
			main(4, argv);
		}
	};
}
