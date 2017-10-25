//
// Created by pavel on 13.05.2017.
//

#include <iostream>
#include <map>
#include <set>

int main() {
    std::map<std::string, std::map<std::string, long long> > shop;
    std::string name, item;
    long long c;
    while(std::cin >> name) {
        std::cin >> item >> c;
        shop[name][item] += c;
    }
    std::set<std::pair<std::string, std::set<std::pair<std::string, long long> > > > p;
    for(std::map<std::string, std::map<std::string, long long> >::iterator it = shop.begin(); it != shop.end(); ++it){
        std::set<std::pair<std::string, long long> > k;
        for(std::map<std::string, long long>::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            k.insert(std::make_pair(it2->first, it2->second));
        }
        p.insert(std::make_pair(it->first, k));
    }
    for(std::set<std::pair<std::string, std::set<std::pair<std::string, long long> > > >::iterator it = p.begin(); it != p.end(); ++it){
        std::cout << it->first << ":\n";
        for(std::set<std::pair<std::string, long long> >::iterator it2 = it->second.begin(); it2 != it->second.end(); ++it2){
            std::cout << it2->first << ' ' << it2->second << '\n';
        }
    }
    //system("pause");
    return 0;
}