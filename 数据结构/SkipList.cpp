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
        srand(time(0)); //������������ӣ�����������ɽ�����ʱʹ��
        _head = new SkiplistNode(-1, 1);//ͷ����ʼ����Ϊ1
    }

    bool search(int target)
    {
        Node* current = _head;
        int levelIndex = _head->_nextVector.size() - 1;
        while (levelIndex >= 0)
        {
            //Ŀ��ֵ����һ������ֵ��
            if (current->_nextVector[levelIndex] != nullptr && current->_nextVector[levelIndex]->_value < target)
                current = current->_nextVector[levelIndex]; //������
            //��һ������ǿ�(β)
            //Ŀ��ֵ����һ�����ҪС
            else if (current->_nextVector[levelIndex] == nullptr || current->_nextVector[levelIndex]->_value > target)
                --levelIndex; //������
            else
                return true; //�ҵ���
        }
        return false;
    }

    void add(int number)
    {
        //��ȡҪ������ݵ�ǰһ��Node�ļ���
        vector<Node*> prevVector = FindPrevNode(number);

        //�����ȡ�����������½�㲢��ʼ��
        int level = RandomLevel();
        Node* newNode = new Node(number, level);

        //�������ȡ�Ĳ���������ǰ���Ĳ������Ǿ�����һ��_head�Ĳ���
        if (level > _head->_nextVector.size()) {
            _head->_nextVector.resize(level, nullptr);
            prevVector.resize(level, _head);
        }

        //����ǰ����
        for (int i = 0; i < level; ++i) {
            newNode->_nextVector[i] = prevVector[i]->_nextVector[i];
            prevVector[i]->_nextVector[i] = newNode;
        }
    }

    bool erase(int number)
    {
        //��ȡҪɾ������ǰһ��Node�ļ���
        vector<Node*> prevVector = FindPrevNode(number);

        if (prevVector[0]->_nextVector[0] == nullptr || prevVector[0]->_nextVector[0]->_value != number)
            return false;
        else
        {
            Node* deleteNode = prevVector[0]->_nextVector[0];
            // deleteNode���ÿһ���ǰ��ָ����������
            for (int i = 0; i < deleteNode->_nextVector.size(); ++i)
                prevVector[i]->_nextVector[i] = deleteNode->_nextVector[i];
            delete deleteNode;

            //��ɾ��������߲�ڵ㣬���µ���ͷ������
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

        //����������ɾ����� ��ÿһ���ǰһ������ָ��
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
	    // rand() ->[0, RAND_MAX]֮�䣬��[0,RAND_MAX]����Ϊ[0,1]
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
    size_t _maxLevel = 32; //����������
    double _p = 0.25; //������һ��ĸ���
};