//Christian Haase
//Pizza Shop Functions
//Extra: header file & hashmap

#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include "cUtils.h"

using namespace std;

double priceCalc(string pName, double sPrice, double lPrice, double pricePerTopping) {
    double total = 0;
    string userSizeOption = readLine("Would you like a large or small pie?(L or S): ");
    int userPieAmountOption = stoi(readLine("How many pizzas would you like?: "));
    map<string, double> subtotals;

    if (userSizeOption == "L") {
        total += lPrice * userPieAmountOption;
        subtotals.insert({"Large Pie", lPrice * userPieAmountOption});
    } else if (userSizeOption == "S") {
        total += sPrice * userPieAmountOption;
        subtotals.insert({"Small Pie", sPrice * userPieAmountOption});
    } else {
        cout<<"Invalid input."<<endl;
        priceCalc(pName, sPrice, lPrice, pricePerTopping);
    }

    double toppingAmount = stoi(readLine("How many toppings would you like?: "));
    total += toppingAmount * pricePerTopping;
    subtotals.insert({"Toppings", toppingAmount * pricePerTopping});
    cout<<"Receipt: "<<endl;
    for (const auto& [key, value] : subtotals) { //stole this hashmap loop from google
        cout<<key<<"..."<<value<<endl;
    }
    cout<<"Total: "<<total<<endl;
    return total;
};

int main() {
    cout << fixed << setprecision(2);
    string pizzaName = readLine("What's the name of your pizza shop?: ");
    double smallPrice = stod(readLine("What's the price of a small pizza?: ")),
    largePrice = stod(readLine("What's the price of a large pizza?: ")),
    pricePerTopping = stod(readLine("What's the price per topping?: "));
    priceCalc(pizzaName, smallPrice, largePrice, pricePerTopping);
    return 0;
}