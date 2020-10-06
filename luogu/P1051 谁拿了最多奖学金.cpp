#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string max_name, name;
    int max_money = 0, sum_money = 0, score, class_score, article_count, money;
    char is_leader, is_west;
    while (n--) {
        money = 0;
        cin >> name >> score >> class_score >> is_leader >> is_west >> article_count;
        if (score > 80 && article_count > 0) money += 8000;
        if (score > 85 && class_score > 80) money += 4000;
        if (score > 90) money += 2000;
        if (score > 85 && is_west == 'Y') money += 1000;
        if (class_score > 80 && is_leader == 'Y') money += 850;
        if (money > max_money) max_money = money, max_name = name;
        sum_money += money;
    }
    cout << max_name << '\n' << max_money << '\n' << sum_money << endl;
    return 0;
}