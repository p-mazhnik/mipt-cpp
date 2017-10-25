//
// Created by pavel on 14.05.2017.
//

#include <iostream>
#include <map>
#include <set>

#define MAX 20000000

class Comp{
public:
    bool operator()(std::pair<int, int> p1, std::pair<int, int> p2){
        return (p1.first < p2.first) || (p1.first == p2.first && p1.second > p2.second);
    }
};

class Radio{
private:
    std::map<int, std::pair<int, bool>, std::greater<int> > id_score; //id = очки + кол-во упоминаний
    std::set<std::pair<int, int>, Comp> score_id; // score = очередь(пары(кол-во голосов, id) )
    int j;
public:
    Radio() : j(1) {};
    int push(int track_id, int score, int c = 0);
    void get();
};

int Radio::push(int track_id, int score, int c) {
    if(score != 0 || c == -1) {
        if (id_score[track_id].second) { //если id уже добавлялся ранее, то удалим его из старого значения баллов
            int k = id_score[track_id].first; //старое кол-во очков
            score_id.erase(std::make_pair(k, track_id)); ///убедиться, что наверху то, что нам нужно(!)
        }
        if(c == -1) id_score[track_id].first = c; // -1
        else id_score[track_id].first += score;
        id_score[track_id].second = 1; // помечаем id использованным
        score_id.insert(std::make_pair(id_score[track_id].first, track_id)); //добавляем новый балл с новым id
    } else{ //score == 0 && c != -1
        if(!id_score[track_id].second){ //если не добавляли
            id_score[track_id].second = 1; // помечаем id использованным
            score_id.insert(std::make_pair(id_score[track_id].first, track_id)); //добавляем новый id к новому баллу
        }
    }
    return id_score[track_id].first;
}

void Radio::get() {
    if((id_score.size() == 0 || score_id.begin()->first <= 0) && score_id.size() < MAX){ //если элементы ещё не добавлялись или все эл-ты с отриц. баллами
        while (id_score[j].first != 0 && j < MAX) ++j; //j - первый неотрицательный id
        push(j, 0);
    }
    int result1 = score_id.rbegin()->second; //track_id c max track_score
    int result2 = score_id.rbegin()->first; //max track_score
    std::cout << result1 << ' ' << result2 << '\n';
    push(result1, 0, -1);
}

int main() {
    std::string s, ip;
    int track_id, time;
    int score;
    Radio r;
    std::map<std::string, std::pair<long long, bool> > ip_time; // ip = time + кол-во обращений к ip
    for(int i = 0; s != "EXIT"; ++i){
        std::cin >> s;
        if(s == "VOTE"){
            std::cin >> ip >> track_id >> score >> time;
            int result;
            long long temp = ip_time[ip].first;
            if(ip_time[ip].second == 0 || temp + 600 <= time){
                result = r.push(track_id, score);
                ip_time[ip].first = time; //меняем время
                ip_time[ip].second = 1; //помечаем ip использованным
            } else{
                result = r.push(track_id, 0);
            }
            std::cout << result << '\n';
        }
        if(s == "GET"){
            r.get();
        }
    }
    //system("pause");
    std::cout << "OK";
    return 0;
}