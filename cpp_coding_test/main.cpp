#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

//더 맵게

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //priority_queue<int> q;
    priority_queue<int, vector<int>, std::greater<int>> q;
    
    for (int i : scoville) {
        q.push(i);
    }

//    while (!q.empty()) {
//        cout << q.top() << ",";
//        q.pop();
//    }
    
    while (q.top()<K) {
        if (q.size()<2) return -1;
        
        int least = q.top(); q.pop();
        int second = q.top(); q.pop();
        int new_scoville = least + second * 2;
        q.push(new_scoville);
        
        answer++;
    }
    
    return answer;
}


int main() {
    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int K = 7;
    std::cout << solution(scoville, K) << endl;
    
    vector<int> scoville2 = {1,2,3};
    int K2 = 14;
    std::cout << solution(scoville2, K2) << endl;
    
    return 0;
}
