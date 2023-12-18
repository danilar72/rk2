#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


class FoodItem {
protected:
    string name;
    string date;
public:
    FoodItem(const string& name, const string& date): name(name),date(date){}

    virtual ~FoodItem() {}

    virtual void displayInfo() const {
        cout << name << ", " << date << endl;
    }
    void setdate(const string& newDate) {
        date = newDate;
    }
};

class Vegetable : public FoodItem {
protected:
    string tip;
public:
    Vegetable(const string& name, const string& date, const string& tip)
        :FoodItem(name,date),tip(tip) {}
    void displayInfo() const override {
        cout << name << ", " << date << ", " << tip << endl;
    }
    void settip(const string& newtip) {
        tip = newtip;
    }
};

class DairyProduct : public FoodItem {
protected:
    int fat ;
public:
    DairyProduct(const string& name, const string& date, int fat)
        :FoodItem(name, date), fat(fat) {}
    void displayInfo() const override {
        cout << name << ", " << date << ", " << fat << endl;
    }
    void setfat(int newfat){
        fat = newfat;
    }
};

void modifyFoodItem(FoodItem* FoodItem) {
    FoodItem->setdate("New date");
}

int main() {
    vector<FoodItem*> FoodItems;
    FoodItems.push_back(new Vegetable("Помидор", "02.05.12", "Классный"));
    FoodItems.push_back(new DairyProduct("Молоко", "02.06.12", 27));

    for (FoodItem* FoodItem : FoodItems) {
        modifyFoodItem(FoodItem);
        FoodItem->displayInfo();
    }

    for (FoodItem* FoodItem : FoodItems) {
        delete(FoodItem);
    }
}
