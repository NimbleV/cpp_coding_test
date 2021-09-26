//주식가격

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    
    //1. 가장 직관적인 방법
    prices.push_back(-100);//무조건 하락이 되도록 끝에 아주 작은 값을 넣어준다.
    for (int i=0; i<prices.size()-1; i++) {
        for (int j=i+1; j<prices.size(); j++) {
            if (prices[i]>prices[j]) {
                answer[i] = j-i;
                if(j==prices.size()-1) answer[i]--;//마지막까지 와서 하락하면 1을 빼준다.
                break;
            }
        }
    }

//
//    //아래 방법을 시도했으나, 실패 케이스도 나오고, 속도도 느리다고 나온다. 흠... 뭘 잘못했는지?... 나중에 다시 볼 기회가 있을까?
//    //2. local minia를 찾아 놓은후. 먼저 이것들과 비교하여 떨어진 지점을 먼저 찾고, 앞쪽으로 전진하면서 정확한 하락 시점을 찾는다.
//    vector<pair<int, int>> minima; // <min_val, position>
//    prices.push_back(-100);//무조건 하락이 되도록 끝에 아주 작은 값을 넣어준다.
//    int pre_sign = 0;
//    for (int i=0; i<prices.size()-1; i++) {
//        int cur_sign = prices[i+1] - prices[i];
//        if (cur_sign>0 && pre_sign<0) {//부호가 마이너스에서 플러스로 변하는 지점이 local minima이다.
//            minima.push_back(make_pair(prices[i], i));
//        }
//        pre_sign = cur_sign;
//    }
//    minima.push_back(make_pair(-100, prices.size()-1));
//
//    for (int i=0; i<prices.size()-1; i++) {
//        //먼저 minia에서 검색
//        int minima_pos = -1;//아래에서 무조건 계산된다.
//        for (int j=0; minima.size(); j++) {
//            if (i < minima[j].second && prices[i] > minima[j].first) { // minia<min_val, position>
//                minima_pos = minima[j].second;
//                break;
//            }
//        }
//        //앞쪽으로 오면서 크거나 같은 지점을 찾고, 위치를 +1해주면 그 지점이 정확한 하락지점.
//        for (int j=minima_pos-1; j>=i; j--) {
//            if (prices[i]<=prices[j]) {
//                answer[i] = j - i + 1;
//                if(j+1==prices.size()-1) answer[i]--;//마지막까지와서 하락했으면 1을 빼준다.
//                break;
//            }
//        }
//    }
//
    return answer;
}


int main() {
    vector<int> prices = {1, 2, 3, 2, 3};
    vector<int> ans = solution(prices);
    for(int a : ans) {
        std::cout << a << ", ";//[4, 3, 1, 1, 0];
    }
    std::cout << std::endl;
    
    vector<int> prices2 = {1, 5, 6, 4, 3, 2, 1};
    vector<int> ans2 = solution(prices2);
    for(int a : ans2) {
        std::cout << a << ", ";//6,2,1,1,1,1,0
    }
    std::cout << std::endl;

    vector<int> prices3 = {3,6,10,9,8,5,6,7,6,2,11,9,4};
    vector<int> ans3 = solution(prices3);
    for(int a : ans3) {
        std::cout << a << ", ";//9, 4, 1, 1, 1, 4, 3, 1, 1, 3, 1, 1, 0,
    }
    std::cout << std::endl;
    
    vector<int> prices4 = {1,2,3,4,5};
    vector<int> ans4 = solution(prices4);//4, 3, 2, 1, 0,
    for(int a : ans4) {
        std::cout << a << ", ";
    }
    std::cout << std::endl;
    
    vector<int> prices5 = {6,5,4,3,2};
    vector<int> ans5 = solution(prices5);//1, 1, 1, 1, 0,
    for(int a : ans5) {
        std::cout << a << ", ";
    }
    std::cout << std::endl;
    
    vector<int> prices6 = {1,2,1,2,1};
    vector<int> ans6 = solution(prices6);//4,1,2,1,0
    for(int a : ans6) {
        std::cout << a << ", ";
    }
    std::cout << std::endl;
    
    return 0;
}
