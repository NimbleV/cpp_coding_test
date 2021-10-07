#include "iostream"
#include <string>
#include <vector>

using namespace std;

vector<pair<int, int>> sol(int n, int m, int x, int y, vector<vector<int>> queries) {
    vector<pair<int, int>> starts;
    if (queries.empty()) {
        starts.push_back(make_pair(x, y));
        return starts;
    }

    vector<int> query = queries.back();
    queries.erase(queries.end());
    
    //query를 이용해서 starts를 구체적으로 계산하고 starts에 저장한다.
    //starts = ???
    
    long long sum = 0;
    vector<pair<int, int>> new_starts;//(starts.begin(), starts.end());//copy
    for (pair<int, int> s : starts) {
        new_starts = sol(n, m, s.first, s.second, queries);
        sum += new_starts.size();
    }
    
    return new_starts;
}

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = -1;
    
    answer = sol(n, m, x, y, queries);
    
    return answer;
}

int main() {
    vector<vector<int>> query1 = {{2,1},{0,1},{1,1},{0,1},{2,1}};//4
    long long sol1 = solution(2,2,0,0,query1);
    std::cout << sol1 << endl;
    
    vector<vector<int>> query2 = {{3,1},{2,2},{1,1},{2,3},{0,1},{2,1}};//2
    long long sol2 = solution(2,5,0,1,query2);
    std::cout << sol2 << endl;

    return 0;
}
