#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

class Dictionary {
public:
    int m;      // size of the hash table
    int cnt;    // number of elements
    string* H;     // pointer to the array

    // hash function: tudo ok
    int Hash(string K) {
        int value = 0;

        for (int i = 0; i < K.length(); i++) {
            value += int(K[i]) * (i+1);
        }

        value *= 19;
        return value % 101;
    }

    // constructor: tudo ok
    Dictionary(int size) {
        m = size;
        cnt = 0;
        H = new string[size];

        for (int i=0; i < size; i++) {
            H[i] = "";
        }
    }

    void insert(string key) {
        if (cnt < m && find(key) == -1) {
            int pos = Hash(key);
            int new_pos = pos;

            if (H[pos] != "") {
                
                for (int j = 1; j <= 19; j++) {
                    new_pos = (pos + j*j + 23*j) % 101;

                    if (H[new_pos] == "")
                        break;
                }

                if (H[new_pos] != "")
                    return ;
            }
            H[new_pos] = key;
            cnt++;
        }
        
    }

    int find(string key) {
        int pos = Hash(key);
        
        if (H[pos] == key) {
            return pos;

        } else {
            return collision(key, pos);
        }
    }

    int collision(string key, int pos) {
        int new_pos;
        
        for (int j = 1; j <= 19; j++) {
            new_pos = (pos + j*j + 23*j) % 101;

            if (H[new_pos] == key) {
                return new_pos;
            }
        }

        return -1;
    }

    void remove(string key) {
        if (cnt > 0 && find(key) != -1) {
            int pos = Hash(key);
            int new_pos = pos;

            if (H[pos] != key) {
                for (int j = 1; j <= 19; j++) {
                    new_pos = (pos + j*j + 23*j) % 101;

                    if (H[new_pos] == key) {
                        break;
                    }
                }
            }

            H[new_pos] = "";
            cnt--;
            
        }
    }

    void print() {
        for (int i = 0; i < m; i++) {
            cout << i << ": " << H[i] << "\n";
        }
    }
};


int main() {
    int n_test_cases;
    cin >> n_test_cases;

    int n_operations;


    string entrada, chave;
    for (int i = 0; i < n_test_cases; i++) {
        Dictionary hash_map(101);
            
        cin >> n_operations;
        for (int k=0; k < n_operations; k++) {
            cin >> entrada;
            
            chave = entrada.substr(4);
            if(entrada.substr(0, 3) == "ADD") {
                hash_map.insert(chave);

            } else if (entrada.substr(0, 3) == "DEL") {
                hash_map.remove(chave);
            }
        }

        cout << hash_map.cnt << '\n';
        int counter = 1, z = 0;

        while (counter <= hash_map.cnt) {

            if(hash_map.H[z] != "") {
                counter++;
                    cout << z << ":" << hash_map.H[z] << "\n";
            }
            z++;
        }
     }
}
