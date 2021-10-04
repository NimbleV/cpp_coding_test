#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//디스크 컨트롤러

int solution(vector<vector<int>> jobs) {
    //set<vector<int>> s (jobs.begin(), jobs.end());
    //시작시간으로 정렬
    sort(jobs.begin(), jobs.end(), [](vector<int>a, vector<int>b) {
        return a.front() < b.front();
    });
    jobs.push_back({1000*10000,10000});
    
    int begin_time = 0;
    int total_time = 0;
    vector<vector<int>> jobs_can_begin;
    
    for(int i=0; i<jobs.size(); ) {
        vector<int> job = jobs[i];
        
        //time보다 작은 것 모으기
        if (begin_time >= job.front()) {
            jobs_can_begin.push_back(job);
            i++;//next item
            continue;
        }

        //소요시간으로 정렬
        sort(jobs_can_begin.begin(), jobs_can_begin.end(), [](vector<int>a, vector<int>b) {
            return a.back() < b.back();
        });
        
        //시간 업데이트
        for(vector<int> job : jobs_can_begin) {
            total_time += begin_time + job.back() - job.front();//소요시간 - 시작시간
            begin_time += job.back();//시작한 일들의 모든 소요시간을 더한다.
        }
        
        //reset
        jobs_can_begin.clear();
        
        if (i==jobs.size()-1) {
            break;
        }
    }
    
    return total_time / (jobs.size()-1);
}


int main() {
    //vector<vector<int>> jobs = { {0, 3}, {1, 9}, {2, 6} };
    vector<vector<int>> jobs = { {2, 6}, {0, 3}, {1, 9} };
    int sol = solution(jobs);
    std::cout << sol << std::endl;

    
    return 0;
}
