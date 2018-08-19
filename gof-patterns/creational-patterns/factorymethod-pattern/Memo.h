//
// Created by rajam on 8/20/2018.
//

#ifndef FACTORYMETHOD_PATTERN_MEMO_H
#define FACTORYMETHOD_PATTERN_MEMO_H

#include <string>
#include <chrono>
#include <ctime>
#include <ostream>

using namespace std;

class Memo {
    class MemoFactory {
    public:
        static Memo create(string title) { return {title}; }
        static Memo create(string title, string text) { return {title, text}; }
    };
public:

    static MemoFactory Factory;

    const string &getText() const {
        return text;
    }
    void setText(const string &text) {
        Memo::text = text;
        last = chrono::system_clock::now();
    }
    time_t time() const { return move(chrono::system_clock::to_time_t(last)); }

    friend ostream &operator<<(ostream &os, const Memo &memo) {
        time_t t1 = memo.time();
        os << "memo: " << endl << " time: " << ctime(&t1) << " title: " << memo.title << endl << " text: " << memo.text << endl;
        return os;
    }

private:
    Memo()= default;
    Memo(string title) : title(title) { last = {chrono::system_clock::now()}; }
    Memo(string title, string text) : title(title), text(text), last(chrono::system_clock::now()) {}
private:
    chrono::system_clock::time_point last;
    string title;
    string text;

};


#endif //FACTORYMETHOD_PATTERN_MEMO_H
