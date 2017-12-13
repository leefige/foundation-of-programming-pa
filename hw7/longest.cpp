#include "Program.h"
using namespace std;

int maxSize = 0;

bool comp(const Prog& a, const Prog& b) {
    if (a.st == b.st) {
        return a.ed < b.ed;
    }
    return a.st < b.st;
}

int main(int argc, char** argv) {
    Program prog;
    prog.sortProg(comp);
    int maxLen = 0;
    const vector<Prog>& program = prog.getProg();
    maxSize = program.size();
    printf("total cnt: %d\n", program.size());
    
    for (int i = 0; i < program.size(); i++) {
        int len = 0, curTime = 0;
        for (int j = i + 1; j < program.size(); j++) {
            int len = 0, curTime = 0;
            if(program[i].st >= curTime) {
                curTime = program[i].ed;
                if (argc > 1) {
                    program[i].print();
                }
                cnt++;
            }
        }
        if(program[i].st >= curTime) {
            curTime = program[i].ed;
            if (argc > 1) {
                program[i].print();
            }
            cnt++;
        }
    }
    printf("most cnt: %d\n", cnt);
}

void getMaxLen(int cnt, int& curTime) {
    if (cnt >= maxSize) {
        return;
    }

}