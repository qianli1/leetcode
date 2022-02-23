#include <vector>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _388_LongestAbsoluteFilePath {
    /**
    * 388. Longest Absolute File Path
    * Suppose we abstract our file system by a string in the following manner:

    The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

    dir
        subdir1
        subdir2
            file.ext
    The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

    The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

    dir
        subdir1
            file1.ext
            subsubdir1
        subdir2
            subsubdir2
                file2.ext
    The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level 
    sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

    We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, 
    in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

    Given a string representing the file system in the above format, return the length of the longest absolute path to file 
    in the abstracted file system. If there is no file in the system, return 0.

    Note:
    The name of a file contains at least a . and an extension.
    The name of a directory or sub-directory will not contain a ..
    Time complexity required: O(n) where n is the size of the input string.

    Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path

    time : O(n);
    space : O(n);
    */
 
 public:
  vector<string> split(string &s) {
    vector<string> res;
    stringstream ss(s);
    string str;
    while (getline(ss, str)) {
        res.push_back(str);
    }
    return res;
  }

  int lengthLongestPath(string input) {
    stack<int> st;
    st.push(0);
    vector<string> v = split(input);
    int res = 0;
    for (string s: v) {
        int level = s.find_last_of('\t') + 1;
        while (level + 1 < st.size()) {
            st.pop();
        }
        int len = st.top() + s.size() - level + 1;
        st.push(len);
        if (s.find('.') != -1) {
            res = max(res, len - 1);
        } 
    }
    return res;
  }
};




