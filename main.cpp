#include <iostream>
#include <cassert>
class TrainCar
{
    int passengersMax = 0;
    int passengers = 0;
    class Train* train = nullptr;
public:
    void load(int value)
    {
        passengers += value;
        if (passengers > passengersMax)
        {
            passengers = passengersMax;
        }
    }
    int getPassengers()
    {
        return passengers;
    }
    TrainCar(class Train* inTrain, int inPassengersMax)
    : train(inTrain), passengersMax(inPassengersMax)
    {
        assert(inTrain != nullptr);
        assert(inPassengersMax >= 0);
    }
    int getNumber();
};
class Train
{
    int count = 5;
    TrainCar** cars = nullptr;
public:
    TrainCar* getCarAt(int index)
    {
        if (this == nullptr) return nullptr;
        if (index < 0) return nullptr;
        if (index >= count) return nullptr;
        return this->cars[index];
    }
    int getCount()
    {
        return count;
    }
    Train(int inCount, int inPassengersMax): count(inCount)
    {
        assert(inCount >= 0);
        cars = new TrainCar*[count];
        for (int i = 0; i < count; ++i)
        {
            cars[i] = new TrainCar(this, inPassengersMax);
        }
    }
};
int TrainCar::getNumber()
{
    for (int i = 0; i < train->getCount(); ++i)
    {
        TrainCar* car = train->getCarAt(i);
        if (car == this) return i;
    }
    assert(false);
}
int main()
{
    Train* train = nullptr;
    train = new Train(10, 30);
    for (int i = 0; i < train->getCount(); ++i)
    {
        int passengers = 0;
        std::cin >> passengers;
        train->getCarAt(i)->load(passengers);
    }
    TrainCar* car3 = train->getCarAt(2);
    std::cout << car3->getNumber() << ": " << car3->getPassengers()
    << std::endl;
}