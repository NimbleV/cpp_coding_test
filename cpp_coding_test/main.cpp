#include <string>
#include <vector>
#include <algorithm>
#include "iostream"

using namespace std;

// dynamic programing
int shortest(int start, vector<int> NotA, int totalLen) {
    if(NotA.empty()) return 0;

    int r = NotA.front();
    NotA.erase(NotA.begin());
    int rr;
    if(r-start>=0)
        rr = (r - start) + shortest(r, NotA, totalLen);
    else
        rr = (totalLen - start + r) + shortest(r, NotA, totalLen);
    NotA.insert(NotA.begin(), r);

    int l = NotA.back();
    NotA.erase(NotA.end()-1);
    int ll;
    if (start-l>=0)
        ll = (start - l) +  shortest(l, NotA, totalLen);
    else
        ll = (totalLen - l + start) +  shortest(l, NotA, totalLen);
    NotA.push_back(l);

    return min(rr, ll);
}

int solution(string name) {
    int answer = 0;
    vector<int> NotA;
    for(int i=0; i<name.size(); i++) {
        int d = name[i] - 'A';
        answer += min(d, 26-d);
        if (d!=0) NotA.push_back(i);
    }

    int l = shortest(0, NotA, (int)name.size());
    answer += l;

    return answer;
}


//// greedy
//int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };
//
//int solution(string name) {
//    int answer = 0;
//    for (auto ch : name)
//        answer += LUT[ch - 'A'];
//    int len = name.length();
//    int left_right = len - 1;
//    for (int i = 0; i < len; ++i) {
//        int next_i = i + 1;
//        while (next_i < len && name[next_i] == 'A')
//            next_i++;
//        left_right = min(left_right, i + len - next_i + min(i, len - next_i));
//    }
//    answer += left_right;
//    return answer;
//}


int main() {
    {
        int s = solution("JDIAGKLPALEINAAEBINQ");//149
        cout << s << endl;
    }
    {
        int s = solution("JEROEN");//56
        cout << s << endl;
    }
    {
        int s = solution("JAN");//23
        cout << s << endl;
    }
    {
        int s = solution("CANAAAAANAN");//48
        cout << s << endl;
    }
    {
        int s = solution("BBBBAAAABA");//12
        cout << s << endl;
    }
    {
        int s = solution("BBBBAAAAAB");//10
        cout << s << endl;
    }
    {
        int s = solution("AABAAAAAAABBB");//11
        cout << s << endl;
    }
    {
        int s = solution("AAB");//2
        cout << s << endl;
    }
    
    return 0;
}




//vector<pair<int, int>> sol(int n, int m, int x, int y, vector<vector<int>> queries) {
//    vector<pair<int, int>> starts;
//    if (queries.empty()) {
//        starts.push_back(make_pair(x, y));
//        return starts;
//    }
//
//    vector<int> query = queries.back();
//    queries.erase(queries.end());
//
//    //query를 이용해서 starts를 구체적으로 계산하고 starts에 저장한다.
//    //starts = ???
//
//    long long sum = 0;
//    vector<pair<int, int>> new_starts;//(starts.begin(), starts.end());//copy
//    for (pair<int, int> s : starts) {
//        new_starts = sol(n, m, s.first, s.second, queries);
//        sum += new_starts.size();
//    }
//
//    return new_starts;
//}
//
//long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
//    long long answer = -1;
//
//    answer = sol(n, m, x, y, queries);
//
//    return answer;
//}
//
//int main() {
//    vector<vector<int>> query1 = {{2,1},{0,1},{1,1},{0,1},{2,1}};//4
//    long long sol1 = solution(2,2,0,0,query1);
//    std::cout << sol1 << endl;
//
//    vector<vector<int>> query2 = {{3,1},{2,2},{1,1},{2,3},{0,1},{2,1}};//2
//    long long sol2 = solution(2,5,0,1,query2);
//    std::cout << sol2 << endl;
//
//    return 0;
//}
