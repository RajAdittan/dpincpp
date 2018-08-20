//
// Created by rajam on 8/20/2018.
//

#include "Memo.h"
#include <iostream>
#include <thread>
#include <zconf.h>

using namespace std;

int main(int argc, char* argv[]) {

    // use factory method "create" to create Memo
    // should you consider moving factory method outside of Memo, friends break SOLID-OCP!
    // consider factory methods much closer to relevant class

    Memo m1 = Memo::Factory.create("crash report", "no crash report");
    Memo m2 = Memo::Factory.create("startup");
    Memo m3 = Memo::Factory.create("close");

    cout << m1;
    m2.setText("application is launched successfully");
    cout << m2;
    sleep(10);
    m3.setText("application is closed with exit 0");
    cout << m3;

    //using lambdas to provide functional interfaces
    Memo m4 = Memo::factory("functional interface demo")();
    Memo m5 = Memo::factory("functional interface demo 2")();
    sleep(2);
    m5.setText("this is constructed via functional factory interface");
    cout << m4 << m5;

    return 0;
}