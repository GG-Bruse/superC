#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "���鼯.cpp"
using namespace std;



namespace link_table
{
	//������
	template<class W>
	struct Edge
	{
		Edge(int dstI, const W& w) : _destionIndex(dstI), _weight(w), _next(nullptr) {}
		//int _sourceIndex; //��ѡ
		int _destionIndex;
		W _weight;
		Edge<W>* _next;
	};

	template<class V, class W, bool Direction = false>
	class Graph
	{
		typedef Edge<W> Edge;
	public:
		Graph() = default;
		Graph(const V* vertexs, size_t size)
			:_vertexs(vertexs, vertexs + size), _linkTable(size, nullptr)
		{
			for (int i = 0; i < size; ++i)
				_indexMap[vertexs[i]] = i;
		}

		int GetVertexIndex(const V& vertex)
		{
			auto it = _indexMap.find(vertex);
			if (it != _indexMap.end()) return it->second;
			else {
				throw invalid_argument("�����ڵĶ���");
				return -1;
			}
		}

		void AddEdge(const V& src, const V& dst, const W& w)
		{
			int srcIndex = GetVertexIndex(src), dstIndex = GetVertexIndex(dst);

			Edge* newEdge = new Edge(dstIndex, w);
			newEdge->_next = _linkTable[srcIndex];
			_linkTable[srcIndex] = newEdge;
			
			if (Direction == false)
			{
				Edge* newEdge = new Edge(srcIndex, w);
				newEdge->_next = _linkTable[dstIndex];
				_linkTable[dstIndex] = newEdge;
			}
		}

		void Print() 
		{
			int size = _vertexs.size();
			//��ӡ���㼯��
			for (int i = 0; i < size; i++)
				cout << "[" << i << "]->" << _vertexs[i] << " ";
			cout << endl << endl;
			//��ӡ�ڽӱ�
			for (int i = 0; i < size; i++) 
			{
				Edge* cur = _linkTable[i];
				cout << "[" << i << ":" << _vertexs[i] << "]->";
				while (cur) {
					cout << "[" << cur->_destionIndex << ":" << _vertexs[cur->_destionIndex] << ":" << cur->_weight << "]->";
					cur = cur->_next;
				}
				cout << "nullptr" << endl;
			}
		}

	private:
		vector<V> _vertexs;				//���㼯��
		unordered_map<V, int> _indexMap;	//ӳ���ϵ
		vector<Edge*> _linkTable;			//���߱�
	};
}













namespace matrix
{
	template<class V, class W, W MAX_W = INT_MAX, bool Direction = false>
	class Graph
	{
	public:
		Graph() = default;
		Graph(const V* vertex, size_t size)
			:_vertexs(vertex, vertex + size), _matrix(size, vector<int>(size, MAX_W)) 
		{
			for (int i = 0; i < size; ++i)
				_indexMap[vertex[i]] = i;
		}

		//��ȡ�����Ӧ���±�
		int GetVertexIndex(const V& v)
		{
			auto it = _indexMap.find(v);
			if (it != _indexMap.end()) //�������
				return it->second;
			else { //���㲻����
				throw invalid_argument("���㲻����");
				return -1;
			}
		}

		//��ӱ�
		void _AddEdge(int& srcIndex, int& dstIndex, const W& weight)
		{
			_matrix[srcIndex][dstIndex] = weight;
			if (Direction == false)
				_matrix[dstIndex][srcIndex] = weight;
		}
		void AddEdge(const V& source, const V& destion, const W& weight)
		{
			int sourceIndex = GetVertexIndex(source), destionIndex = GetVertexIndex(destion);
			_AddEdge(sourceIndex, destionIndex, weight);
		}

