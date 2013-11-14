#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int sides = 6;

inline int r_sides(){ return(rand()%sides +1);}

int main()
{
    const int n_dices = 2;
    int d1 , d2;

    srand(time(NULL));

    cout<<"enter the number of trails";

    int trails;

    cin>>trails;

    int *outcomes = new int[n_dices*sides + 1];

    for(int i=0 ; i<n_dices*sides+1 ; i++)
        outcomes[i] = 0;

    for(int j=0 ; j<trails ; j++)
        outcomes[(d1 = r_sides()) + (d2 = r_sides())]++;

    cout<<"probability \n";

    for(int j=2 ; j< n_dices*sides + 1 ; j++)
        cout<<"j= "<<j<<" p= "<<static_cast<double>(outcomes[j])/trails<<endl;
    cout<<static_cast<double>(rand())/static_cast<double>(RAND_MAX);

    return 0;
}
