#ifndef PART1_OOP5OBSERVER_H
#define PART1_OOP5OBSERVER_H

template <typename T>
class Observer {
public:
    virtual void handleEvent(const T&) = 0;
    virtual ~Observer() {};
};

#endif //PART1_OOP5OBSERVER_H
