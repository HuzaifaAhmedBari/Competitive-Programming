#include <bits/stdc++.h>
using namespace std;
class Professor {
    public:
        string name;
        static int count;
        int age,pub;
        void input()
        {
            cin>>name;
            cin>>age;
            cin>>pub;
            count++;
        }
        void print()
        {
            cout<<name<<" "<<age<<" "<<pub<<" "<<count<<endl;
        }
};
int Professor::count=0;
class Student {
    public:
        string name;
        static int count;
        int age,sum=0;
        void input()
        {
            cin>>name;
            cin>>age;
            for(int i=0;i<6;i++)
            {
                int temp;
                cin>>temp;
                sum+=temp;
            }
            count++;
        }
        void print()
        {
            cout<<name<<" "<<age<<" "<<sum<<" "<<count<<endl;;
        }
        
};
int Student::count=0;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        if(m==1)
        {
            Professor p;
            p.input();
            p.print();
        }
        else
        {
            Student s;
            s.input();
            s.print();
        }
    }
    return 0;
}