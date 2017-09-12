#include "tugas1.h"

#include <QDebug>

Tugas1::Tugas1()
{

}

void Tugas1::setInitVelocity(double v){
    v0 = v;
}
void Tugas1::setInitPosition(double x){
    x0 = x;
}
void Tugas1::setTimeRange(double ti, double tf, int N){
    dt = (tf-ti)/N;

    for(double t=ti; t < tf - dt; t += dt){
        T.push_back(t);
        a.push_back(0);
        v.push_back(0);
        x.push_back(0);
    }
}

void Tugas1::setInitialGuess(double a_, double b_){
    x1 = a_;
    x2 = b_;
}

double Tugas1::ai(double t){
    return 2*t*t - 5*t + 10;
}

double Tugas1::vi(double t){
    return (2/3)*t*t*t - (5/2)*t*t + 10*t + v0;
}

void Tugas1::calculate(){
    //Metode euler
    qDebug() << "Calculate";
    a[0] = ai(T[0]);
    v[0] = v0;
    x[0] = x0;
    for(int i=1; i < (int) T.size(); i++){
        a[i] = ai(T[i]);
        v[i] = v[i-1]+a[i]*dt;
        x[i] = x[i-1]+v[i]*dt;
    }

    //Bisection
    int j = 0;
    while(j < limitIterasi){
        double c = (x1 + x2)/2;
        double fa = vi(x1);
        double fb = vi(c);

        qDebug() << fa << fb << c;
        if(fabs(fa*fb) < err){
            t_v0 = c;
            break;
        } else if(fa*fb < 0){
            x2 = c;
        } else if(fa*fb > 0){
           x1 = c;
        }
        j++;
    }

}

int Tugas1::size(){
    return (int) T.size();
}

double Tugas1::getZeroVelocity(){
    return t_v0;
}

vector<double> Tugas1::getTime(){
    return T;
}

vector<double> Tugas1::getAcceleration(){
    return a;
}
vector<double> Tugas1::getVelocity(){
    return v;
}
vector<double> Tugas1::getPosition(){
    return x;
}
