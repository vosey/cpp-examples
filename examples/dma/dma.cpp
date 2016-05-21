//
// Created by wangwei on 16/5/20.
//
#include "dma.h"
#include <cstring>

//baseDMA methods
baseDMA::baseDMA(const char *l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

baseDMA::baseDMA(const baseDMA &rs)
{
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
}

baseDMA::~baseDMA()
{
    delete [] label;
}

//基类赋值运算符
baseDMA & baseDMA::operator=(const baseDMA &rs)
{
    if (this == &rs)
        return *this;
    delete [] label;
    label = new char[std::strlen(rs.label) + 1];
    std::strcpy(label, rs.label);
    rating = rs.rating;
    return *this;
}


std::ostream & operator<<(std::ostream & os, const baseDMA & rs)
{
    os << "Label: " << rs.label << std::endl;
    os << "Rating: " << rs.rating << std::endl;
    return os;
}

//lacksDMA methods
lacksDMA::lacksDMA(const char *c, const char *l, int r) : baseDMA(l, r)
{
    //只拷贝39个字符,然后将第40个字符设置为 字符串结束符
    std::strncpy(color, c, 39);
    color[39] = '\0';
}

lacksDMA::lacksDMA(const char *c, const baseDMA &rs) : baseDMA(rs)
{
    //拷贝COL_LEN - 1个字符,并将字符数组最后一个设置为结束符
    std::strncpy(color, c, COL_LEN - 1);
    color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const lacksDMA & ls)
{
    //强制转换为基类引用类型
    //派生类使用基类友元的方式就是进行强制类型转换
    os << (const baseDMA &) ls; //这里实际上是为了提供访问基类的 label 和rating  ,也就是这里输出了label和rating的值
    os << "Color: " << ls.color << std::endl;
    return os;
}

//hasDMA methods
hasDMA::hasDMA(const char * s, const char * l, int r) : baseDMA(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const baseDMA &rs) : baseDMA(rs)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs) : baseDMA(hs)  //执行基类复制构造函数
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete [] style;
}

hasDMA & hasDMA::operator=(const hasDMA &hs)
{
    if (this == &hs)
        return *this;
    baseDMA::operator=(hs); //执行基类的赋值函数
    delete [] style;        //删除原来的style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

std::ostream & operator<<(std::ostream &os, const hasDMA & hs)
{
    os << (const baseDMA &) hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}
