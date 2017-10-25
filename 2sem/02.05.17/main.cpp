#include <iostream>
#include <string>
#include <sstream>
#include <map>

int main()
{
    std::string text;
    std::stringstream sin("+7(918)8765432"); //????? (stream)
    std::getline(sin, text);
    std::string sw = "en";
    //std::cout << s.find(sw) << '\n';

    /*int count = 0;
    for(size_t pos = s.find(sw); pos < s.size(); pos = s.find(sw, pos + 1)){
        count++;
    }
    std::cout << count;*/

//    //????????? ?? ?????:
//    std::map<std::string, int> words;
//    size_t pos = 0;
//    size_t w_end = 0;
//    while(w_end < text.size()){
//        w_end = text.find_first_of(" \n.,!?", pos);
//        if(pos != w_end){
//            std::string word = text.substr(pos, w_end - pos);
//            words[word]++;
//        }
//        pos = w_end + 1;
//    }
//    for(std::map<std::string, int>::iterator it = words.begin(); it != words.end(); ++it){
//        std::cout << it->first << ' ' << it->second << '\n';
//    }
    //???????? ???????? ?? ??????:
    size_t pos = 0;
    while(pos < text.size()){
        pos = text.find_first_of("()-+", pos);
        if(pos < text.size())
            text.erase(pos, 1);
    }
    std::cout << text;
    if(phone[0] == '7' || phone[0] == '8'){
        phone.replace(0, 1, "+7");
    }
    return 0;
}
