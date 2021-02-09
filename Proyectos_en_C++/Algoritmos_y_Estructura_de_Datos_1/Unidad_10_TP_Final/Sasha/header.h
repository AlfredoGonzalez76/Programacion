
#ifndef HEADER_H
#define HEADER_H

class Animal
{
protected:
  string name;
  int code;
public:
  virtual void eat() = 0;
  virtual void sleep() = 0;
  void setName();
  void getName();
  void setCode(int);
  void getTipe();
  void toBreed();
};

class Oviparous : public Animal
{
public:
  virtual void eat() = 0;
  virtual void sleep() = 0;
  void layEggs();
};

class Mammal : public Animal
{
public:
  virtual void eat() = 0;
  virtual void sleep() = 0;
  void nurse();
};

class Crocodile : public Oviparous
{
public:
  Crocodile();
  ~Crocodile();
  void eat();
  void sleep();
};

class Goose : public Oviparous
{
public:
  Goose();
  ~Goose();
  void eat();
  void sleep();
};

class Pelican : public Oviparous
{
public:
  Pelican();
  ~Pelican();
  void eat();
  void sleep();
};

class Bat : public Mammal
{
public:
  Bat();
  ~Bat();
  void eat();
  void sleep();
};

class Whale : public Mammal
{
public:
  Whale();
  ~Whale();
  void eat();
  void sleep();
};

class SeaLion : public Mammal
{
public:
  SeaLion();
  ~SeaLion();
  void eat();
  void sleep();
};



#endif