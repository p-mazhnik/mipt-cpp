#include <iostream>
#include <map>
#include <set>

std::string phone(std::string &word){
    size_t pos = 0;
    while (pos < word.size()) {
        pos = word.find_first_of("()-+", pos);
        if (pos < word.size())
            word.erase(pos, 1);
    }
    return word;
}

int main()
{
    std::map<std::string, std::pair<std::set<std::string>, std::string> > name;
    std::map<std::string, bool> name_bool;
    std::map<std::string, std::set<std::string> > phone_name;
    std::string text;
    std::string command1;
    std::cin >> command1;
    while(command1 != "finish"){
        std::string command2;
        if(command1 == "add"){
            std::cin >> command2;
            std::string fio;
            getline(std::cin, text);
            text += ' ';
            bool flag = 1;
            size_t prev = 0, cur;
            while((cur = text.find(' ', prev)) != std::string::npos){
                std::string word = text.substr(prev, cur - prev); //с какого символа и сколько символов
                unsigned long long k = word.find('@');
                if(flag && word.find_first_of("7891234560") != std::string::npos && k == std::string::npos){
                    if((command2 == "person" && name_bool[fio]) || (command2 == "phone" && !name_bool[fio])){
                        flag = 0;
                    } else {
                        ///телефонный номер
                        std::string ph = phone(word);
                        if (command2 == "person" || name[fio].first.find(ph) == name[fio].first.end()) {
                            name[fio].first.insert(ph);
                            phone_name[ph].insert(fio);
                        } else {
                            flag = 0;
                        }
                    }
                }
                else if(command2 == "person" && flag && k != std::string::npos){
                    if(name_bool[fio]) {
                        flag = 0;
                    } else {
                        ///email
                        name[fio].second = word;
                    }
                }
                else{
                    if(fio.size() == 0){
                        fio = (word);
                    }
                    else{
                        fio += (' ' + word);
                    }
                }
                prev = cur + 1;
            }
            if(command2 == "person" && name_bool[fio]){
                flag = 0;
            }
            if(flag){
                std::cout << "DONE" << '\n';
                name[fio];
                name_bool[fio] = 1;
            } else{
                std::cout << "FAIL" << '\n';
            }
        }
        if(command1 == "replace"){
            std::cin >> command2;
            std::string fio;
            getline(std::cin, text);
            text += ' ';
            bool flag = 1; //успешность функции
            bool flag2 = 0; //0 - старый телефон
            size_t prev = 0, cur;
            std::string old_number;
            while(flag && (cur = text.find(' ', prev)) != std::string::npos){
                std::string word = text.substr(prev, cur - prev); //с какого символа и сколько символов
                unsigned long long k = word.find('@');
                if(command2 == "phone" && word.find_first_of("7891234560") != std::string::npos){
                    if(!name_bool[fio]){
                        flag = 0;
                    } else {
                        ///телефонный номер
                        std::string ph = phone(word);
                        if(flag2 == 0) {
                            old_number = ph;
                        }
                        if (name[fio].first.find(ph) == name[fio].first.end()) {
                            if(flag2 == 0) {
                                flag = 0;
                            } //если не нашли старый номер
                            else {
                                name[fio].first.erase(old_number);
                                phone_name[old_number].erase(fio);
                                if(phone_name[old_number].size() == 0) {
                                    phone_name.erase(old_number);
                                }
                                name[fio].first.insert(ph);
                                phone_name[ph].insert(fio);
                            }
                        } else {
                            if(flag2 == 0) {
                                flag2 = 1;
                            }
                            else {
                                flag = 0;
                            }
                        }
                    }
                }
                else if(command2 == "email" && k != std::string::npos){
                    if(!name_bool[fio]) {
                        flag = 0;
                    } else {
                        ///email
                        name[fio].second = word;
                    }
                }
                else{
                    if(fio.size() == 0){
                        fio += (word);
                    }
                    else{
                        fio += (' ' + word);
                    }
                }
                prev = cur + 1;
            }
            if(flag){
                std::cout << "DONE" << '\n';
            } else{
                std::cout << "FAIL" << '\n';
            }
        }
        if(command1 == "delete"){
            std::cin >> command2;
            bool flag = 1;
            if(command2 == "person"){
                std::string fio;
                getline(std::cin, fio);
                fio.erase(0, 1);
                if(!name_bool[fio]){
                    flag = 0;
                } else{
                    for(std::set<std::string>::iterator it = name[fio].first.begin(); it != name[fio].first.end(); ++it){
                        phone_name[*it].erase(fio);
                        if(phone_name[*it].size() == 0) {
                            phone_name.erase(*it);
                        }
                    }
                    name.erase(fio);
                    name_bool[fio] = 0;
                }
            }
            if(command2 == "phone"){
                getline(std::cin, text);
                text += ' ';
                std::string fio;
                size_t prev = 0, cur;
                while(flag && (cur = text.find(' ', prev)) != std::string::npos){
                    std::string word = text.substr(prev, cur - prev); //с какого символа и сколько символов
                    if(word.find_first_of("7891234560") != std::string::npos){
                        if(!name_bool[fio]){
                            flag = 0;
                        } else {
                            ///телефонный номер
                            std::string ph = phone(word);
                            if (name[fio].first.find(ph) == name[fio].first.end()) {
                                flag = 0;
                            } else {
                                name[fio].first.erase(ph);
                                phone_name[ph].erase(fio);
                                if(phone_name[ph].size() == 0) {
                                    phone_name.erase(ph);
                                }
                            }
                        }
                    }
                    else{
                        if(fio.size() == 0){
                            fio += (word);
                        }
                        else{
                            fio += (' ' + word);
                        }
                    }
                    prev = cur + 1;
                }
            }
            if(flag){
                std::cout << "DONE" << '\n';
            } else{
                std::cout << "FAIL" << '\n';
            }
        }
        if(command1 == "print"){
            std::cin >> command2;
            bool flag = 1;
            if(command2 == "person"){
                std::string fio;
                getline(std::cin, fio);
                fio.erase(0, 1);
                if(!name_bool[fio]){
                    flag = 0;
                } else{
                    std::cout << "Name: " << fio;
                    if(name[fio].first.size() != 0){
                        std::cout << "; Phones: ";
                    }
                    for(std::set<std::string>::iterator it = name[fio].first.begin(); it != name[fio].first.end(); ++it){
                        std::cout << *it;
                        if(it != --name[fio].first.end()){
                            std::cout << ", ";
                        }
                    }
                    if(name[fio].second != ""){
                        std::cout << "; Email: " << name[fio].second;
                    }
                    std::cout << '\n';
                }
            }
            if(command2 == "phone"){
                std::string ph;
                getline(std::cin, ph);
                ph.erase(0, 1);
                ph = phone(ph);
                if(phone_name[ph].size() == 0){
                    flag = 0;
                }
                else{
                    std::cout << "Names: ";
                    for(std::set<std::string>::iterator it = phone_name[ph].begin(); it != phone_name[ph].end(); ++it){
                        std::cout << *it;
                        if(it != --phone_name[ph].end()){
                            std::cout << ", ";
                        }
                    }
                    std::cout << '\n';
                }
            }
            if(!flag) {
                std::cout << "FAIL\n";
            }
        }
        if(command1 == "pr"){
            for(std::map<std::string, std::pair<std::set<std::string>, std::string> >::iterator it = name.begin(); it != name.end(); ++it){
                std::cout << it->first << " Email: " << it->second.second << " Phone: ";
                for(std::set<std::string>::iterator it2 = it->second.first.begin(); it2 != it->second.first.end(); ++it2){
                    std::cout << *it2 << ' ';
                }
                std::cout << '\n';
            }
        }
        std::cin >> command1;
    }
    return 0;
}
