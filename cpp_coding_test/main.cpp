#include <string>
#include <vector>
#include <iostream>

//기능개발

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    vector<int> remains(progresses.size());
    for (int i=0; i<progresses.size(); i++) {
        remains[i] = ((100-progresses[i]-1) / speeds[i]) + 1;
    }

    int cur_value = -1;
    int cur_len = 0;
    
    for (int i=0; i<remains.size(); i++) {
        if (cur_value < remains[i]) {
            answer.push_back(cur_len);
            cur_value = remains[i];
            cur_len = 1;
        }
        else {
            cur_len++;
        }
    }
    answer.push_back(cur_len);
    answer.erase(answer.begin());
    
    return answer;
}


int main() {
    vector<int> progresses1 = {93, 30, 55};
    vector<int> speeds1 = {1, 30, 5};
    vector<int> ans1 = solution(progresses1, speeds1);
    for(int a : ans1) {
        cout << a; //[2, 1]
    }
    cout << endl;
    
    vector<int> progresses2 = {95, 90, 99, 99, 80, 99};
    vector<int> speeds2 = {1, 1, 1, 1, 1, 1};
    vector<int> ans2 = solution(progresses2, speeds2);
    for(int a : ans2) {
        cout << a; //[1, 3, 2]
    }
    cout << endl;
    
    vector<int> progresses3 = {99, 98, 97, 96, 95, 94};
    vector<int> speeds3 = {1, 1, 1, 1, 1, 1};
    vector<int> ans3 = solution(progresses3, speeds3);
    for(int a : ans3) {
        cout << a; //[1, 3, 2]
    }
    cout << endl;
    
    return 0;
}
