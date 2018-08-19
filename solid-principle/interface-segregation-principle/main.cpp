//
// Created by rajam on 8/18/2018.
//

#include <iostream>
#include <string>
using namespace std;

struct Document;

struct Printer {
    virtual void print(Document& doc) const = 0;
};

struct Scanner {
    virtual void scan(Document& doc) const = 0;
};

struct PrinterImpl : Printer {
protected:
    string name;
public:
    PrinterImpl(const string &name) : name(name) {}

    void print(Document &doc) const override {
        cout << "doc print using : [" << name << "]" << endl;
    }
};

struct ScannerImpl : Scanner {
protected:
    string name;
public:
    ScannerImpl(const string &name) : name(name) {
    }

    void scan(Document &doc) const override {
        cout << "doc scan using: [" << name << "]" << endl;
    }
};

struct Multifunction : Printer, Scanner {};

struct MultifunctionImpl : Multifunction {
protected:
    const Printer &printer;
    const Scanner &scanner;
public:
    MultifunctionImpl(const Printer &printer, const Scanner &scanner)
    : printer(printer), scanner(scanner) {
    }

    void print(Document &doc) const override {
        printer.print(doc);
    }

    void scan(Document &doc) const override {
        scanner.scan(doc);
    }
};

struct Document {
    string header;
    string body;
    string footer;
    int margin[4];
};

int main(int argc, char* argv[]) {
    const Printer &printer = PrinterImpl("samsung-laser");
    const Scanner &scanner = ScannerImpl("samsung-scanfit");
    const Multifunction & mfp = MultifunctionImpl(printer, scanner);
    Document doc;
    mfp.print(doc);
    mfp.scan(doc);
    return 0;
}