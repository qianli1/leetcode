#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _609_FindDuplicateFileinSystem {
    /**
    * 609. Find Duplicate File in System
    * Given a list of directory info including directory path, and all the files with contents in this directory, you need to 
    * find out all the groups of duplicate files in the file system in terms of their paths.

    A group of duplicate files consists of at least two files that have exactly the same content.

    A single directory info string in the input list has the following format:

    "root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"

    It means there are n files (f1.txt, f2.txt ... fn.txt with content f1_content, f2_content ... fn_content, respectively) in 
    directory root/d1/d2/.../dm. Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

    The output is a list of group of duplicate file paths. For each group, it contains all the file paths of the files that have 
    the same content. A file path is a string that has the following format:

    "directory_path/file_name.txt"

    Example 1:

    Input:
    ["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
    Output:  
    [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
    */
 
 public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    unordered_map<string, vector<string>> mp;
    for (string path : paths) {
        stringstream ss(path);
        string root;
        string s;
        getline(ss, root, ' ');
        while (getline(ss, s, ' ')) {
            string fileName = root + '/' + s.substr(0, s.find('('));
            string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
            mp[fileContent].push_back(fileName);            
        }
    }
    
    vector<vector<string>> res;
    for (auto file : mp) {
        if (file.second.size() > 1)
            res.push_back(file.second);
    }

    return res;
  }
};




