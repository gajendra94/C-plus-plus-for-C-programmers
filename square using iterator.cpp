#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template<typename ForwardIterator>
void square(ForwardIterator first , ForwardIterator last)
{
    for(; first!=last ; first++)
        *first = (*first)*(*first);
}
int main()
{
    vector<int> sample(10);

    for(int i=0 ; i<sample.size() ; i++)
        sample[i] = i;

    square(sample.begin() , sample.end());

    for(int i=0 ; i<sample.size() ; i++)
        cout<<sample[i]<<endl;

    return 0;
}
