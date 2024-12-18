#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

struct Location {
    string name;
    string density;
    vector<string> restaurants;
};

vector<Location> initializeLocations() {
    return {
        {"서울", "붐빔", {"식당A", "식당B", "식당C"}},
        {"경기", "여유", {"식당D", "식당E", "식당F"}},
        {"부산", "붐빔", {"식당G", "식당H", "식당I"}},
        {"천안", "여유", {"식당J", "식당K", "식당L"}},
        {"대구", "붐빔", {"식당M", "식당N", "식당O"}},
        {"제주", "여유", {"식당P", "식당Q", "식당R"}}
    };
}

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), 
              [](unsigned char c){ return tolower(c); });
    return s;
}

void getLocationInfo(const vector<Location>& locations) {
    string input;
    cout << "어느 지역으로 놀러가나요?: ";
    for (const auto& loc : locations) {
        cout << loc.name << " ";
    }
    cout << "\n입력: ";
    cin >> input;

    auto it = find_if(locations.begin(), locations.end(),
                      [&input](const Location& loc) {
                          return toLower(loc.name) == toLower(input);
                      });

    if (it != locations.end()) {
        cout << "인구 밀집도: " << it->density << endl;
        cout << "추천 식당:" << endl;
        for (const auto& restaurant : it->restaurants) {
            cout << "- " << restaurant << endl;
        }
    } else {
        cout << "해당 지역에 대한 정보가 없습니다." << endl;
    }
}

int main() {
    vector<Location> locations = initializeLocations();

    char continueChoice;
    do {
        getLocationInfo(locations);
        
        cout << "\n계속하시겠습니까? (y/n): ";
        cin >> continueChoice;
    } while (tolower(continueChoice) == 'y');

    cout << "프로그램을 종료합니다." << endl;
    return 0;
}
