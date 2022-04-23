#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Book
{
        friend bool Search_Book(Book* ,string name);
public:
        Book(string name,string author,string press,int price)
        {
                this->m_BookName = name;
                this->m_BookAuthor = author;
                this->m_BookPress = press;
                this->m_price = price;
        }
        string reName()
        {
                return this->m_BookName;
        }
        void Print()const
        {
                cout << this->m_BookName << " " << this->m_BookAuthor << " " << this->m_BookPress << endl;
        }
private:
        string m_BookName;
        string m_BookAuthor;
        string m_BookPress;
        int m_price;
};
bool Search_Book(Book* b,string name)
{
        if (name == b->reName())
        {
                return true;
        }
        return false;
}
int main()
{
        vector<Book*>v;
        int num;
        cin >> num;
        for (int i = 0; i < num; ++i)
        {
                int price;
                string name, author, press;
                cin >> name >> author >> press;
                cin >> price;
                Book* bp = new Book(name, author, press, price);
                v.push_back(bp);
        }
        string test_book;
        cin >> test_book;
        bool ret;
        for (vector<Book*>::iterator it = v.begin(); it != v.end(); ++it)
        {
                ret = Search_Book(*it, test_book);
                if (ret == true)
                {
                        (*it)->Print();
                        break;
                }
        }
        if (ret == false)
        {
                cout << "没有该书" << endl;
        }
        return 0;
}
