#include <iostream>
#include <cassert>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>
#include <functional>
#include "并查集.cpp"
using namespace std;





//邻接表
namespace link_table
{
	template<class W>
	struct Edge
	{
		Edge(const int dest, const W& w) :_destinationIndex(dest), _weight(w), _next(nullptr) {}
		int _destinationIndex;//目标点的下标
		W _weight;//权值
		Edge<W>* _next;
	};

	template<class V, class W, bool Direction = false>
	class Graph
	{
		typedef Edge<W> Edge;
	public:
		Graph(const V* v, size_t size)
		{
			_vertexs.reserve(size);
			for (size_t i = 0; i < size; ++i) {
				_vertexs.push_back(v[i]);
				_indexMap[v[i]] = i;
			}
			_table.resize(size, nullptr);
		}
		size_t GetVertexIndex(const V& v)
		{
			auto it = _indexMap.find(v);
			if (it != _indexMap.end()) return it->second;
			else {
				assert(false);
				return -1;
			}
		}
		void AddEdge(const V& src, const V& dest, const W& w)
		{
			size_t srcIndex = GetVertexIndex(src);
			size_t destIndex = GetVertexIndex(dest);

			//头插
			Edge* edge = new Edge(destIndex, w);
			edge->_next = _table[srcIndex];
			_table[srcIndex] = edge;
			//无向图添加两次
			if (Direction == false) {
				Edge* edge = new Edge(srcIndex, w);
				edge->_next = _table[destIndex];
				_table[destIndex] = edge;
			}
		}
		void Print()
		{
			for (size_t i = 0; i < _table.size(); ++i)
			{
				cout << _vertexs[i] << "[" << i << "]->";
				Edge* cur = _table[i];
				while (cur != nullptr)
				{
					cout << _vertexs[cur->_destinationIndex]
						<< "[" << cur->_destinationIndex << "]" << cur->_weight << "->";
					cur = cur->_next;
				}
				cout << "nullptr" << endl;
			}
		}
	private:
		vector<V> _vertexs;//顶点集合
		unordered_map<V, int> _indexMap;//顶点与下标的映射
		vector<Edge*> _table;//邻接表
	};



	void TestGraph()
	{
		string a[] = { "张三", "李四", "王五", "赵六" };
		Graph<string, int, true> g1(a, 4);
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
		g1.Print();
	}
};










//邻接矩阵
namespace matrix
{
	template<class V, class W, W MAX_W = INT_MAX, bool Direction = false>
	class Graph
	{
		typedef Graph<V, W, MAX_W, Direction> Self;
	public:
		Graph() = default;
		Graph(const V* v, size_t size)
		{
			_vertexs.reserve(size);
			for (size_t i = 0; i < size; ++i) {
				_vertexs.push_back(v[i]);
				_indexMap[v[i]] = i;
			}
			_matrix.resize(size);
			for (size_t i = 0; i < size; ++i) {
				_matrix[i].resize(size, MAX_W);
			}
		}

		size_t GetVertexIndex(const V& v) 
		{
			auto it = _indexMap.find(v);
			if (it != _indexMap.end()) return it->second;
			else {
				assert(false);
				return -1;
			}
		}

		void _addEdge(size_t srcIndex, size_t destIndex, const W& w)
		{
			_matrix[srcIndex][destIndex] = w;
			//无向图添加两次
			if (Direction == false) _matrix[destIndex][srcIndex] = w;
		}
		void AddEdge(const V& src, const V& dest, const W& w)
		{
			size_t srcIndex = GetVertexIndex(src);
			size_t destIndex = GetVertexIndex(dest);
			_addEdge(srcIndex, destIndex, w);
		}

		void BFS(const V& src)
		{
			size_t srcIndex = GetVertexIndex(src);
			
			queue<int> qe;
			qe.push(srcIndex);
			vector<bool> visited(_vertexs.size(), false);
			visited[srcIndex] = true;

			while (!qe.empty())
			{
				int front = qe.front();
				qe.pop();
				//访问
				cout << front << ":" << _vertexs[front] << endl;
				//入队列
				for (int j = 0; j < _matrix[front].size(); ++j)
					if (_matrix[front][j] != MAX_W && visited[j] == false) {
						qe.push(j);
						visited[j] = true;
					}
			}
		}

