#include <string>
#include <vector>

#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp_by_second(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool comp_by_first(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, int> um_genre_totalPlay; // map<genre, total_play>
    unordered_map<string, vector<pair<int, int>>> um_arr; // map < genre, arr < pair<play, index> > >

    for (int i=0; i<genres.size(); i++) {
        // 1. count total plays of each genres
        string genre = genres[i];
        if (um_genre_totalPlay.find(genre) == um_genre_totalPlay.end()) { // can not find
            um_genre_totalPlay[genre] = plays[i]; // init
        } else {
            um_genre_totalPlay[genre] += plays[i]; // add
        }
        // 2. make arrays for each genres
        um_arr[genre].push_back( make_pair(plays[i], i) ); // pair<play, index>
    }
    
    // 3. sort genres by totalPlay
    vector<pair<string, int>> genre_array(um_genre_totalPlay.begin(), um_genre_totalPlay.end());
    sort(genre_array.begin(), genre_array.end(), comp_by_second);
    
    // 4. get top two songs for each genre
    for (int i=0; i<genre_array.size(); i++) {
        string genre = genre_array[i].first;
        
        vector<pair<int, int>> arr_play_index = um_arr[genre];
        
        //sort
        sort(arr_play_index.begin(), arr_play_index.end(), comp_by_first);
        
        //push index to answer
        for (int j=0; j< min((int)arr_play_index.size(), 2); j++) { // max 2
            answer.push_back(arr_play_index[j].second);
        }
    }
    
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
