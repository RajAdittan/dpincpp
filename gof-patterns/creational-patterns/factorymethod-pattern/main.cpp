//
// Created by rajam on 8/20/2018.
//

#include "Memo.h"
#include <iostream>
#include <thread>
#include <zconf.h>

using namespace std;

int main(int argc, char* argv[]) {

    Memo m1 = Memo::Factory.create("crash report", "no crash report");
    Memo m2 = Memo::Factory.create("startup");
    Memo m3 = Memo::Factory.create("close");

    cout << m1;
    m2.setText("application is launched successfully");
    cout << m2;
    sleep(10);
    m3.setText("application is closed with exit 0");
    cout << m3;

    return 0;
}