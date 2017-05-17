//
// Created by pavel on 13.05.2017.
//

#include <iostream>
#include <map>
#include <set>

int main() {
    std::map<std::string, std::set<std::string> > words;

    std::string text;
    while(std::getline(std::cin, text)) {
        size_t pos = 0;
        size_t w_end = 0;
        std::string key;
        while (w_end < text.size()) {
            w_end = text.find_first_of(" \n-,", pos);
            if (pos != w_end) {
                std::string word = text.substr(pos, w_end - pos);
                if (pos == 0) {
                    key = word;
                } else {
                    words[word].insert(key);
                }
            }
            pos = w_end + 1;
        }
    }
    std::set<std::pair<std::string, std::set<std::string> > > p;
    for(std::map<std::string, std::set<std::string> >::iterator it = words.begin(); it != words.end(); ++it){
        p.insert(*it);
    }
    std::cout << p.size() << '\n';
    for(std::set<std::pair<std::string, std::set<std::string> > >::iterator it = p.begin(); it != p.end(); ++it){
        std::cout << it->first << " - ";
        for(std::set<std::string>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            std::cout << *it2;
            if(it2 != --it->second.end()){
                std::cout << ", ";
            }
        }
        std::cout << '\n';
    }
    //system("pause");
    return 0;
}