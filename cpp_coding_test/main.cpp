#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

int solution(std::vector<int> priorities, int position) {
    int ans = 1;

    while (1) {
        //find max
        std::vector<int>::iterator iter = std::max_element(priorities.begin(), priorities.end());
        //int max_val = *iter;
        long max_pos = std::distance(priorities.begin(), iter);
        
        //move elements
        for (int i = 0; i < max_pos; i++) {
            priorities.push_back(priorities[0]); // copy back
            priorities.erase(priorities.begin()); // remove front
            position--;
            if (position < 0) position = (int)priorities.size() - 1;
        }

        //check
        if (position == 0) return ans;

        //remove first element
        priorities.erase(priorities.begin());
        position--;
        ans++;
    }

    return 0;
}


int main() {
    std::vector<int> priorities1 = {2, 1, 3, 2};
    int location1 = 2;
    int ans1 = solution(priorities1, location1);//1
    std::cout << ans1 << std::endl;
    
    std::vector<int> priorities2 = {1,1,9,1,1,1};
    int location2 = 0;
    int ans2 = solution(priorities2, location2);//5
    std::cout << ans2 << std::endl;
    
    return 0;
}
