#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

//이중우선순위큐

std::vector<int> solution(std::vector<std::string> operations) {
    std::vector<int> answer;

    while (!operations.empty()) {
        std::string s = operations.front();
        operations.erase(operations.begin());

        if (s.find("I") != std::string::npos) {
            std::string sub = s.substr(2);
            int i = std::atoi(sub.c_str());
            //std::cout << i << std::endl;
            answer.push_back(i);
            std::sort(answer.begin(), answer.end(), [] (int a, int b) {
                return a>b;
            });
        }
        else if (s.find("D 1") != std::string::npos) {
            if (answer.empty()) continue;
            answer.erase(answer.begin());
        }
        else if (s.find("D -1") != std::string::npos) {
            if (answer.empty()) continue;
            answer.erase(answer.end()-1);
        }
        else {
            ;//??
        }
    }

    if (answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    else {
        int f = answer.front();
        int b = answer.back();
        answer.clear();
        answer.push_back(f);
        answer.push_back(b);
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
