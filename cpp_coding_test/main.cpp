#include <string>
#include <vector>

#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, int> map_genre_totalPlay; // map<genre, total_play>
    unordered_map<string, vector<pair<int, int>>> map_genre_arr; // map < genre, arr < pair<play, index> > >

    for (int i=0; i<genres.size(); i++) {
        // 1. count total plays of each genres
        string genre = genres[i];
        map_genre_totalPlay[genre] += plays[i]; // add
        // 2. make arrays for each genres
        map_genre_arr[genre].push_back( make_pair(plays[i], i) ); // pair<play, index>
    }
    
    // 3. sort genres by totalPlay
    vector<pair<string, int>> genre_array(map_genre_totalPlay.begin(), map_genre_totalPlay.end());
    sort(genre_array.begin(), genre_array.end(), [] (pair<string, int>& a, pair<string, int>& b) {
        return a.second > b.second;
    });
    
    // 4. get top two songs for each genre
    for (int i=0; i<genre_array.size(); i++) {
        string genre = genre_array[i].first;
        vector<pair<int, int>> arr_play_index = map_genre_arr[genre];
        
        //sort
        sort(arr_play_index.begin(), arr_play_index.end(), [] (pair<int, int>& a, pair<int, int>& b) {
            return a.first> b.first;
        });
        
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
