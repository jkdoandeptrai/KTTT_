#include<iostream>
#include<cmath>
#include<string>
#include<iomanip>
using namespace std;
// công thức 1 bit dấu, 8 bit E, 23 bit F
// (-1)^s, 1.F * 2^(e = E - 127(1023) )   
    // cout<<stoi("10001",NULL,2);
string input(int &in){
    string result;

    cout<<"Single Precision: 1"<<endl;
    cout<<"Double Precision: 2"<<endl;
    cout<<"Nhap lua chon: ";
    cin>>in;
    if (in == 1){
        cout<<"Nhap code: ";
        cin>>result;
        while ( result.length() != 32){
            cout<<"Nhap lai(32bit): ";
            cin>>result;
        }

    } else{
        cout<<"Nhap code: ";
        cin>>result;
        while ( result.length() != 64){
            cout<<"Nhap lai(64bit): ";
            cin>>result;
        }
    }
    return result;
}   
double stoF(string x, int size){
    double F = 1;
    for(int i = 1 ; i <= size; i++ ){
        F = F + (int(x[i-1])-48) *pow(2,-i);
    }
    return F;
}
double Single(string s){
    string S = s.substr(0,1);
    string E = s.substr(1,8);
    string F = s.substr(9);
    return pow(-1, stoi(S,NULL,10))*stoF(F,23)*pow(2,(stoi(E,NULL,2)-127));
}
double Double(string s){ 
    string S = s.substr(0,1);
    string E = s.substr(1,11);
    string F = s.substr(12);
    return pow(-1, stoi(S,NULL,10))*stoF(F,52)*pow(2,(stoi(E,NULL,2)-1023));
}
double decode(){
    int what{-1};
    string x = input(what);
    if (what == 1)
        return Single(x);
    return Double(x);
}
int main(){
    cout<<fixed<<setprecision(100)<<decode();
    return 0;

}

 