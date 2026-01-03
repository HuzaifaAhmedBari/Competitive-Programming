    #include<iostream>
    #include<cmath>
    using namespace std;
    int main()
    {
        int t;
        cin>>t;
        int n;
        int count=2;
        int flag;
        while(t--)
        {
            flag=1;
            count=2;
            cin>>n;
            if(n==0)
            {
                cout<<0<<endl;
                continue;
            }
            if(n==1)
            {
                cout<<1<<endl;
                continue;
            }
            for(int i=round(sqrt(n));i>=2;i--)
            {
                if (n % i == 0) {
                    count++;
                    if (i != n / i) {
                        count++;
                    }
                }
        
            }
            cout<<count<<endl;
        }
    }
