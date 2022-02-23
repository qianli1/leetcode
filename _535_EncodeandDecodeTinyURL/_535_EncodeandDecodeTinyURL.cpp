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

class _535_EncodeandDecodeTinyURL {
    /**
    * 535. Encode and Decode TinyURL
    * TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl 
    * and it returns a short URL such as http://tinyurl.com/4e9iAk.

    Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode 
    algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be 
    decoded to the original URL.

    time : O(1);
    space : O(1); n 个 string O(n)
    */
 
 private:
  unordered_map<string, string> map;
  string mapping = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

 public:

  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    string res;
    for (int i = 0; i < 6; i++) {
        int index = rand() % mapping.size();
        res.push_back(mapping[index]);
    }
    string url = "http://tinyurl.com/" + res;
    if (!map.count(url)) {
        map[url] = longUrl;
    }
    return url;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    return map[shortUrl];
  }
};




