#include <iostream>
#include <iomanip>
#include <list>

struct Station {
	double added_oil;
	double oil_price;
};

void insert(std::list<Station> &list, double oil_price) {
	for (std::list<Station>::iterator iter = list.begin(); iter != list.end(); ++iter) {
		if (iter->oil_price > oil_price) {
			list.insert(iter, { 0.0, oil_price });
			return;
		}
	}
	list.push_back({ 0.0, oil_price });
}

int main() {
	double d1, d2, c, p;
	int n;
	std::cin >> d1 >> c >> d2 >> p >> n;
	std::list<Station> stations;
	stations.push_back({ 0.0, p });

	double distance, oil_price, last_distance = 0.0, oil_require, money = 0.0, oil_remaining;
	std::list<Station>::iterator iter;
	for (int i = 1; i <= n; ++i) {
		std::cin >> distance >> oil_price;
		oil_require = (distance - last_distance) / d2;
		iter = stations.begin();
		while (oil_require) {
			oil_remaining = c - iter->added_oil;
			if (oil_require < oil_remaining) {
				iter->added_oil += oil_require;
				money += oil_require * iter->oil_price;
				break;
			}
			else {
				oil_require -= oil_remaining;
				money += oil_remaining * iter->oil_price;
				stations.erase(iter);
				if (stations.empty()) {
					std::cout << "No Solution" << std::endl;
					return 0;
				}
				iter = stations.begin();
			}
		}
		last_distance = distance;
		insert(stations, oil_price);
	}

	oil_require = (d1 - last_distance) / d2;
	iter = stations.begin();
	while (oil_require) {
		oil_remaining = c - iter->added_oil;
		if (oil_require < oil_remaining) {
			iter->added_oil += oil_require;
			money += oil_require * iter->oil_price;
			break;
		}
		else {
			oil_require -= oil_remaining;
			money += oil_remaining * iter->oil_price;
			stations.erase(iter);
			if (stations.empty()) {
				std::cout << "No Solution" << std::endl;
				return 0;
			}
			iter = stations.begin();
		}
	}
	
	std::cout << std::setprecision(2) << std::fixed << money << std::endl;
	return 0;
}