		struct Edge
		{
			Edge(int srcIndex, int dstIndex, const W& weight) 
				:_sourceIndex(srcIndex), _destionIndex(dstIndex), _weight(weight) {}
			bool operator>(const Edge& edge)const {
				return _weight > edge._weight;
			}
			int _sourceIndex;
			int _destionIndex;
			W _weight;
		};
		W Kruskal(Graph<V, W, MAX_W, Direction>& minTree)
		{
			int size = _vertexs.size();
			//��С��������ʼ��
			minTree._vertexs = _vertexs;
			minTree._indexMap = _indexMap;
			minTree._matrix.resize(size, vector<W> (size, MAX_W));
			
			priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;//С��
			for (int i = 0; i < size; ++i)
				for (int j = 0; j < i; ++j)//ֻ��������һ�룬��������ظ��ı�
					if (_matrix[i][j] != MAX_W)
						minHeap.push(Edge(i, j, _matrix[i][j]));

			UnionFindSet ufs(size); //size������Ĳ��鼯, �����л�
			int count = 0; //��ѡ�ߵ�����
			W totalWeight = W(); //��С����������Ȩֵ
			while (!minHeap.empty() && count < size - 1)
			{
				//��ȡ��ʱ��С�ı�
				Edge minEdge = minHeap.top();
				minHeap.pop();
				int srcI = minEdge._sourceIndex, dstI = minEdge._destionIndex;
				W weight = minEdge._weight;
				if (!ufs.IsInSet(srcI, dstI)) //�ߵ�Դ�����Ŀ�궥�㲻��ͬһ������, ���޻�
				{
					minTree._AddEdge(srcI, dstI, weight);
					ufs.Union(srcI, dstI);
					++count;
					totalWeight += weight;
					cout << "ѡ��: " << _vertexs[srcI] << "->" << _vertexs[dstI] << ":" << weight << endl;
				}
			}
			if (count == size - 1) {
				cout << "������С�������ɹ�" << endl;
				return totalWeight;
			}
			else {
				cout << "�޷�������С������" << endl;
				return W();
			}
		}
		W Prim(Graph<V, W, MAX_W, Direction>& minTree, const V& start)
		{
			int size = _vertexs.size();
			//��С��������ʼ��
			minTree._vertexs = _vertexs;
			minTree._indexMap = _indexMap;
			minTree._matrix.resize(size, vector<W>(size, MAX_W));

			int startIndex = GetVertexIndex(start);
			vector<bool> forest(size, false);
			forest[startIndex] = true;
			priority_queue<Edge, vector<Edge>, greater<Edge>> minHeap;

			//����ʼ�������ӵı߼������
			for (int j = 0; j < size; ++j)
				if (_matrix[startIndex][j] != MAX_W)
					minHeap.push(Edge(startIndex, j, _matrix[startIndex][j]));

			int count = 0;
			W totalWeight = W();
			while (!minHeap.empty() && count < size - 1)
			{
				Edge minEdge = minHeap.top();
				minHeap.pop();
				int srcIndex = minEdge._sourceIndex, dstIndex = minEdge._destionIndex;
				W weight = minEdge._weight;

				if (forest[dstIndex] == false) // �ߵ�Ŀ�궥�㻹û�б����뵽forest������
				{
					//��Ŀ�궥�����ӳ�ȥ�ı߼��뵽���ȼ�������
					for (int j = 0; j < size; ++j)
						if (_matrix[dstIndex][j] != MAX_W)
							minHeap.push(Edge(dstIndex, j, _matrix[dstIndex][j]));
					minTree._AddEdge(srcIndex, dstIndex, weight);
					forest[dstIndex] = true;
					++count;
					totalWeight += weight;
					cout << "ѡ��: " << _vertexs[srcIndex] << "->" << _vertexs[dstIndex] << ":" << weight << endl;
				}	
			}
			if (count == size - 1) {
				cout << "������С�������ɹ�" << endl;
				return totalWeight;
			}
			else {
				cout << "�޷�������С������" << endl;
				return W();
			}
		}

