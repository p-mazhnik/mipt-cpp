//
// Created by pavel on 06.12.2017.
//

#include <iostream>
#include <vector>

std::vector<int> Z_function(std::string str) {
    std::vector<int> z (str.length());
    z[0] = str.length();
	for (int i = 1, l = 0, r = 0; i < str.length(); ++i) {
		if (i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
		while (i + z[i] < str.length() && str[z[i]] == str[i + z[i]]) {
            ++z[i];
        }
		if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
	}
	return z;
}

int main(){
	std::string input;
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> input;
	std::vector<int> z = Z_function(input);
	for (int i = 0; i < z.size(); ++i) {
		std::cout << z[i] << ' ';
	}
	return 0;
}