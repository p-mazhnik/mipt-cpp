//
// Created by pavel on 15.05.2017.
//

#include <iostream>
#include <list>

int main(){
    std::string s;
    std::list<char> result;
    std::list<char>::iterator it = result.begin();
    getline(std::cin, s);
    for (int i = 0; i < s.size(); ++i) {
        switch (s[i]){
            case '<':
                if(it != result.begin()) --it;
                break;
            case '>':
                if(it != result.end()) ++it;
                break;
            case '#':
                if(it != result.end()) {
                    it = result.erase(it);
                }
                break;
            case '@':
                if(it != result.begin()) {
                    std::list<char>::iterator temp = it;
                    result.erase(--it);
                    it = temp;
                }
                break;
            case '^':
                it = result.begin();
                break;
            case '$':
                it = result.end();
                break;
            default:
                result.insert(it, s[i]);
        }
    }
    for(std::list<char>::iterator i = result.begin(); i != result.end(); ++i){
        std::cout << *i;
    }
    return 0;
}