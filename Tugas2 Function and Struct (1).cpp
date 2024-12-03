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
//struct yang diminta oleh soal

studentType siswa[20];
//deklarasi array siswa dengan index 20 dan bertipe studentType

void data_siswa();
void nilai_siswa();
int nilaimaks(studentType listnilai[]);
string pemiliknilai(int nilai);
//deklarasi fungsi-fungsi yang akan digunakan pada bagian main

const int jumlah_siswa = 20;
//jumlah siswa, bisa disesuaikan lagi agar mudah dalam pengecekan program (testing)
int main(){
    data_siswa();
    nilai_siswa();
    
    int nilai_maksimum = nilaimaks(siswa);

    string pemilik = pemiliknilai(nilai_maksimum);
    cout << "Nilai tertinggi kelas adalah " << nilai_maksimum << ", yang dimiliki oleh " << pemilik;
    return 0;
}

void data_siswa(){
    /*fungsi untuk mendapatkan data identitas 
    siswa berupa nama depan dan belakang siswa dari data csv
    */
    ifstream file ("data siswa.csv");
    int i=0;

    string line;

    getline(file, line);
    //lewati data pada baris pertama yang merupakan header saja

    while (getline(file, line) && i < jumlah_siswa){
        istringstream ss(line);
        string namadepan, namabelakang, stringnilai;
        int nilaites;

        getline(ss, namadepan, ',');
        getline(ss, namabelakang, ',');
        getline(ss, stringnilai, ',');
        /*membaca data yang ada pada file csv
        lalu meng-assign string pada csv menuju 
        variabel yang sesuai*/
        nilaites = stoi(stringnilai);

        siswa[i].studentFName = namadepan;
        siswa[i].studentLName = namabelakang;
        siswa[i].testScore = nilaites;
        i++;
    }

    file.close();
}

void nilai_siswa(){//fungsi untuk membaca nilai siswa pada data csv
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
    }   //penetapan predikat pada setiap siswa sesuai nilainya

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
                    /*output berupa tabel sehingga diperlukan jarak dari 
                    setiap keluaran agar mudah dibaca dan rapi
                    */
        cout << '\n';
    }
    
    cout << '\n';
}

int nilaimaks(studentType listnilai[]){//fungsi untuk mencari nilai tertinggi dari siswa
    int nilaitop = 0;

    for(int i=0; i<jumlah_siswa; i++){
        if(listnilai[i].testScore > nilaitop){
            nilaitop = listnilai[i].testScore;
        }
    }
    //algoritma pencarian nilai tertinggi pada array nilai siswa yang sudah diinputkan sebelumnya
    /*jika variabel nilaitop saat ini lebih dari nilai yang ditemukan di array, maka nilai array
    akan menggantikan nilai dari variabel nilaitop, jika sama atau kurang dari nilai pada array,
    maka nilaitop akan tetap seperti sebelumnya lalu loop berlanjut ke i selanjutnya*/

    return nilaitop;
    //keluaran berupa nilai maksimum yang ada pada array student bagian testScore
}

string pemiliknilai(int nilai){//fungsi untuk mencari pemilik nilai tertinggi
    /*menggunakan input nilai yang didapat dari fungsi nilaimaks maka akan dicari nama pada array student yang
    memiliki nilai tersebut, setelah ketemu nilai yang sama, maka pemiliknya yaitu siswa ke-i akan disebut namanya*/
    string pemilik;

    for(int i=0; i<jumlah_siswa; i++){
        if(nilai == siswa[i].testScore){
            pemilik = siswa[i].studentFName + " " + siswa[i].studentLName;
        }
    }
    
    return pemilik;
    //keluaran berupa string pemilik dengan nama pemilik nilai tertinggi
}