		void Dijkstra(const V& source, vector<W>& dist, vector<int>& parentPath)
		{
			int size = _vertexs.size();
			int srcIndex = GetVertexIndex(source);
			dist.resize(size, MAX_W);
			dist[srcIndex] = W();
			parentPath.resize(size, -1);

			vector<bool> S(size, false);//��ȷ�����·���Ķ���ļ���
			for (int i = 0; i < size; ++i)//Ŀ���ǽ�Q�����е����ж��㶼����S����
			{
				//�Ӽ���Q��ѡ��һ������ֵ��С�Ķ���
				W minW = MAX_W;		//��¼��С����ֵ
				int u = -1;			//��¼ӵ����С����ֵ�Ķ���
				for(int j = 0; j < size; ++j)
					if (S[j] == false && dist[j] < minW) {
						minW = dist[j];
						u = j;
					}
				//��ѡ���Ķ������S����
				S[u] = true;
				//��u���ӳ�ȥ�Ķ�������ɳڸ���
				for (int v = 0; v < size; ++v)
				{
					if (S[v] == false && _matrix[u][v] != MAX_W && dist[u] + _matrix[u][v] < dist[v])
					{
						dist[v] = dist[u] + _matrix[u][v];
						parentPath[v] = u;
					}
				}
			}
		}
		bool BellmanFord(const V& source, vector<W>& dist, vector<int>& parentPath)
		{
			int size = _vertexs.size();
			int srcIndex = GetVertexIndex(source);
			dist.resize(size, MAX_W);
			dist[srcIndex] = W();
			parentPath.resize(size, -1);

			for (int k = 0; k < size - 1; ++k) // ������size - 1��
			{
				bool update = false;//��¼�����Ƿ���¹�
				for (int i = 0; i < size; ++i)
				{
					for (int j = 0; j < size; ++j)
					{
						if (_matrix[i][j] != MAX_W && dist[i] != MAX_W && dist[i] + _matrix[i][j] < dist[j])
						{
							dist[j] = dist[i] + _matrix[i][j];
							parentPath[j] = i;
							update = true;
						}
					}
				}
				if (update == false) break;
			}
			for (int i = 0; i < size; ++i) 
				for (int j = 0; j < size; ++j)
					if (_matrix[i][j] != MAX_W && dist[i] + _matrix[i][j] < dist[j])
						return false; //���и�Ȩ��·��ͼ�޷�������·��
			return true;
		}
		void FloydWarshall(vector<vector<W>>& vvDist, vector<vector<int>>& vvParentPath)
		{
			int size = _vertexs.size();
			vvDist.resize(size, vector<W>(size, MAX_W));
			vvParentPath.resize(size, vector<int>(size, -1));

			//�����ڽӾ����ʼ��ֱ�������Ķ���
			for (int i = 0; i < size; ++i)
			{
				for (int j = 0; j < size; ++j)
				{
					if (_matrix[i][j] != MAX_W)//i -> j �б�
					{
						vvDist[i][j] = _matrix[i][j];
						vvParentPath[i][j] = i;
					}
					if (i == j) vvDist[i][j] = W();
				}
			}
			for (int k = 0; k < size; ++k)//����ѡȡ����������Ϊi->j·�����м䶥��
				for (int i = 0; i < size; ++i)
					for (int j = 0; j < size; ++j)
						if (vvDist[i][k] != MAX_W && vvDist[k][j] != MAX_W &&
							vvDist[i][k] + vvDist[k][j] < vvDist[i][j])
						{
							vvDist[i][j] = vvDist[i][k] + vvDist[k][j];
							vvParentPath[i][j] = vvParentPath[k][j];
						}
		}

		//��ӡ���·����·��Ȩֵ
		void PrintShortPath(const V& src, const vector<W>& dist, const vector<int>& parentPath) 
		{
			int n = _vertexs.size();
			int srci = GetVertexIndex(src); //��ȡԴ������±�
			for (int i = 0; i < n; i++) 
			{
				vector<int> path;
				int cur = i;
				while (cur != -1) { //Դ�����ǰ������Ϊ-1
					path.push_back(cur);
					cur = parentPath[cur];
				}
				reverse(path.begin(), path.end()); //����
				for (int j = 0; j < path.size(); j++) {
					cout << _vertexs[path[j]] << "->";
				}
				cout << "·��Ȩֵ: " << dist[i] << "" << endl;
			}
		}
		//��ӡ���㼯�Ϻ��ڽӾ���
		void Print() 
		{
			int size = _vertexs.size();
			//��ӡ���㼯��
			for (int i = 0; i < size; i++)
				cout << "[" << i << "]->" << _vertexs[i] << endl;
			cout << endl;

			//��ӡ�ڽӾ���
			cout << "  ";
			for (int i = 0; i < size; i++)
				printf("%4d", i);
			cout << endl;
			for (int i = 0; i < size; i++) 
			{
				cout << i << " "; //���±�
				for (int j = 0; j < size; j++) 
				{
					if (_matrix[i][j] == MAX_W) printf("%4c", '*');
					else printf("%4d", _matrix[i][j]);
				}
				cout << endl;
			}
			cout << endl;
		}

