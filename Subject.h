#pragma once
#ifndef PART1_OOP5SUBJECT_H
#define PART1_OOP5SUBJECT_H
#include "OOP5EventException.h"
#include <vector>

template<typename T>
class Subject {

    std::vector<Observer<T>*> observers;

public:
    void notify(const T& t) {
        for (Observer<T>* observer : observers) {
            observer->handleEvent(t);
        }
    }
    
    void addObserver(Observer<T>& newObserver) {
        for (auto observer : observers) {
            if (observer == &newObserver)
                throw ObserverAlreadyKnownToSubject();
        }
        observers.push_back(&newObserver);
    }

    void removeObserver(Observer<T>& toRemoveObserver) {
        for(auto it = observers.begin() ; it != observers.end();it++){
            if (*it == &toRemoveObserver) {
                observers.erase(it);
                return;
            }
        }
        throw ObserverUnknownToSubject();
    }
    Subject<T>& operator+=(Observer<T>& observer) {
        addObserver(observer);
        return *this;
    }
    Subject<T>& operator-=(Observer<T>& observer) {
        removeObserver(observer);
        return *this;
    }
    Subject<T>& operator()(const T& t) {
        notify(t);
        return *this;
    }
};

#endif //PART1_OOP5SUBJECT_H
