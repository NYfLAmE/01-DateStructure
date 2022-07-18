#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const int N = 1010;
char a[1010];

int main()
{
    int t;
    cin >> t;

    getchar();
    while (t --)  
    {
        cin.getline(a, 1010);
        
        int cnt = 0;
        if ((!(a[0] >= '0' && a[0] <= '9')))
        {
            if (strlen(a) <= 32)
            {
                if (strlen(a) == 0)
                {
                    cout << "CE" << endl;
                    continue;
                }
                else
                {
                    for (int i = 0; i < strlen(a); i ++)
                    {
                        if ((a[i] >= '0' && a[i] <= '9') || (a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z') || a[i] == '_' || a[i] == '$' )
                        {
                            cnt ++;
                            continue;
                        }
                        else
                        {
                            if (i == strlen(a) - 1 && a[i] == ' ')
                            {
                                cout << "YES" << endl;
                                break;
                            }
                            cout << "CE" << endl;
                            break;
                        }
                    }
                    if (cnt == strlen(a)) cout << "OK" << endl;
                }
                
            }
            else cout << "CE" << endl;
        }
        else
        {
            cout << "CE" << endl;
        }
    }

    return 0;
}