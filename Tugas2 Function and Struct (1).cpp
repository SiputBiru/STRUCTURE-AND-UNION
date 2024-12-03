#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

struct studentType{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

studentType siswa[20];

void data_siswa();
void nilai_siswa();
int nilaimaks(studentType listnilai[]);
string pemiliknilai(int nilai);

const int jumlah_siswa = 20;
int main(){
    data_siswa();
    nilai_siswa();
    
    int nilai_maksimum = nilaimaks(siswa);

    string pemilik = pemiliknilai(nilai_maksimum);
    cout << "Nilai tertinggi kelas adalah " << nilai_maksimum << ", yang dimiliki oleh " << pemilik;
    return 0;
}

void data_siswa(){
    ifstream file ("data siswa.csv");
    int i=0;

    string line;

    getline(file, line);
     while (getline(file, line) && i < jumlah_siswa){
        istringstream ss(line);
        string namadepan, namabelakang, stringnilai;
        int nilaites;

        getline(ss, namadepan, ',');
        getline(ss, namabelakang, ',');
        getline(ss, stringnilai, ',');
        nilaites = stoi(stringnilai);

        siswa[i].studentFName = namadepan;
        siswa[i].studentLName = namabelakang;
        siswa[i].testScore = nilaites;
        i++;
    }

    file.close();
}

void nilai_siswa(){
    for (int j=0; j<jumlah_siswa; j++){
        if(siswa[j].testScore >= 85){
            siswa[j].grade = 'A';
        } 
        else if(siswa[j].testScore >= 70 && siswa[j].testScore < 85){
            siswa[j].grade = 'B';
        } 
        else if(siswa[j].testScore >= 60 && siswa[j].testScore < 70){
            siswa[j].grade = 'C';
        } 
        else{
            siswa[j].grade = 'D';
        }
    }   

    cout  << '\n'
                << "Berikut tabel nilai siswa satu kelas:" << '\n'
                << "-------------------------------------------" << '\n';

    cout  << left << setw(19) << "Nama siswa" << setw(15) << "Nilai siswa" 
                << setw(11) << "Predikat" << '\n'
                << "-------------------------------------------" << '\n';
    for(int k=0; k<jumlah_siswa; k++){
        cout  <<  left <<  setw(24)
                    << siswa[k].studentLName + ", " + siswa[k].studentFName 
                    << setw(13) << siswa[k].testScore
                    << setw(5) <<  siswa[k].grade;
        cout << '\n';
    }
    
    cout << '\n';
}

int nilaimaks(studentType listnilai[]){
    int nilaitop = 0;

    for(int i=0; i<jumlah_siswa; i++){
        if(listnilai[i].testScore > nilaitop){
            nilaitop = listnilai[i].testScore;
        }
    }

    return nilaitop;
}

string pemiliknilai(int nilai){
    string pemilik;

    for(int i=0; i<jumlah_siswa; i++){
        if(nilai == siswa[i].testScore){
            pemilik = siswa[i].studentFName + " " + siswa[i].studentLName;
        }
    }
    
    return pemilik;
}
