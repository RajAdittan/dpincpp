//
// Created by rajam on 8/17/2018.
//

#include "journal.h"
#include "persistor.h"
#include <iostream>

using namespace std;
using namespace solid::principle::single_responsibility;

int main(int argc, char* argv[]) {
    //1. journal responsibility is to provide a journal structure.
    journal j("testing");
    j.add_entry("begin journal");
    j.add_entry("this is a journal");
    j.add_entry("end journal");

    //2. persistor responsibility is to save a journal
    persistor p(j, cout);
    p.save();

    return 0;
}
