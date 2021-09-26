#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

//다리를 지나는 트럭

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int> bridge;
    for (int i=0; i<bridge_length; i++) {
        bridge.push(0);
    }
    int total_weight=0;
    
    for (int i=0; i<truck_weights.size(); ) {//여기서는 마지막 차를 다리에 올리는 것까지만 계산.
        total_weight -= bridge.front();//다리를 건넌 차 무게 제거.
        bridge.pop();
        
        if (total_weight + truck_weights[i] <= weight) {//무게가 허용되면 다리에 올린다.
            total_weight += truck_weights[i];
            bridge.push(truck_weights[i]);
            i++;//다음 차 대기.
        } else {
            bridge.push(0);//차를 못 올리면. 0은 빈 칸.
        }
        
        answer++;
    }
    
    answer += bridge_length;//마지막 차가 다리를 지나는데 필요한 추가 시간.
    
    return answer;
}

int main() {
    int bridge_length = 2;
    int weight = 10;
    std::vector<int> truck_weights = {7, 4, 5, 6};
    int ans = solution(bridge_length, weight, truck_weights);//8
    std::cout << ans << std::endl;
    
    int bridge_length2 = 100;
    int weight2 = 100;
    std::vector<int> truck_weights2 = {10};
    int ans2 = solution(bridge_length2, weight2, truck_weights2);//10
    std::cout << ans2 << std::endl;
    
    int bridge_length3 = 100;
    int weight3 = 100;
    std::vector<int> truck_weights3 = {10,10,10,10,10,10,10,10,10,10};
    int ans3 = solution(bridge_length3, weight3, truck_weights3);//11
    std::cout << ans3 << std::endl;
    
    return 0;
}
