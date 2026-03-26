# UBER
# 🚖 Uber Low-Level Design (LLD) in C++

This project is a **Low-Level Design (LLD)** implementation of a simplified **Uber ride-booking system** using **C++** and core **Object-Oriented Programming (OOP)** concepts.

It is designed to demonstrate:
- **OOP principles**
- **Design Patterns**
- **Class relationships**
- **System decomposition**
- **Scalable LLD thinking**

---

# 📌 Features

- Add and manage **Riders**
- Add and manage **Drivers**
- Create and manage **Trips**
- Driver assignment using **Driver Matching Strategy**
- Fare calculation using **Pricing Strategy**
- Thread-safe **Singleton Managers**
- Modular design using **header + cpp + main** structure

---

# 🧠 OOP Concepts Used

This project demonstrates the following OOP principles:

## 1. Encapsulation
Classes hide internal data using `private` members and expose behavior using public methods.

## 2. Abstraction
Abstract base classes are used for:
- `PricingStrategy`
- `DriverMatchingStrategy`

## 3. Inheritance
Used for extending strategy interfaces:
- `DefaultPricingStrategy : PricingStrategy`
- `RatingBasedPricingStrategy : PricingStrategy`
- `LeastTimeBasedMatchingStrategy : DriverMatchingStrategy`

## 4. Polymorphism
Runtime polymorphism is used through strategy pointers:
- `PricingStrategy*`
- `DriverMatchingStrategy*`

## 5. Association / Aggregation / Composition
The project demonstrates real-world object relationships such as:
- `Trip` associated with `Rider` and `Driver`
- `DriverMgr` aggregates multiple `Driver`
- `Driver` composes `Location`

---

# 🎯 Design Patterns Used

## 1. Singleton Pattern
Used for centralized manager classes:
- `RiderMgr`
- `DriverMgr`
- `TripMgr`
- `StrategyMgr`

## 2. Strategy Pattern
Used for pluggable business logic:
- Driver Matching Strategy
- Pricing Strategy

This makes the system **extensible** and easy to maintain.

---

# 🏗️ Class Structure

## Core Entities
- `Rider`
- `Driver`
- `Location`
- `Trip`
- `TripMetaData`

## Manager Classes
- `RiderMgr`
- `DriverMgr`
- `TripMgr`
- `StrategyMgr`

## Strategy Classes
- `PricingStrategy`
  - `DefaultPricingStrategy`
  - `RatingBasedPricingStrategy`

- `DriverMatchingStrategy`
  - `LeastTimeBasedMatchingStrategy`

---

# 🔄 Trip Booking Flow

1. Rider requests a trip
2. `TripMgr` creates `TripMetaData`
3. `StrategyMgr` selects:
   - pricing strategy
   - driver matching strategy
4. Matching strategy finds the best driver
5. Pricing strategy calculates trip fare
6. `Trip` is created and stored
7. Trip details can be displayed

---

# 📂 Project Structure

```bash
UberLLD/
│
├── main.cpp
│
├── Enums.hpp
│
├── Location.hpp
├── Location.cpp
│
├── Rider.hpp
├── Rider.cpp
│
├── Driver.hpp
├── Driver.cpp
│
├── TripMetaData.hpp
├── TripMetaData.cpp
│
├── PricingStrategy.hpp
├── PricingStrategy.cpp
│
├── DriverMatchingStrategy.hpp
├── DriverMatchingStrategy.cpp
│
├── RiderMgr.hpp
├── RiderMgr.cpp
│
├── DriverMgr.hpp
├── DriverMgr.cpp
│
├── StrategyMgr.hpp
├── StrategyMgr.cpp
│
├── Trip.hpp
├── Trip.cpp
│
├── TripMgr.hpp
├── TripMgr.cpp
