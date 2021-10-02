#include <string>
#include <vector>
#include <iostream>
#include <set>

//이중우선순위큐

std::vector<int> solution(std::vector<std::string> operations) {
    std::vector<int> answer;
    std::multiset<int> set;

    for (std::string s : operations) {
        if (s.find("I") != std::string::npos) {
            std::string sub = s.substr(2);
            int i = std::atoi(sub.c_str());
            //std::cout << i << std::endl;
            set.insert(i);
        }
        else if (s.find("D -1") != std::string::npos) {
            if (set.empty()) continue;
            set.erase(set.begin());
        }
        else if (s.find("D 1") != std::string::npos) {
            if (set.empty()) continue;
            set.erase(--set.end());
        }
        else {
            ;//??
        }
    }
    
    if (set.empty()) {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    else {
        answer.push_back(*(--set.end()));
        answer.push_back(*set.begin());
        return answer;
    }
}

int main() {
    std::vector<std::string> operations = {"I 16","D 1"};
    std::vector<int> sol = solution(operations);
    std::cout << sol[0] << ", " << sol[1] << std::endl;
    
    std::vector<std::string> op2 = {"I 7","I 5","I -5","D -1"};
    std::vector<int> sol2 = solution(op2);
    std::cout << sol2[0] << ", " << sol2[1] << std::endl;
    
    std::vector<std::string> op3 = {"I -1","I 10","I 3","D 1"};
    std::vector<int> sol3 = solution(op3);
    std::cout << sol3[0] << ", " << sol3[1] << std::endl;
    
    return 0;
}
