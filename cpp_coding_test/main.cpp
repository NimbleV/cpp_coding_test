#include <string>
#include <vector>

#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, int> um_cnt;
    unordered_map<string, vector<pair<int, int>>> um_arr; // pair<play, index>

    for (int i=0; i<genres.size(); i++) {
        // 1. count total plays of each genres
        string s = genres[i];
        if (um_cnt.find(s) == um_cnt.end()) {//can not find
            um_cnt[s] = plays[i];
        } else {
            um_cnt[s] += plays[i];
        }
        // 2. make arrays for each genres
        um_arr[s].push_back( make_pair(plays[i], i) ); // pair<play, index>
    }
    
    // 3. sort genres by um_cnt
    //um_cnt.
    
    
    return answer;
}

int main() {
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500, 600, 150, 800, 2500};
    vector<int> ans = solution(genres, plays);
    for(int a : ans) {
        cout << a;
    }
    cout << endl;
    
    return 0;
}
