#include "Program.h"
using namespace std;

void Program::read(string file) {
#ifdef DEBUG
    printf("Reading %s\n", file.c_str());
#endif

    ifstream fin(file.c_str());
    if (!fin.is_open()) {
        printf("bad file: %s\n", file.c_str());
        return;
    }

    while(fin.get() != EOF) {
        fin.unget();

        int sth, stm, edh, edm, pref;
        char tp;
        fin >> sth >> tp >> stm >> tp >> edh >> tp >> edm >> tp;
        while (fin.get() != '\t') {
            // name
        }
        fin >> pref;
        fin.get();  // \n
        programs.push_back(Prog(sth, stm, edh, edm, pref));

#ifdef DEBUG
        printf("%d:%d-%d:%d %d\n", sth, stm, edh, edm, pref);
#endif
    }
    fin.close();
}

void Program::sortProg(bool (*comp)(const Prog&, const Prog&)) {
        sort(programs.begin(), programs.end(), comp);
#ifdef DEBUG
        for (int i = 0; i < programs.size(); i++) {
            printf("%d:%d\n", programs[i].len, programs[i].pref);
        }
#endif
    }