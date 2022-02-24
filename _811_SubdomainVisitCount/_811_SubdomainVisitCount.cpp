#include <vector>
#include <string>
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

class _811_SubdomainVisitCount {
    /**
    * 811. Subdomain Visit Count
    * A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, 
    * we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we 
    * will also visit the parent domains "leetcode.com" and "com" implicitly.

    Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed 
    by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".

    We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, 
    and in any order), that explicitly counts the number of visits to each subdomain.

    Example 1:
    Input: 
    ["9001 discuss.leetcode.com"]
    Output: 
    ["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
    Explanation: 
    We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. 
    So they will all be visited 9001 times.

    Example 2:
    Input: 
    ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
    Output: 
    ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
    Explanation: 
    We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times. For the subdomains, we will 
    visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.

    */
 
 public:
  vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> mp;
    for (string cpdomain : cpdomains) {
        size_t cut = cpdomain.find(' ');
        int num = stoi(cpdomain.substr(0, (int)cut));
        string domain = cpdomain.substr((int)(cut + 1));
        mp[domain] += num;
        for (int i = 0; i < domain.size(); i++) {
            if (domain[i] == '.') {
                string d = domain.substr(i + 1);
                mp[d] += num;
            }
        }
    }
    vector<string> res;
    for (auto& v : mp) {
        res.push_back(to_string(v.second) + " " + v.first);
    }
    return res;   
  }
};




