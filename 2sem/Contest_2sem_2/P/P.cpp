//
// Created by pavel on 14.05.2017.
//

#include <iostream>
#include <map>

class Cache{
private:
    std::map<int, int> q, m;
    size_t size;
    int time;
public:
    Cache(size_t size) : size(size), time(0) {}
    bool get_user(int user_id);
};

bool Cache::get_user(int user_id) {
    this->time++;
    int flag = m[user_id];
    bool result = (bool)flag;
    if(flag == 0){
        m[user_id] = this->time;
        q.insert(std::make_pair(this->time, user_id));
        //std::cout << '\n' << "begin: " << *q.begin() << " end: " << *(--q.end()) << '\n';
        if(q.size() > this->size){
            //std::cout << "big size" << '\n';
            int temp = q.begin()->second;
            q.erase(q.begin()->first);
            m.erase(temp);
        }
    } else{
        q.erase(m[user_id]);
        //std::cout << '\n' << q.size() << " top: " << *q.begin() << " end: " << *(--q.end()) << '\n';
        m[user_id] = this->time;
        q.insert(std::make_pair(this->time, user_id));
        //std::cout << '\n' << "top: " << *q.begin() << " end: " << *(--q.end()) << '\n';
    }
    return !result;
}

int main(){
    size_t size;
    std::cin >> size;
    Cache s(size);
    int i;
    while(std::cin >> i){
        std::cout << s.get_user(i) << ' ';
    }
    return 0;
}