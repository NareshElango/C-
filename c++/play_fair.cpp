#include <iostream>
#include <vector>
using namespace std;

vector<int> getpos(char p, char mat[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (mat[i][j] == p) {
                return {i, j};
            }
        }
    }
    // Return a default value if the character is not found (you might want to handle this differently)
    //return {-1, -1};
}

string encrypt(string p, char mat[5][5]) {
    int r1, c1, r2, c2;
    vector<int> temp;
    string cipher = "";
    for (int i = 0; i < p.size(); i += 2) {
        temp = getpos(p[i], mat);
        r1 = temp[0];
        c1 = temp[1];

        temp = getpos(p[i + 1], mat); // Fix here
        r2 = temp[0];
        c2 = temp[1];

        if(r1==r2){
            cipher=cipher+mat[r1][(c1==4)?0:c1+1]+mat[r2][(c2==4)?0:c2+1];
        }
        else if(c1==c2){
            cipher=cipher+mat[(r1==4)?0:r1+1][c1]+mat[(r2==4)?0:r2+1][c2];
        }
        else{
            cipher=cipher+mat[r1][c2]+mat[r2][c1];
        }
    
    }
    return cipher;
}

string decrypt(string p, char mat[5][5]) {
    int r1, c1, r2, c2;
    vector<int> temp;
    string cipher = "";
    for (int i = 0; i < p.size(); i += 2) {
        temp = getpos(p[i], mat);
        r1 = temp[0];
        c1 = temp[1];

        temp = getpos(p[i + 1], mat); // Fix here
        r2 = temp[0];
        c2 = temp[1];

       if(r1==r2){
            cipher=cipher+mat[r1][(c1==0)?4:c1-1]+mat[r2][(c2==0)?4:c2-1];
        }
        else if(c1==c2){
            cipher=cipher+mat[(r1==0)?4:r1-1][c1]+mat[(r2==0)?4:r2-1][c2];
        }
        else{
            cipher=cipher+mat[r1][c2]+mat[r2][c1];
        }
    
    }
    return cipher;
}

int main() {
    char mat[5][5];
    string key = "KEYWORD";
    bool iskeypres[26] = {false};
    int r = 0, c = 0;

    for (int i = 0; i < key.size(); i++) {
        iskeypres[key[i] - 'A'] = true;
        mat[r][c] = key[i];
        c++;
        if (c > 4) {
            c = 0;
            r++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (i == 9) {
            continue;
        } else if (!iskeypres[i]) { // Check if the position is not occupied by the key
            mat[r][c] = 'A' + i;
            c++;
            if (c > 4) {
                c = 0;
                r++;
            }
        }
    }

    // Separate matrix input loop
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;

    string plain, encryptt, decryptt;
    cin >> plain;
    for (int i = 0; i < plain.size(); i++) {
        plain[i] = toupper(plain[i]);
        if (plain[i] == 'J') {
            plain[i] = 'I';
        }
    }

    for (int i = 0; i < plain.size(); i += 2) {
        if (plain[i] == plain[i + 1]) {
            plain[i + 1] = 'X';
        }
    }

    if (plain.size() % 2 != 0) {
        plain += 'X';
    }

    cout << "Plain text: " << plain << endl;
    encryptt = encrypt(plain, mat);
    cout << "Encrypted: " << encryptt << endl;
    decryptt = decrypt(encryptt, mat);
    cout << "Decrypted: " << decryptt << endl;

    return 0;
}
