#include "Program.h"
using namespace std;

bool comp(const Prog& a, const Prog& b) {
    if (a.ed == b.ed) {
        return a.st < b.st;
    }
    return a.ed < b.ed;
}

int main(int argc, char** argv) {
    Program prog;
    prog.sortProg(comp);
    int cnt = 0, curTime = 0;

    const vector<Prog>& program = prog.getProg();
    // printf("total cnt: %d\n", program.size());
    
    for (int i = 0; i < program.size(); i++) {
        if(program[i].st >= curTime) {
            curTime = program[i].ed;
            cnt++;
        }
    }
    printf("%d\n", cnt);
}