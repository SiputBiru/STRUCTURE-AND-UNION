#include <iostream>
#include <cmath>
#include <iomanip>

const double pi = 3.1416;
//deklarasi pi sebagai konstan dengan nilai 3.1416

struct koordinat {
    int x;
    int y;
};
//data structure berupa x dan y yang akan digunakan sebagai titik 1 dan titik 2

//berikut fungsi yang akan digunakan dalam program:
double distance(koordinat& t1, koordinat& t2);
// t1 adalah titik 1 sementara t2 adalah titik 2

double radius(koordinat& pusat, koordinat& titik);
/*titik 1 dianggap sebagai pusat lingkaran sementara titik 2 
dianggap sebagai titik yang berada di keliling lingkaran
*/

double circumference(double radius);
double area(double radius);

int main(){
    koordinat t1, t2;

    //bagian input pengguna
    std:: cout << "Input koordinat titik pertama: " << '\n';
    std:: cout << "x = "; std:: cin >> t1.x;
    std:: cout << "y = "; std:: cin >> t1.y;
    std:: cout << '\n';

    std:: cout << "Input koordinat titik kedua: " << '\n';
    std:: cout << "x = "; std:: cin >> t2.x;
    std:: cout << "y = "; std:: cin >> t2.y;
    std:: cout << '\n';

    double jarak = distance(t1, t2);
    double jari_jari = radius(t1, t2);
    double keliling = circumference(jari_jari);
    double luas_lingkaran = area(jari_jari);

    //penetapan angka desimal di belakang koma sebanyak 2
    std:: cout  << std:: fixed << std:: setprecision (2);

    //bagian output program
    std:: cout  << "-------------------" << '\n';
    std:: cout  << "Jarak antara dua titik tersebut adalah " << jarak << '\n';
    std:: cout  << "Jari-jari lingkaran yang terbentuk adalah " << jari_jari 
                << " (titik pertama adalah pusat lingkaran)" << '\n';
    std:: cout  << "Keliling lingkaran adalah " << keliling << '\n';
    std:: cout  << "Luas lingkaran adalah " << luas_lingkaran << '\n';

    return 0;
}

double distance(koordinat& t1, koordinat& t2){
    return sqrt(pow(t2.x - t1.x, 2) + pow(t2.y - t1.y, 2));
}

double radius(koordinat& pusat, koordinat& titik){
    return distance(pusat, titik);
}

double circumference(double radius){
    return 2*pi*radius;
}

double area(double radius){
    return pi*pow(radius, 2);
}

/* Properti fungsi-fungsi yang digunakan:

1) double distance(koordinat& t1, koordinat& t2)
Formal Parameter = koordinat& t1 dan koordinat& t2
Actual Parameter = t1 dan t2
Function Signature = distance(koordinat&, koordinat&)

2) double radius(koordinat& pusat, koordinat& titik)
Formal Parameter = koordinat& pusat dan koordinat& titik
Formal Parameter = t1 dan t2
Function Signature = radius(koordinat&, koordinat&)

3) double circumference(double radius)
Formal Parameter = double radius
Actual Parameter = jari_jari
Function Signature = circumference(double)

4) double area(double radius)
Formal Parameter = double radius
Actual Parameter = jari_jari
Function Signature = area(double)
*/