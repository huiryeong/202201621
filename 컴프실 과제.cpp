#include <iostream>
#include <string>

using namespace std;

// 장소 정보를 저장하기 위한 구조체
struct Location {
    string name;
    string density; // "붐빔" 또는 "여유"
    string restaurants[3]; // 추천 식당 3곳
};

// 장소 데이터 생성
void initializeLocations(Location locations[], int &size) {
    size = 6; // 장소 수
    locations[0] = {"서울", "붐빔", {"식당A", "식당B", "식당C"}};
    locations[1] = {"경기", "여유", {"식당D", "식당E", "식당F"}};
    locations[2] = {"부산", "붐빔", {"식당G", "식당H", "식당I"}};
    locations[3] = {"천안", "여유", {"식당J", "식당K", "식당L"}};
    locations[4] = {"대구", "붐빔", {"식당M", "식당N", "식당O"}};
    locations[5] = {"제주", "여유", {"식당P", "식당Q", "식당R"}};
}

// 사용자에게 지역 입력 받기
void getLocationInfo(Location locations[], int size) {
    string input;
    cout << "지역을 선택하세요: 서울, 경기, 부산, 천안, 대구, 제주" << endl;
    cout << "입력: ";
    cin >> input;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (locations[i].name == input) {
            found = true;
            cout << "인구 밀집도: " << locations[i].density << endl;
            cout << "추천 식당:" << endl;
            for (const auto &restaurant : locations[i].restaurants) {
                cout << "- " << restaurant << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "해당 지역에 대한 정보가 없습니다." << endl;
    }
}

int main() {
    Location locations[10]; // 최대 10개 장소
    int size;

    // 장소 데이터 초기화
    initializeLocations(locations, size);

    // 지역 정보 출력
    getLocationInfo(locations, size);

    return 0;
}
