#include<bits/stdc++.h>
using namespace std;

struct page{
        int num;
        int time;
        };

int findnum(vector<struct page> &V, int val){
        int size = V.size();
        for(int i = 0; i < size; i++){
                if(V[i].num == val)
                   return i + 1;

        }
        return false;
        }

int maxtime(vector<struct page> &V){
        int size = V.size();
        int min = 0;
        for(int i = 0; i < size; i++){
                if(V[min].time > V[i].time)
                        min = i;
        }
        return min;
        }

int main(){
        int n;
        int frame ;

        cout << "Enter the number of page" << endl;
                cin >>n;
        vector<struct page> V(n);
        int stamp = 0;
         cout<<"Enter Number of Frames :\n";
                cin>>frame ;
        cout << "Enter the input string" << endl;
        for(int i = 0; i < frame; i++){
                V[i].time = -1;
                V[i].num = -1;
        }
        int pagerr = 0;
        for(int i = 0; i < frame; i++){
                int x;
                cin >> x;
                if(findnum(V,x) == false){
                        V[i].num = x;
                        V[i].time = stamp;
                        stamp++;
                        pagerr++;
                 }
                 else{
                        int ind = findnum(V,x) - 1;
                        V[ind].time = stamp;
                        stamp++;
                     }
        }

        for(int i = frame; i < n; i++){
                int x;
                cin >> x;
                if(findnum(V,x) == false){
                        int ind = maxtime(V);
                        V[ind].num = x;
                        V[ind].time = stamp;
                        stamp++;
                        pagerr++;
                 }
                 else{
                        int ind = findnum(V,x) - 1;
                        V[ind].time = stamp;
                        stamp++;
                     }

       }
       pagerr++;
       cout<<"Total PageFault :\n" ;
       cout << pagerr << endl;
       return 0;
       }

