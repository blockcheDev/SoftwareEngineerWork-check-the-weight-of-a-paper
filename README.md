| 这个作业属于哪个课程 | [首页 - 计科21级12班 - 广东工业大学 - 班级博客 - 博客园 (cnblogs.com)](https://edu.cnblogs.com/campus/gdgy/CSGrade21-12) |
| -------------------- | ------------------------------------------------------------ |
| 这个作业要求在哪里   | [个人项目 - 作业 - 计科21级12班 - 班级博客 - 博客园 (cnblogs.com)](https://edu.cnblogs.com/campus/gdgy/CSGrade21-12/homework/13014) |
| 这个作业的目标       | 使用个人开发流程进行一个论文查重项目开发                     |

- GitHub 项目地址：[blockcheDev/SoftwareEngineerWork-check-the-weight-of-a-paper: 软工作业2：论文查重项目 (github.com)](https://github.com/blockcheDev/SoftwareEngineerWork-check-the-weight-of-a-paper)

# 模块接口的设计与实现过程

| 函数                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| string ReadTXT(char* addr)                                   | 打开地址为addr的文本，读取内容并用string返回                 |
| void PrintTXT(char* addr, const double& val)                 | 打开地址为addr的文本，将val值输出至文件                      |
| map<string, int> GetWordFrequency(const string& text)        | 传入text文本，用n-gram算法分词，然后计算词频，返回一个map    |
| double GetSimilarity(const vector<int>& vec1,const vector<int>& vec2) | 传入两个词向量vec，用余弦公式计算余弦相似度并返回            |
| int main(int argc, char* argv[])                             | 用命令行参数按顺序将[原文文件] [抄袭版论文的文件] [答案文件]的路径传入，然后主函数内会依次调用各个功能函数完成论文查重，并将文本相似度输出至答案文件 |

# 模块接口部分的性能改进

## 性能测试

![image-20230913153056770](https://img2023.cnblogs.com/blog/2646249/202309/2646249-20230913153057774-663712105.png)

可以看到，对于整个程序而言，独占时间最多的用户函数是 GetWordFrequency()，这也不难解释，因为这是对整篇文本进行分词操作，并将每个词语存入散列表的重要函数。

对于一个长度为 n 的文本，使用参数为 k 的 n-gram 分词操作，这个函数的整体复杂度为 $O(k*n*logn)$，一般 n-gram 的参数会设为6以下，所以复杂度可以视为 $O(n*logn)$，这个 log 是使用散列表时元素冲突造成的重复查询而均摊下来的复杂度。

所以最占用时间的自然是Hash函数，除此之位其他操作复杂度均为 $O(n)$ 以下。

## 性能改进

由于在当前程序使用散列表的插入操作较多，而一但发生冲突，将会使单次操作复杂度从 $O(1)$ 降为 $O(n)$。

所以可以使用底层为红黑树的 std::map 代替 std::unordered_map，std::map 的单次插入复杂度是稳定 $O(logn)$ 的，在极端状况下可以提升程序性能和稳定性。

# 模块部分单元测试展示

## Test1

1. 文件列表

   ![image-20230913161250673](https://img2023.cnblogs.com/blog/2646249/202309/2646249-20230913161250196-1062504479.png)

2. 文件内容

![image-20230913161039981](https://img2023.cnblogs.com/blog/2646249/202309/2646249-20230913161039790-1590656184.png)

![image-20230913161122518](https://img2023.cnblogs.com/blog/2646249/202309/2646249-20230913161122302-658886181.png)

3. 运行过程

   ![image-20230913161423238](https://img2023.cnblogs.com/blog/2646249/202309/2646249-20230913161422883-1015805951.png)

4. 运行结果

   ![image-20230913161450008](https://img2023.cnblogs.com/blog/2646249/202309/2646249-20230913161449673-621197348.png)

## Test2

毫无相关的两个文本

![image-20230913162255817](https://img2023.cnblogs.com/blog/2646249/202309/2646249-20230913162255442-1711860681.png)
![image-20230913162417503](https://img2023.cnblogs.com/blog/2646249/202309/2646249-20230913162417017-512295277.png)

# 模块部分异常处理说明

## GetSimilarity() 函数异常处理

![image-20230913161645252](https://img2023.cnblogs.com/blog/2646249/202309/2646249-20230913161644880-1674072742.png)

没有加上第52行代码前，如果 b 或 c 的值为0，也就是两个文本丝毫不相关，程序会进行除0操作，总所周知，数学上除0是没有意义的，于是程序报错了。

# 附录

## PSP表格

| PSP2.1                                  | Personal Software Process Stages        | 预估耗时（分钟） | 实际耗时（分钟） |
| --------------------------------------- | --------------------------------------- | ---------------- | ---------------- |
| Planning                                | 计划                                    | 1200             | 725              |
| · Estimate                              | · 估计这个任务需要多少时间              | 1200             | 725              |
| Development                             | 开发                                    | 480              | 395              |
| · Analysis                              | · 需求分析 (包括学习新技术)             | 40               | 60               |
| · Design Spec                           | · 生成设计文档                          | 20               | 20               |
| · Design Review                         | · 设计复审                              | 20               | 10               |
| · Coding Standard                       | · 代码规范 (为目前的开发制定合适的规范) | 10               | 5                |
| · Design                                | · 具体设计                              | 120              | 30               |
| · Coding                                | · 具体编码                              | 120              | 60               |
| · Code Review                           | · 代码复审                              | 30               | 30               |
| · Test                                  | · 测试（自我测试，修改代码，提交修改）  | 120              | 180              |
| Reporting                               | 报告                                    | 270              | 330              |
| · Test Repor                            | · 测试报告                              | 120              | 240              |
| · Size Measurement                      | · 计算工作量                            | 30               | 30               |
| · Postmortem & Process Improvement Plan | · 事后总结, 并提出过程改进计划          | 120              | 60               |
|                                         | · 合计                                  | 750              | 725              |