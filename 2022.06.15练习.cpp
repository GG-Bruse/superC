//T4
#include<iostream>
using namespace std;
class Commodity
{
        friend char* getName(Commodity& temp);
public:

        bool operator<(const Commodity& temp)const
        {
                return (this->price < temp.price);
        }
        bool operator>=(const Commodity& temp)const
        {
                return this->price >= temp.price;
        }

        Commodity()
        {
                this->count = 0;
                this->number = 0;
                this->p_name = nullptr;
                this->price = 0.0;
        }
        Commodity(long n, char* p, double e, int c)
        {
                this->number = n;
                this->p_name = p;
                this->price = e;
                this->count = c;
        }
        Commodity(const Commodity& temp)
        {
                this->number = temp.number;
                this->p_name = temp.p_name;
                this->price = temp.price;
                this->count = temp.count;
        }
        int getCount()
        {
                return count;
        }
        ~Commodity()
        {
                this->number = 0;
                this->p_name = nullptr;
                this->price = 0.0;
                this->count = 0;
        }
private:
        long number;//商品号
        char* p_name;//商品名
        double price;//商品价格
        int count;//商品总数
};
class CClothes:public Commodity//服装类
{
public:
        CClothes(long n, char* p, double e, int c, char* cl) :Commodity(n, p, e, c)
        {
                this->p_brand = cl;
        }
        void usedFor()
        {
                cout << "服装可用于穿" << endl;
        }
        ~CClothes()
        {
                this->p_brand = nullptr;
        }
private:
        char* p_brand;//品牌
};
class CFood:public Commodity//食品类
{
public:
        CFood(long n, char* p, double e, int c, char* cl) :Commodity(n, p, e, c)
        {
                this->p_brand = cl;
        }
        void usedFor()
        {
                cout << "食品可用于吃" << endl;
        }
        ~CFood()
        {
                this->p_brand = nullptr;
        }
private:
        char* p_brand;//品牌
};

char* getName(Commodity& temp)
{
        return temp.p_name;
}

int main()
{
        Commodity obj1((long)1, (char*)"haha", 10, 10), obj2((long)2, (char*)"hehe", 20, 20);
        cout << (obj1 >= obj2) << endl;
        return 0;
/}








//T5
#include<iostream>
using namespace std;
class Commodity
{
        friend char* getName(Commodity& temp);
public:

        bool operator<(const Commodity& temp)const
        {
                return (this->price < temp.price);
        }
        bool operator>=(const Commodity& temp)const
        {
                return this->price >= temp.price;
        }

        Commodity(long n, char* p, double e, int c)
        {
                this->number = n;
                this->p_name = p;
                this->price = e;
                this->count = c;

                ++total_goods;
                total_price += e;
        }
        Commodity(const Commodity& temp)
        {
                this->number = temp.number;
                this->p_name = temp.p_name;
                this->price = temp.price;
                this->count = temp.count;

                ++total_goods;
                total_price += this->price;
        }
        int getCount()
        {
                return count;
        }

        long getTotalGoods()
        {
                return this->total_goods;
        }
        double getTotalPrice()
        {
                return this->total_price;
        }
        virtual void usedFor() = 0;

        ~Commodity()
        {
                this->number = 0;
                this->p_name = nullptr;
                this->price = 0.0;
                this->count = 0;
        }
private:
        long number;//商品号
        char* p_name;//商品名
        double price;//商品价格
        int count;//商品总数

        static long total_goods;//总商品数
        static double total_price;//商品总价格
};
class CClothes :public Commodity//服装类
{
public:
        CClothes(long n, char* p, double e, int c, char* cl) :Commodity(n, p, e, c)
        {
                this->p_brand = cl;
        }
        void usedFor()
        {
                cout << "服装可用于穿" << endl;
        }
        ~CClothes()
        {
                this->p_brand = nullptr;
        }
private:
        char* p_brand;//品牌
};
class CFood :public Commodity//食品类
{
public:
        CFood(long n, char* p, double e, int c, char* cl) :Commodity(n, p, e, c)
        {
                this->p_brand = cl;
        }
        void usedFor()
        {
                cout << "食品可用于吃" << endl;
        }
        ~CFood()
        {
                this->p_brand = nullptr;
        }
private:
        char* p_brand;//品牌
};

char* getName(Commodity& temp)
{
        return temp.p_name;
}
long Commodity::total_goods = 0;
double Commodity::total_price = 0.0;
int main()
{
        Commodity* ptr = new CClothes((long)111, (char*)"卫衣", 500, 10,(char*)"耐克");
        ptr->usedFor();
        Commodity* ptr2 = new CClothes((long)222, (char*)"卫衣", 200, 5, (char*)"匹克");
        cout << (*ptr >= *ptr2) << endl;
        return 0;
}
