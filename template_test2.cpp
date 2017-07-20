#include <iostream>

using namespace std;

template <typename T>
class Item{
    T data;
public:
    T Get() const;
    void SetData(T d);

    template <typename U>
    Item<T>& operator+=(const Item<U>& rhs);

    template <typename U>
    void SetAverageFrom(U u[], int size);
};

template <typename T>
template <typename U>
Item<T>& Item<T>::operator+=(const Item<U>& rhs){
    data += rhs.Get();
    return *this;
}

template <typename T>
void Item<T>::SetData(T d){
    data = d;
}
template <typename T>
T Item<T>::Get() const{
    return data;
}

template <typename T>
template <typename U>
void Item<T>::SetAverageFrom(U u[], int size)
{
    U avg;
    for(int i =0; i<size; i++)
    {
        avg += u[i];
    }
    data = avg.Get()/size;
}

int main()
{
    const int Size = 10;
    Item<long> Values[Size];

    for(int nItem = 0; nItem < Size; ++nItem)
        Values[nItem].SetData(nItem * 40);

    Item<float> FloatItem;
    FloatItem.SetAverageFrom(Values, Size);

    cout << FloatItem.Get() << endl;

    return 0;
}
