#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    fstream file;
    srand(time(NULL));
    file.open("key_value_2.txt",ios::out);
    for(int i=0;i<200000;i++) {//quantity of pairs
        int temp=(rand()%5000000)+1;
        file<<endl<<temp<<" "<<temp/100;
    }
    file.close();
    cout<<"Number were generated";
    return 0;
}