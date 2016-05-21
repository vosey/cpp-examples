//
// Created by wangwei on 16/5/20.
//

#ifndef DMA_H
#define DMA_H

#include <iostream>

//Base Clas Using DMA
class baseDMA
{
private:
    char * label;
    int rating;

public:
    baseDMA(const char * l = "null", int r = 0);
    baseDMA(const baseDMA & rs);
    virtual ~baseDMA();
    baseDMA &operator=(const baseDMA & rs);
    friend std::ostream &operator<<(std::ostream & os, const baseDMA & rs);
};

//derived class without DMA
//no destructor needed
//uses implicit copy constructor
//uses implicit assignment operator
//lacksDMA 没有使用new 分配内存
//lackdDMA 使用了隐式复制构造函数 和 隐式赋值运算符
//所以lacksDMA继承自baseDMA之后无需显式实现析构函数
class lacksDMA : public baseDMA
{
private:
    enum { COL_LEN = 40 };
    char color[COL_LEN];
public:
    lacksDMA(const char * c = "blank", const char * l = "null", int r = 0);
    lacksDMA(const char * c, const baseDMA &rs);
    friend std::ostream &operator<<(std::ostream & os , const lacksDMA &rs);
};

//derived class with DMA
class hasDMA : public baseDMA
{
private:
    char * style;
public:
    hasDMA(const char * s = "none", const char * l = "null", int r = 0);
    hasDMA(const char * s, const baseDMA & rs);
    hasDMA(const hasDMA & hs);
    ~hasDMA();
    hasDMA &operator=(const hasDMA & hs);
    friend std::ostream &operator<<(std::ostream & os, const hasDMA & hs);

};

#endif //DMA_H
