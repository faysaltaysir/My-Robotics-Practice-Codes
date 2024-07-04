//#include <bits/stdc++.h>
//using namespace std;
//
//class IntegerFactory {
//private:
//    int n;
//    int arr[10001];
//public:
//
//    IntegerFactory (int n, int *ar) {
//        this->n = n;
//        for (int i = 0; i < n; i++)  {
//            arr[i] = ar[i];
//        }
//    }
//    void query () {
//        int c; cin >> c;
//        cout << sum(c) << '\n';
//    }
//
//    int sum (int c) {
//        int tot = 0;
//        for (int i = 0; i < n; i++) {
//            tot += (c == 0 && (arr[i] & 1) or (c == 1 && arr[i] % 2 == 0)? arr[i]:0);
//        }
//
//       return tot;
//    }
//
//};
//
//int main () {
//
//    int n;
//    cin >> n;
//    int ar[n];
//    for (int i = 0; i < n; i++) {
//        cin >> ar[i];
//    }
//
//    IntegerFactory obj(n, ar);
//    obj.query();
//return 0;
//}

#include<iostream>
using namespace std;

class planet{
private:

    string planet_name;
    double distance,diameter;
    int number_of_moon;


public:

    string get_planet_name(){
        return planet_name;
    }
    void set_planet_name(string s){
        planet_name = s;
    }

    int get_no_of_moons(){
        return number_of_moon;
    }
    void set_no_of_moons(int d){
        number_of_moon = d;
    }
    int get_diameter(){
        return diameter;
    }
    void set_diameter(int d){
        diameter = d;
    }
    int get_distance_from_sun(){
        return distance;
    }
    void set_distance_from_sun(int a){
        distance = a;
    }
    friend double light (planet a);
};


double light (planet a) {
    return 1e6 * (double) a.distance / 186000;
}


int main()
{

    int n; cin >> n;
    planet arr[n];
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int a, b, c; cin >> a >> b >> c;
        planet obj;
        obj.set_planet_name (s);
        obj.set_distance_from_sun(a);
        obj.set_diameter(b);
        obj.set_no_of_moons(c);
        arr[i] = obj;
    }

    for (int i = 0; i < n; i++) {
        cout << light(arr[i]) << '\n';
    }
}


//
//
//
//
//
//
//
//
//
//
//
//


