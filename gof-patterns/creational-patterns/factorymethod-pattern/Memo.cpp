//
// Created by rajam on 8/20/2018.
//

#include "Memo.h"

function<Memo()> Memo::factory(string title) {
    return [=]{ return move(Memo(title));};
}

function<Memo()> Memo::factory(string title, string text) {
    return [=]{ return move(Memo(title, text)); };
}