		void _dfs(size_t srcIndex, vector<bool>& visvited)
		{
			cout << srcIndex << ":" << _vertexs[srcIndex] << endl;
			visvited[srcIndex] = true;
			for (size_t j = 0; j < _matrix[srcIndex].size(); ++j)
				if (_matrix[srcIndex][j] != MAX_W && visvited[j] == false)
					_dfs(j, visvited);
		}
		void DFS(const V& src)
		{
			size_t srcIndex = GetVertexIndex(src);
			vector<bool> visvited(_vertexs.size(), false);
			_dfs(srcIndex, visvited);
		}

		struct Edge
		{
			Edge(size_t srci, size_t dsti, const W& w) : _srcIndex(srci), _destIndex(dsti), _w(w) {}
			bool operator>(const Edge& edge) const {
				return _w > edge._w;
			}
			size_t _srcIndex;
			size_t _destIndex;
			W _w;
		};
		W Kruskal(Self& minTree)
		{
			size_t size = _vertexs.size();
			//初始化
			minTree._vertexs = _vertexs;
			minTree._indexMap = _indexMap;
			minTree._matrix.resize(size);
			for (size_t i = 0; i < size; ++i)
				minTree._matrix[i].resize(size, MAX_W);

			priority_queue<Edge, vector<Edge>, greater<Edge>> minqe;
			for (size_t i = 0; i < size; ++i)
				for (size_t j = 0; j < size; ++j)
					if (i < j && _matrix[i][j] != MAX_W)
						minqe.push(Edge(i, j, _matrix[i][j]));

			int count = 0;
			W totalW = W();
			UnionFindSet ufs(size);
			while (!minqe.empty())
			{
				Edge min = minqe.top();
				minqe.pop();
				if (!ufs.IsInSet(min._srcIndex, min._destIndex))
				{
					cout << _vertexs[min._srcIndex] << "-" << _vertexs[min._destIndex] <<
						":" << _matrix[min._srcIndex][min._destIndex] << endl;
					minTree._addEdge(min._srcIndex, min._destIndex, min._w);
					ufs.Union(min._srcIndex, min._destIndex);
					++count;
					totalW += min._w;
				}
			}
			if (count == size - 1) return totalW;
			else return W();
		}
		W Prim(Self& minTree, const W& src)
		{
			size_t size = _vertexs.size();
			size_t srcIndex = GetVertexIndex(src);
			minTree._vertexs = _vertexs;
			minTree._indexMap = _indexMap;
			minTree._matrix.resize(size);
			for (size_t i = 0; i < size; ++i)
				minTree._matrix[i].resize(size, MAX_W);

			vector<bool> X(size, false), Y(size, true);
			X[srcIndex] = true;
			Y[srcIndex] = false;

			priority_queue<Edge, vector<Edge>, greater<Edge>> minqe;
			//先将srcIndex连接的边添加到队列中
			for (size_t j = 0; j < size; ++j)
				if (_matrix[srcIndex][j] != MAX_W)
					minqe.push(Edge(srcIndex, j, _matrix[srcIndex][j]));

			size_t count = 0;
			W totalW = W();
			while (!minqe.empty())
			{
				Edge min = minqe.top();
				minqe.pop();

				if (X[min._destIndex])
				{
					/*cout << "构成环:";
					cout << _vertexs[min._srcIndex] << "->" << _vertexs[min._destIndex] 
						<< ":" << min._w << endl;*/
				}
				else
				{
					minTree._addEdge(min._srcIndex, min._destIndex, min._w);
					/*cout << _vertexs[min._srcIndex] << "->" << _vertexs[min._destIndex]
						<< ":" << min._w << endl;*/
					X[min._destIndex] = true;
					Y[min._destIndex] = false;
					++count;
					totalW += min._w;
					if (count == size - 1) break;
					//将_destIndex连接的边添加到队列中
					for (size_t j = 0; j < size; ++j)
						if (_matrix[min._destIndex][j] != MAX_W && Y[j])
							minqe.push(Edge(min._destIndex, j, _matrix[min._destIndex][j]));
				}
			}
			if (count == size - 1) return totalW;
			else return W();
		}