		void BFS(const V& source)
		{
			int sourceIndex = GetVertexIndex(source);
			queue<int> qe;
			vector<bool> visited(_vertexs.size(), false);
			qe.push(sourceIndex);
			visited[sourceIndex] = true;

			while (!qe.empty())
			{
				int front = qe.front();
				qe.pop();
				cout << _vertexs[front] << " ";
				for (int j = 0; j < _vertexs.size(); ++j)
				{
					if (_matrix[front][j] != MAX_W && visited[j] == false)
					{
						qe.push(j);
						visited[j] = true;
					}
				}
			}
			cout << endl;
		}

		void _DFS(int srcIndex, vector<bool>& visvited)
		{
			cout << _vertexs[srcIndex] << " "; // ����
			visvited[srcIndex] = true;
			for (int j = 0; j < _vertexs.size(); ++j)
				if (_matrix[srcIndex][j] != MAX_W && visvited[j] == false)
					_DFS(j, visvited);
		}
		void DFS(const V& source)
		{
			int sourceIndex = GetVertexIndex(source);
			vector<bool> visvited(_vertexs.size(), false);
			_DFS(sourceIndex, visvited);
			cout << endl;
		}

	private:
		vector<V> _vertexs;					//���㼯��
		unordered_map<V, int> _indexMap;	//����ӳ���±�
		vector<vector<int>> _matrix;		//�ڽӾ���
	};
}






