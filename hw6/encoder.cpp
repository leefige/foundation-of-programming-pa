#include <fstream>
#include <cstring>
using namespace std;

void checker();

int main(int argc, char** argv) {
    const char* key = "liyifei";
    const int keyLen = strlen(key);
    
    ifstream fin;
    fin.open("plainText.txt");

    ofstream fout;
    fout.open("cipherText.txt");

    int cur = 0;
    fin>>noskipws; 
    while (!fin.eof()) {
        char word;
        fin >> word;
        if (!(word >= 'a' && word <= 'z')) {
            fout << word;
            continue;
        }
        char cipher = (word + (key[cur % keyLen] - 'a') - 'a') % 26 + 'a';
        fout << cipher;
        cur++;
    }
    fout.close();
    fin.close();
    if (argc > 1) {
        checker();
    }
    return 0;
}

void checker() {
    ifstream fin1, fin2;
    fin1.open("plainText.txt");
    fin2.open("cipherText.txt");

    char buf1[20], buf2[20];
    while (!fin1.eof() && !fin2.eof()) {
        fin1 >> buf1;
        fin2 >> buf2;
        printf("%s -> %s\n", buf1, buf2);
    }
    fin1.close();
    fin2.close();
}