		void Dijkstra(const V& src, vector<W>& dist, vector<int>& pPath)
		{
			size_t size = _vertexs.size();
			size_t srcIndex = GetVertexIndex(src);
			dist.resize(size, MAX_W);
			pPath.resize(size, -1);

			dist[srcIndex] = 0;
			pPath[srcIndex] = srcIndex;

			//已经确定最短路径的顶点集合
			vector<bool> S(size, false);

			for(size_t count = 0; count < size; ++count)
			{
				//选最短路径顶点更新其他路径
				int u = 0;
				W min = MAX_W;
				for (size_t i = 0; i < size; ++i)
				{
					if (S[i] == false && dist[i] < min) 
					{
						u = i;
						min = dist[i];
					}
				}
				S[u] = true;
				//松弛更新与u连接的顶点
				for (size_t v = 0; v < size; ++v)
				{
					if (_matrix[u][v] != MAX_W && dist[u] + _matrix[u][v] < dist[v])
					{
						dist[v] = dist[u] + _matrix[u][v];
						pPath[v] = u;
					}
				}
			}
		}



		void Print()
		{
			for(int i = 0; i < _vertexs.size(); ++i)
				cout << _vertexs[i] << "-" << i << " ";
			cout << endl << endl;
			cout << "  ";
			for (size_t i = 0; i < _vertexs.size(); ++i)
				printf("%4d ", i);
			cout << endl;
			// 打印矩阵
			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				cout << i << " ";
				for (size_t j = 0; j < _matrix[i].size(); ++j)
				{
					if (_matrix[i][j] != MAX_W)
						printf("%4d ", _matrix[i][j]);
					else
						printf("%4c ", '#');
				}
				cout << endl;
			}
			cout << endl << endl;
			// 打印所有的边
			for (size_t i = 0; i < _matrix.size(); ++i)
			{
				for (size_t j = 0; j < _matrix[i].size(); ++j)
				{
					if (i < j && _matrix[i][j] != MAX_W)
						cout << _vertexs[i] << "-" << _vertexs[j] << ":" << _matrix[i][j] << endl;
				}
			}
		}
		// 打印最短路径的逻辑算法
		void PrinrtShotPath(const V& src, const vector<W>& dist, const vector<int>& parentPath)
		{
			size_t N = _vertexs.size();
			size_t srci = GetVertexIndex(src);
			for (size_t i = 0; i < N; ++i)
			{
				if (i == srci)
					continue;
				vector<int> path;
				int parenti = i;
				while (parenti != srci)
				{
					path.push_back(parenti);
					parenti = parentPath[parenti];
				}
				path.push_back(srci);
				reverse(path.begin(), path.end());
				for (auto pos : path)
					cout << _vertexs[pos] << "->";
				cout << dist[i] << endl;
			}
		}
	private:
		vector<V> _vertexs;//顶点集合
		unordered_map<V, int> _indexMap;//顶点与下标的映射
		vector<vector<W>> _matrix;//邻接矩阵
	};



	void TestGraphDBFS()
	{
		string a[] = { "张三", "李四", "王五", "赵六", "周七" };
		Graph<string, int> g1(a, sizeof(a) / sizeof(string));
		g1.AddEdge("张三", "李四", 100);
		g1.AddEdge("张三", "王五", 200);
		g1.AddEdge("王五", "赵六", 30);
		g1.AddEdge("王五", "周七", 30);
		g1.Print();
		cout << endl;
		g1.BFS("张三");
		cout << endl;
		g1.DFS("张三");
	}
	void TestGraph()
	{
		Graph<char, int, INT_MAX, true> g("0123", 4);
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
	void TestGraphMinTree()
	{
		const char* str = "abcdefghi";
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
		Graph<char, int> pminTree;
		cout << "Prim:" << g.Prim(pminTree, 'a') << endl;
		pminTree.Print();
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
		g.PrinrtShotPath('s', dist, parentPath);
		// 图中带有负权路径时，贪心策略则失效了。
		// 测试结果可以看到s->t->y之间的最短路径没更新出来
		/*const char* str = "sytx";
		Graph<char, int, INT_MAX, true> g(str, strlen(str));
		g.AddEdge('s', 't', 10);
		g.AddEdge('s', 'y', 5);
		g.AddEdge('t', 'y', -7);
		g.AddEdge('y', 'x', 3);
		vector<int> dist;
		vector<int> parentPath;
		g.Dijkstra('s', dist, parentPath);
		g.PrinrtShotPath('s', dist, parentPath);*/
	}
};









int main()
{
	//link_table::TestGraph();
	//matrix::TestGraphDBFS();
	//matrix::TestGraphMinTree();
	matrix::TestGraphDijkstra();
	return 0;
}