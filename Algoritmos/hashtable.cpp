#include <iostream>

using namespace std;

class Music {
    public:
        string nome = "None";
        int tempo = 0;
        int total = 0;
        int key = 0;
        Music(string s, int t) {
            nome = s;
            tempo = t;
        }
        void Increment() {
            total += tempo;
        }
};

int main() {
    int M, t, count = 0, key;
    string input = "Begin", s;
    Music *spotify = nullptr;

    cin >> M;
    spotify = (Music*) calloc(M, sizeof(Music));
    if (spotify == nullptr) {
        cout << "Chorou" << endl;
        exit(1);
    }

    while (input != "END") {
        cin >> input;
        if (input == "ADD") {
            count++;
            if (count > (M - 1)/2) {
                M = M*2 + 1;
                spotify = (Music*) realloc(spotify, M * sizeof(Music));
                if (spotify == nullptr) {
                    cout << "Chorou2" << endl;
                    exit(1);
                }
            }

            cin >> s >> t;
            for (int i = 0; i < s.length() ; i++) {
                key += s[i]*i;
            }

            bool verif = false;
            for (int i = 0; verif != true; i++) {
                if (spotify[(key + i) % M].tempo == 0) {
                    spotify[(key + i) % M].nome = s;
                    spotify[(key + i) % M].tempo = t;
                    spotify[(key + i) % M].key = key;
                    verif = true;

                    cout << s << " " << (key + i) % M << endl;
                } 
            }

        } else if (input == "PLAY") {
            cin >> s;
            for (int i = 0; i < M; i++) {
                if (s == spotify[i].nome) {
                    spotify[i].Increment();
                    cout << spotify[i].nome << " " << spotify[i].total << endl;
                }
            }
            
        } else if (input == "TIME") {
            cin >> s;
            for (int i = 0; i < M; i++) {
                if (s == spotify[i].nome) {
                    cout << spotify[i].nome << " " << spotify[i].total << endl;
                }
            }
        } else { }
    }
}