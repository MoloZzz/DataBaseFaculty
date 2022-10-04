#pragma once
#include<iostream>

void admin() {

	system("cls");
	std::cout << "This is admin menu" << std::endl;
	int l = 0;
	while (true) {
		std::cout << "press 1 to come back" << std::endl;
		std::cin >> l;
		if (l == 1) {
			return;
		}
	}
}