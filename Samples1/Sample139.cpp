#include<iostream>
using namespace std;
class Showhim{
    int x;
    public:
        Showhim(int x) : x(x){};
        void displayinfo(){
            cout<<x;
        }
};
int main()
{
    Showhim s[2] = {(1),(2)};
    for(int i=0;i<2;i++)
    {
        s[i].displayinfo();
    }
}