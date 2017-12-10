#include <fstream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Prog {
    int sth, stm, edh, edm;
    int st;
    int ed;
    int len;
    int pref;

    Prog(int _sth, int _stm, int _edh, int _edm, int _pref) {
        sth = _sth;
        stm = _stm;
        edh = _edh;
        edm = _edm;
        st = 60 * _sth + _stm;
        ed = 60 * _edh + _edm;
        len = ed - st;
        pref = _pref;
    }

    void print() const {
        printf("%d:%d-%d:%d %d\n", sth, stm, edh, edm, pref);
    }
};

class Program {
    vector<Prog> programs;
    void read(string file);

public:
    Program() {
        string channels[22] = {"cctv1","cctv11","cctv13","cctv15","cctv3","cctv5","cctv6","cctv8","cctvarabic","cctvfrench","cctvrussian","cctv10","cctv12","cctv14","cctv2","cctv4asia","cctv5plus","cctv7","cctv9","cctvdoc","cctvnews","cctvxiyu"};
        for (int i = 0; i < 22; i++) {
            read(string("./CCTV1208/") + channels[i]);
        }
        
    }

    ~Program() {
        programs.clear();
    }

    const vector<Prog>& getProg() const {
        return programs;
    }

    void sortProg(bool (*comp)(const Prog&, const Prog&));
};
