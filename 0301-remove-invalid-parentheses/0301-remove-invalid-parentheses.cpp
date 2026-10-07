#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

class Solution {
public:
    bool isValid(const std::string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
            }
            if (count < 0) return false;
        }
        return count == 0;
    }

    std::vector<std::string> removeInvalidParentheses(std::string s) {
        std::vector<std::string> result;
        if (s.empty()) return {""};

        std::unordered_set<std::string> visited;
        std::queue<std::string> q;

        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            std::string curr = q.front();
            q.pop();

            if (isValid(curr)) {
                result.push_back(curr);
                found = true;
            }

            // If we found valid expressions at this depth, 
            // we don't need to explore further depths (minimum removals guarantee)
            if (found) continue;

            // Generate all possible states by removing 1 parenthesis
            for (int i = 0; i < curr.length(); i++) {
                if (curr[i] != '(' && curr[i] != ')') continue;

                std::string next = curr.substr(0, i) + curr.substr(i + 1);
                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return result;
    }
};