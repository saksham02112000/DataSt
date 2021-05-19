// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int x=10,y=7;
//     int count=0;
//     for(int i=1;i<y;i++)
//     {
//         for (int j = i+1; j <= y; j++)
//         {
//             if((x%i)%j==(x%j)%i)
//             {
//                 count++;
//             }
//         }
        
//     }
//     cout<<count<<endl;return 0;
// }



#include <bits/stdc++.h>
using namespace std;
int main() {
    // your code goes here
    long long m;
    cin>>m;
    while(m--)
    {
        long long n,M;
        cin>>n>>M;
        long long count=0;
        vector<long long> arr(n+1,1);
            for (int a = 2; a <= n; a++) {
                long long x=M%a;
                count+=arr[x];
                for (int b = x ; b <= n; b+=a) {
                        arr[b]++;
                    }
                // for(int i=0;i<=3;i++)
                // {
                //     cout<<arr[i]<<" ";
                // }cout<<endl;
                // }
       cout<<count<<endl;
    }
    return 0;
}
