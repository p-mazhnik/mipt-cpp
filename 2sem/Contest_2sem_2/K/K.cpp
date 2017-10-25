//
// Created by pavel on 12.05.2017.
//

#include <iostream>
#include <map>
#include <set>

class Comp{
public:
    bool operator()(std::pair<int, std::string> a, std::pair<int, std::string> b){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int main() {
    std::string word;
    std::map<std::string, int> words;
    while(std::cin >> word){
        words[word]++;
    }
    std::set<std::pair<int, std::string>, Comp> p;
    for(std::map<std::string, int>::iterator it = words.begin(); it != words.end(); ++it){
        p.insert(std::make_pair(it->second, it->first));
        //std::cout << it->first << ' ' << it->second << '\n';
    }
    for(std::set<std::pair<int, std::string>, Comp>::iterator it = p.begin(); it != p.end(); ++it){
        std::cout << it->second << '\n';
    }
    //system("pause");
    return 0;
}