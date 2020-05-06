/*************************************************************************
	> File Name: 5.case.cpp
	> Author:赵睿 
	> Mail: 1767153298@qq.com
	> Created Time: 2020年05月04日 星期一 19时44分37秒
 ************************************************************************/

#include<iostream>
#include<algorithm>

using namespace std;

const int N=3010;

int a[N],b[N];
int f[N][N];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);

    for(int i=1;i<=n;i++)   
        for(int j=1;j<=n;j++)
        {
            f[i][j]=f[i-1][j];
            if(a[i]==b[j])
            {
                f[i][j]=max(f[i][j],1);
                for(int k=1;k<j;k++)
                    if(b[k]<b[j])
                        f[i][j]=max(f[i][j],f[i-1][k]+1);
            }
        }
    int res=0;
    for(int i=1;i<=n;i++) res=max(f[n][i],res);
    cout<< res <<endl;
    return 0;
}

