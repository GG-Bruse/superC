#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <chrono>
using namespace std;

struct SkiplistNode
{
    SkiplistNode(int value, int level)
        :_value(value) ,_nextVector(level, nullptr) {}
    int _value;
    vector<SkiplistNode*> _nextVector;
};

class Skiplist
{
    typedef SkiplistNode Node;
public:
    Skiplist()
    {
        srand(time(0)); //设置随机数种子，后续随机生成结点层数时使用
        _head = new SkiplistNode(-1, 1);//头结点初始层数为1
    }

    bool search(int target)
    {
        Node* current = _head;
        int levelIndex = _head->_nextVector.size() - 1;
        while (levelIndex >= 0)
        {
            //目标值比下一个结点的值大
            if (current->_nextVector[levelIndex] != nullptr && current->_nextVector[levelIndex]->_value < target)
                current = current->_nextVector[levelIndex]; //向右走
            //下一个结点是空(尾)
            //目标值比下一个结点要小
            else if (current->_nextVector[levelIndex] == nullptr || current->_nextVector[levelIndex]->_value > target)
                --levelIndex; //向下走
            else
                return true; //找到了
        }
        return false;
    }

    void add(int number)
    {
        //获取要添加数据的前一个Node的集合
        vector<Node*> prevVector = FindPrevNode(number);

        //随机获取层数，构建新结点并初始化
        int level = RandomLevel();
        Node* newNode = new Node(number, level);

        //若随机获取的层数超过当前最大的层数，那就升高一下_head的层数
        if (level > _head->_nextVector.size()) {
            _head->_nextVector.resize(level, nullptr);
            prevVector.resize(level, _head);
        }

        //链接前后结点
        for (int i = 0; i < level; ++i) {
            newNode->_nextVector[i] = prevVector[i]->_nextVector[i];
            prevVector[i]->_nextVector[i] = newNode;
        }
    }

    bool erase(int number)
    {
        //获取要删除结点的前一个Node的集合
        vector<Node*> prevVector = FindPrevNode(number);

        if (prevVector[0]->_nextVector[0] == nullptr || prevVector[0]->_nextVector[0]->_value != number)
            return false;
        else
        {
            Node* deleteNode = prevVector[0]->_nextVector[0];
            // deleteNode结点每一层的前后指针链接起来
            for (int i = 0; i < deleteNode->_nextVector.size(); ++i)
                prevVector[i]->_nextVector[i] = deleteNode->_nextVector[i];
            delete deleteNode;

            //若删除的是最高层节点，重新调整头结点层数
            int headLevel = _head->_nextVector.size() - 1;
            while (headLevel >= 0)
            {
                if (_head->_nextVector[headLevel] == nullptr)
                    --headLevel;
                else break;
            }
            _head->_nextVector.resize(headLevel + 1);
            return true;
        }
    }

private:
    vector<Node*> FindPrevNode(int number)
    {
        Node* current = _head;
        int levelIndex = _head->_nextVector.size() - 1;

        //待插入结点或待删除结点 的每一层的前一个结点的指针
        vector<Node*> prevVector(levelIndex + 1, _head);

        while (levelIndex >= 0)
        {
            if (current->_nextVector[levelIndex] != nullptr && current->_nextVector[levelIndex]->_value < number)
                current = current->_nextVector[levelIndex];
            else if (current->_nextVector[levelIndex] == nullptr || current->_nextVector[levelIndex]->_value >= number)
            {
                prevVector[levelIndex] = current;
                --levelIndex;
            }
        }
        return prevVector;
    }

    int RandomLevel()
    {
        size_t level = 1;
	    // rand() ->[0, RAND_MAX]之间，将[0,RAND_MAX]看作为[0,1]
        while (rand() <= RAND_MAX * _p && level < _maxLevel)
            ++level;
	    return level;
    }
    int RandomLevelCPP()
    {
        static std::default_random_engine generator(std::chrono::system_clock::now().time_since_epoch().count());
        static std::uniform_real_distribution<double> distribution(0.0, 1.0);

        size_t level = 1;
        while (distribution(generator) <= _p && level < _maxLevel)
            ++level;
        return level;
    }

private:
    Node* _head;
    size_t _maxLevel = 32; //最大层数限制
    double _p = 0.25; //多增加一层的概率
};