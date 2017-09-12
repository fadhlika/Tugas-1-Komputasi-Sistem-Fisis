#ifndef TUGAS1_H
#define TUGAS1_H

#include <vector>
#include <QtMath>
using namespace std;

class Tugas1
{
public:
    Tugas1();
    void calculate();
    void setInitVelocity(double);
    void setInitPosition(double);
    void setTimeRange(double, double, int);
    void setInitialGuess(double, double);
    vector<double> getAcceleration();
    vector<double> getVelocity();
    vector<double> getPosition();
    vector<double> getTime();
    double getZeroVelocity();
    int size();

private:
    double v0; //Kecepatan awal
    double x0; //Posisi awal
    double dt;
    double ai(double); // fungsi percetapan
    double vi(double); //fungsi kecepatan
    double t_v0; //t saat V = 0
    double x1; //tebakan bisection awal
    double x2; //tebakan bisection akhir
    const double err = 0.1; // toleransi error
    const int limitIterasi = 100; //limit iterasi bisection
    vector<double> T; // array waktu
    vector<double> a; // array percepatan
    vector<double> v; // array keepatan
    vector<double> x; // array posisi
};

#endif // TUGAS1_H
