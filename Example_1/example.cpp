/*
    Существует контейнер, содержащий в себе пулы IP-адресов.
    Каждый пул имеет уникальный идентификатор и содержит в себе диапазон IP-адресов (т.е. адреса идут последовательно).
    Диапазон может содержать миллионы IP-адресов.
    IP-адреса могут быть в формате IPv4 или IPv6.

    Написать 2 функции поиска пула:
     - по его имени
     - по IP-адресу, который он хранит

    Код не обязан компилироваться, но должен полностью отражать логику работы.
*/

#include <string>
#include <array>
#include <map>
#include <cstdio>
#include <cstdint>
#include "init.h"

using namespace std;

template<typename T>
class Addr
{
    private:
        T addr;
        
    public:
        Addr(string str)
        { /* MAGIC */ }
        
        bool operator<(const Addr<T> &o) const
        { /* MAGIC */ }
        
        bool operator>(const Addr<T> &o) const
        { /* MAGIC */ }
};

template<typename T>
class Pool
{
    private:
        // begin, end
        pair<T, T> addrs;
    
    public:
        bool contains(const T &addr) const
        {
            if (addr < addrs.first || addr > addrs.second)
                return false;
            return true;
        }
};

template <typename T>
class PoolDatabase
{
    private:
        map<string, Pool<T>> pool;
        
    public:
        Pool<T> &poolForAddr(const T &addr) const
        {
            for (auto it : pool) {
                auto value = it.second;
                if (value.contains(addr))
                    return value;
            }
        }
        
        Pool<T> &poolForName(const string &name) const
        {
            return pool[name];
        }
};

using Ip4Addr = Addr<array<uint_least8_t,  4>>;
using Ip6Addr = Addr<array<uint_least8_t, 16>>;

int main()
{
    PoolDatabase<Ip4Addr> pd4;
    PoolDatabase<Ip6Addr> pd6;

    init(pd4);
    init(pd6);
    
    Pool<Ip4Addr> forName = pd4.poolForName("name");
    Pool<Ip4Addr> forAddr = pd4.poolForAddr("192.168.1.1");

    Pool<Ip6Addr> forName = pd6.poolForName("name");
    Pool<Ip6Addr> forAddr = pd6.poolForAddr("1050:0:0:0:5:600:300c:326b");
    Pool<Ip6Addr> forAddr = pd6.poolForAddr("ff06::c3");

    return EXIT_SUCCESS;
}