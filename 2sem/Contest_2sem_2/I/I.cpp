//
// Created by pavel on 09.05.2017.
//

#include <iostream>
#include <map>

int main() {
    std::string s1;
    std::string s2;
    std::map<std::string, std::string> map;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> s1;
        std::cin >> s2;
        map.insert(std::make_pair(s1, s2));
        map.insert(std::make_pair(s2, s1));
    }
    std::string s3;
    std::cin >> s3;
    std::map<std::string, std::string>::iterator it = map.find(s3);
    if(it != map.end() ){
        std::cout << (*it).second;
    }
}