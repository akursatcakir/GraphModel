#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections::Generic;
using namespace System::Drawing;

public ref class Graph {
public:
	enum class VertexState { White, Gray, Black };
	typedef Action ^ ReDrawFunction; 
	ref class Vertice;
	typedef Action<Vertice^> ^ StateChangedFunction;
private:
	ReDrawFunction reDrawFunc = nullptr;
	StateChangedFunction stateChangedFunc = nullptr;
public:
	ref class Vertice {
		VertexState _state;
		int _data;
		unsigned int _reachTime, _processTime;
		int _x, _y;
		unsigned int _radius;
		Graph^ parent;
	public:
		List<Vertice^> neighbors;
		[Category("About")]
		[DisplayName("ID")]
		[Description("Vertice number")]
		[ReadOnly(true)]
		property int data {
			void set(int data) {
				_data = data;
			}
			int get() {
				return _data;
			}
		}
		[Category("About")]
		[DisplayName("Degree")]
		[Description("Degree of this vertice. It equals to neighbor count")]
		[ReadOnly(true)]
		property int degree {
			int get() {
				return neighbors.Count;
			}
		}
		[Category("Traversal")]
		[DisplayName("State")]
		[Description("White: Not reached\nGray: Reached, but not processed\nBlack: Reached and processed")]
		[ReadOnly(true)]
		property VertexState  state {
			void set(VertexState v) {
				_state = v;
				if (parent->stateChangedFunc)
					parent->stateChangedFunc(this);
			}
			VertexState get() {
				return _state;
			}
		}
		[Category("Traversal")]
		[DisplayName("Reaching Sequence")]
		[Description("Sequence of pushed to stack")]
		[ReadOnly(true)]
		property unsigned int reachTime {
			void set(unsigned int reachTime) {
				_reachTime = reachTime;
			}
			unsigned int get() {
				return _reachTime;
			}
		}
		[Category("Traversal")]
		[DisplayName("Processing Sequence")]
		[Description("Sequence of pulled from stack")]
		[ReadOnly(true)]
		property unsigned int processTime {
			void set(unsigned int processTime) {
				_processTime = processTime;
			}
			unsigned int get() {
				return _processTime;
			}
		}
		[Category("Drawing")]
		[DisplayName("X Coordinate")]
		property int x {
			void set(int x) {
				if (_x != x) {
					_x = x;
					parent->reDrawFunc();
				}
			}
			int get() {
				return _x;
			}
		}
		[Category("Drawing")]
		[DisplayName("Y Coordinate")]
		property int y {
			void set(int y) {
				if (_y != y) {
					_y = y;
					parent->reDrawFunc();
				}
			}
			int get() {
				return _y;
			}
		}
		[Category("Drawing")]
		[DisplayName("Radius")]
		[Description("Vertice shape's radius")]
		property unsigned int radius {
			void set(unsigned int radius) {
				if (_radius != radius) {
					_radius = radius;
					parent->reDrawFunc();
				}
			}
			unsigned int get() {
				return _radius;
			}
		}
		Vertice(Graph^ Parent){
			parent = Parent;
		}
	};

	enum class TraversalAlgorithm { DFS, BFS };
private:

	void runDFS(Vertice^ vertice, int SleepTime);
	
	void runBFS(Vertice^ vertice, int SleepTime);

	void _traversal(int SleepTime, TraversalAlgorithm alg);

	static void TraversalThreadProc(Object^ obj);
	
	void MarkVisited(Vertice^ vertice, int SleepTime);

	unsigned int time;

	Vertice^ getVertice(int data);

	unsigned int getVerticeCount();

	int getNeighborCount(int data);

	unsigned int getPathCount();

	bool isComplete();

	unsigned int _SleepTime;

public:
	List<Vertice^> vertices;

	void Delete();

	void PlaceVertices(int width, int height);

	void setReDrawFunc(ReDrawFunction func);

	void setStateChangedFunc(StateChangedFunction func);

	void Traversal(TraversalAlgorithm alg);

	void TraversalAsync(TraversalAlgorithm alg);

	void LoadFromText(String^ text);

	void Paint(Graphics^ graphics);

	Vertice^ findVerticeFromPos(int x, int y);
	[Category("Traversal")]
	[DisplayName("Waiting Time (ms)")]
	[Description("Waiting time after every operations. Unit: milliseconds")]
	property unsigned int SleepTime {
		unsigned int get() {
			return _SleepTime;
		}
		void set(unsigned int SleepTime) {
			_SleepTime = SleepTime;
		}
	}

	[Category("Graph")]
	[DisplayName("Vertice Count")]
	[ReadOnly(true)]
	property unsigned int VerticeCount {
		unsigned int get() {
			return getVerticeCount();
		}
	}

	[Category("Graph")]
	[DisplayName("Path Count")]
	[ReadOnly(true)]
	property unsigned int PathCount {
		unsigned int get() {
			return getPathCount();
		}
	}

	[Category("Graph")]
	[DisplayName("Is Complete")]
	[Description("In complete graph, all vertices are neighbor to each other vertices.\nTrue: This graph is complete graph\nFalse: This graph is non complete graph")]
	[ReadOnly(true)]
	property bool IsComplete {
		bool get() {
			return isComplete();
		}
	}

};