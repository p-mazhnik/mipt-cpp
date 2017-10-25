//
// Created by pavel on 25.04.2017.
//

#include <iostream>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <sstream>

std::map<std::string, int> result(){
    std::map<std::string, int> map;
    map.insert(std::make_pair("one", 1));
    map.insert(std::make_pair("two", 2));
    map.insert(std::make_pair("three", 3));
    map.insert(std::make_pair("four", 4));
    map.insert(std::make_pair("five", 5));
    map.insert(std::make_pair("six", 6));
    map.insert(std::make_pair("seven", 7));
    map.insert(std::make_pair("eight", 8));
    map.insert(std::make_pair("nine", 9));
    map.insert(std::make_pair("ten", 10));
    map.insert(std::make_pair("eleven", 11));
    map.insert(std::make_pair("twelve", 12));
    map.insert(std::make_pair("thirteen", 13));
    map.insert(std::make_pair("fourteen", 14));
    map.insert(std::make_pair("fifteen", 15));
    map.insert(std::make_pair("sixteen", 16));
    map.insert(std::make_pair("seventeen", 17));
    map.insert(std::make_pair("eighteen", 18));
    map.insert(std::make_pair("nineteen", 19));
    map.insert(std::make_pair("twenty", 20));
    map.insert(std::make_pair("thirty", 30));
    map.insert(std::make_pair("forty", 40));
    map.insert(std::make_pair("fifty", 50));
    map.insert(std::make_pair("sixty", 60));
    map.insert(std::make_pair("seventy", 70));
    map.insert(std::make_pair("eighty", 80));
    map.insert(std::make_pair("ninety", 90));
    return map;
};

class Comp{
private:
    std::map<std::string, int> numbers = result();
    int conversion(std::string);
public:
    bool operator()(std::string s1, std::string s2){
        return conversion(s1) < conversion(s2);
    }
};

int Comp::conversion(std::string str){
    int result = 0;
    std::istringstream string_stream(str);
    while(!string_stream.eof()){
        std::string s;
        string_stream >> s;
        auto it = this->numbers.find(s);
        if(it != this->numbers.end()){
            result += it->second;
        }
    }
    return result;
}

int main() {
    /*std::queue<int, std::list<int> > que;
    std::set<int, Comp> set;
    set.insert(82);
    set.insert(100);
    set.insert(13);
    set.insert(55);
    set.insert(65);

    for(auto it = set.begin(); it != set.end(); ++it){
        std::cout << *it << " ";
    }
    auto it = set.find(65);
    std::cout << std::endl;
    std::cout << (it != set.end() ? *it : -1);*/
    /*std::cout << map["one"] << std::endl;

    for(auto it = map.begin(); it != map.end(); ++it){
        std::cout << it->first << " " << it->second << std::endl;
    }*/
    std::string s = "0";
    std::set<std::string, Comp> set;
    for(int i = 0; s != "EXIT"; ++i){
        std::cin >> s;
        char str[100];
        std::string str2;
        if(s == "PUSH"){
            std::cin.getline(str, 100);
            str2 = str;
            set.insert(str2);
        }
        if(s == "POP"){
            set.erase(set.begin());
        }
        if(s == "PR"){
            for(std::set<std::string, Comp>::iterator it = set.begin(); it != set.end(); ++it){
                std::cout << *it << ", ";
            }
            std::cout << std::endl;
        }

    }
}