using namespace matrix;
void TestGraph()
{
	Graph<char, int, true> g("0123", 4);
	g.AddEdge('0', '1', 1);
	g.AddEdge('0', '3', 4);
	g.AddEdge('1', '3', 2);
	g.AddEdge('1', '2', 9);
	g.AddEdge('2', '3', 8);
	g.AddEdge('2', '1', 5);
	g.AddEdge('2', '0', 3);
	g.AddEdge('3', '2', 6);
	g.Print();
}
void TestBDFS()
{
	string a[] = { "����", "����", "����", "����", "����" };
	Graph<string, int> g1(a, sizeof(a) / sizeof(string));
	g1.AddEdge("����", "����", 100);
	g1.AddEdge("����", "����", 200);
	g1.AddEdge("����", "����", 30);
	g1.AddEdge("����", "����", 30);
	g1.Print();
	g1.BFS("����");
	g1.DFS("����");
}
void TestGraphMinTree()
{
	const char str[] = "abcdefghi";
	Graph<char, int> g(str, strlen(str));
	g.AddEdge('a', 'b', 4);
	g.AddEdge('a', 'h', 8);
	//g.AddEdge('a', 'h', 9);
	g.AddEdge('b', 'c', 8);
	g.AddEdge('b', 'h', 11);
	g.AddEdge('c', 'i', 2);
	g.AddEdge('c', 'f', 4);
	g.AddEdge('c', 'd', 7);
	g.AddEdge('d', 'f', 14);
	g.AddEdge('d', 'e', 9);
	g.AddEdge('e', 'f', 10);
	g.AddEdge('f', 'g', 2);
	g.AddEdge('g', 'h', 1);
	g.AddEdge('g', 'i', 6);
	g.AddEdge('h', 'i', 7);

	Graph<char, int> kminTree;
	cout << "Kruskal:" << g.Kruskal(kminTree) << endl;
	kminTree.Print();
	cout << endl << endl;

	Graph<char, int> pminTree;
	cout << "Prim:" << g.Prim(pminTree, 'a') << endl;
	pminTree.Print();
	cout << endl;
}
void TestGraphDijkstra()
{
		const char* str = "syztx";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 10);
		g.AddEdge('s', 'y', 5);
		g.AddEdge('y', 't', 3);
		g.AddEdge('y', 'x', 9);
		g.AddEdge('y', 'z', 2);
		g.AddEdge('z', 's', 7);
		g.AddEdge('z', 'x', 6);
		g.AddEdge('t', 'y', 2);
		g.AddEdge('t', 'x', 1);
		g.AddEdge('x', 'z', 4);

		vector<int> dist;
		vector<int> parentPath;
		g.Dijkstra('s', dist, parentPath);
		g.PrintShortPath('s', dist, parentPath);

		// ͼ�д��и�Ȩ·��ʱ��̰�Ĳ�����ʧЧ�ˡ�
		// ���Խ�����Կ���s->t->y֮������·��û���³���
		/*const char* str = "sytx";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 10);
		g.AddEdge('s', 'y', 5);
		g.AddEdge('t', 'y', -7);
		g.AddEdge('y', 'x', 3);
		vector<int> dist;
		vector<int> parentPath;
		g.Dijkstra('s', dist, parentPath);
		g.PrintShortPath('s', dist, parentPath);*/

		//const char* str = "syztx";
		//Graph<char, int, INT_MAX, true> g(str, strlen(str));
		//g.AddEdge('s', 't', 6);
		//g.AddEdge('s', 'y', 7);
		//g.AddEdge('y', 'z', 9);
		//g.AddEdge('y', 'x', -3);
		//g.AddEdge('z', 's', 2);
		//g.AddEdge('z', 'x', 7);
		//g.AddEdge('t', 'x', 5);
		//g.AddEdge('t', 'y', 8);
		//g.AddEdge('t', 'z', -4);
		//g.AddEdge('x', 't', -2);
		//vector<int> dist;
		//vector<int> parentPath;
		//g.Dijkstra('s', dist, parentPath);
		//g.PrintShortPath('s', dist, parentPath);
}
void TestGraphBellmanFord()
{
	const char* str = "syztx";
	Graph<char, int, INT_MAX, true> g(str, strlen(str));
	/*g.AddEdge('s', 't', 10);
	g.AddEdge('s', 'y', 5);
	g.AddEdge('y', 't', 3);
	g.AddEdge('y', 'x', 9);
	g.AddEdge('y', 'z', 2);
	g.AddEdge('z', 's', 7);
	g.AddEdge('z', 'x', 6);
	g.AddEdge('t', 'y', 2);
	g.AddEdge('t', 'x', 1);
	g.AddEdge('x', 'z', 4);*/

	g.AddEdge('s', 't', 6);
	g.AddEdge('s', 'y', 7);
	g.AddEdge('y', 'z', 9);
	g.AddEdge('y', 'x', -3);
	//g.AddEdge('y', 's', 1); // ����
	g.AddEdge('z', 's', 2);
	g.AddEdge('z', 'x', 7);
	g.AddEdge('t', 'x', 5);
	//g.AddEdge('t', 'y', -8); //����
	g.AddEdge('t', 'y', 8);

	g.AddEdge('t', 'z', -4);
	g.AddEdge('x', 't', -2);
	vector<int> dist;
	vector<int> parentPath;
	if (g.BellmanFord('s', dist, parentPath))
		g.PrintShortPath('s', dist, parentPath);
	else
		cout << "����Ȩ��·" << endl;
}
void TestFloydWarShall()
{
	const char* str = "12345";
	Graph<char, int, INT_MAX, true> g(str, strlen(str));
	g.AddEdge('1', '2', 3);
	g.AddEdge('1', '3', 8);
	g.AddEdge('1', '5', -4);
	g.AddEdge('2', '4', 1);
	g.AddEdge('2', '5', 7);
	g.AddEdge('3', '2', 4);
	g.AddEdge('4', '1', 2);
	g.AddEdge('4', '3', -5);
	g.AddEdge('5', '4', 6);
	vector<vector<int>> vvDist;
	vector<vector<int>> vvParentPath;
	g.FloydWarshall(vvDist, vvParentPath);

	// ��ӡ��������֮������·��
	for (size_t i = 0; i < strlen(str); ++i)
	{
		g.PrintShortPath(str[i], vvDist[i], vvParentPath[i]);
		cout << endl;
	}
}
int main()
{
	//TestGraph();
	//TestBDFS();
	//TestGraphMinTree();
	//TestGraphDijkstra();
	//TestGraphBellmanFord();
	TestFloydWarShall();
	return 0;
}