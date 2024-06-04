#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main(){
    fstream file;
    srand(time(NULL));
    file.open("key_value.txt",ios::out);
    for(int i=0;i<200000;i++) {//quantity of pairs
        int temp=(rand()%500000)+1;
        file<<temp<<" "<<temp/100<<endl;
    }
    file.close();
    cout<<"Number were generated";
    return 0;
}