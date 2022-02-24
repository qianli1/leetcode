#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

/**
* 本代码来自 CSON 官方视频课程，由 @CSON 提供
* 题目来源： http://leetcode.com
* CSON 致力于在 CS 领域内帮助中国人找到工作，让更多海内外国人受益
* 讲师： Edward Shi
* 官方网站： https://cspiration.com
* 版权归 CSON 所有， 禁止 转载！
*/

class _734_SentenceSimilarity {
    /**
    * 734. Sentence Similarity
    * Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, 
    * determine if two sentences are similar.

    For example, "great acting skills" and "fine drama talent" are similar, if the similar word pairs are pairs = [["great", 
    "fine"], ["acting","drama"], ["skills","talent"]].

    Note that the similarity relation is not transitive. For example, if "great" and "fine" are similar, and "fine" and "good" 
    are similar, "great" and "good" are not necessarily similar.

    However, similarity is symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

    Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] 
    are similar, even though there are no specified similar word pairs.

    Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never 
    be similar to words2 = ["doubleplus","good"].

    time : O(n);
    space : O(n);
    */
 
 public:
  bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
    if (words1.size() != words2.size()) {
        return false;
    }
    
    unordered_set<string> s;
    for (auto pair : pairs) {
        s.insert(pair[0] + "%" + pair[1]);
    }
    
    for (int i = 0; i < words1.size(); i++) {
        if (words1[i] != words2[i] &&
            !s.count(words1[i] + "%" + words2[i]) &&
            !s.count(words2[i] + "%" + words1[i])) {
            return false;
        }
    }
    return true;
  }
};




